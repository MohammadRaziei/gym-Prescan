
import socket
import struct, json


import os, numpy as np


prescan_port = 9620


def find_and_kill_port(port):
    result = os.popen("netstat -ano | findstr :{} | findstr ESTABLISHED".format(port)).read().strip()
    if result != '':
        pid = result.split(" ")[-1]
        os.popen("taskkill /PID {} /F".format(pid))

########################################################
class Reciver_UDP:

    def __init__(self, port_number=0, this_socket=None):
        self.port_number = port_number
        self.this_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    def build(self):
        self.this_socket.bind(("", self.port_number))
        print("waiting on port:", self.port_number)

    def get(self):
        data, addr = self.this_socket.recvfrom(1024)
        x = struct.unpack('d', data)
        # if x[0] >= 0:
        # print(self.name,": ", x[0])
        return x[0]

    def __del__(self):
        self.close()

    def close(self):
        self.this_socket.close()


class Reciver_UDP_json:
    def __init__(self, port_number=0):
        self.port_number = port_number
        self.this_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    def build(self):
        self.this_socket.bind(("", self.port_number))
        print("waiting on port:", self.port_number)

    def get(self):
        data, addr = self.this_socket.recvfrom(1024)
        data = json.loads(data.decode("utf-8"))
        return data

    def get_str(self):
        data, addr = self.this_socket.recvfrom(1024)
        return data.decode("utf-8")

    def __del__(self):
        self.close()

    def close(self):
        self.this_socket.close()


class Transmitter_UDP:

    def __init__(self, port_number, fmt=None, host='localhost', this_socket=None):
        self.fmt = fmt if fmt is not None else "d"
        self.port_number = port_number
        self.this_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.host = host
        print("Sending data to port: {}".format(port_number))

    def send(self, *ac,fmt=None):
        __format__ = fmt if fmt is not None else self.fmt
        y = struct.pack(__format__, *ac)
        self.this_socket.sendto(y, (self.host, self.port_number))
        # print("The Action is: ", ac)

    def close(self):
        self.this_socket.close()

def error(*args):
    print('Error: ',*args)



'''
class Transmitter_UDP_2:

    def __init__(self, name, port_number=0, host='129.97.229.120', this_socket=None):
        self.name = name
        self.port_number = port_number
        self.this_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.host = host
        print("Sending data to port: ", self.port_number)

    def send_data(self, off_set,desired_velocity,throttle_flag,brake_flag,reset_flag):

        # print((off_set),end='-')
        # print((desired_velocity))
        # print((throttle_flag))
        # print((brake_flag))
        # print((reset_flag))
        # exit()
        # print("--------")

        y = struct.pack("ddddd", (off_set),desired_velocity,throttle_flag,brake_flag,reset_flag)
        # y = struct.pack("ddddd", 0.0,0.0,0.0,0.0,0.0)
        # print(y)
        self.this_socket.sendto(y, (self.host, self.port_number))
        #print("The Action is: ", ac)
'''