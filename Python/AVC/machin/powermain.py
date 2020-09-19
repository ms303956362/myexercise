import sys
import numpy as np
import torch as t
import torch.nn as nn
from machin.frame.algorithms import MADDPG
from machin.utils.logging import default_logger as logger
sys.path.append('.')
from powerenv import PowerNet
from pypower.api import case39


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


def main():
    # the number of buses controled by different agents
    agentBuses = [
        [2, 14, 15, 16, 17, 18, 25, 26, 27, 28, 29, 30, 37, 38],
        [13, 19, 20, 21, 22, 23, 24, 33, 34, 35, 36],
        [1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 31, 32, 39]
    ]
    agentBuses = [[b - 1 for b in buses] for buses in agentBuses]

    # the number of generators controled by different agents
    agentGens = [
        [0, 7, 8],
        [3, 4, 5, 6],
        [1, 2, 9]
    ]

    # powernet environement configuration
    ppc = case39()
    powerenv = PowerNet(ppc, agentBuses, agentGens)
    max_episodes = 1000
    max_steps = 200
    agent_num = len(agentGens)
    states_dim = list(map(lambda x : 4 * x, list(map(len, agentBuses))))
    actions_dim = list(map(len, agentGens))
    solved_reward = 0.1
    solved_repeat = 5

    # model
    maddpg = MADDPG(
        [Actor(sdim, adim) for sdim, adim in zip(states_dim, actions_dim)],
        [Actor(sdim, adim) for sdim, adim in zip(states_dim, actions_dim)],
        [Critic(sum(states_dim), sum(actions_dim)) for _ in range(agent_num)],
        [Critic(sum(states_dim), sum(actions_dim)) for _ in range(agent_num)],
        [list(range(agent_num))] * agent_num,
        t.optim.Adam,
        nn.MSELoss(reduction='sum')
    )

    # training
    episode, step, reward_fulfilled = 0, 0, 0
    smoothed_total_reward = 0

    while episode < max_episodes:
        episode += 1
        total_reward = 0
        terminal = False
        step = 0
        states = [t.tensor(st, dtype=t.float32).view(1, st.shape[0])
                  for st in powerenv.reset()]
        
        while not terminal and step <= max_steps:
            step += 1
            with t.no_grad():
                old_states = states
                # agent model inference
                result = maddpg.act([{"state": st} for st in states])
                action = [act.numpy() for act in result]
                
                states, rewards, terminals, _ = powerenv.step(action)
                states = [t.tensor(st, dtype=t.float32) for st in states]
                total_reward += float(sum(rewards)) / agent_num
                terminal = bool(np.prod(terminals))

                maddpg.store_transitions([{
                    "state": {"state": ost},
                    "action": {"action": act},
                    "next_state": {"state": st},
                    "reward": float(rew),
                    "terminal": term or step == max_steps
                } for ost, act, st, rew, term in zip(
                                # ???
                    old_states, result, states, rewards, terminals
                )])
        
        # total reward is divided by steps here, since:
        # "Agents are rewarded based on minimum agent distance
        #  to each landmark, penalized for collisions"
        total_reward /= step

        # update, update more if episode is longer, else less
        if episode > 100:
            for _ in range(step):
                maddpg.update()

        # show reward
        smoothed_total_reward = (smoothed_total_reward * 0.9 +
                                 total_reward * 0.1)
        logger.info("Episode {} total reward={:.2f}"
                    .format(episode, smoothed_total_reward))

        if smoothed_total_reward > solved_reward and episode > 100:
            reward_fulfilled += 1
            if reward_fulfilled >= solved_repeat:
                logger.info("Environment solved!")
                exit(0)
        else:
            reward_fulfilled = 0

if __name__ == "__main__":
    main()
