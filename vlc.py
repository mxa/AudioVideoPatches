import pyext
import sys
from socket import *

class vlc(pyext._class):
	def __init__(self,host,port):
		self.s = socket(AF_INET, SOCK_STREAM)    # create a TCP socket
		self.s.connect((str(host), port)) # connect to server on the port
		
	def list_1(self,*atoms):
		self.s.send(' '.join(map(str,atoms))+"\r")
		d = self.s.recv(1024)
		self._outlet(1,d.split())
