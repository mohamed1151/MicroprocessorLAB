#define clockPin 6 //SHCP 
#define latchPin 4 //STCP 
#define dataPin 5 //DS 
int num;
int map7seg[10] = {
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00100111,
  0b01111111,
  0b01101111
};
void setLed(uint8_t _state){
  for(int i = 0; i < 8; i++){
    digitalWrite(dataPin,(_state >> (7-i)) & 0x01);
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}  

void setup() {
  pinMode(dataPin,OUTPUT);    //set output
  pinMode(latchPin,OUTPUT);   //set output
  pinMode(clockPin,OUTPUT);   //set output
  Serial.begin(9600);
}

void loop() { 
  if(Serial.available() > 0)
   {
   char inByte = Serial.read();
    if(('0'<=inByte)&&(inByte<='9')){
      num = inByte - '0';
    }
    setLed(map7seg[num]);
  }
}
