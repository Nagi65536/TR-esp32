#include <Arduino.h>
#include <ArduinoJson.h>

void setup()
{
  Serial.begin(115200);
  DynamicJsonDocument doc(1024);

  deserializeJson(doc, F("{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}"));
  JsonObject obj = doc.as<JsonObject>();

  long time = obj[F("time")];
  const char* sensor = obj[F("sensor")];
  obj[F("time")] = time;

  while (true)
  {
  Serial.println(sensor);
  delay(1000);
  }
}

void loop()
{
  // not used in this example
}