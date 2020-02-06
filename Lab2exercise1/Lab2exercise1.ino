int clk_pin = 13; //SHCP 
int latch_pin = 10; //STCP 
int data_pin = 11; //DS 
bool toggle;

void setup() {
// put your setup code here, to run once: 
  pinMode(clk_pin,OUTPUT); 
  pinMode(latch_pin,OUTPUT); 
  pinMode(data_pin,OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly: 
  digitalWrite(latch_pin,LOW);
  int data = 0b1000000000000000;
  digitalWrite (latch_pin, LOW);
  for (int i=0;i<16;i++){
   digitalWrite(data_pin, data >>(15-i)&0b0000000000000001);
    digitalWrite(clk_pin, HIGH);
    delay(100);
    digitalWrite(clk_pin, LOW);
    delay(100);
    digitalWrite(latch_pin, HIGH);
    digitalWrite(latch_pin, LOW);
}
}
