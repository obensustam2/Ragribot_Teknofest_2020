
#include <Servo.h> 
Servo Servo_Motor ;

int en1 = 2 ;  // m1 pwm pin sağ ön
int d1 = 22 ;  // m1 direction
int d2 = 24 ;  // m1 direction

int en2 = 3 ;  // m2 pwm pin sol ön
int d3 = 28 ;  // m2 direction
int d4 = 30 ;  // m2 direction

int en3 = 4 ;  // m3 pwm pin sağ arka
int d5 = 34 ;  // m3 direction
int d6 = 36 ;  // m3 direction

int en4 = 5 ;  // m4 pwm pin sol arka
int d7 = 40 ;  // m4 direction
int d8 = 42 ;  // m4 direction

int en5 = 8 ; // digger pwm pin
int d9 = 43 ; // digger direction
int d10 = 45 ; // digger direction

int en6 = 9 ; // pump pwm pin 
int d11 = 49 ; // pump direction
int d12 = 51 ; // pump direction

int i = 255 ; // movement pwm 
int j = 255 ; // digger pwm
int k = 64 ; // pump pwm

void setup() 
{
    Servo_Motor.attach(10); 
    
    pinMode(d1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(en1, OUTPUT); 

    pinMode(d3, OUTPUT);
    pinMode(d4, OUTPUT);
    pinMode(en2, OUTPUT); 

    pinMode(d5, OUTPUT);
    pinMode(d6, OUTPUT);
    pinMode(en3, OUTPUT); 

    pinMode(d7, OUTPUT);
    pinMode(d8, OUTPUT);
    pinMode(en4, OUTPUT); 

    pinMode(d9, OUTPUT);
    pinMode(d10, OUTPUT);
    pinMode(en5, OUTPUT); 

    pinMode(d11, OUTPUT);
    pinMode(d12, OUTPUT);
    pinMode(en6, OUTPUT); 
}

void loop() 
{
  //forward
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
  analogWrite(en1, i);

  digitalWrite(d3, LOW);
  digitalWrite(d4, HIGH);
  analogWrite(en2, i);

  digitalWrite(d5, LOW);
  digitalWrite(d6, HIGH);
  analogWrite(en3, i);

  digitalWrite(d7, LOW);
  digitalWrite(d8, HIGH);
  analogWrite(en4, i);
  delay(3000);
        
  //backward
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  analogWrite(en1, i);

  digitalWrite(d3, HIGH);
  digitalWrite(d4, LOW);
  analogWrite(en2, i);

  digitalWrite(d5, HIGH);
  digitalWrite(d6, LOW);
  analogWrite(en3, i);

  digitalWrite(d7, HIGH);
  digitalWrite(d8, LOW);
  analogWrite(en4, i);
  delay(3000);
  
  //stop
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);

  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  digitalWrite(d5, LOW);
  digitalWrite(d6, LOW);

  digitalWrite(d7, LOW);
  digitalWrite(d8, LOW);
  delay(3000);

  //digger ON
  digitalWrite(d9, LOW);
  digitalWrite(d10, HIGH);
  analogWrite(en5, j);
  delay(3000) ;

  //digger OFF
  digitalWrite(d9, LOW);
  digitalWrite(d10, LOW);
  delay(3000) ;

  //servo 0 degree
  Servo_Motor.write(0) ;
  delay(1000) ;
    
  //servo 180 degree
  Servo_Motor.write(180) ;
  delay(1000) ;
       
  //pump ON
  digitalWrite(d11, LOW);
  digitalWrite(d12, HIGH);
  analogWrite(en6, k);
  delay(1000) ;
        
  //pump OFF
  digitalWrite(d11, LOW);
  digitalWrite(d12, LOW);
  delay(3000) ;
       
 }
