#define LED_PIN_1 8
#define INT_PIN   3
int count=1;
int i=0;
int j=0;

void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(INT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), 
                  ISR_Callback, RISING);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED_PIN_1, HIGH);
  delay(i); 
  digitalWrite(LED_PIN_1, LOW);
  delay(i);
}

void ISR_Callback(){
 j = count%3;
 if(j == 1)
 {
 i = 1000;
 Serial.println("mode 1\n");
 }
 if(j == 2)
 {
 i = 2000;
 Serial.println("mode 2\n");
 }
 if(j == 0)
 {
 i = 3000;
 Serial.println("mode 3");
 }
 count++;
}
