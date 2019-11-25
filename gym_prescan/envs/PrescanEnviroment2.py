from gym_prescan.envs.PrescanModel2 import *
from time import sleep,time




class Enviroment:
    def __init__(self,outport=None, inport=None,host='localhost'):
        self.outport = outport
        self.out = Reciver_UDP_json(outport)
        self.out.build()

        self.inport = inport
        self.inp = Transmitter_UDP(inport,fmt='ddd',host=host)
        self.done=False

    def __del__(self):
        self.close()

    def close(self):
        self.out.close()
        self.inp.close()

        for model in Model.objects:
            model.close()
        try:
            eng.quit()
        except:
            pass
        # print('Enviroment-------close')

    def reset(self):
        self.send_vec([0,0,1])
    
        # while True:
        #     self.get()
        #     if not bool(self.data['done']):
        #         break
        ### self.done = False
        flag = True
        while flag:
            t = time()
            while True: 
                self.get()
                if not bool(self.data['done']):
                    flag = False
                    break
                if time() - t > 3:
                    print('Retrying to reset environment!')
                    break
            self.send_vec([0,0,0])
            self.send_vec([0,0,1])
        self.send_vec([0,0,0])
        self.send_vec([0,0,0])
        return 

    def send_vec(self,data):
        o = data[0];v = data[1];r = data[2]
        self.inp.send(o,v,r)

    def send(self,data):
        o = data[0];v = data[1]
        self.inp.send(o,v,0)
        # self.off_set_UDP.send(o)
        # self.desired_velocity_UDP.send(v)
        # self.reset_UDP.send(r,'?')

    def get(self):
        self.data = self.out.get()
        self.agent = self.data['Vehicles'][self.data['Object']]
        self.collision = self.data['Collision']
        self.collision['Occurred'] = bool(self.collision['Occurred'])
        # if self.data['done'] :
        #     self.done = True 
        self.done = bool(self.data['done'])
        return self.data

    def create_model(self, car_name=None, road_name=None):
        self.road = Road(road_name)
        self.car = Vehicle(car_name, self.road)
        self.road.create()
        self.car.create()
    
    def close_window(self):
        os.system('TASKKILL /F /IM VisViewerApp.exe 2> NUL')

