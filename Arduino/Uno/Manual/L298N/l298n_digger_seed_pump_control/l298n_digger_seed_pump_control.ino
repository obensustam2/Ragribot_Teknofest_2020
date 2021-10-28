
#include <Servo.h> 

Servo Servo_Motor ;

int en1 = 6 ; //enable-pwm kazıcı motor
int d2 = 7 ; //direction
int d1 = 8 ; //direction

int en2 = 11 ; //enable-pwm su pompası
int d4 =  12 ; //direction
int d3 =  13 ; //direction
  
void setup() {  
  
  Servo_Motor.attach(10); 

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(en1, OUTPUT);

  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(en2, OUTPUT);

}

void loop() {

   digitalWrite(d1, LOW);
   digitalWrite(d2, HIGH);
   analogWrite(en1, 255);
   delay(5000) ;

   digitalWrite(d1, LOW);
   digitalWrite(d2, LOW);
   delay(1000) ;

   Servo_Motor.write(0) ;
   delay(1000) ;

   Servo_Motor.write(180) ;
   delay(1000) ;

   digitalWrite(d3, LOW);
   digitalWrite(d4, HIGH);
   analogWrite(en2, 127);
   delay(1000) ;

   digitalWrite(d3, LOW);
   digitalWrite(d4, LOW);
   delay(1000) ;
}
