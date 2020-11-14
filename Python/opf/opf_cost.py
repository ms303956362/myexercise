from constant import COST, MODEL, NCOST, COST
import numpy as np


def opf_cost(x, ppc):
    baseMVA, gen, gencost = ppc['baseMVA'], ppc['gen'], ppc['gencost']
    # 维数
    nx = x.shape[0]
    ng = gen.shape[0]
    # 状态变量
    pg = x[0 : ng]

    f = 0
    df = np.zeros(nx)
    if np.sum(gencost[:, MODEL]) == 2 * ng:
        # 多项式
        y = np.zeros(ng)
        xx = pg * baseMVA
        n = gencost.astype(int)[0, NCOST]
        for i in range(n):
            # 目标函数
            y = y * xx + gencost[:, COST + i]
            if i > 0:
                # 目标函数梯度
                df[0 : ng] = df[0 : ng] * xx + (n - i) * gencost[:, COST + i - 1]
        f = np.sum(y)
    
    return f, df


if __name__ == "__main__":
    from case5 import case5
    from constant import PMAX, PMIN, QMAX, QMIN
    ppc = case5()
    bus, gen, branch = ppc["bus"], ppc["gen"], ppc["branch"]
    nb = bus.shape[0]
    ng = gen.shape[0]
    x = np.zeros(2 * (ng + nb))
    x[0 : ng] = (gen[:, PMAX] + gen[:, PMIN]) / 2
    x[ng : 2 * ng] = (gen[:, QMAX] + gen[:, QMIN]) / 2
    x[2 * ng : 2 * (ng + nb) : 2] = 0
    x[2 * ng + 1: 2 * (ng + nb) : 2] = 1
    x[-1] = 1.05
    f, df = opf_cost(x, ppc)
