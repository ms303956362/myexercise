import functools
from typing import Dict
from utils import plot_mses
from constants import dealer_intervals, player_intervals, action_space
from functools import lru_cache
import gym
import numpy as np

# @lru_cache(None)
# def coarse_code(state, action):
#     x = np.zeros((len(dealer_intervals) * len(player_intervals) * len(action_space), ))
#     i_s = list(filter(lambda i: player_intervals[i][0] <= state[0] <= player_intervals[i][1], list(range(len(player_intervals)))))
#     j_s = list(filter(lambda j: dealer_intervals[j][0] <= state[1] <= dealer_intervals[j][1], list(range(len(dealer_intervals)))))
#     for i in i_s:
#         for j in j_s:
#             x[(i + 1) * (j + 1) * (action + 1) - 1] = 1
#     return x

@lru_cache(None)
def coarse_code(s, a):
    feature = []
    for d in dealer_intervals:
        for p in player_intervals:
            for act in action_space:
                if s[0] >= p[0] and s[0] <= p[1] and s[1] >= d[0] and s[1] <= d[1] and a == act:
                    feature.append(1)
                else:
                    feature.append(0) 
    return np.array(feature)

def q_approximation(state: tuple, action: int, weights: np.ndarray):
    return coarse_code(state, action).T @ weights

def eps_greedy(env: gym.Env, state, weights, eps, done=False):
    if done or np.random.rand() < eps:
        return env.action_space.sample()
    else:
        return 1 if q_approximation(state, 0, weights) < q_approximation(state, 1, weights) else 0

def linear_func_approximation(env: gym.Env, lmbda=0.5, gamma: float=0.99, 
                                num_episode: int=10000, q_star=None, eps: float=0.05, alpha: float=0.01):
    mse = np.zeros((num_episode,)) if q_star else None
    weights = np.zeros((len(dealer_intervals) * len(player_intervals) * len(action_space), ))
    for k in range(1, num_episode + 1):
        e = np.zeros((len(dealer_intervals) * len(player_intervals) * len(action_space), ))
        state = env.reset()
        action = eps_greedy(env, state, weights, eps)
        done = False
        # interact with eps-greedy policy
        while not done:
            # step
            next_state, reward, done, _ = env.step(action)
            # eps-greedy
            next_action = eps_greedy(env, next_state, weights, eps, done)
            # update policy
            td_error = reward + gamma * (0 if done else q_approximation(next_state, next_action, weights)) - q_approximation(state, action, weights)
            e = gamma * lmbda * e + coarse_code(state, action)
            weights += alpha * td_error * e
            # update state, action
            state = next_state
            action = next_action
        if k % max(num_episode / 50, 1000) == 0:
            print('Lambda: {}, Episode {}'.format(lmbda, k))
        if q_star:
            mse[k - 1] = sum([sum([(q_star[s][a] - q_approximation(s, a, weights))**2 for a in q_star[s]]) for s in q_star])
    return weights, mse


if __name__ == '__main__':
    from easy21_env import Easy21Env
    from mc_control import mc_control
    from utils import plot_value_function
    from constants import DEALER_MAX_SHOW_SCORE, BUST_MAX_SCORE, BUST_MIN_SCORE
    from utils import plot_mse

    env = Easy21Env()
    q_star = {(sum_player, sum_dealer): {0: 0, 1: 0} 
        for sum_dealer in range(BUST_MIN_SCORE, DEALER_MAX_SHOW_SCORE + 1) 
        for sum_player in range(BUST_MIN_SCORE, BUST_MAX_SCORE + 1)}
    q_star = mc_control(env, q_star, gamma=1.0, num_episode=1000000)
    # q_star = None
    lmbdas = np.linspace(0, 1, num=11)
    mses = []
    mses_last = []
    for l in lmbdas:
        weights, mse = linear_func_approximation(env, lmbda=l, gamma=1.0, num_episode=10000, q_star=q_star)
        if l == 0 or l == 1:
            q_table = {(sum_player, sum_dealer): {a: q_approximation((sum_player, sum_dealer), a, weights) for a in action_space} 
                for sum_dealer in range(BUST_MIN_SCORE, DEALER_MAX_SHOW_SCORE + 1) 
                for sum_player in range(BUST_MIN_SCORE, BUST_MAX_SCORE + 1)}
            v_table = {state: max(q_table[state].values()) for state in q_table}
            plot_value_function(v_table)
        if mse is not None:
            mses.append(mse)
            mses_last.append(mse[-1])
    if mse is not None:
        plot_mse(lmbdas, np.array(mses_last))
        plot_mses(lmbdas, mses)
