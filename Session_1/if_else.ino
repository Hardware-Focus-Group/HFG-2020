const int LED = 13;
const int BUTTON = 5;

void setup() {
  pinMode(LED, OUTPUT);
  //  pinMode(BUTTON, INPUT);
  //  digitalWrite(BUTTON, HIGH);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  bool state = digitalRead(BUTTON);

  if (state == HIGH) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
  delay(10);
}
