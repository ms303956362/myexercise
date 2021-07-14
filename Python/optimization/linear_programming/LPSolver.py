import numpy as np


class LPSolver:
    def __init__(self) -> None:
        '''
        Solve the linear programming in the standard form
        min  c^T x
        s.t. Ax = b
             x >= 0
        '''
        self.A: np.ndarray = None
        self.b: np.ndarray = None
        self.c: np.ndarray = None
        self.m = None
        self.n = None

    def build(self, A: np.ndarray, b: np.ndarray, c: np.ndarray):
        # check the dimension of matrix A and vector b and c
        assert len(A.shape) == 2 and len(b.shape) == 1 and len(c.shape) == 1    # whether A is matrix, b and c are vector
        # TODO check whether the rows of A are linearly independent. If not, eliminate the redundant row
        m, n = A.shape
        assert m <= n and b.shape[0] == m and c.shape[0] == n
        self.A = A
        self.b = b
        self.c = c
        self.m = m
        self.n = n
    
    def solve(self):
        assert self.A is not None and self.b is not None and self.c is not None and self.m == None and self.n == None   # whether initialized
        raise NotImplementedError
