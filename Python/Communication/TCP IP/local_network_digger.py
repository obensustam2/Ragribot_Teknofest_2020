import socket
import time
import serial

HOST = '192.168.137.45'
PORT2 = 8889

def digger_hareket():

    s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s2.bind((HOST, PORT2))
    s2.listen(5)
    print("Socket2 is now listening")

    while True:

        c2, addr2 = s2.accept()
        print("Connect with " + addr2[0] )
        data2 = c2.recv(1024)
        a2=data2[5:7]
        print(a2)

        if(a2 == b'10'):
            ser2.write(str(1).encode('utf-8'))
            print("Kazici calisiyor")
            time.sleep(1)
        elif(a2 ==b'11'):
            ser2.write(str(2).encode('utf-8'))
            print("Kazici duruyor")
            time.sleep(1)

if __name__ == '__main__' :
    ser2 = serial.Serial('/dev/ttyACM0', 15500)
    ser2.flush()
    digger_hareket()