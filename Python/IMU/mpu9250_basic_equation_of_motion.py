import time

x = 0
Vx = 10
ax = 0
t = 2

while True:

    print("Position = ", x)
    print("Velocity = ", Vx)
    print("Acceleration = ", ax)
    print()

    x = x + Vx*t + 0.5*ax*t*t
    Vx = Vx + ax*t

    time.sleep(5)