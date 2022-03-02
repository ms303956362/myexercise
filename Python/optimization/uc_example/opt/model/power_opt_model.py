import pandapower as pp


class PowerOptModel:
    def __init__(self, net: pp.pandapowerNet):
        self.net = net
        self.b_bus = net._ppc['internal']['Bbus'].A
