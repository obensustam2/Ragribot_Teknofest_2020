import time
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
ser.flush()

def all_together():

    time.sleep(2)

    while True:

        ser.write(str(4).encode('utf-8'))
        print("Digger ON")

        ser.write(str(1).encode('utf-8'))
        print("Forward")
        time.sleep(4)

        ser.write(str(5).encode('utf-8'))
        print("Digger OFF")

        ser.write(str(2).encode('utf-8'))
        print("Right Spin")
        time.sleep(1.5)

        ser.write(str(1).encode('utf-8'))
        print("Forward")
        time.sleep(1)

        ser.write(str(2).encode('utf-8'))
        print("Right Spin")
        time.sleep(1.5)

        ser.write(str(4).encode('utf-8'))
        print("Digger ON")

        ser.write(str(1).encode('utf-8'))
        print("Forward")
        time.sleep(4)

        ser.write(str(5).encode('utf-8'))
        print("Digger OFF")

        ser.write(str(3).encode('utf-8'))
        print("Left Spin")
        time.sleep(1.5)

        ser.write(str(1).encode('utf-8'))
        print("Forward")
        time.sleep(1)

        ser.write(str(3).encode('utf-8'))
        print("Left Spin")
        time.sleep(1.5)

if __name__ == '__main__' :
    all_together()