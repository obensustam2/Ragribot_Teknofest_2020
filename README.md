# How robot works ?

Seperate actuator control and fully seed sowing application can be triggered from android app via socket communication(tcp-ip) 

After receiving command from mobile app, raspberry pi sends actuator commands to Arduino via serial communication.

Sensor measurements are done on raspberry pi and uploaded to ThingSpeak IOT platform. Then data is visualized on Android app.

ThinkSpeak IOT Platform: https://thingspeak.com/channels/1024833/private_show

MIT App Inventor: http://ai2.appinventor.mit.edu/#5971858543738880