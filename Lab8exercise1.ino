#define LED1_PIN 5
#define LED2_PIN 6
float brightness = 0;
String buff;
int state;
int Port=0;

void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if(inByte == 'L')
    {
      state = 0; 
      buff = ""; 
    }
    if((inByte == '1')&&(state == 0))
      {
        Port = LED1_PIN;
      }
    if((inByte == '2')&&(state == 0))
      {
       Port = LED2_PIN;
      }

    if(inByte == 'B')
    {
      state = 1; 
      buff = "";
    }
    if((('0'<= inByte)&&(state == 1))&&((inByte <= '9')&&(state == 1)))
    {
      buff += inByte;
    }
    if(inByte == '\n')
    {
      brightness = buff.toInt();
      Serial.println(brightness);
      analogWrite(Port,int(brightness*2.54));
  }
 }
}
