import socket
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('192.168.137.230', 8888))  
s.send('19'.encode())