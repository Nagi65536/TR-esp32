#include <Arduino.h>

#define HALL_PIN 25

void setup()
{
  pinMode(HALL_PIN, ANALOG);
  Serial.begin(115200);
}

void loop()
{
  Serial.println(analogRead(HALL_PIN));
  delay(100);
}