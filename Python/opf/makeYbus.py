from numpy import ones, conj, nonzero, exp, pi, r_
from scipy.sparse import csr_matrix

from constant import GS, BS
from constant import F_BUS, T_BUS, BR_R, BR_X, BR_B, BR_STATUS, SHIFT, TAP


def makeYbus(baseMVA, bus, branch):
    """
    节点导纳矩阵Ybus和支路导纳矩阵Yf和Yt
    """
    # 维数
    nb = bus.shape[0]     
    nl = branch.shape[0]    

    # 计算支路导纳矩阵元素
    stat = branch[:, BR_STATUS]              
    Ys = stat / (branch[:, BR_R] + 1j * branch[:, BR_X]) 
    Bc = stat * branch[:, BR_B]             
    tap = ones(nl)                           
    i = nonzero(branch[:, TAP])              
    tap[i] = branch[i, TAP]                  
    tap = tap * exp(1j * pi / 180 * branch[:, SHIFT]) 

    Ytt = Ys + 1j * Bc / 2
    Yff = Ytt / (tap * conj(tap))
    Yft = - Ys / conj(tap)
    Ytf = - Ys / tap

    # 计算对地导纳
    Ysh = (bus[:, GS] + 1j * bus[:, BS]) / baseMVA

    # 计算连接矩阵
    f = branch[:, F_BUS] - 1                          
    t = branch[:, T_BUS] - 1                         
    Cf = csr_matrix((ones(nl), (range(nl), f)), (nl, nb))
    Ct = csr_matrix((ones(nl), (range(nl), t)), (nl, nb))

    # 计算支路导纳矩阵
    i = r_[range(nl), range(nl)]                

    Yf = csr_matrix((r_[Yff, Yft], (i, r_[f, t])), (nl, nb))
    Yt = csr_matrix((r_[Ytf, Ytt], (i, r_[f, t])), (nl, nb))

    ## 建立Ybus
    Ybus = Cf.T * Yf + Ct.T * Yt + csr_matrix((Ysh, (range(nb), range(nb))), (nb, nb))

    return Ybus.A, Yf.A, Yt.A


if __name__ == "__main__":
    from case5 import case5
    ppc = case5()
    Ybus, Yf, Yt = makeYbus(ppc['baseMVA'], ppc['bus'], ppc['branch'])
    print(Ybus)
    print(Yf)
    print(Yt)
