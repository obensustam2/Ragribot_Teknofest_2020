import socket
import time
import serial

HOST = '192.168.137.45'
PORT1 = 8888

def hareket_ve_kazici():

    s1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s1.bind((HOST, PORT1))
    s1.listen(5)
    print("Socket is now listening")

    while True:

        c1, addr1 = s1.accept()
        print("Connect with " + addr1[0] )
        data1 = c1.recv(1024)
        a1=data1[5:7]
        print(a1)

        if(a1 == b'10'):
            ser1.write(str(1).encode('utf-8'))
            print("Arac ileri gidiyor")
            time.sleep(1)
        elif(a1 ==b'11'):
            ser1.write(str(2).encode('utf-8'))
            print("Arac saga gidiyor")
            time.sleep(1)
        elif(a1 ==b'12'):
            ser1.write(str(3).encode('utf-8'))
            print("Arac geri gidiyor")
            time.sleep(1)
        elif(a1 ==b'13'):
            ser1.write(str(4).encode('utf-8'))
            print("Arac sola gidiyor")
            time.sleep(1)
        elif(a1 ==b'14'):
            ser1.write(str(5).encode('utf-8'))
            print("Arac duruyor")
            time.sleep(1)
        elif(a1 == b'15'):
            ser2.write(str(1).encode('utf-8'))
            print("Kazici calisiyor")
            time.sleep(1)
        elif(a1 ==b'16'):
            ser2.write(str(2).encode('utf-8'))
            print("Kazici duruyor")
            time.sleep(1)

if __name__ == '__main__' :
    ser1 = serial.Serial('/dev/ttyACM0', 9600)
    ser2 = serial.Serial('/dev/ttyACM1', 15500)
    ser1.flush()
    ser2.flush()
    hareket_ve_kazici()