#include <AFMotor.h>
#include <Servo.h> 
 
Servo Servo_Motor ;  
AF_DCMotor DC_Motor(3) ;
AF_DCMotor Water_Pump(4) ;

uint8_t i = 255 ;

void setup() {  
  
Serial.begin(15500);
Servo_Motor.attach(10); 

}

void loop() {

if (Serial.available() > 0) {

int motor_case = Serial.read() - '0';

    switch (motor_case) {
    
      case 1 : 
        DC_Motor.run(FORWARD);
        DC_Motor.setSpeed(i);
        delay(1000) ;
        break;
        
      case 2 : 
        DC_Motor.run(RELEASE);
        delay(1000) ;
        break;
        
      case 3 :
        Servo_Motor.write(0) ;
        delay(1000) ;
        break ;
    
      case 4 :
        Servo_Motor.write(180) ;
        delay(1000) ;
        break ;
        
      case 5 :
        Water_Pump.run(FORWARD);
        Water_Pump.setSpeed(i);
        delay(1000) ;
        break ;
        
      case 6 :
        Water_Pump.run(RELEASE);
        delay(1000) ;
        break ;

   }
  }
 } 
