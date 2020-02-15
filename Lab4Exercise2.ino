#include<SPI.h>
#define CLOCK_PIN 13 //SHCP 
#define SS_PIN_1 10 //STCP 
#define DATA_PIN 11 //DS 
#define SS_PIN_2 9 
#define buzzer 6

int buttonPin1 = A0;
int buttonPin2 = A1;
int buttonPin3 = A2;


int buttonState1 ;    
int buttonState2 ; 
int buttonState3 ;  

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

int i=0;
int j=0;
int k,l;
bool toggle = 0;

void spi_write_1(unsigned char cData) {
  shiftOut(DATA_PIN,CLOCK_PIN, MSBFIRST, cData);
  digitalWrite(SS_PIN_1, HIGH);
  digitalWrite(SS_PIN_1, LOW);
}

void spi_write_2(unsigned char cData) {
  shiftOut(DATA_PIN,CLOCK_PIN, MSBFIRST, cData);
  digitalWrite(SS_PIN_2, HIGH);
  digitalWrite(SS_PIN_2, LOW);
}

void setup()
{
  pinMode(SS_PIN_1, OUTPUT);
  pinMode(SS_PIN_2, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  spi_write_1(map7seg[i/10]); 
  spi_write_2(map7seg[i%10]); 
  buttonState1 = digitalRead(buttonPin1); 
  buttonState2 = digitalRead(buttonPin2); 
  buttonState3 = digitalRead(buttonPin3); 
  if (buttonState1 == 0 && buttonState2 == 1 && buttonState3 == 1){
    i++;
//    if(i<=9){
//      spi_write_2(map7seg[i]); 
//    }
//    if(i>9){
//      j++;
//      i=0;
//      spi_write_1(map7seg[j]);
//      spi_write_2(map7seg[i]); 
//    }
    Serial.println("increase");
  }
  if (buttonState1 == 1 && buttonState2 == 0 && buttonState3 == 1){
      i--;
//    if(i<=0){
//      spi_write_2(map7seg[i]); 
//    }
//    if(i<0){
//      i=9;
//      j--;
//      spi_write_1(map7seg[j]);
//      spi_write_2(map7seg[i]); 
//    }
    Serial.println("decrease");
  }
  if (buttonState1 == 1 && buttonState2 == 1 && buttonState3 == 0){
    toggle = !toggle;
    Serial.println(toggle);
  }
  if (toggle==1){
     
//    if(i<=0){
//      spi_write_2(map7seg[i]); 
//    }
//    if(i<0){
//      i=9;
//      j--;
//      spi_write_1(map7seg[j]);
//      spi_write_2(map7seg[i]); 
//    }
    if(i==0){
      spi_write_1(map7seg[0]);
      spi_write_2(map7seg[0]); 
      tone(buzzer, 1000);
      toggle = 0;
    }
    else {i--;}
  }
  
  delay(500);
  }
