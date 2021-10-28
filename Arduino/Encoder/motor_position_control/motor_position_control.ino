
// Pin Allocation

int outputA = 2 ; // interrupt encoder
int outputB = 9 ; // direction encoder

int en1 = 6 ;     // motor enable-pwm
int d2 = 7 ;      // motor direction
int d1 = 8 ;      // motor direction

// Position Parameters

int encoder_pulse ;
float motor_degree ;

// Controller Variables

float Kp = 2.5 ;
float Ki = 1.0 ;
float Kd = 0.1 ;

float Frequency  = 50 ;
float Ts = 1/Frequency ;

float control_output = 0 ;
float control_output_1 = 0 ;
float control_output_2 = 0 ;

float error = 0 ; 
float error_1 = 0 ;
float error_2 = 0 ;

float angle_setpoint = 170 ;

float A ;
float B ;
float C ;
  
void setup() 
{ 
  Serial.begin (9600) ;
  
  pinMode(d1, OUTPUT) ;
  pinMode(d2, OUTPUT) ;
  pinMode(en1, OUTPUT) ;
  
  pinMode (outputA,INPUT) ;
  pinMode (outputB,INPUT) ;

  attachInterrupt(digitalPinToInterrupt(outputA), encoder, RISING) ;  // go to encoder function when there is a rising at outputA

// Timer1 Initialization
  
  cli() ;
  TCCR1A = 0 ;
  TCCR1B = 0 ;
  TCNT1  = 0 ;
  OCR1A = 311.5 ;
  TCCR1B |= (1 << WGM12) ;
  TCCR1B |= (1 << CS12) | (1 << CS10) ;  
  TIMSK1 |= (1 << OCIE1A) ;
  sei() ;
  
  A =  Kp + Ki*Ts/2 + Kd/Ts ;
  B = -Kp + Ki*Ts/2 - 2*Kd/Ts ;
  C =  Kd/Ts ;

}

void loop() 
{ 
Serial.println(motor_degree) ;  
}

void encoder() 
{  
  if (digitalRead(outputB) == 1) { 
       encoder_pulse ++ ; //cw 
 } 
  else {
       encoder_pulse -- ; //ccw
 }

   motor_degree = encoder_pulse*(360.0/6533.0) ;
}

ISR(TIMER1_COMPA_vect)
{

  error = angle_setpoint - motor_degree ;
  control_output = control_output_1 + A*error + B*error_1 + C*error_2 ;   // PID Controller

  // Update Variable
  control_output_1 = control_output ;
  error_2 = error_1 ;
  error_1 = error ;

  if (control_output>=255) {
    control_output = 255 ;
}

  if (error<0) {
    digitalWrite(d1,LOW) ;
    digitalWrite(d2, HIGH) ;
    analogWrite(en1, control_output) ;
 }

  else if (error>=0) {
    digitalWrite(d1, HIGH) ;
    digitalWrite(d2, LOW) ;
    analogWrite(en1, control_output) ;
    
 }
}
