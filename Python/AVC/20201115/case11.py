# Copyright (c) 1996-2015 PSERC. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

"""Power flow data for 9 bus, 3 generator case.
"""

from numpy import array
from pypower.api import runpf

def case11():
    """Power flow data for 9 bus, 3 generator case.
    Please see L{caseformat} for details on the case file format.

    Based on data from Joe H. Chow's book, p. 70.

    @return: Power flow data for 9 bus, 3 generator case.
    """
    ppc = {"version": '2'}

    ##-----  Power Flow Data  -----##
    ## system MVA base
    ppc["baseMVA"] = 1.0

    ## bus data
    # bus_i type Pd Qd Gs Bs area Vm Va baseKV zone Vmax Vmin
    ppc["bus"] = array([
        [1, 3, 0,      0, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [2, 1, 0.8, -3.3, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [3, 2, 0,      0, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [4, 1, 6.3,  2.5, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [5, 1, 5.0, -2.3, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [6, 1, 5.0,  0.7, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [7, 1, 36.9, 8.3, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [8, 1, 0.7, -0.7, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [9, 1, 11,   1.8, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [10, 1, 3.5, -8.5, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9],
        [11, 1, 17.1, -2.5, 0, 0, 1, 1, 0, 345, 1, 1.1, 0.9]
    ])



    ## generator data
    # bus, Pg, Qg, Qmax, Qmin, Vg, mBase, status, Pmax, Pmin, Pc1, Pc2,
    # Qc1min, Qc1max, Qc2min, Qc2max, ramp_agc, ramp_10, ramp_30, ramp_q, apf
    ppc["gen"] = array([
        [1, 0,  0, 300, -300, 1, 100, 1, 250, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [3, 0,  -1.1, 300, -300, 1, 100, 1, 270, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ])

    ## branch data
    # fbus, tbus, r, x, b, rateA, rateB, rateC, ratio, angle, status, angmin, angmax
    ppc["branch"] = array([
        [1, 4, 0.5916,    1.3432,    10.3008,   250, 250, 250, 0, 0, 1, -360, 360],
        [1, 5, 9.1137,  20.69346,   158.6856,   250, 250, 250, 0, 0, 1, -360, 360],
        [1, 2, 4.345965, 9.86785,  302.68368,   150, 150, 150, 0, 0, 1, -360, 360],
        [1, 6, 2.616108, 7.491582,  59.85338,   300, 300, 300, 0, 0, 1, -360, 360],
        [1, 7, 3.95032308, 11.31228882, 78.218, 150, 150, 150, 0, 0, 1, -360, 360],
        [1, 8, 2.25456,   6.45624,   51.5816,   250, 250, 250, 0, 0, 1, -360, 360],
        [8, 9, 2.25456,   6.45624,   51.5816,     250, 250, 250, 0, 0, 1, -360, 360],
        [1, 10, 4.22807, 9.600206,  73.61816, 250, 250, 250, 0, 0, 1, -360, 360],
        [10, 11, 3.06901, 6.968458, 53.43688, 250, 250, 250, 0, 0, 1, -360, 360],
        [11, 3, 2.883408, 8.257032, 65.96888, 250, 250, 250, 0, 0, 1, -360, 360]
    ])

    for i in range(10):
        ppc["branch"][i][2] = ppc["branch"][i][2]/(121*121)
        ppc["branch"][i][3] = ppc["branch"][i][3]/(121*121)
        ppc["branch"][i][4] = ppc["branch"][i][4]/(121*121)
    # print(ppc["branch"][1])

    ##-----  OPF Data  -----##
    ## area data
    # area refbus
    ppc["areas"] = array([
        [1, 5]
    ])

    ## generator cost data
    # 1 startup shutdown n x1 y1 ... xn yn
    # 2 startup shutdown n c(n-1) ... c0
    ppc["gencost"] = array([
        [2, 1500, 0, 3, 0.11,   5,   150],
        [2, 3000, 0, 3, 0.1225, 1,   335]
    ])

    return ppc

if __name__ == '__main__':
    ppc = case9()
    runpf(ppc)