from typing import Callable, Dict, Tuple, List
import numpy as np


def ips(f_func: Callable[[np.ndarray], Tuple[np.ndarray, np.ndarray]], 
        h_func: Callable[[np.ndarray], Tuple[np.ndarray, np.ndarray]], 
        g_func: Callable[[np.ndarray], Tuple[np.ndarray, np.ndarray]],
        hess_func: Callable[[np.ndarray, Tuple[np.ndarray, np.ndarray]], np.ndarray], 
        x0: np.ndarray, gl: np.ndarray, gu: np.ndarray, max_it=50) -> Dict:
    """
        min f(x)
         x
    s.t.
        h(x) = 0
        gl <= g(x) <= gu
    """
    # 参数初始化
    i = 0

    # 常数
    eps = 1e-6
    sigma = 0.1

    # 维数
    nx = x0.shape[0]
    neq = h_func(x0)[0].shape[0]
    niq = g_func(x0)[0].shape[0]

    # 参数初始化
    y = np.ones(neq) * (-1e-10)   # 等式约束拉格朗日乘子
    y[0:neq:2] = -y[0:neq:2]    
    l = np.ones(niq)              # 下限松弛因子
    u = np.ones(niq)              # 上限松弛因子
    z = np.ones(niq)              # 下限不等式约束拉格朗日乘子
    w = np.ones(niq) * (-0.5)     # 上限不等式约束拉格朗日乘子

    # Newton迭代
    x = x0
    converged = False
    while i < max_it:
        i += 1
        # 计算对偶间隙
        gap = np.dot(l, z) - np.dot(u, w)
        if gap < eps:
            converged = True
            break
        
        # 计算扰动因子
        mu = sigma * gap / niq
        
        # 求解修正方程
        ## 系数矩阵
        f, df = f_func(x)
        h, dh = h_func(x)
        g, dg = g_func(x)
        Hess = hess_func(x, (y, z + w)) # 注意d2f负号
        L_inv = np.diag(1 / l)
        U_inv = np.diag(1 / u)
        Z = np.diag(z)
        W = np.diag(w)
        Hess -= dg @ (L_inv @ Z - U_inv @ W) @ dg.T
        
        ## 常数项
        Lx = df - dh @ y - dg @ (z + w)
        Ly = h
        Lz = g - l - gl
        Lw = g + u - gu
        Ll = l * z - mu
        Lu = u * w + mu
        Lx += dg @ (L_inv @ (Ll + Z @ Lz) + U_inv @ (Lu - W @ Lw))

        ## 求解修正量
        A_sub = np.r_[
            np.c_[Hess, dh],
            np.c_[dh.T, np.zeros((neq, neq))]
        ]
        b_sub = np.r_[Lx, -Ly]
        dxdy = np.linalg.solve(A_sub, b_sub)
        dx = dxdy[:nx]
        dy = dxdy[nx:(nx + neq)]
        du = -Lw - dg.T @ dx
        dw = -U_inv @ Lu - U_inv @ W @ du
        dl = Lz + dg.T @ dx
        dz = -L_inv @ Ll - L_inv @ Z @ dl

        ## 更新迭代
        idx_l = np.flatnonzero(dl < 0)
        idx_u = np.flatnonzero(du < 0)
        alpha_p = 0.9995 * min([np.min(-l[idx_l] / dl[idx_l]) if len(idx_l) else 1, np.min(-u[idx_u] / du[idx_u]) if len(idx_u) else 1, 1])
        idx_z = np.flatnonzero(dz < 0)
        idx_w = np.flatnonzero(dw > 0)
        alpha_d = 0.9995 * min([np.min(-z[idx_z] / dz[idx_z]) if len(idx_z) else 1, np.min(-w[idx_w] / dw[idx_w]) if len(idx_w) else 1, 1])
        x = x + alpha_p * dx
        l = l + alpha_p * dl
        u = u + alpha_p * du
        y = y + alpha_d * dy
        z = z + alpha_d * dz
        w = w + alpha_d * dw

    if not converged:
        print('Not converged!')
    else:
        print('Converged in ' + str(i) + ' iterations!')
    
    return x, f

if __name__ == "__main__":
    '''
         min f(x) = x1^2 + x2^2 + x3^2 + 8
          x
    s.t. -x1 - x2^2 + 2 = 0
         x2 + 2*x3^2 - 3 = 0
         0 <= x1^2 - x2 + x3^2 <= M
         -M <= x1 + x2^2 + x3^2 <= 20
         0 <= x1 <= M
         0 <= x2 <= M
         0 <= x3 <= M
    M -> inf
    '''
    M = 1
    def obj(x):
        f = np.sum(x*x) + 8
        df = 2 * x
        return f, df
    
    def eqcons(x):
        h = np.array([-x[0] - x[1] * x[1] + 2, x[1] + 2 * x[2] * x[2] - 3])
        dh = np.array([
                [-1, 0],
                [-2*x[1], 1],
                [0, 4*x[2]]
            ])
        return h, dh
    
    def neqcons(x):
        g = np.array([x[0] * x[0] - x[1] + x[2] * x[2], x[0] + x[1] * x[1] + x[2] * x[2]])
        dg = np.array([
            [2 * x[0], 1],
            [-1, 2 * x[1]],
            [2 * x[2], 2 * x[2]]
        ])
        return g, dg
    
    def hess(x, s):
        d2f = np.eye(3) * 2
        y, z = s
        d2hy = np.zeros((3, 3))
        d2hy[1][1] = -2 * y[0]
        d2hy[2][2] = 4 * y[1]
        d2gz = np.zeros((3, 3))
        d2gz[0][0] = 2 * z[0]
        d2gz[1][1] = 2 * z[1]
        d2gz[2][2] = 2 * z[0] + 2 * z[1]
        return -d2f + d2hy + d2gz

    x0 = np.ones(3) * 0.5
    gl = np.array([0, 0])
    gu = np.array([M, 20])
    ips(obj, eqcons, neqcons, hess, x0, gl, gu)
