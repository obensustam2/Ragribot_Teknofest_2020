from gpiozero import CPUTemperature
from time import sleep, strftime, time

cpu = CPUTemperature()
with open("/home/pi/cpu_temp.cvs", "a") as log:
    while True:
        temp = cpu.temperature
        log.write("{0}, {1}\n".format(strftime("%d-%m-%Y %H:%M"), str(temp)))
        sleep(1)