from gym_prescan.envs.utils import *

ExperimentName = ''
bdroot = ''
prescanFile = ''

def set_experimant(ExpName):
    global ExperimentName, bdroot, prescanFile
    ExperimentName = ExpName
    bdroot = ExperimentName + "_cs"
    prescanFile = ExperimentName + ".pb"
    print(ExperimentName)



class Model:
    objects=[]
    def __init__(self, name, model):
        Model.objects.append(self)
        self.name = name
        self.model = model

    def close(self):
        Model.objects.remove(self)
        print('{} closed!'.format(self.name))


    def create(self):
        pass

    def __str__(self):
        return self.name

    def __repr__(self):
        return '{}({!r})'.format(self.model, self.name)


####--------------------------------------------------------------####
class Road(Model):
    objects = []
    
    def __init__(self, name=None):
        __name__ = name if name is not None else 'StraightRoad_1'
        Road.objects.append(self)
        Model.__init__(self, __name__, 'Road')

    def create(self):
        self.length = 750
        self.numberOfLanes = 5
        self.laneWidth = 3.5

    # def __del__(self):
    #     self.close()

    def close(self):
        Road.objects.remove(self)
        super().close()



####--------------------------------------------------------------####

class Vehicle(Model):
    objects = []

    def __init__(self, name, data_port=None, road=None):
        Vehicle.objects.append(self)
        Model.__init__(self, name, 'Vehicle')
        self.road = road

    def close(self):
        Vehicle.objects.remove(self)
        super().close()






####==========================================================#######
