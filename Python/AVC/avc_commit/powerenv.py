import gym
import numpy as np
from copy import deepcopy
from pypower.api import runpf, ppoption
from pypower.idx_bus import PD, QD, VM, VA
from pypower.idx_gen import GEN_BUS, PG, QG, VG


class PowerNet(gym.Env):
    def __init__(self, ppc, areaBuses, areaGens, vref = 1.0, alpha=0.1, beta=0.5) -> None:
        """
        Power net environment for reinforcement learning, implemented by using pypower, gym
        @ppc: dict, pypower case
        @areaBuses: List[List[]], i-th term is the list of bus numbers in i-th area
        @areaGens: List[List[]], i-th term is the list of generator numbers in i-th area
        @vref: reference voltage of the system, p.u.
        """
        # 初始化pypower 模型和设置，ppc是当前电网运行模型，ppc0是原始电网模型
        self.ppc = ppc
        self.ppopt = ppoption(PF_ALG=1, VERBOSE=0, OUT_ALL=0)
        self.ppc0 = deepcopy(self.ppc)
        # areaBuses和areaGens是List of List，表示各agent所控制区域的节点和发电机
        self.areaBuses = areaBuses
        self.areaGens = areaGens
        # 一些常量，如参考电压、计算reward时需要的参数等
        self.vref = vref
        self.alpha = alpha
        self.beta = beta
        # 根据agent控制区域的节点数和发电机数，确定各agent的输入（状态s)和输出（动作a)维数
        self.state_dim = list(map(lambda x: 4 * x, list(map(len, areaBuses))))  # each term in states list is PD, QD, V, theta of buses in each area
        self.action_dim = list(map(len, areaGens)) # each term in actions list is voltage of generators in each area
        # 检查各agent的状态维数总和以及动作维数总和，应分别等于电网节点数和发电机数
        assert(sum(self.state_dim) / 4 == len(ppc['bus']))
        assert(sum(self.action_dim) == len(ppc['gen']))
    
    def reset(self):
        '''
        Reset and generate the operating state of power grid randomly
        '''
        # copy原始电网模型
        self.ppc = deepcopy(self.ppc0)
        # random load level, 0.7~1.3  在原始电网模型基础上，随机生成系统负荷水平，范围0.7~1.3
        level = 1 + 0.3 * np.random.rand()
        self.ppc['bus'][:, (PD, QD)] *= level
        self.ppc['gen'][:, (PG, QG)] *= level
        # 将pypower电网模型数据，整理为machin库agent所需的输入形式
        # 输入state为list of list，state[j]为第j个agent的输入特征向量，包括该agent区域内各节点的有功无功注入功率、节点电压幅值相角
        state = [np.zeros(dim) for dim in self.state_dim]
        state_bus = self.ppc['bus'][:, (PD, QD, VM, VA)]
        state_gen = self.ppc['gen'][:, (GEN_BUS, PG, QG)]
        # 根据节点负荷和各节点发电机数据转换为注入功率
        # 计算整个电网的各节点注入功率
        state_bus = self._cal_inject_power(state_bus, state_gen)
        for j, buses in enumerate(self.areaBuses):
            assert(len(state[j]) / 4 == len(buses))
            # 选中各agent控制区域的节点编号作为下标，拼接
            state[j] = np.concatenate([state_bus[buses][:, i] for i in range(4)])
        return state
    
    def get_state(self, ppc):
        '''
        get the operating state of the power grid and return vector of state
        '''
        # 读取模型中的节点负荷功率、电压和发电机出力
        state = [np.zeros(dim) for dim in self.state_dim]
        state_bus = ppc['bus'][:, (PD, QD, VM, VA)]
        state_gen = ppc['gen'][:, (GEN_BUS, PG, QG)]
        # 转换为节点注入功率
        state_bus = self._cal_inject_power(state_bus, state_gen)
        for j, buses in enumerate(self.areaBuses):
            assert(len(state[j]) / 4 == len(buses))
            # 选中各agent控制区域的节点编号作为下标，拼接
            state[j] = np.concatenate([state_bus[buses][:, i] for i in range(4)])
        return state


    def step(self, action):
        '''
        Calculate the operating state of power grid and the reward according to the given voltage of generator
        @action: List(np.array(batch_size, action_dim)), len = len(areaGens)
        @state: List(np.array(batch_size, state_dim)), len = len(areaBuses)
        '''
        # 设定发电机机端电压，并计算新的电网运行状态和reward
        assert(len(action) == len(self.areaGens))
        # 返回的变量
        batch_size = action[0].shape[0]
        state = [np.zeros((batch_size, dim)) for dim in self.state_dim]
        reward = [np.zeros(batch_size) for _ in range(len(self.areaBuses))]
        terminal = [np.zeros(batch_size) for _ in range(len(self.areaBuses))]
        for i in range(batch_size):
            # set voltage of generators，在pypower电网模型中设置发电机机端电压
            for j, gens in enumerate(self.areaGens):
                assert(len(self.ppc['gen'][gens, VG]) == len(gens))
                self.ppc['gen'][gens, VG] = action[j][i]
            # calculate power flow，计算潮流
            result, _ = runpf(self.ppc, self.ppopt)
            # calculate the p, q, v, theta of buses，提取节点负荷功率和电压、发电机出力
            result_bus = result['bus'][:, (PD, QD, VM, VA)]
            result_gen = result['gen'][:, (GEN_BUS, PG, QG)]
            # 根据负荷功率和发电机出力，计算节点注入功率
            result_bus = self._cal_inject_power(result_bus, result_gen)
            for j, buses in enumerate(self.areaBuses):
                assert(len(state[j][i]) / 4 == len(buses))
                state[j][i] = np.concatenate([result_bus[buses][:, i] for i in range(4)])
            # caculate the rewards，根据报告中对reward的定义计算各节点的reward，见表3.1
            reward_bus = self._cal_reward_bus(result['bus'][:, VM])
            # 根据2.3.2.3节的公式，计算各agent的reward
            for j, r in enumerate(reward):
                # the voltages of all buses in [0.95, 1.05]
                if np.where((0.95 <= result['bus'][:, VM]) * (result['bus'][:, VM] <= 1.05))[0].tolist() == list(range(len(result['bus'][:, VM]))):
                    r[i] = np.sum(reward_bus) / np.arange(result['bus'].shape[0])
                # the voltages of all buses in [0.8, 1.2], and some of them not in [0.95, 1.05]
                elif np.where((0.8 <= result['bus'][:, VM]) * (result['bus'][:, VM]  <= 1.2))[0].tolist() == list(range(len(result['bus'][:, VM]))):
                    for k, buses in enumerate(self.areaBuses):
                        if k != j:
                            r[i] += self.beta * np.sum(reward_bus[buses])
                        else:
                            r[i] += np.sum(reward_bus[buses])
                    r[i] *= self.alpha
                # v < 0.8 or v > 1.2 
                else:
                    r[i] = -5
            # judge whether voltage violation in each area happened，判断各控制区域的节点电压是否有越限，如果没有越限，该区域训练中止
            for j, term in enumerate(terminal):
                buses = np.array(self.areaBuses[j])
                if ((0.95 <= result['bus'][buses][:, VM]) * (result['bus'][buses][:, VM] <= 1.05)).all():
                    term[i] = True
                else:
                    term[i] = False
        return state, reward, terminal, {}
    
    def _cal_inject_power(self, result_bus, result_gen):
        '''
        Inject power of buses
        @result_bus: (num_bus, 4), PD, QD, VM, VA of all buses
        @result_gen: (num_bus, 3), GEN_BUS, PG, QG
        @result_concat: (num_bus, ), concat 2nd dimension
        '''
        # 根据各节点负荷功率和发电机出力，计算节点注入功率
        for bus_i, pg, qg in result_gen:
            result_bus[int(bus_i) - 1][0] -= pg # PD
            result_bus[int(bus_i) - 1][1] -= qg # QD
        return result_bus

    def _cal_reward_bus(self, result_v):
        '''
        @result_v: (num_bus, ) VM
        '''
        # 根据报告计算节点reward，见表3.1
        reward_bus = np.zeros(len(result_v))
        idx, = np.where((0.95 <= result_v) * (result_v <= self.vref))
        reward_bus[idx] = (result_v[idx] - 0.95) / (self.vref - 0.95)
        idx, = np.where((self.vref < result_v) * (result_v  <= 1.05))
        reward_bus[idx] = (1.05 - result_v[idx]) / (1.05 - self.vref)
        idx, = np.where((0.8 <= result_v) * (result_v  < 0.95))
        reward_bus[idx] = (self.vref - result_v[idx]) / (0.8 - self.vref)
        idx, = np.where((1.05 < result_v) * (result_v  <= 1.2))
        reward_bus[idx] = (result_v[idx] - self.vref) / (self.vref - 1.2)
        idx, = np.where((result_v < 0.8) + (result_v > 1.2))
        reward_bus[idx] = -5
        return reward_bus


