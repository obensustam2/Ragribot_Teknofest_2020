import random
from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

from mpu6050 import mpu6050
import time
mpu = mpu6050(0x68)



plt.style.use('fivethirtyeight')

x_vals = []
y_vals = []

index = count()

while True:

    accel_data = mpu.get_accel_data()
    x_vals.append(next(index))
    y_vals.append(str(accel_data['x']))

    plt.cla()
    plt.plot(x_vals, y_vals)
    plt.tight_layout()
    plt.show()
    #ani = FuncAnimation(plt.gcf(), animate, interval=1000)
    time.sleep(1)


