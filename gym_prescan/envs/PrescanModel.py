import matlab.engine
from gym_prescan.envs.utils import *

globals()['eng'] = matlab.engine.connect_matlab()

ExperimentName = ''
bdroot = ''
prescanFile = ''

def set_experimant(ExpName):
    global ExperimentName, bdroot, prescanFile
    ExperimentName = ExpName
    bdroot = ExperimentName + "_cs"
    prescanFile = ExperimentName + ".pb"
    print(ExperimentName)



def getDefaultFilename():
    eng.prescan.experiment.getDefaultFilename()


def objectsFindByName(name):
    global ExperimentName
    eng.eval(ExperimentName + "_models = prescan.experiment.readDataModels('" + ExperimentName + ".pb');", nargout=0)
    return int(
        eng.eval("prescan.worldmodel.objectsFindByName(" + ExperimentName + "_models.worldmodel, '" + name + "')"))


class sim:
    global bdroot

    @staticmethod
    def Update():
        eng.set_param(bdroot, 'SimulationCommand', 'update', nargout=0)

    @staticmethod
    def Pause():
        eng.set_param(bdroot, 'SimulationCommand', 'pause', nargout=0)

    @staticmethod
    def Continue():
        eng.set_param(bdroot, 'SimulationCommand', 'continue', nargout=0)

    @staticmethod
    def Stop():
        eng.set_param(bdroot, 'SimulationCommand', 'stop', nargout=0)

    @staticmethod
    def Start():
        eng.set_param(bdroot, 'SimulationCommand', 'start', nargout=0)

    @staticmethod
    def Restart():
        eng.eval("set_param(bdroot, 'SimulationCommand', 'stop');set_param(bdroot, 'SimulationCommand', 'start');",nargout=0)

    @staticmethod
    def Status():
        '''
        The software returns 'stopped', 'initializing', 'running', 'paused', 'compiled', 'updating', 'terminating', or 'external'.
        '''
        return eng.get_param(bdroot, 'SimulationStatus')

    @staticmethod
    def Time():
        return eng.get_param(bdroot, 'SimulationTime')

    @staticmethod
    def Close_window():
        # eng.close_system(bdroot)
        os.system('TASKKILL /F /IM VisViewerApp.exe 2> NUL')


def python2matlab(**args):
    for key, value in args.items():
        eng.workspace[key] = eng.double(value)


def matlab2python(*args):
    for arg in args:
        globals()[arg] = eng.workspace[arg]


def pysim_update(**args):
    python2matlab(**args)
    sim.Update()


def prescan_regenerate():
    global bdroot, eng
    eng.generate_all(bdroot)


########################################################
class Model:
    global ExperimentName, bdroot
    __shared_flags__ = {'create_model': False}
    objects = []

    def __init__(self, name, model):
        Model.objects.append(self)
        self.name = name
        self.model = model

    def create(self):
        self.create_model_ones()
        self.id = Model.objectsFindByName(self.name)
        self.object = eng.eval(ExperimentName + "_models.worldmodel.object{" + str(self.id) + ", 1} ")
        self.position = self.object['pose']['position']
        self.orientation = self.object['pose']['orientation']

    # def __del__(self):
    #     self.close()

    def close(self):
        Model.objects.remove(self)
        print('{} closed!'.format(self.name))


    @staticmethod
    def create_model():
        eng.eval(ExperimentName + "_models = prescan.experiment.readDataModels('" + ExperimentName + ".pb');",
                 nargout=0)

    def create_model_ones(self):
        if (not Model.__shared_flags__['create_model']) and (eng.exist(ExperimentName + '_models') != 1):
            Model.create_model()
            Model.__shared_flags__['create_model'] = True

    @staticmethod
    def objectsFindByName(name):
        return int(eng.eval("prescan.worldmodel.objectsFindByName(" + ExperimentName + "_models.worldmodel, '" + name + "')"))

    @staticmethod
    def Update(**args):
        python2matlab(**args)
        sim.Update()

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
        super().create()
        self.length = self.object['road']['straightRoad']['roadLength']
        self.numberOfLanes = len(self.object['road']['roadEnds'][0]['laneEnds'])
        self.laneWidth = self.object['road']['roadEnds'][0]['laneEnds'][0]['width']

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
        # self.port = data_port

    def create(self, data_port=None):
        super().create()
        # self.port = data_port if data_port is not None else self.port
        # self.data = Reciver_UDP_json(self.port)
        # self.data.build()
    #
    # def __del__(self):
    #     self.close()

    def close(self):
        # self.data.close()
        Vehicle.objects.remove(self)
        super().close()






####==========================================================#######
