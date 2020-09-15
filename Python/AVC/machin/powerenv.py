import gym
import gym
from pypower.api import case39

class PowerNet(gym.Env):
    def __init__(self, ppc, areaBuses, areaGens, vref = 1.0) -> None:
        """
        Power net environment for reinforcement learning, implemented by using pypower, gym
        @ppc: dict, pypower case
        @areaBuses: list, i-th term is the list of bus numbers in i-th area
        @areaGens: list, i-th term is the list of generator numbers in i-th area
        @vref: voltage reference
        """
        self.ppc = ppc
        self.ppc0 = ppc
        self.areaBuses = areaBuses
        self.areaGens = areaGens
        self.vref = vref
        self.state_dim = map(lambda x: 4 * x, map(len, areaBuses))
        self.action_dim = map(len, areaGens)
        assert(sum(self.states_dim) == len(ppc['bus']))
        assert(sum(self.actions_dim) == len(ppc['gen']))
    
    def reset(self):
        self.ppc = self.ppc0

    def step(self, action):
        pass