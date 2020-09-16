import gym
import numpy as np
from copy import deepcopy
from pypower.api import runpf, ppoption
from pypower.idx_bus import PD, QD, VM, VA
from pypower.idx_gen import GEN_BUS, PG, QG, VG

class PowerNet(gym.Env):
    def __init__(self, ppc, areaBuses, areaGens, vref = 1.0, alpha=0.1, beta=0.5) -> None:
        """
        Power net environment for reinforcement learning, implemented by using pypower, gym
        @ppc: dict, pypower case
        @areaBuses: List[List[]], i-th term is the list of bus numbers in i-th area
        @areaGens: List[List[]], i-th term is the list of generator numbers in i-th area
        @vref: voltage reference
        """
        self.ppc = ppc
        self.ppopt = ppoption()
        self.ppc0 = deepcopy(self.ppc)
        self.areaBuses = areaBuses
        self.areaGens = areaGens
        self.vref = vref
        self.alpha = alpha
        self.beta = beta
        self.state_dim = map(lambda x: 4 * x, map(len, areaBuses))  # each term in states list is PD, QD, V, theta of buses in each area
        self.action_dim = map(len, areaGens) # each term in actions list is voltage of generators in each area
        assert(sum(self.states_dim) == len(ppc['bus']))
        assert(sum(self.actions_dim) == len(ppc['gen']))
    
    def reset(self):
        self.ppc = deepcopy(self.ppc0)

    def step(self, action):
        '''
        @action: List(np.array(batch_size, action_dim)), len = len(areaGens)
        @state: List(np.array(batch_size, state_dim)), len = len(areaBuses)
        '''
        assert(len(action) == len(self.areaGens))
        batch_size = action[0].shape[0]
        state = [np.zeros((batch_size, dim)) for dim in self.state_dim]
        reward = [np.zeros(batch_size)]
        for i in range(batch_size):
            # set voltage of generators
            for j, gens in enumerate(self.areaGens):
                self.ppc['gen'][gens, VG] = action[j][i]
            # calculate power flow
            result, success = runpf(self.ppc, self.ppopt)
            # calculate the p, q, v, theta of buses
            for j, buses in enumerate(self.areaBuses):
                result_bus = result['bus'][buses, (PD, QD, VM, VA)]
                result_gen = result['gen'][buses, (GEN_BUS, PG, QG)]
                state[j][i] = self._cal_inject_power(result_bus, result_gen)
            # caculate the rewards
            reward_bus = self._cal_reward_bus(result['bus'][:, VM])
            for j, r in enumerate(reward):
                if np.where(0.95 <= result['bus'][:, VM] <= 1.05) == np.arange(result['bus'].shape[0]):
                    r[i] = np.sum(reward_bus) / np.arange(result['bus'].shape[0])
                elif np.where(0.8 <= result['bus'][:, VM] <= 1.2) == np.arange(result['bus'].shape[0]):
                    for k, buses in enumerate(self.areaBuses):
                        if k != j:
                            r[i] += self.beta * np.sum(reward_bus[buses])
                        else:
                            r[i] += np.sum(reward_bus[buses])
                    r[i] *= self.alpha
                else:
                    r[i] = -5
        return state
    
    def _cal_inject_power(self, result_bus, result_gen):
        '''
        Inject power of buses
        @result_bus: (num_bus, 4), PD, QD, VM, VA of all buses
        @result_gen: (num_bus, 3), GEN_BUS, PG, QG
        @result_concat: (num_bus, ), concat 2nd dimension
        '''
        for bus_i, pg, qg in result_gen:
            result_bus[bus_i][0] -= pg # PD
            result_bus[bus_i][1] -= qg # QD
        return np.concatenate([result_bus[:, i] for i in range(4)])

    def _cal_reward_bus(self, result_v):
        '''
        @result_v: (num_bus, ) VM
        '''
        reward_bus = np.zeros(len(result_v))
        idx = np.where([0.95 <= result_v <= self.vref])
        reward_bus[idx] = (result_v[idx] - 0.95) / (self.vref - 0.95)
        idx = np.where(self.vref < result_v <= 1.05)
        reward_bus[idx] = (1.05 - result_v[idx]) / (1.05 - self.vref)
        idx = np.where(0.8 <= result_v < 0.95)
        reward_bus[idx] = (self.vref - result_v[idx]) / (0.8 - self.vref)
        idx = np.where(1.05 < result_v <= 1.2)
        reward_bus[idx] = (result_v[idx] - self.vref) / (self.vref - 1.2)
        idx = np.where(result_v < 0.8 or result_v >1.2)
        reward_bus[idx] = -5
        return reward_bus

if __name__ == "__main__":
    pass