if __name__ == "__main__":
    import torch as t
    import torch.nn as nn
    from machin.frame.algorithms import MADDPG
    from machin.utils.logging import default_logger as logger
    from pypower.api import case39
    # model definition，定义Actor和Critic模型
    class Actor(nn.Module):
        def __init__(self, state_dim, action_dim):
            super(Actor, self).__init__()

            self.fc1 = nn.Linear(state_dim, 16)
            self.fc2 = nn.Linear(16, 16)
            self.fc3 = nn.Linear(16, action_dim)

        def forward(self, state):
            a = t.relu(self.fc1(state))
            a = t.relu(self.fc2(a))
            a = t.tanh(self.fc3(a))
            a = 1 + 0.2 * a
            return a


    class Critic(nn.Module):
        def __init__(self, state_dim, action_dim):
            # This critic implementation is shared by the prey(DDPG) and
            # predators(MADDPG)
            # Note: For MADDPG
            #       state_dim is the dimension of all states from all agents.
            #       action_dim is the dimension of all actions from all agents.
            super(Critic, self).__init__()

            self.fc1 = nn.Linear(state_dim + action_dim, 16)
            self.fc2 = nn.Linear(16, 16)
            self.fc3 = nn.Linear(16, 1)

        def forward(self, state, action):
            state_action = t.cat([state, action], 1)
            q = t.relu(self.fc1(state_action))
            q = t.relu(self.fc2(q))
            q = self.fc3(q)
            return q

    # 各agent控制区域的节点编号
    agentBuses = [
        [2, 14, 15, 16, 17, 18, 25, 26, 27, 28, 29, 30, 37, 38],
        [13, 19, 20, 21, 22, 23, 24, 33, 34, 35, 36],
        [1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 31, 32, 39]
    ]

    # 下标从0开始
    agentBuses = [[b - 1 for b in buses] for buses in agentBuses]

    # 各agent控制区域的发电机编号
    agentGens = [
        [0, 7, 8],
        [3, 4, 5, 6],
        [1, 2, 9]
    ]

    # 计算各agent的输入输出维数
    agent_num = len(agentGens)
    states_dim = list(map(lambda x : 4 * x, list(map(len, agentBuses))))
    actions_dim = list(map(len, agentGens))

    # 使用machin库定义MADDPG模型
    maddpg = MADDPG(
        [Actor(sdim, adim) for sdim, adim in zip(states_dim, actions_dim)],
        [Actor(sdim, adim) for sdim, adim in zip(states_dim, actions_dim)],
        [Critic(sum(states_dim), sum(actions_dim)) for _ in range(agent_num)],
        [Critic(sum(states_dim), sum(actions_dim)) for _ in range(agent_num)],
        [list(range(agent_num))] * agent_num,
        t.optim.Adam,
        nn.MSELoss(reduction='sum')
    )
    
    # 建立电网模型和强化学习environment
    ppc = case39()
    powerenv = PowerNet(ppc, agentBuses, agentGens)
    states = [t.tensor(st, dtype=t.float32).view(1, st.shape[0])
                  for st in powerenv.reset()]
    
    # MADDPG与environment互动一次并更新参数，测试自定义的PowerEnv送给MADDPG输入是否符合要求
    with t.no_grad():
        result = maddpg.act([{"state": st} for st in states])
        action = [act.numpy() for act in result]
        states, rewards, violated, _ = powerenv.step(action)
        states = [t.tensor(st, dtype=t.float32)
                  for st in states]
    maddpg.update()
    