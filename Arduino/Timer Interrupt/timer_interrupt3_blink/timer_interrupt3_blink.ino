
//timer1 will interrupt at 50Hz

//storage variables
boolean toggle1 = 0;

void setup(){

  pinMode(13, OUTPUT);

cli();//stop interrupts

  //set timer1 interrupt at 50Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  
  // set compare match register for 50hz increments
  OCR1A = 311.5;// = (16*10^6) / (50*1024) - 1 (must be <65536)
  
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);


sei();//allow interrupts

}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 50Hz toggles pin 13 (LED)
//generates pulse wave of frequency 50Hz/2 = 25Hz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle1){
    digitalWrite(13,HIGH);
    toggle1 = 0;
  }
  else{
    digitalWrite(13,LOW);
    toggle1 = 1;
  }
}

void loop(){
  //do other things here
}
