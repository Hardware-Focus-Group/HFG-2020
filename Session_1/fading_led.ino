#define LED 13
void setup() {
  // put your setup code here, to run once:
   pinMode(LED,OUTPUT);
}

void loop() {
//  0v = 1 and 2^8=256=5V 
  for(int i=0;i<256;i+=10){
    analogWrite(LED,i);
    delay(50);
  }
  for(int i=255;i>=0;i-=10){
    analogWrite(LED,i);
    delay(50);
  }
}
