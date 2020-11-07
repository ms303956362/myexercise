import numpy as np
import torch as t
import torch.nn as nn
from machin.frame.algorithms import MADDPG
from machin.utils.logging import default_logger as logger

import sys
sys.path.append('.')
from powerenv import PowerNet


class VoltageController:
    def __init__(self, ppc, agentBuses, agentGens, Actor, Critic) -> None:
        # 定义模型和参数
        self.ppc = ppc
        self.agentBuses = agentBuses
        self.agentGens = agentGens
        self.powerenv = PowerNet(ppc, agentBuses, agentGens)
        self.agent_num = len(agentGens)
        self.states_dim = list(map(lambda x : 4 * x, list(map(len, agentBuses))))
        self.actions_dim = list(map(len, agentGens))
        self.maddpg = MADDPG(
                        [Actor(sdim, adim) for sdim, adim in zip(self.states_dim, self.actions_dim)],
                        [Actor(sdim, adim) for sdim, adim in zip(self.states_dim, self.actions_dim)],
                        [Critic(sum(self.states_dim), sum(self.actions_dim)) for _ in range(self.agent_num)],
                        [Critic(sum(self.states_dim), sum(self.actions_dim)) for _ in range(self.agent_num)],
                        [list(range(self.agent_num))] * self.agent_num,
                        t.optim.Adam,
                        nn.MSELoss(reduction='sum')
                    )
    
    def train(self, max_episodes=100, max_steps=20, solved_reward = 0.1, solved_repeat = 5):
        # training，训练模型，对应流程图3.3
        # 初始化
        episode, step, reward_fulfilled = 0, 0, 0
        smoothed_total_reward = 0

        # 各agent损失曲线
        action_losses = [[] for _ in range(len(self.agentBuses))]
        value_losses = [[] for _ in range(len(self.agentGens))]
        time_step = [0]
        # 开始各episode的训练（外层循环）
        while episode < max_episodes:
            # 初始化，重置environment，生成新的电网运行状态
            episode += 1
            total_reward = 0
            terminal = False
            step = 0
            states = [t.tensor(st, dtype=t.float32).view(1, st.shape[0])
                    for st in self.powerenv.reset()]
            
            # agent与environment互动，通过控制机端电压，控制电网电压
            while not terminal and step <= max_steps:
                step += 1
                with t.no_grad():
                    old_states = states
                    # agent model inference，根据state，通过MADDPG模型计算agent控制区域的机端电压
                    result = self.maddpg.act([{"state": st} for st in states])
                    action = [act.numpy() for act in result]
                    
                    # agent与environment交互一步，获取交互后的下一状态
                    states, rewards, terminals, _ = self.powerenv.step(action)
                    states = [t.tensor(st, dtype=t.float32) for st in states]
                    total_reward += float(sum(rewards)) / self.agent_num
                    terminal = bool(np.prod(terminals))

                    # 存储(s_t, a_t, s_t+1, r_t+1, terminal_t)到replay buffer
                    self.maddpg.store_transitions([{
                        "state": {"state": ost},
                        "action": {"action": act},
                        "next_state": {"state": st},
                        "reward": float(rew),
                        "terminal": term or step == max_steps
                    } for ost, act, st, rew, term in zip(
                        old_states, result, states, rewards, terminals
                    )])
            
            # total reward is divided by steps here, since:
            # "Agents are rewarded based on minimum agent distance
            #  to each landmark, penalized for collisions"
            # 计算单步平均reward
            total_reward /= step

            # update, update more if episode is longer, else less
            # 20%个episode后，更新模型参数
            if episode > int(0.2 * max_episodes):
                for _ in range(step):
                    self.maddpg.update()

                    # if you want to plot loss, please revise the `update` function, return `all_loss` directly and uncomment the code in line 81~85, line 174~185
                    # 如果需要存储loss曲线，需要修改MADDPG中update的源码，直接返回各agent的reward，把以下代码去掉注释，并注释上面update的代码
                    # loss = self.maddpg.update()
                    # time_step.append(time_step[-1] + 1)
                    # for all, vll, (al, vl) in zip(action_losses, value_losses, loss):
                    #     all.append(al)
                    #     vll.append(vl)

            # 打印训练信息
            # show reward
            smoothed_total_reward = (smoothed_total_reward * 0.9 +
                                    total_reward * 0.1)
            logger.info("Episode {} total reward={:.2f}"
                        .format(episode, smoothed_total_reward))

            if smoothed_total_reward > solved_reward and episode > int(0.3 * max_episodes):
                reward_fulfilled += 1
                if reward_fulfilled >= solved_repeat:
                    logger.info("Environment solved!")
                    exit(0)
            else:
                reward_fulfilled = 0
        time_step.pop()
        return action_losses, value_losses, time_step

    def act(self, ppc):
        '''
        Control the voltage using MADDPG model
        '''
        with t.no_grad():
            sts = self.powerenv.get_state(ppc)
            states = [t.tensor(st, dtype=t.float32).view(1, st.shape[0])
                    for st in sts]
            result = self.maddpg.act(states)


if __name__ == "__main__":
    from pypower.api import case39
    import matplotlib.pyplot as plt
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
            a = 1 + 0.1 * a
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

    # powernet environement configuration，建立电网模型
    ppc = case39()

    # the number of buses controled by each agent，各agent控制区域的节点
    agentBuses = [
        [2, 14, 15, 16, 17, 18, 25, 26, 27, 28, 29, 30, 37, 38],
        [13, 19, 20, 21, 22, 23, 24, 33, 34, 35, 36],
        [1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 31, 32, 39]
    ]
    agentBuses = [[b - 1 for b in buses] for buses in agentBuses]

    # the number of generators controled by each agent，各agent控制区域的发电机编号
    agentGens = [
        [0, 7, 8],
        [3, 4, 5, 6],
        [1, 2, 9]
    ]

    # voltage controller，电压控制模型，训练
    vc = VoltageController(ppc, agentBuses, agentGens, Actor, Critic)
    vc.train()

    # 如果需要打印loss曲线，需要修改MADDPG中update的源码，直接返回各agent的reward，把以下代码去掉注释，并注释上面update的代码
    # if you want to plot loss, please revise the `update` function, return `all_loss` directly and uncomment the code in line 81~85, line 174~185
    # action_losses, value_losses, time_step = vc.train()
    # num = 1
    # for al in action_losses:
    #     plt.subplot(2, 3, num)
    #     plt.plot(time_step, al)
    #     num += 1
    # for vl in value_losses:
    #     plt.subplot(2, 3, num)
    #     plt.plot(time_step, vl)
    #     num += 1
    # plt.savefig(str(num))
    # plt.show()
