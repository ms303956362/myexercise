import numpy as np
from constant import NCOST, COST, F_BUS
from derivatives import d2Sbus_dV2, d2Sbr_dV2


def opf_hess(x, lmbda, Ybus, Yf, ppc):
    '''
    目标函数、等式约束点乘拉格朗日乘子、不等式约束点乘拉格朗日乘子的Hess矩阵
    输入参数：
        x:      状态变量 {Pg, Qg, theta, Vm}
        lmbda:  等式约束和不等式约束的拉格朗日乘子
        Ybus:   节点导纳矩阵
        Yf:     支路导纳矩阵
        ppc：   标准case
    '''
    baseMVA, bus, gen, branch, gencost = ppc['baseMVA'], ppc['bus'], ppc['gen'], ppc['branch'], ppc['gencost']
    
    # 维数
    nx = x.shape[0]
    nb = bus.shape[0]
    nl = branch.shape[0]
    ng = gen.shape[0]

    # 状态变量
    pg = x[0 : ng]
    qg = x[ng : 2 * ng]
    theta = x[2 * ng: 2 * (ng + nb) - 1 : 2]
    vm = x[2 * ng + 1: 2 * (ng + nb) : 2]
    V = vm * np.exp(1j * theta)

    # 拉格朗日乘子
    y, c = lmbda

    # 目标函数Hess矩阵
    d2f = np.zeros((nx, nx))
    n = gencost[0, NCOST].astype(int)
    d2f_dpg = np.zeros(ng)
    xx = pg * baseMVA
    for i in range(0, n - 2):
        d2f_dpg = d2f_dpg * xx + gencost[:, COST + i] * (n - i - 1) * (n - i - 2)
    d2f[0:ng, 0:ng] = np.diag(d2f_dpg)

    # 等式约束Hess矩阵
    d2h = np.zeros((nx, nx))
    yp = y[0 : 2 * nb : 2]
    yq = y[1 : 2 * nb : 2]
    dp_daa, dp_dav, dp_dva, dp_dvv = d2Sbus_dV2(Ybus, V, yp)
    dq_daa, dq_dav, dq_dva, dq_dvv = d2Sbus_dV2(Ybus, V, yq)
    d2h[2 * ng : nx : 2, 2 * ng : nx : 2] = -dp_daa.real - dq_daa.imag
    d2h[2 * ng : nx : 2, 2 * ng + 1: nx : 2] = -dp_dav.real - dq_dav.imag
    d2h[2 * ng + 1: nx : 2, 2 * ng : nx : 2] = -dp_dva.real - dq_dva.imag
    d2h[2 * ng + 1: nx : 2, 2 * ng + 1: nx : 2] = -dp_dvv.real - dq_dvv.imag

    # 不等式约束Hess矩阵
    d2g = np.zeros((nx, nx))
    f = branch[:, F_BUS].astype(int) - 1
    Cf = np.zeros((nl, nb))
    Cf[np.arange(nl), f] = 1
    cp = c[2 * ng + nb : 2 * ng + nb + nl]
    dpf_daa, dpf_dav, dpf_dva, dpf_dvv = d2Sbr_dV2(Cf, Yf, V, cp)
    d2g[2 * ng : nx : 2, 2 * ng : nx : 2] = dpf_daa.real
    d2g[2 * ng : nx : 2, 2 * ng + 1: nx : 2] = dpf_dav.real
    d2g[2 * ng + 1: nx : 2, 2 * ng : nx : 2] = dpf_dva.real
    d2g[2 * ng + 1: nx : 2, 2 * ng + 1: nx : 2] = dpf_dvv.real

    return -d2f + d2h + d2g


if __name__ == "__main__":
    from makeYbus import makeYbus
    from case5 import case5
    from constant import PMAX, PMIN, QMAX, QMIN
    ppc = case5()
    Ybus, Yf, Yt = makeYbus(ppc['baseMVA'], ppc['bus'], ppc['branch'])
    bus, gen, branch = ppc["bus"], ppc["gen"], ppc["branch"]
    nb = bus.shape[0]
    ng = gen.shape[0]
    nl = branch.shape[0]
    x = np.zeros(2 * (ng + nb))
    x[0 : ng] = (gen[:, PMAX] + gen[:, PMIN]) / 2
    x[ng : 2 * ng] = (gen[:, QMAX] + gen[:, QMIN]) / 2
    x[2 * ng : 2 * (ng + nb) : 2] = 0
    x[2 * ng + 1: 2 * (ng + nb) : 2] = 1
    x[-1] = 1.05
    y = np.ones(2 * nb) * (-1e-10)   # 等式约束拉格朗日乘子
    y[0:2 * nb:2] = -y[0:2 * nb:2]  
    z = np.ones(2 * ng + nb + nl)              # 下限不等式约束拉格朗日乘子
    w = np.ones(2 * ng + nb + nl) * (-0.5)
    hess = opf_hess(x, (y, z + w), Ybus, Yf, ppc)
