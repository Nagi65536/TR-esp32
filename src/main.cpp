#include <Arduino.h>

uint8_t HALL_PIN = 23;

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(HALL_PIN, INPUT);
  Serial.begin(115200);
}

void loop()
{
  Serial.println(digitalRead(HALL_PIN));
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
}