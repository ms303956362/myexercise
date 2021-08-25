import cvxpy as cp
from cvxpy.settings import Q
import numpy as np


x = cp.Variable(5)
y = cp.Variable(5)
A = np.array([
    [1, 3, 0, 4, 1],
    [1, 2, 0, -3, 1],
    [-1, -4, 3, 0, 0]
], dtype=float)
b = np.array([2, 2, 1], dtype=float)
c = np.array([2, 3, 3, 1, -2], dtype=float)
c2 = np.array([1, 2, 5, 7, -7], dtype=float)

cons = [cp.maximum(A @ x, A @ y) == b , x >= 0]
obj = cp.Minimize(c.T @ x + c2.T @ y)
prob = cp.Problem(obj, cons)
prob.solve(solver=cp.CPLEX)

print(prob.value)
print(x.value)
print(prob.constraints[0].dual_value)
