from constant import FINITE, INFEASIBLE
from revised_simplex import revised_simplex
import numpy as np


class LPSolver:
    def __init__(self, A: np.ndarray, b: np.ndarray, c: np.ndarray) -> None:
        '''
        Solve the linear programming in the standard form
        min  c^T x
        s.t. Ax = b
             x >= 0
        '''
        # check the dimension of matrix A and vector b and c
        assert len(A.shape) == 2 and len(b.shape) == 1 and len(c.shape) == 1    # whether A is matrix, b and c are vector
        # TODO check whether the rows of A are linearly independent. If not, eliminate the redundant row
        m, n = A.shape
        assert m <= n and b.shape[0] == m and c.shape[0] == n
        self.A = A
        self.b = b
        self.c = c

    def solve(self, max_iter=100, verbose=1):
        # whether the matrices and vectors are initialized correctly
        assert isinstance(self.A, np.ndarray) and isinstance(self.b, np.ndarray) and isinstance(self.c, np.ndarray)
        assert len(self.A.shape) == 2 and len(self.b.shape) == 1 and len(self.c.shape) == 1
        m, n = self.A.shape
        assert m <= n and self.b.shape[0] == m and self.c.shape[0] == n
        # Phase I
        if verbose >= 1:
            print('Phase I starts')
        # change the problem so that b >= 0
        i_neg_b, = np.where(self.b < 0)
        self.A[i_neg_b, :] *= -1
        self.b[i_neg_b] *= -1
        # solve the auxiliary problem
        A_aux = np.column_stack((self.A, np.eye(m)))
        c_aux = np.concatenate((np.zeros(n), np.ones(m)))
        x_aux = np.concatenate((np.zeros(n), self.b))
        lB_aux = [i + n for i in range(m)]
        res_aux = revised_simplex(A_aux, self.b, c_aux, x_aux, lB_aux, max_iter, verbose)
        assert res_aux['status'] == FINITE
        # check optimal cost
        if res_aux['cost'] > 0:
            if verbose >= 1:
                print('The problem is infeasible')
            return {'status': INFEASIBLE}
        assert res_aux['cost'] == 0
        # check whether there are artficial variables in the basis
        lB = res_aux['basic_indices']
        B_inv = np.linalg.inv(A_aux[:, lB])
        A = self.A
        b = self.b
        # there exists basic artificial variable
        if max(lB) >= n:
            l_arti, = np.where(np.array(lB) >= n)
            for l in l_arti:
                A_l = B_inv[l, :] @ self.A
                # there exists redundant constraint
                if (A_l == 0).all():
                    i_nr = [i for i in range(m) if i != l]
                    A = A[i_nr, :]
                    b = b[i_nr]
                    B_inv = B_inv[i_nr, :][:, i_nr]
                    lB.pop(l)
                    m -= 1
                else:
                    # change the basis
                    j = np.where(A_l != 0)[0][0]
                    lB[lB.index(lB[l])] = j
                    # caculate the inverse of the new basis matrix
                    u = B_inv @ A[:, j]
                    Q = np.eye(m)
                    Q[:, l] = -u / u[l]
                    Q[l][l] = 1 / u[l]
                    B_inv = Q @ B_inv
        # Phase II
        if verbose >= 1:
            print('==============================================')
            print('Phase II starts')
        x = np.zeros(n)
        x[lB] = B_inv @ b
        return revised_simplex(A, b, self.c, x, lB, max_iter, verbose)


if __name__ == '__main__':
    # test0
    A = np.array([
        [1, 2, 3, 0],
        [-1, 2, 6, 0],
        [0, 4, 9, 0],
        [0, 0, 3, 1]
    ], dtype=float)
    b = np.array([3, 2, 5, 1], dtype=float)
    c = np.array([1, 1, 1, 0], dtype=float)
    
    # test1
    # A = np.array([
    #     [1, 3, 0, 4, 1],
    #     [1, 2, 0, -3, 1],
    #     [-1, -4, 3, 0, 0]
    # ], dtype=float)
    # b = np.array([2, 2, 1], dtype=float)
    # c = np.array([2, 3, 3, 1, -2], dtype=float)

    solver = LPSolver(A, b, c)
    solver.solve()
