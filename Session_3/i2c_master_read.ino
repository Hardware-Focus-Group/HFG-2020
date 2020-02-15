#include <Wire.h>

/* Master Reader */
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start Serial for output
}

void loop()
{
  Wire.requestFrom(2, 7);    // request 7 bytes from slave device #2

  while(1 < Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }

  int x = Wire.read();
  Serial.println(x);

  delay(500);
}

/* Slave Writer */
/*
void setup()
{
  Wire.begin(2);
  Wire.onRequest(requestHandler);
}

byte num = 0;

void loop()
{
  delay(100);
}

// Function that executes whenever the master requests
// data from the slave
void requestHandler(int byteCount)
{
  Wire.write("Hello ");
  Wire.write(num);
  num++;
}
*/
