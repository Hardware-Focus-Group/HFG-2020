const int trigpin = 11;
const int echopin = 12;
float duration, inches, cm;
//temperature dependent velocity eqn in cm/microsecond
float vel = (331 + (0.61 * 24))/10000;

void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
  //ping
  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  
  //echo
  duration = pulseIn(echopin, HIGH);

  //distance = speed * time
  cm = (duration / 2.00) * (vel);
  //1 inch = 2.54 cm
  inches = cm / 2.54;

  Serial.print(inches,1);
  Serial.print("in, ");
  Serial.print(cm,1);
  Serial.println("cm");
  delay(200);
}
