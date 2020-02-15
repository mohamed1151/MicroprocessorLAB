#include<SPI.h>
#define CLOCK_PIN 13 //SHCP 
#define SS_PIN_1 10 //STCP 
#define DATA_PIN 11 //DS 
#define SS_PIN_2 9 
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

int i,j;

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
  
  Serial.begin(9600);
}

void loop()
{
  for(j=0;j<=9;j++){
    spi_write_1(map7seg[j]); 

    for(i=0;i<=9;i++){
      spi_write_2(map7seg[i]); 
    delay(500);
    }
  }
}
