from mpu6050 import mpu6050
mpu = mpu6050(0x68)
import time
import psutil
import matplotlib.pyplot as plt


plt.rcParams['animation.html'] = 'jshtml'
fig = plt.figure()
ax = fig.add_subplot(111)
fig.show()

i = 0
x, y = [], []
accel_data = mpu.get_accel_data()

while True:
    accel_data = mpu.get_accel_data()
    x.append(i)
    y.append(str(accel_data['x']))
    
    ax.plot(x, y, color='b')
    
    fig.canvas.draw()
    
    time.sleep(1)
    i +=1