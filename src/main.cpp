#include <WiFi.h>
#include <WiFiUDP.h>
#include <ArduinoJson.h>

const char ssid[] = "MeidenPad";       // TODO
const char pass[] = "MeideniPad@0311"; // TODO
static WiFiUDP wifiUdp;
static const char *raspberryIP = "10.151.40.4";
static const int raspberryPort = 9000; //送信先のポート

IPAddress remoteIP; // 相手のIPアドレス
int port;
DynamicJsonDocument doc(1024);

static void WiFi_setup()
{
  static const int kLocalPort = 7000; //自身のポート
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  wifiUdp.begin(kLocalPort);
}

static void Serial_setup()
{
  Serial.begin(115200);
  Serial.println(""); // to separate line
}

void setup()
{
  Serial_setup();
  WiFi_setup();
}

void loop()
{
  int count = 0;
  char data[64];

  while (1)
  {
    count++;

    //パケットの送信
    wifiUdp.beginPacket(raspberryIP, raspberryPort);
    wifiUdp.printf("Hello,server?");
    wifiUdp.endPacket();

    //パケットの受信
    if (wifiUdp.parsePacket())
    {
      wifiUdp.read(data, 64);
      remoteIP = wifiUdp.remoteIP();
      port = wifiUdp.remotePort();
      Serial.print("data : ");
      Serial.println(data); // UDP通信で来た値を表示

      deserializeJson(doc, F(data));
      JsonObject obj = doc.as<JsonObject>();
      int car_id = obj[F("car_id")];
      const char* start = obj[F("start")];

      Serial.print(car_id);
      Serial.print(" / ");
      Serial.println(start);
      Serial.println();
    }

    delay(3000);
  }
}