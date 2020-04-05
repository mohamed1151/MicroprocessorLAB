#define MOTOR_D1 7
#define MOTOR_D2 8
#define MOTOR_PWM 6

void setVelocity(int vel) {
  if(vel > 0 && vel < 256){
    digitalWrite(MOTOR_D1,HIGH);
    digitalWrite(MOTOR_D2,LOW);
    analogWrite(MOTOR_PWM,vel);
    delay(1000);
  }
  if(vel < 0 && vel > -256){
    vel = vel*(-1);
    digitalWrite(MOTOR_D1,LOW);
    digitalWrite(MOTOR_D2,HIGH);
    analogWrite(MOTOR_PWM,vel);
    delay(1000);
  }
  else{
    digitalWrite(MOTOR_D1,LOW);
    digitalWrite(MOTOR_D2,LOW);
  }
}

void setup() {
  pinMode(MOTOR_D1,OUTPUT);
  pinMode(MOTOR_D2,OUTPUT);
  pinMode(MOTOR_PWM,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  setVelocity(255);
  setVelocity(-255);
  setVelocity(0);
}
