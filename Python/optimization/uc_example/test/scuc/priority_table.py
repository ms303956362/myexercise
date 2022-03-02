'''
Optimization of Power System Operation, 2nd edition, P257
'''

from typing import Dict, List, Tuple
from bisect import bisect_left


def backtrack(i: int, n: int, hasZero: bool, state: list, cost: float, max_p: float, min_p: float, units_data: List[Dict], combs: List[Dict[tuple, Dict]]):
    if i == n:
        combs.append({'state': tuple(state), 'total_cost': cost, 'max_p': max_p, 'min_p': min_p})
        return
    state.append(0)
    backtrack(i + 1, n, True, state, cost, max_p, min_p, units_data, combs)
    state.pop()
    if not hasZero:
        state.append(1)
        cost += units_data[i]['cost']
        max_p += units_data[i]['max_p']
        min_p += units_data[i]['min_p']
        backtrack(i + 1, n, False, state, cost, max_p, min_p, units_data, combs)
        state.pop()


def calcCost(load: float, combs: List[Dict[tuple, Dict]], units_data: List[Dict], prev_state: Tuple=None)->Tuple[Tuple, float]:
    keys = [comb['max_p'] for comb in combs]
    i = bisect_left(keys, load)
    while i < len(keys):
        # TODO 组合的合法性
        break
        i += 1
    
    cost = 0.0
    for j, s in enumerate(combs[i]['state']):
        if s == 1:
            p = min(load, units_data[j]['max_p'])
            load -= p
            cost += units_data[j]['avg_cost'] * p
    return combs[i]['state'], cost

if __name__ == '__main__':
    units_data = [
        {'name': 1, 'max_p': 80.0,  'min_p': 25.0, 'cost': 213.00, 'avg_cost': 23.54, 'start_up_cost': 350.0,  'state': -5, 'min_up_times': 4, 'min_down_times': 2},
        {'name': 2, 'max_p': 250.0, 'min_p': 60.0, 'cost': 585.62, 'avg_cost': 20.34, 'start_up_cost': 400.0,  'state': 8,  'min_up_times': 5, 'min_down_times': 3},
        {'name': 3, 'max_p': 300.0, 'min_p': 75.0, 'cost': 684.74, 'avg_cost': 19.74, 'start_up_cost': 1100.0, 'state': 8,  'min_up_times': 5, 'min_down_times': 4},
        {'name': 4, 'max_p': 60.0,  'min_p': 20.0, 'cost': 252.00, 'avg_cost': 28.00, 'start_up_cost': 0.0,    'state': -6, 'min_up_times': 1, 'min_down_times': 1},
    ]

    loads = [450, 530, 600, 540, 400, 280, 290, 500]

    # ordering of the unit combinations
    n = len(units_data)
    units_data.sort(key=lambda unit: unit['avg_cost'])
    combs = []
    backtrack(0, n, False, [], 0.0, 0.0, 0.0, units_data, combs)
    combs.sort(key=lambda comb: comb['max_p'])
    
    result = [calcCost(load, combs, units_data) for load in loads]
    pass
