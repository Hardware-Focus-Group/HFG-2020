#define LED 13
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600); // BAUD rate of ur choice
}

void loop() {
  // put your main code here, to run repeatedly:
  char ch = NULL;
  if (Serial.available()) {
    ch = Serial.read();
    if(ch == 'F' || ch == 'f'){
      digitalWrite(LED, HIGH);
      Serial.println("WE R ON");
      }else if(ch == 'L' || ch == 'l'){
        digitalWrite(LED, LOW);
        Serial.println("DAMN WE R OFF");
        }
        else{}
  }
  delay(10);
}
