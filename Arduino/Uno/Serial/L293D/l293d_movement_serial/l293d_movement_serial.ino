#include <AFMotor.h>

AF_DCMotor motor1(1); // Sol Ön Motor
AF_DCMotor motor2(2); // Sol Arka Motor
AF_DCMotor motor3(3); // Sağ Ön Motor
AF_DCMotor motor4(4); // Sağ Arka Motor

uint8_t i = 255 ; // Maksimum Hız

void setup() 
{
Serial.begin(9600);
}

void loop() 
{
  
if (Serial.available() > 0) {

int motor_case = Serial.read() - '0';

    switch (motor_case) {

      case 1 : // İleri
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        
        motor1.setSpeed(i);
        motor2.setSpeed(i); 
        motor3.setSpeed(i); 
        motor4.setSpeed(i); 
        delay(1000) ;
        break;

      case 2 : // Sağ İleri
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        
        motor1.setSpeed(i);
        motor2.setSpeed(i); 
        motor3.setSpeed(i-150); 
        motor4.setSpeed(i-150); 
        delay(1000) ;
        break;
        
      case 3 : // Sağ Geri
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        
        motor1.setSpeed(i);
        motor2.setSpeed(i); 
        motor3.setSpeed(i-150); 
        motor4.setSpeed(i-150); 
        delay(1000) ;
        break;
        
      case 4 : // Geri
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        
        motor1.setSpeed(i);
        motor2.setSpeed(i); 
        motor3.setSpeed(i); 
        motor4.setSpeed(i); 
        delay(1000) ;
        break;  

      case 5 : // Sol Geri
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        
        motor1.setSpeed(i-150);
        motor2.setSpeed(i-150); 
        motor3.setSpeed(i); 
        motor4.setSpeed(i); 
        delay(1000) ;
        break;

      case 6 : // Sol İleri
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        
        motor1.setSpeed(i-150);
        motor2.setSpeed(i-150); 
        motor3.setSpeed(i); 
        motor4.setSpeed(i); 
        delay(1000) ;
        break;

      case 7: // Dur
        motor1.run(RELEASE) ;
        motor2.run(RELEASE) ;
        motor3.run(RELEASE) ;
        motor4.run(RELEASE) ;
        delay(1000) ;
        break ;

      case 8 : // Sağ Spin
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        
        motor1.setSpeed(i);
        motor2.setSpeed(i); 
        motor3.setSpeed(i-100); 
        motor4.setSpeed(i-100); 
        delay(1000) ;
        break;

     case 9 : // Sol Spin
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        
        motor1.setSpeed(i-100);
        motor2.setSpeed(i-100); 
        motor3.setSpeed(i); 
        motor4.setSpeed(i); 
        delay(1000) ;
        break;
   }
  }
 }
