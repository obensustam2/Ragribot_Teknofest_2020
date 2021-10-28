import requests
import json
import serial
import time

def thingspeak_read() :
    URL='https://api.thingspeak.com/channels/1024833/fields/1.json?api_key='
    KEY='P1IVLK79FD8FMIBE'
    HEADER='&results=1'
    NEW_URL=URL+KEY+HEADER
    print(NEW_URL)

    while True :
        get_data=requests.get(NEW_URL).json()
        field_1=get_data['feeds'][0]
        b = list(field_1.values())[-1]

        if  int(b) == 10 :
            ser.write(str(1).encode('utf-8'))
            print("sending number is " + str(1) + ". Car is going forward ")
            time.sleep(1)
        elif int(b) == 11 :
            ser.write(str(2).encode('utf-8'))
            print("sending number is " + str(2) + ". Car is turning right ")
            time.sleep(1)
        elif int(b) == 12 :
            ser.write(str(3).encode('utf-8'))
            print("sending number is " + str(3) + ". Car is going backward ")
            time.sleep(1)
        elif int(b) == 13 :
            ser.write(str(4).encode('utf-8'))
            print("sending number is " + str(4) + ". Car is turning left ")
            time.sleep(1)
        elif int(b) == 14 :
            ser.write(str(5).encode('utf-8'))
            print("sending number is " + str(5) + ". Car is stopped ")
            time.sleep(1)

if __name__ == '__main__' :
    ser = serial.Serial('/dev/ttyACM0', 9600)
    ser.flush()
    thingspeak_read()