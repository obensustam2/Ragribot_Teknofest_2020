from mpu9250_i2c import *

time.sleep(1) # delay necessary to allow mpu9250 to settle

print("recording data")
print()

x = 0
y = 0
z = 0
Vx = 0
Vy = 0
Vz = 0
t = 1

while True:

    try:

        ax,ay,az,wx,wy,wz = mpu6050_conv() # read and convert mpu6050 data

    except:
        continue

    print("Position [m]: x = ", x)
    print("Position [m]: y = ", y)
    print("Position [m]: z = ", z)
    print()

    x = x + Vx*t + 0.5*ax*t*t
    y = y + Vy*t + 0.5*ay*t*t
    z = z + Vz*t + 0.5*az*t*t

    Vx = Vx + ax*t
    Vy = Vy + ay*t
    Vz = Vz + az*t

    time.sleep(1)