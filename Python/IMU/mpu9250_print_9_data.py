# MPU6050 9-DoF Example Printout

from mpu9250_i2c import *

time.sleep(1) # delay necessary to allow mpu9250 to settle

print("recording data")
print()

while True:
    try:
        ax,ay,az,wx,wy,wz = mpu6050_conv() # read and convert mpu6050 data
        mx,my,mz = AK8963_conv() # read and convert AK8963 magnetometer data
    except:
        continue

    print()
    print("accel [g]: x = ", ax)
    print("accel [g]: y = ", ay)
    print("accel [g]: z = ", az)
    print("gyro [dps]: x = ", wx)
    print("gyro [dps]: y = ", wy)
    print("gyro [dps]: z = ", wz)
    print("mag [uT]: x =", mx)
    print("mag [uT]: y =", my)
    print("mag [uT]: z =", mz)
    print()
    print("{}".format("-"*30))

    time.sleep(1)