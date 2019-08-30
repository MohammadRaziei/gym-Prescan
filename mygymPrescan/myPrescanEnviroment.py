from myPrescanModel import *
from utils import *

from time import sleep


class Discrete:
    r"""A discrete space in :math:`\{ 0, 1, \\dots, n-1 \}`.
    Example::
        >>> Discrete(2)
    """

    def __init__(self, n):
        assert n >= 0
        self.n = n

    def __repr__(self):
        return "Discrete(%d)" % self.n


class Enviroment:
    def __init__(self,outport=None, inport=None):
        self.outport = outport
        self.out = Reciver_UDP_json(outport)
        self.out.build()

        self.inport = None
        off_set_port, desired_velocity_port,reset_port = inport
        self.off_set_UDP = Transmitter_UDP(off_set_port)  # 8072)
        self.desired_velocity_UDP = Transmitter_UDP(desired_velocity_port)  # 8073)
        self.reset_UDP = Transmitter_UDP(reset_port,fmt='?')  # 8075)

    def __del__(self):
        self.close()

    def close(self):
        self.out.close()
        self.off_set_UDP.close()
        self.desired_velocity_UDP.close()
        self.reset_UDP.close()
        for model in Model.__shared_flags__['objects']:
            model.close()
        try:
            eng.quit()
        except:
            pass
        # print('Enviroment-------close')

    def reset(self):
        self.reset_UDP.send(True)
        self.reset_UDP.send(False)
        self.send((0,0))

    def send(self,data):
        o,d = data
        self.off_set_UDP.send(o)
        self.desired_velocity_UDP.send(d)
        # self.reset_UDP.send(r,'?')

    def get(self):
        self.data = self.out.get()
        self.object = self.data['Vehicles'][self.data['Object']]
        return self.data

    def create_model(self, car_name=None, road_name=None):
        self.road = Road(road_name)
        self.car = Vehicle(car_name, self.road)
        self.road.create()
        self.car.create()
        # print('_____________env______________')
