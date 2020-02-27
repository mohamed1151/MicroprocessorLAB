#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height,in pixels
#define OLED_RESET  -1 // Reset pin # (or 1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int Pushbutton1 = A0;
int Pushbutton2 = A1;

int buttonState1;
int buttonState2;

void setup() {

pinMode(Pushbutton1, INPUT_PULLUP); 
pinMode(Pushbutton2, INPUT_PULLUP);
display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
display.clearDisplay(); // clears the screen and buffer
//display.drawPixel(127, 63, WHITE);
//display.drawLine(0, 63, 127, 21, WHITE);
display.drawCircle(30, 25, 20, WHITE);
display.drawCircle(100, 25, 20, WHITE);
//display.fillCircle(30, 25, 20, WHITE);
display.display();
Serial.begin(9600);
}

void loop() {
 buttonState1 = digitalRead(Pushbutton1); 
 buttonState2 = digitalRead(Pushbutton2); 
 Serial.println(buttonState1);
 Serial.println(buttonState2);
 Serial.println("------------------");
 display.clearDisplay();

if(buttonState1 == 1 && buttonState2 == 0)
{
  display.fillCircle(30, 25, 20, WHITE);
  display.drawCircle(100, 25, 20, WHITE);
}


if(buttonState1 == 1 && buttonState2 == 1){
  display.fillCircle(30, 25, 20, WHITE);
  display.fillCircle(100, 25, 20, WHITE);
}

if(buttonState1 == 0 && buttonState2 == 1){
  display.drawCircle(30, 25, 20, WHITE);
  display.fillCircle(100, 25, 20, WHITE);
}
display.display();
}
