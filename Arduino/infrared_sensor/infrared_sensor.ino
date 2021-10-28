
int IRSensor = 7 ; 


void setup() 
{
  pinMode (IRSensor, INPUT) ; 
  Serial.begin(9600) ;
}

void loop()
{
  int statusSensor = digitalRead (IRSensor) ;
  if (statusSensor == 0) {
     Serial.println("Object is detected"); 
  }
  
  else {
    Serial.println("Object is not detected"); 
  }
}
