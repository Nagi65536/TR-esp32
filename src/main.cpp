#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 26
#define SS_PIN 5
#define MISO_PIN 19
#define MOSI_PIN 23
#define SCK_PIN 18

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance
int count = 0;

void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void setup()
{
  Serial.begin(115200); // Initialize serial communications with the PC
  Serial.println("Hello!!");
  while (!Serial); // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  Serial.println("Hello!!");
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN);
  mfrc522.PCD_Init(); // Init MFRC522
  delay(4);           // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop()
{
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  Serial.print(count);
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();
  count++;
}