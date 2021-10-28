
void setup() 
{
  setupPWM16() ;
}

void loop() 
{
  static uint16_t i ;
  analogWrite16(9, i) ;
  analogWrite16(10, 0xffff - i) ;
  i++ ;
  delay(1) ;
}

/* Configure digital pins 9 and 10 as 16-bit PWM outputs. */
void setupPWM16() 
{
  DDRB |= _BV(PB1) | _BV(PB2) ;        
  TCCR1A = _BV(COM1A1) | _BV(COM1B1)  | _BV(WGM11) ;                   
  TCCR1B = _BV(WGM13)  | _BV(WGM12)   | _BV(CS10) ;                    
  ICR1 = 0xffff;                      
}

/* 16-bit version of analogWrite(). Works only on pins 9 and 10. */
void analogWrite16(uint8_t pin, uint16_t val)
{
  switch (pin) {
    case  9: 
      OCR1A = val ; 
      break ;
    
    case 10: 
      OCR1B = val ; 
      break ;
 }
}
