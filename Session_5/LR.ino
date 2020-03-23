#include <Firmata.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

byte analogPin;

void analogWriteCallback(byte pin, int value)
{
  pinMode(pin, OUTPUT);
  analogWrite(pin, value);
}

void setup()
{
  dht.begin();
  Firmata.setFirmwareVersion(FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
  Firmata.begin();
}

void loop()
{
  while (Firmata.available()) {
    Firmata.processInput();
  }

  for (analogPin = 0; analogPin < TOTAL_ANALOG_PINS; analogPin++) {
    if (analogPin == 0) {
      int t = dht.readTemperature();
      t = map(t, 25, 50, 0, 1023);
      Firmata.sendAnalog(analogPin, t);
    } else if (analogPin == 1) {
      int h = dht.readHumidity();
      h = map(h, 0, 100, 0, 1023);
      Firmata.sendAnalog(analogPin, h);
    } else {
      Firmata.sendAnalog(analogPin, analogRead(analogPin));
    }
  }
}
