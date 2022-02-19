import RPi.GPIO as GPIO
import time
import urllib.request

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

TRIG = 16
ECHO = 18
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)

TRIG2 = 11
ECHO2 = 13
GPIO.setup(TRIG2,GPIO.OUT)
GPIO.setup(ECHO2,GPIO.IN)

def sensor():

    while True:

        GPIO.output(TRIG, False) #calibration
        time.sleep(2)
        GPIO.output(TRIG, True)
        time.sleep(0.00001)
        GPIO.output(TRIG, False)

        while GPIO.input(ECHO)==0 :
            pulse_start = time.time()

        while GPIO.input(ECHO)==1 :
            pulse_end = time.time()

        pulse_duration = pulse_end - pulse_start
        distance = pulse_duration * 17150
        new_distance = round(distance+1.15, 2)
        print("Seed Level " + str(new_distance) + " cm")

        URL = 'https://api.thingspeak.com/update?api_key='
        KEY = 'MAVC087S1HVCXGIJ'
        HEADER = '&field1={}'.format(new_distance)
        NEW_URL = URL + KEY + HEADER
        data= urllib.request.urlopen(NEW_URL)
        print(data)

        GPIO.output(TRIG2, False)
        time.sleep(2)
        GPIO.output(TRIG2, True)
        time.sleep(0.00001)
        GPIO.output(TRIG2, False)

        while GPIO.input(ECHO2)==0 :
            pulse_start2 = time.time()

        while GPIO.input(ECHO2)==1 :
            pulse_end2 = time.time()

        pulse_duration2 = pulse_end2 - pulse_start2
        distance2 = pulse_duration2 * 17150
        new_distance2 = round(distance2+1.15, 2)
        print("Water Level " + str(new_distance2) + " cm")

        URL2 = 'https://api.thingspeak.com/update?api_key='
        KEY2 = 'L7PNZHFMRGF8CD25'
        HEADER2 = '&field1={}'.format(new_distance2)
        NEW_URL2 = URL2 + KEY2 + HEADER2
        data2= urllib.request.urlopen(NEW_URL2)
        print(data2)

        time.sleep(13)

if __name__ == '__main__' :
    sensor()