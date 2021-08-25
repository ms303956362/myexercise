import pyomo.environ as pyo

m = pyo.ConcreteModel()
m.x = pyo.Var([1, 2], domain=pyo.NonNegativeReals)
m.OBJ = pyo.Objective(expr=2 * m.x[1] + 3*m.x[2])
m.cons = pyo.Constraint(expr=3 * m.x[1] + 4 * m.x[2] >= 1)
opt = pyo.SolverFactory('cplex')
opt.solve(m)
