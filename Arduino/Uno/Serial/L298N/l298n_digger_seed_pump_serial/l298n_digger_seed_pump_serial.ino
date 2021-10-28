
#include <Servo.h> 
Servo Servo_Motor ;

int en1 = 6 ; //enable-pwm kazıcı motor
int d2 = 7 ; //direction
int d1 = 8 ; //direction

int en2 = 11 ; //enable-pwm su pompası
int d4 =  12 ; //direction
int d3 =  13 ; //direction

int i = 150 ;
  
void setup() {  
  
  Serial.begin(15500);
  Servo_Motor.attach(10); 

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(en1, OUTPUT);

  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(en2, OUTPUT);

}

void loop() {

if (Serial.available() > 0) {

int motor_case = Serial.read() - '0';

    switch (motor_case) {
    
      case 1 :   // Digger ON
        digitalWrite(d1, LOW);
        digitalWrite(d2, HIGH);
        analogWrite(en1, i);
        delay(1000) ;
        break;
        
      case 2 :   // Digger OFF
        digitalWrite(d1, LOW);
        digitalWrite(d2, LOW);
        delay(1000) ;
        break;
        
      case 3 :   // Servo 0 Degree
        Servo_Motor.write(0) ;
        delay(1000) ;
        break ;
    
      case 4 :  // Servo 180 Degree
        Servo_Motor.write(180) ;
        delay(1000) ;
        break ;
        
      case 5 :  // Pump ON
        digitalWrite(d3, LOW);
        digitalWrite(d4, HIGH);
        analogWrite(en2, i);
        delay(1000) ;
        break ;
        
      case 6 :  // Pump OFF
        digitalWrite(d3, LOW);
        digitalWrite(d4, LOW);
        delay(1000) ;
        break ;

   }
  }
 } 
