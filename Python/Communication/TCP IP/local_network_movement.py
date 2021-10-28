import socket
import time
import serial

HOST = '192.168.137.45'
PORT = 8888

def tcp_ip_server():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen(5)
    print("Socket is now listening")

    while True:
        c, addr = s.accept()
        print("Connect with " + addr[0] )
        data = c.recv(1024)
        a=data[5:7]
        print(a)

        if(a == b'10'):
            ser.write(str(1).encode('utf-8'))
            print("Arac ileri gidiyor")
            time.sleep(1)
        elif(a ==b'11'):
            ser.write(str(2).encode('utf-8'))
            print("Arac saga gidiyor")
            time.sleep(1)
        elif(a ==b'12'):
            ser.write(str(3).encode('utf-8'))
            print("Arac geri gidiyor")
            time.sleep(1)
        elif(a ==b'13'):
            ser.write(str(4).encode('utf-8'))
            print("Arac sola gidiyor")
            time.sleep(1)
        elif(a ==b'14'):
            ser.write(str(5).encode('utf-8'))
            print("Arac duruyor")
            time.sleep(1)

if __name__ == '__main__' :
    ser = serial.Serial('/dev/ttyACM0', 9600)
    ser.flush()
    tcp_ip_server()