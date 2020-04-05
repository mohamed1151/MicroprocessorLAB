void setup()
{
  //pinMode(4, OUTPUT);
  DDRD = 0b11111100;
  DDRB = 0b000011;
  //DDRB = 0b00001000;
}

void loop()
{
  //digitalWrite(4, HIGH);
  int i;
  int j;
  PORTD = 0b00000100;
  //PORTB = 0b000001;
  for(i=0;i<6;i++)
  {
    //if(i<6)
    //{
  	delay(300);
    PORTD = PORTD << 1;
    //}
    //else{
    //  PORTB = 0b000001;
    //  delay(300);
   // PORTB = PORTB << 1;
   // 
  }
  PORTB = 0b000001;
  for(j=0;j<2;j++)
  {
    delay(300);
    PORTB = PORTB << 1;

  }
  
  //PORTD = 0x10; //0b00010000;
  //PORTB = 0b00001000;
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(4, LOW);
  //PORTD = 0x00;
  //delay(1000); // Wait for 1000 millisecond(s)
  
}