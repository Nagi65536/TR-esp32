#include <Arduino.h>
#include <ESP32Servo.h>

Servo servo; //Servoオブジェクトを作成

void setup() {
  servo.attach(15); //PWMの制御線をD15以外に接続している場合はここの数字を変更する

}

void loop() {
  servo.write(20); //サーボモータの角度を20度に設定
  delay(2000); //2秒待機
  servo.write(160); //サーボモータの角度を160度に設定
  delay(2000); //2秒待機
}