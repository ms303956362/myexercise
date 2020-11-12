from numpy import array

def case():
    ppc = {"version": '2'}

    ##-----  Power Flow Data  -----##
    ## system MVA base
    ppc["baseMVA"] = 1

    ## bus data
    # bus_i type Pd Qd Gs Bs area Vm Va baseKV zone Vmax Vmin
    ppc["bus"] = array([
        [1,	1,	1.6, 0.8,  0,  0,	1,	1,	0,	1,	1,	1.1, 0.9],
        [2,	1,	2,	 1,	   0,  0,	1,	1,	0,	1,	1,	1.1, 0.9],
        [3,	1,	3.7, 1.3,  0,  0,	1,	1,	0,	1,	1,	1.1, 0.9],
        [4,	2,	0,	 0,	   0,  0,	1,	1,	0,	1,	1,	1.1, 0.9],
        [5,	3,	0,	 0,    0,  0,	1,	1,	0,	1,	1,	1.1, 0.9]
    ])

    ## generator data
    # bus, Pg, Qg, Qmax, Qmin, Vg, mBase, status, Pmax, Pmin, Pc1, Pc2,
    # Qc1min, Qc1max, Qc2min, Qc2max, ramp_agc, ramp_10, ramp_30, ramp_q, apf
    ppc["gen"] = array([
        [4,	5,	0,	3,	-3,	    1.05,	1,	1,	8,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0],
	    [5,	0,	0,	5,	-2.1,	1.05,	1,	1,	8, 	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0]
    ])

    ## branch data
    # fbus, tbus, r, x, b, rateA, rateB, rateC, ratio, angle, status, angmin, angmax
    ppc["branch"] = array([
        [1,	2,	0.04,	0.25,	0.5, 2,	    2,	  2,     0,	   0,	1,	-360,	360],
	    [1,	3,	0.1,	0.35,	0,	 0.65,	0.65, 0.65,  0,	   0,	1,	-360,	360],
	    [2,	3,	0.08,	0.3,	0.5, 2,	    2,	  2,	 0,	   0,	1,	-360,	360],
	    [2,	4,	0,	    0.015,	0,	 6,   	6,	  6,	 1.05, 0,	1,	-360,	360],
	    [3,	5,	0,      0.03,	0,	 5,	    5,	  5,     1.05, 0,	1,	-360,	360]
    ])

    ##-----  OPF Data  -----##

    ## generator cost data
    # 1 startup shutdown n x1 y1 ... xn yn
    # 2 startup shutdown n c(n-1) ... c0
    ppc["gencost"] = array([
        [2,	0,	0,	3, 50.4395,	 200.4335,	1200.6485],
	    [2,	0,	0,	3, 200.55,	 500.746,	1857.201]
    ])

    return ppc


if __name__ == "__main__":
    from pypower.api import runopf, ppoption
    ppopt = ppoption(OPF_FLOW_LIM=1, OUT_GEN=True)
    runopf(case(), ppopt)
