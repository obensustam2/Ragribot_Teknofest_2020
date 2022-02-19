import math
from random import randint, random
from mpu9250_i2c import *
from time import sleep, strftime, time

sleep(1)

print("recording data")
print()

with open("/home/osustam/headingAngle8.cvs", "a") as log:
    while True:
        try:
            # headingDeg = randint(1, 10)
            mx,my,mz = AK8963_conv() # read and convert AK8963 magnetometer data

            headingRad= math.atan2(my, mx)

            if(headingRad > 2*math.pi):
                headingRad = headingRad - 2*(math.pi)

            if(headingRad < 0):
                headingRad = headingRad + 2*(math.pi)

            headingDeg = int(headingRad * 180/(math.pi))

        except:
            continue

        print("Heading Angle = " + str(headingDeg))
        log.write("{0}, {1}\n".format(strftime("%d-%m-%Y %H:%M"), str(headingDeg)))
        sleep(1)