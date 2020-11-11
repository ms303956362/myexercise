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
        # training
        episode, step, reward_fulfilled = 0, 0, 0
        smoothed_total_reward = 0

        action_losses = [[] for _ in range(len(self.agentBuses))]
        value_losses = [[] for _ in range(len(self.agentGens))]
        s_reward = [[0] for _ in range(len(self.agentBuses))]
        t_reward = [[] for _ in range(len(self.agentBuses))]
        time_step = [0]
        iter_step = [0]
        while episode < max_episodes:
            episode += 1
            total_reward = 0
            terminal = False
            step = 0
            states = [t.tensor(st, dtype=t.float32).view(1, st.shape[0])
                    for st in self.powerenv.reset()]
            
            # reward
            for tl in t_reward:
                tl.append(0)
            
            while not terminal and step <= max_steps:
                step += 1
                with t.no_grad():
                    old_states = states
                    # agent model inference
                    result = self.maddpg.act([{"state": st} for st in states])
                    action = [act.numpy() for act in result]
                    
                    states, rewards, terminals, _ = self.powerenv.step(action)
                    states = [t.tensor(st, dtype=t.float32) for st in states]
                    total_reward += float(sum(rewards)) / self.agent_num
                    terminal = bool(np.prod(terminals))
                    
                    # cum reward
                    for tl, r in zip(t_reward, rewards):
                        tl[-1] += r.item()

                    self.maddpg.store_transitions([{
                        "state": {"state": ost},
                        "action": {"action": act},
                        "next_state": {"state": st},
                        "reward": float(rew),
                        "terminal": bool(term) or step == max_steps
                    } for ost, act, st, rew, term in zip(
                        old_states, result, states, rewards, terminals
                    )])
            
            # total reward is divided by steps here, since:
            # "Agents are rewarded based on minimum agent distance
            #  to each landmark, penalized for collisions"
            total_reward /= step
            for tl in t_reward:
                tl[-1] /= step
            iter_step.append(iter_step[-1] + 1)
            for sl, tl in zip(s_reward, t_reward):
                sl.append(sl[-1] * 0.9 + tl[-1] * 0.1)

            # update, update more if episode is longer, else less
            if episode > int(0.2 * max_episodes):
                # time step
                for _ in range(step):
                    loss = self.maddpg.update()
                    time_step.append(time_step[-1] + 1)
                    for all, vll, (al, vl) in zip(action_losses, value_losses, loss):
                        all.append(al)
                        vll.append(vl)

            # show reward
            smoothed_total_reward = (smoothed_total_reward * 0.9 +
                                    total_reward * 0.1)
            
            logger.info("Episode {} total reward={:.2f}"
                        .format(episode, smoothed_total_reward))

            if smoothed_total_reward > solved_reward and episode > int(0.3 * max_episodes):
                reward_fulfilled += 1
                if reward_fulfilled >= solved_repeat:
                    logger.info("Environment solved!")
                    break
            else:
                reward_fulfilled = 0
        time_step.pop()
        iter_step.pop()
        for sl in s_reward:
            sl.pop(0)
        return action_losses, value_losses, s_reward, t_reward, time_step, iter_step

    def act(self, ppc):
        with t.no_grad():
            sts = self.powerenv.get_state(ppc)
            states = [t.tensor(st, dtype=t.float32).view(1, st.shape[0])
                    for st in sts]
            result = self.maddpg.act(states)


if __name__ == "__main__":
    from pypower.api import case39
    import matplotlib
    matplotlib.use('Agg')
    import h5py
    from case11 import case11
    
    # model definition
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
            a = 1 + 0.15 * a
            return a


    class Critic(nn.Module):
        def __init__(self, state_dim, action_dim):
            # This critic implementation is shared by the prey(DDPG) and
            # predators(MADDPG)
            # Note: For MADDPG
            #       state_dim is the dimension of all states from all agents.
            #       action_dim is the dimension of all actions from all agents.
            super(Critic, self).__init__()

            self.fc1 = nn.Linear(state_dim + action_dim, 20)
            self.fc2 = nn.Linear(20, 16)
            self.fc3 = nn.Linear(16, 1)

        def forward(self, state, action):
            state_action = t.cat([state, action], 1)
            q = t.relu(self.fc1(state_action))
            q = t.relu(self.fc2(q))
            q = self.fc3(q)
            return q
    # 89, 89
    # np.random.seed(172)
    # t.manual_seed(89)

    # powernet environement configuration
    ppc = case39()

    # the number of buses controled by each agent
    agentBuses = [
        [2, 14, 15, 16, 17, 18, 25, 26, 27, 28, 29, 30, 37, 38],
        [13, 19, 20, 21, 22, 23, 24, 33, 34, 35, 36],
        [1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 31, 32, 39]
    ]
    agentBuses = [[b - 1 for b in buses] for buses in agentBuses]

    # the number of generators controled by each agent
    agentGens = [
        [0, 7, 8],
        [3, 4, 5, 6],
        [1, 2, 9]
    ]

    # ppc = case11()
    # agentBuses = [
    #     [3, 10, 11],
    #     [1, 2, 4, 5, 6, 7, 8, 9]
    # ]

    # agentBuses = [[b - 1 for b in buses] for buses in agentBuses]

    # agentGens = [
    #     [0],
    #     [1]
    # ]

    # voltage controller
    vc = VoltageController(ppc, agentBuses, agentGens, Actor, Critic)
    action_losses, value_losses, s_reward, t_reward, time_step, iter_step = vc.train(max_episodes=100, solved_reward=0.2)
    with h5py.File('loss.h5', 'w') as f:
        f.create_dataset('action_losses', data=np.array(action_losses))
        f.create_dataset('value_losses', data=np.array(value_losses))
        f.create_dataset('s_reward', data=np.array(s_reward))
        f.create_dataset('t_reward', data=np.array(t_reward))
        f.create_dataset('time_step', data=np.array(time_step))
        f.create_dataset('iter_step', data=np.array(iter_step))

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
