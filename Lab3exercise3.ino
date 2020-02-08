#define clockPin 6 //SHCP 
#define latchPin 4 //STCP 
#define dataPin 5 //DS 
int num = 0;
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
int buttonPin1 = A0;
int buttonPin2 = A1;

int buttonState1 ;    
int buttonState2 ;    

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
  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
 buttonState1 = digitalRead(buttonPin1); 
 buttonState2 = digitalRead(buttonPin2); 
  if (buttonState1 == 0 && buttonState2 == 1){
    num++;
    Serial.println("button up");
  }
  if (buttonState2 == 0 && buttonState1 == 1){
    num--;
    Serial.println("button down");

  }
  if(num < 0)
    num = 9;
  if(num > 9)
    num = 0;
  Serial.println(num);
  setLed(map7seg[num]);
  delay(1000);
}
