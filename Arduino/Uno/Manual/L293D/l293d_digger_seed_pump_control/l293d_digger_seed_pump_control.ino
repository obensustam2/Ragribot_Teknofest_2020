
#include <AFMotor.h>
#include <Servo.h> 

AF_DCMotor DC_Motor1(1);
AF_DCMotor DC_Motor2(2);
AF_DCMotor DC_Motor3(3);
AF_DCMotor Water_Pump(4) ;
Servo Servo_Motor ;  

int i = 255 ;

void setup() 
{
Servo_Motor.attach(10); 
}

void loop() 
{
   DC_Motor1.run(FORWARD);
   DC_Motor2.run(FORWARD);
   DC_Motor3.run(FORWARD);
   DC_Motor1.setSpeed(i);
   DC_Motor2.setSpeed(i);
   DC_Motor3.setSpeed(i);
   delay(3000) ;
   
   DC_Motor1.run(RELEASE) ;
   DC_Motor2.run(RELEASE) ;
   DC_Motor3.run(RELEASE) ;
   delay(1000) ;

   Water_Pump.run(FORWARD);
   Water_Pump.setSpeed(i-100);
   delay(3000) ;
   Water_Pump.run(RELEASE);
   delay(1000) ;

   Servo_Motor.write(0) ;
   delay(1000) ;
   Servo_Motor.write(30) ;
   delay(1000) ;
   Servo_Motor.write(60) ;
   delay(1000) ;
   Servo_Motor.write(90) ;
   delay(1000) ;
   Servo_Motor.write(120) ;
   delay(1000) ;
   Servo_Motor.write(150) ;
   delay(1000) ;
   Servo_Motor.write(180) ;
   delay(1000) ;
   
 }
