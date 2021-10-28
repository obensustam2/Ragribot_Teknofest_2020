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

        ser.write(str(6).encode('utf-8'))
        print("Seed ON")
        time.sleep(0.4)

        ser.write(str(8).encode('utf-8'))
        print("Pump ON")
        time.sleep(0.6)

        ser.write(str(9).encode('utf-8'))
        print("Pump OFF")

        ser.write(str(7).encode('utf-8'))
        print("Seed OFF")
        time.sleep(1)

        ser.write(str(6).encode('utf-8'))
        print("Seed ON")
        time.sleep(0.4)

        ser.write(str(8).encode('utf-8'))
        print("Pump ON")
        time.sleep(0.6)

        ser.write(str(9).encode('utf-8'))
        print("Pump OFF")

        ser.write(str(7).encode('utf-8'))
        print("Seed OFF")
        time.sleep(1)

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

        ser.write(str(6).encode('utf-8'))
        print("Seed ON")
        time.sleep(0.4)

        ser.write(str(8).encode('utf-8'))
        print("Pump ON")
        time.sleep(0.6)

        ser.write(str(9).encode('utf-8'))
        print("Pump OFF")

        ser.write(str(7).encode('utf-8'))
        print("Seed OFF")
        time.sleep(1)

        ser.write(str(6).encode('utf-8'))
        print("Seed ON")
        time.sleep(0.4)

        ser.write(str(8).encode('utf-8'))
        print("Pump ON")
        time.sleep(0.6)

        ser.write(str(9).encode('utf-8'))
        print("Pump OFF")

        ser.write(str(7).encode('utf-8'))
        print("Seed OFF")
        time.sleep(1)

        ser.write(str(5).encode('utf-8'))
        print("Digger OFF")

        ser.write(str(3).encode('utf-8'))
        print("Left Spin")
        time.sleep(0.7)

        ser.write(str(1).encode('utf-8'))
        print("Forward")
        time.sleep(1)

        ser.write(str(3).encode('utf-8'))
        print("Left Spin")
        time.sleep(1.5)


if __name__ == '__main__':
    all_together()