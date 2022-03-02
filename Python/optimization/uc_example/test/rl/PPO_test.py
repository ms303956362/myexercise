import torch
import torch.nn as nn
import gym
from torch.distributions.categorical import Categorical
from torch.distributions import Distribution


class BaseAgent(object):
    def __init__(self, policy_net: nn.Module):
        self.policy = policy_net

    def act(self, obs) -> Distribution:
        raise NotImplementedError


class CartPoleAgent(BaseAgent):
    def __init__(self, policy_net: nn.Module):
        super(CartPoleAgent, self).__init__(policy_net)

    def act(self, obs) -> Categorical:
        return Categorical(self.policy(torch.as_tensor(obs, dtype=torch.float32)))


class PPO(object):
    def __init__(self, agent: BaseAgent, value_net: nn.Module, env: gym.Env, eps=0.01, n_trajectories=10,
                 n_epochs=100, n_max_steps=100):
        self.agent = agent
        self.value_net = value_net
        self.env = env
        self.eps = eps
        self.n_trajectories = n_trajectories
        self.n_epochs = n_epochs
        self.n_max_steps = n_max_steps

    def train(self):
        for _ in range(self.n_epochs):
            trajectories = self._interact()

    def _interact(self):
        trajectories = []
        for _ in range(self.n_trajectories):
            trajectory = []
            obs = self.env.reset()
            for _ in range(self.n_max_steps):
                action = self.agent.act(obs).sample()
                obs_next, reward, done, _ = self.env.step(action)
                trajectory.append((obs, action, reward, obs_next))
                if done:
                    break
                obs = obs_next
            trajectories.append(trajectory)
        return trajectories

    def _update_policy(self):
        pass

    def _fit_value(self):
        pass


if __name__ == '__main__':
    from torch.distributions.bernoulli import Bernoulli
    dist = Bernoulli(torch.Tensor([[0.3, 0.5, 0.7], [0.1, 0.2, 0.9]]))
    print(dist.sample())
