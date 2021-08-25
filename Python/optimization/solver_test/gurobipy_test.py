import numpy as np
import gurobipy as gp
from gurobipy import GRB

try:
    # m = gp.Model('model')
    # x = m.addVar(vtype=GRB.BINARY, name='x')
    # y = m.addVar(vtype=GRB.BINARY, name='y')
    # z = m.addVar(vtype=GRB.BINARY, name='z')
    # m.setObjective(x + y + 2 * z, GRB.MAXIMIZE)
    # m.addConstr(x + 2 * y + 3 * z <= 4, 'c0')
    # m.addConstr(x + y >= 1, 'c1')
    # m.optimize()

    m = gp.Model('model')
    x = m.addMVar((3,), vtype=GRB.BINARY, name='x')
    A = np.array([[1.0, 2.0, 3.0],
                  [-1.0, -1.0, 0]])
    b = np.array([4.0, -1.0])
    c = np.array([1.0, 1.0, 2.0])
    m.setObjective(c.T @ x, GRB.MAXIMIZE)
    m.addConstr(A @ x <= b, 'c0')
    m.optimize()

    for v in m.getVars():
        print('{} {}'.format(v.varName, v.x))
    print('Obj:', m.objVal)
except gp.GurobiError as e:
    print(e)
