import gym
import numpy as np
from constants import STICK, HIT, RED, BLACK, DEALER_STICK_SCORE, BUST_MIN_SCORE, BUST_MAX_SCORE

class Easy21Env(gym.Env):
    def __init__(self) -> None:
        self.action_space = gym.spaces.Discrete(2)
        self.sum_player = 0
        self.sum_dealer = 0
    
    def step(self, action):
        assert action == STICK or action == HIT, 'Action should be 0 or 1'
        reward = 0
        done = False
        info = {}
        if action == HIT:
            # player draws a card
            self.sum_player += self._draw()
            # if player goes bust, player losts
            if self.sum_player > BUST_MAX_SCORE or self.sum_player < BUST_MIN_SCORE:
                reward = -1
                done = True
        else:
            # sum of dealer's cards < 17
            while self.sum_dealer < DEALER_STICK_SCORE:
                # dealer draws a card
                self.sum_dealer += self._draw()
                # if dealer goes bust, player wins
                if self.sum_dealer > BUST_MAX_SCORE or self.sum_dealer < BUST_MIN_SCORE:
                    reward = 1
                    done = True
                    break
            # neither dealer nor player goes bust
            if not done:
                # sum_player > sum_dealer, player wins, ==, draws, <, losts
                reward = 1 if self.sum_player > self.sum_dealer else (0 if self.sum_player == self.sum_dealer else -1)
                done = True
        return (self.sum_player, self.sum_dealer), reward, done, info
    
    def reset(self):
        self.sum_dealer = np.random.randint(1, 11)
        self.sum_player = np.random.randint(1, 11)
        return self.sum_player, self.sum_dealer

    def _draw(self):
        value = np.random.randint(1, 11)
        color = RED if np.random.rand() < 1/3 else BLACK
        return value if color == BLACK else -value

if __name__ == '__main__':
    easy21_env = Easy21Env()
    print_interval = 2
    for eps in range(10):
        done = False
        total_reward = 0
        time_steps = 0
        easy21_env.reset()
        print('Episode {} starts'.format(eps))
        while not done:
            action = easy21_env.action_space.sample()
            (sum_player, sum_dealer), reward, done, _ = easy21_env.step(action)
            total_reward += reward
            time_steps += 1
            if time_steps % print_interval == 0:
                print('    Time step:', time_steps, 'player scores:', sum_player, 'dealer scores:', sum_dealer)
        print('Total reward:{:>3}, Total time steps:{:>3}, player scores:{:>3}, dealer scores:{:>3}\n'.format(total_reward, time_steps, sum_player, sum_dealer))
