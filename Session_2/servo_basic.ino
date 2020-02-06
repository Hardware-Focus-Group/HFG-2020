#include<Servo.h>
Servo myservo;
void setup(){
  myservo.attach(9);
}

void loop(){
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(500);
}
