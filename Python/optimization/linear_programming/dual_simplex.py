from constant import ERROR, FINITE, INFEASIBLE
import numpy as np

def dual_simplex(A: np.ndarray, b: np.ndarray, c: np.ndarray, x: np.ndarray, lB: list, max_iter = 100, verbose=1, eps=1e-10) -> dict:
    m, n = A.shape
    assert len(lB) == m
    # inverse of basis matrix
    B_inv = np.linalg.inv(A[:, lB])
    # indices of nonbasic variables
    lN = list(set([i for i in range(n)]).difference(set(lB)))
    assert np.linalg.norm(B_inv @ b - x[lB]) < eps and np.linalg.norm(x[lN]) < eps
    for iter in range(max_iter):
        cost = c[lB].T @ x[lB]
        if verbose >= 1:
            print('Cost: {}, Basis: {}, x: {}'.format(cost, lB, x))
        # check whether the components of x_B >= 0 for all
        if (x[lB] >= 0).all():
            if verbose >= 1:
                print('Optimal cost is finite. Find optimal cost {} after {} iterations'.format(cost, iter + 1))
            return {'status': FINITE, 'basic_indices': lB, 'extreme_point': x, 'cost': cost, 'dual_vector': (c[lB].T @ B_inv).T}
        # find a negative basic variable (pivot row)
        l = np.where(x[lB] < 0)[0][0]
        v = B_inv[l, :] @ A
        # optimal dual is +inf, primal infeasible
        if (v >= 0).all():
            if verbose >= 1:
                print('Optimal cost is infinite. Find it after {} iterations'.format(iter + 1))
            return {'status': INFEASIBLE, 'basic_indices': lB, 'cost': np.inf, 'extreme_ray': -B_inv[l, :]}
        # find pivot colunm
        i_neg, = np.where(v < 0)
        A_neg = B_inv @ A[:, i_neg]
        c_r = c[i_neg].T - c[lB].T @ A_neg
        # lexicographic pivoting rule
        j = np.lexsort(np.flip(np.row_stack((c_r, A_neg)) / np.abs(v[i_neg]), axis=0))[0]
        # construct row operation matrix
        u = B_inv @ A[:, j]
        Q = np.eye(m)
        Q[:, l] = -u / u[l]
        Q[l][l] = 1 / u[l]
        # move to a new basic solution
        x[lB] = Q @ x[lB]
        x[lB[l]], x[j] = x[j], x[lB[l]]
        lB[lB.index(lB[l])] = j
        # calculate B_inv for the new basis
        B_inv = Q @ B_inv
    return {'status': ERROR}

if __name__ == '__main__':
    # test0
    # A = np.array([
    #     [1, 2, -1, 0],
    #     [1, 0, 0, -1]
    # ], dtype=float)
    # b = np.array([2, 1], dtype=float)
    # c = np.array([1, 1, 0, 0], dtype=float)
    # x = np.array([0, 0, -2, -1], dtype=float)
    # lB = [2, 3]

    # test1
    A = np.array([
        [-1, 2, 1],
        [-1, -1, -2]
    ], dtype=float)
    b = np.array([3, 1], dtype=float)
    c = np.array([1, -2, 2], dtype=float)
    x = np.array([0, 7/3, -5/3], dtype=float)
    lB = [1, 2]

    dual_simplex(A, b, c, x, lB)
