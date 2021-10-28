import requests
import json
import serial
import time

def read_and_control() :
    URL='https://api.thingspeak.com/channels/1024833/fields/4.json?api_key='
    KEY='P1IVLK79FD8FMIBE'
    HEADER='&results=1'
    NEW_URL=URL+KEY+HEADER
    print(NEW_URL)

    while True :
        get_data=requests.get(NEW_URL).json()
        field_4=get_data['feeds'][0]
        b = list(field_4.values())[-1]

        if  int(b) == 1 :
            ser.write(str(1).encode('utf-8'))
            print("sending number is " + str(1))
            time.sleep(1)
        elif int(b) == 2 :
            ser.write(str(2).encode('utf-8'))
            print("sending number is " + str(2) )
            time.sleep(1)
        elif int(b) == 3 :
            ser.write(str(3).encode('utf-8'))
            print("sending number is " + str(3) )
            time.sleep(1)
        elif int(b) == 4 :
            ser.write(str(4).encode('utf-8'))
            print("sending number is " + str(4) )
            time.sleep(1)
        elif int(b) == 5 :
            ser.write(str(5).encode('utf-8'))
            print("sending number is " + str(5) )
            time.sleep(1)
        elif int(b) == 6 :
            ser.write(str(6).encode('utf-8'))
            print("sending number is " + str(6) )
            time.sleep(1)


if __name__ == '__main__' :
    ser = serial.Serial('/dev/ttyACM0', 9600)
    ser.flush()
    read_and_control()