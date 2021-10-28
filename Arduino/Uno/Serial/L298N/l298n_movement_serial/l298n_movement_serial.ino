
int en1 = 6 ; //enable-pwm sağ ön motor
int d2 = 7 ; //direction
int d1 = 8 ; //direction

int en2 = 11 ; //enable-pwm sol ön motor
int d4 =  12 ; //direction
int d3 =  13 ; //direction

int en3 = 5 ; //enable-pwm sağ arka motor
int d6 =  4 ; //direction
int d5 =  3 ; //direction

int en4 = 9 ; //enable-pwm sol arka motor
int d8 =  10 ; //direction
int d7 =  2 ; //direction

int i = 200 ;

void setup() { 

  Serial.begin(9600);

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

  // Turn off motors 
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);

  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  digitalWrite(d5, LOW);
  digitalWrite(d6, LOW);

  digitalWrite(d7, LOW);
  digitalWrite(d8, LOW);
  
  } 
 
 void loop() { 
  
 
  if (Serial.available() > 0) {

  int motor_case = Serial.read() - '0';

  switch (motor_case) {
  
  case 1 ://forward
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
  analogWrite(en1, i-25);

  digitalWrite(d3, LOW);
  digitalWrite(d4, HIGH);
  analogWrite(en2, i-25);

  digitalWrite(d5, LOW);
  digitalWrite(d6, HIGH);
  analogWrite(en3, i);

  digitalWrite(d7, LOW);
  digitalWrite(d8, HIGH);
  analogWrite(en4, i);
  delay(1000);
  break;
  
  case 2://backward
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  analogWrite(en1, i-25);

  digitalWrite(d3, HIGH);
  digitalWrite(d4, LOW);
  analogWrite(en2, i-25);

  digitalWrite(d5, HIGH);
  digitalWrite(d6, LOW);
  analogWrite(en3, i);

  digitalWrite(d7, HIGH);
  digitalWrite(d8, LOW);
  analogWrite(en4, i);
  
  delay(1000);
  break;
  
  case 3://stop
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);

  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  digitalWrite(d5, LOW);
  digitalWrite(d6, LOW);

  digitalWrite(d7, LOW);
  digitalWrite(d8, LOW);
  
  delay(1000);
  break;
 }
 }
 }
