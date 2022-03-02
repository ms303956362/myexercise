import numpy as np
import gym
from gym import spaces


class SCUCEnv(gym.Env):
    def __init__(self, n_time, n_nodes, n_edges, n_node_features=6, n_edge_features=5):
        """
        The environment of optimizing SCUC problem

        :param n_time: The number of dispatch intervals
        :param n_nodes: The number of nodes in power grid
        :param n_edges: The number of edges in power grid
        :param n_node_features: The number of node features
        :param n_edge_features: The number of edge features
        """
        super(SCUCEnv, self).__init__()
        self.n_time = n_time
        self.n_nodes = n_nodes
        self.n_edges = n_edges
        self.n_node_features = n_node_features
        self.n_edge_features = n_edge_features
        self.action_space = spaces.MultiBinary([n_time, n_edges + 1, n_edges])
        self.observation_space = spaces.Dict({
            'node_features': spaces.Box(low=-np.inf, high=np.inf, shape=(n_time, n_nodes, n_node_features)),
            'edge_features': spaces.Box(low=-np.inf, high=np.inf, shape=(n_time, n_edges, n_edge_features))
        })

    def step(self, action):
        obs = {
            "node_features": np.random.rand(self.n_time, self.n_nodes, self.n_node_features),
            "edge_features": np.random.rand(self.n_time, self.n_edges, self.n_edge_features)
        }
        reward = 1
        done = True
        return obs, reward, done, {}

    def reset(self):
        obs = {
            "node_features": np.random.rand(self.n_time, self.n_nodes, self.n_node_features),
            "edge_features": np.random.rand(self.n_time, self.n_edges, self.n_edge_features)
        }
        return obs

    def render(self, mode="human"):
        pass


if __name__ == '__main__':
    from stable_baselines3.common.env_checker import check_env
    env = SCUCEnv(200, 300, 24)
    check_env(env)
