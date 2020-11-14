from case5 import case5
from pypower.api import pips, runopf, ppoption


if __name__ == "__main__":
    from numpy import array, r_, float64, dot, eye, zeros
    from scipy.sparse import csr_matrix
    
    
    def f2(x):
        f = dot(array([1, 1, 1]), x**2) + 8
        df = 2 * x
        return f, df
    

    def gh2(x):
        h = array([-x[0]**2 + x[1] - x[2]**2, x[0] + x[1]**2 + x[2]**2 - 20])
        dh = csr_matrix(array([
                                [-2*x[0], 1     ],
                                [1,       2*x[1]],
                                [-2*x[2], 2*x[2]]
                            ]))
        g = array([-x[0] - x[1]**2 + 2, x[1] + 2*x[2]**2 - 3])
        dg = csr_matrix(array([
                    [-1,      0     ],
                    [-2*x[1], 1     ],
                    [0,       4*x[2]]
                ]))
        return h, g, dh, dg
    

    def hess2(x, lam, cost_mult=1):
        lm = lam['eqnonlin']
        mu = lam["ineqnonlin"]
        d2f = eye(3) * 2
        d2g = zeros((3, 3))
        d2g[1][1] = -2 * lm[0]
        d2g[2][2] = 4 * lm[1]
        d2h = zeros((3, 3))
        d2h[0][0] = -2 * mu[0]
        d2h[1][1] = 2 * mu[1]
        d2h[2][2] = -2 * mu[0] + 2 * mu[1]
        Lxx = csr_matrix(d2f + d2g + d2h)
        return Lxx
    
    
    x0 = array([1, 1, 1], float64)
    xmin = zeros(3)
    solution = pips(f2, x0, gh_fcn=gh2, hess_fcn=hess2, xmin=xmin)
    print(solution['x'])
    print(solution['f'])

    ppc = case5()
    ppopt = ppoption(OUT_GEN=True)
    runopf(ppc, ppopt)
    