from constant import ERROR, FINITE, UNBOUNDED
from LPSolver import LPSolver
import numpy as np

class RevisedSimplexSolver(LPSolver):
    def __init__(self) -> None:
        super().__init__()
    
    @staticmethod
    def simplex(A: np.ndarray, b: np.ndarray, c: np.ndarray, x: np.ndarray, lB: list, max_iter = 100, verbose=1) -> dict:
        '''
        @parameters: 
        lB: indices of basic variables
        max_iter: maximum number of iterations
        verbose: how much info will be printed
        @return: 
        flag: 1: finite, 2: infinite
        lB: 
        '''
        m, n = A.shape
        assert len(lB) == m
        # inverse of basis matrix
        B_inv = np.linalg.inv(A[:, lB])
        # indices of nonbasic variables
        lN = list(set([i for i in range(n)]).difference(set(lB)))
        for iter in range(max_iter):
            # cost coefficients
            c_B = c[lB]
            c_N = c[lN]
            cost = c_B.T @ x[lB]
            if verbose >= 1:
                print('Cost: {}, Basis: {}, x: {}'.format(cost, lB, x))
            # reduced costs of nonbasic variables
            N = A[:, lN]
            c_r = c_N.T - c_B.T @ B_inv @ N
            # all reduced costs of nonbasic variables are nonnegative
            if (c_r >= 0).all():
                if verbose >= 1:
                    print('Optimal cost is finite. Find optimal cost {} after {} iterations'.format(cost, iter + 1))
                return {'status': FINITE, 'basic_indices': lB, 'extreme_point': x, 'cost': cost}
            # find the minimum index of the variable with negative reduced cost
            j = lN[np.where(c_r < 0)[0][0]]
            u = B_inv @ A[:, j]
            # all components of u are nonpositive
            if (u <= 0).all():
                if verbose >= 1:
                    print('Optimal cost is infinite. Find it after {} iterations'.format(iter + 1))
                d = np.zeros(n)
                d[lB] = -u
                d[j] = 1
                return {'status': UNBOUNDED, 'basic_indices': lB, 'extreme_ray': d, 'cost': -np.inf}
            # find the smallest x_b(i) / u_i with u_i > 0
            i_pos, = np.where(u > 0)
            theta = x[np.array(lB)[i_pos]] / u[i_pos]
            theta_star = np.min(theta)
            # Blands' rule
            l = np.min(i_pos[theta == theta_star])
            # move to a new basic feasible solution
            x[lB] = x[lB] - theta_star * u
            x[lB[l]] = 0    # eliminate the numerical error
            x[j] = theta_star
            # change the basis
            lN[lN.index(j)] = lB[l]
            lB[lB.index(lB[l])] = j
            # caculate the inverse of the new basis matrix
            Q = np.eye(m)
            Q[:, l] = -u / u[l]
            Q[l][l] = 1 / u[l]
            B_inv = Q @ B_inv
        return {'status': ERROR}

if __name__ == '__main__':
    # test 0
    # A = np.array([
    #     [1, 2, 2, 1, 0, 0],
    #     [2, 1, 2, 0, 1, 0],
    #     [2, 2, 1, 0, 0, 1]
    # ], dtype=float)
    # b = np.array([20, 20, 20], dtype=float)
    # c = np.array([-10, -12, -12, 0, 0, 0], dtype=float)
    # x = np.array([0, 0, 0, 20, 20, 20], dtype=float)
    # lB = [3, 4, 5]

    # test1
    # A = np.array([
    #     [1, 2, 3, 0],
    #     [-1, 2, 6, 0],
    #     [0, 4, 9, 0],
    #     [0, 0, 3, 1]
    # ], dtype=float)
    # b = np.array([3, 2, 5, 1], dtype=float)
    # c = np.array([1, 1, 1, 0], dtype=float)
    # x = np.array([1, 1/2, 1/3, 0], dtype=float)
    # lB = [0, 1, 2, 3]

    # test2
    # A = np.array([
    #     [1, -1, 0],
    #     [0, 1, -1]
    # ], dtype=float)
    # b = np.array([1, 3], dtype=float)
    # c = np.array([-1, -1, -1], dtype=float)
    # x = np.array([2, 1, 0], dtype=float)
    # lB = [0, 1]

    # test3
    A = np.array([
        [1, 3, 0, 4, 1],
        [1, 2, 0, -3, 1],
        [-1, -4, 3, 0, 0]
    ])
    b = np.array([2, 2, 1])
    c = np.array([2, 3, 3, 1, -2])

    solver = RevisedSimplexSolver()
    solver.build(A, b, c)
    d = solver.solve()
