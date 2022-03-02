import gurobipy as gp
import pandapower as pp
from opt.model.power_opt_model import PowerOptModel


class SCUCModel(PowerOptModel):
    def __init__(self, net: pp.pandapowerNet):
        super(SCUCModel, self).__init__(net)
