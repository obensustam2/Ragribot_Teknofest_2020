
int en = 6 ;  // pwm pin 
int d2 = 7 ;  // direction pin
int d1 = 8 ;  // direction pin

int k = 127 ; // pwm value

void setup() 
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(en, OUTPUT); 
}

void loop() 
{
// Motor ON
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
  analogWrite(en, k);
  delay(4000) ;
    
// Motor OFF
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  delay(4000) ;
}
