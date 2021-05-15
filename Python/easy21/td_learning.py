from typing import Dict
from utils import plot_mses
import gym
import numpy as np

def sarsa_lambda(env: gym.Env, q_table: Dict[tuple, Dict], n0=100, lmbda=0.5, gamma: float=0.99, num_episode: int=10000, q_star=None):
    n_table = {state: {action: 0 for action in q_table[state]} for state in q_table}
    eps = {state: 1 for state in q_table}
    mse = np.zeros((num_episode,)) if q_star else None
    for k in range(1, num_episode + 1):
        e = {state: {action: 0 for action in q_table[state]} for state in q_table}
        state = env.reset()
        action = env.action_space.sample() if np.random.rand() < eps[state] else max(q_table[state], key=q_table[state].get)
        done = False
        # interact with eps-greedy policy
        while not done:
            # step
            next_state, reward, done, _ = env.step(action)
            # eps-greedy
            next_action = env.action_space.sample() if done or np.random.rand() < eps[state] else max(q_table[state], key=q_table[state].get)
            # update policy
            td_error = reward + gamma * (0 if done else q_table[next_state][next_action]) - q_table[state][action]
            e[state][action] += 1
            n_table[state][action] += 1
            eps[state] = n0 / (n0 + sum(n_table[state].values()))
            for s in q_table:
                for a in q_table[s]:
                    alpha = 1 / max(n_table[s][a], 1)
                    q_table[s][a] += alpha * td_error * e[s][a]
                    e[s][a] *= gamma * lmbda
            # update state, action
            state = next_state
            action = next_action
        if k % max(num_episode / 50, 1000) == 0:
            print('Episode {}'.format(k))
        if q_star:
            mse[k - 1] = sum([sum([(q_star[s][a] - q_table[s][a])**2 for a in q_table[s]]) for s in q_table])
    return q_table, mse


if __name__ == '__main__':
    from easy21_env import Easy21Env
    from mc_control import mc_control
    from utils import plot_value_function
    from constants import DEALER_MAX_SHOW_SCORE, BUST_MAX_SCORE, BUST_MIN_SCORE
    from utils import plot_mse

    env = Easy21Env()
    q_table = {(sum_player, sum_dealer): {0: 0, 1: 0} 
        for sum_dealer in range(BUST_MIN_SCORE, DEALER_MAX_SHOW_SCORE + 1) 
        for sum_player in range(BUST_MIN_SCORE, BUST_MAX_SCORE + 1)}
    q_star = {(sum_player, sum_dealer): {0: 0, 1: 0} 
        for sum_dealer in range(BUST_MIN_SCORE, DEALER_MAX_SHOW_SCORE + 1) 
        for sum_player in range(BUST_MIN_SCORE, BUST_MAX_SCORE + 1)}
    q_star = mc_control(env, q_star, gamma=1.0, num_episode=1000000)
    lmbdas = np.linspace(0, 1, num=11)
    mses = []
    mses_last = []
    for l in lmbdas:
        q_table, mse = sarsa_lambda(env, q_table, lmbda=l, gamma=1.0, num_episode=10000, q_star=q_star)
        if mse is not None:
            mses.append(mse)
            mses_last.append(mse[-1])
    v_table = {state: max(q_star[state].values()) for state in q_star}
    plot_value_function(v_table)
    plot_mse(lmbdas, np.array(mses_last))
    plot_mses(lmbdas, mses)
