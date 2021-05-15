from typing import Dict
import gym
import numpy as np


def mc_control(env: gym.Env, q_table: Dict[tuple, Dict], n0=100, gamma: float=0.99, num_episode: int=10000):
    n_table = {state: {action: 0 for action in q_table[state]} for state in q_table}
    eps = {state: 1 for state in q_table}
    for k in range(1, num_episode + 1):
        trajectory = []
        state = env.reset()
        done = False
        # interact with eps-greedy policy
        while not done:
            # eps-greedy
            action = env.action_space.sample() if np.random.rand() < eps[state] else max(q_table[state], key=q_table[state].get)
            # step
            next_state, reward, done, _ = env.step(action)
            # store
            trajectory.append((state, action, reward))
            state = next_state
        # update policy
        trajectory.reverse()
        ret = 0
        for state, action, reward in trajectory:
            ret = gamma * ret + reward
            n_table[state][action] += 1
            q_table[state][action] += 1 / n_table[state][action] * (ret - q_table[state][action])
            eps[state] = n0 / (n0 + sum(n_table[state].values()))
        if k % (num_episode / 50) == 0:
            print('Episode {}, Total reward:{:>3}, Total time steps:{:>3}, final state:{}'.format(k, ret, len(trajectory), trajectory[0][0]))
    return q_table


if __name__ == '__main__':
    from easy21_env import Easy21Env
    from utils import plot_value_function
    from constants import DEALER_MAX_SHOW_SCORE, BUST_MAX_SCORE, BUST_MIN_SCORE
    env = Easy21Env()
    q_table = {(sum_player, sum_dealer): {0: 0, 1: 0} 
        for sum_dealer in range(BUST_MIN_SCORE, DEALER_MAX_SHOW_SCORE + 1) 
        for sum_player in range(BUST_MIN_SCORE, BUST_MAX_SCORE + 1)}
    q_table = mc_control(env, q_table, gamma=1.0, num_episode=1000000)
    v_table = {state: max(q_table[state].values()) for state in q_table}
    plot_value_function(v_table)
