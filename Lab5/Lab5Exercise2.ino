#include <ThreeWire.h>
#include <RtcDS1302.h> 
ThreeWire myWire(4,5,2); // IO, SCLK, CE 
RtcDS1302<ThreeWire> Rtc(myWire); 
RtcDateTime i;

void printDateTime(const RtcDateTime& dt){ 
 Serial.print(dt.Year(), DEC); 
 Serial.print('/'); 
 Serial.print(dt.Month(), DEC); 
 Serial.print('/'); 
 Serial.print(dt.Day(), DEC); 
 Serial.print(' '); 
 Serial.print(dt.Hour(), DEC); 
 Serial.print(':'); 
 Serial.print(dt.Minute(), DEC); 
 Serial.print(':'); 
 Serial.print(dt.Second(), DEC); 
 Serial.println(); 
 Serial.print("Total Seconds since 1/1/2000 : "); 
 Serial.print(dt.TotalSeconds()); 
 Serial.println();
}

void setup() { 
 pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  
 Serial.begin(9600); 
 Rtc.Begin(); 
 RtcDateTime setting_time(2020,2,2,23,0,0); 
 // year, month, dayOfMonth, hour, minute, second 
 printDateTime(setting_time); 
 //Try to comment This line 
 Rtc.SetDateTime(setting_time); 
 RtcDateTime now = Rtc.GetDateTime(); 
 i = now.TotalSeconds();
 Serial.println("start");
} 

void loop() { 
 RtcDateTime now = Rtc.GetDateTime(); 

 if(now.TotalSeconds() <= i+120){
 if(now.TotalSeconds()% 2 == 0){
   digitalWrite(13, HIGH);
   printDateTime(now);
 }
 else if(now.TotalSeconds()% 2 == 1)
 {
  digitalWrite(13, LOW);
  printDateTime(now);
 }
}
  else if(now.TotalSeconds() > i+120)
 {
  digitalWrite(13, LOW);
  Serial.println("stop");
 }
}
  
