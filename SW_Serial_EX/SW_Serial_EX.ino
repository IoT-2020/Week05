#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(2, 3); // RX, TX
 
void setup()  
{
  // HW Serial 초기화
  Serial.begin(9600);
  Serial.println("Goodnight moon!");
 
  // SW Serial 최기화
  mySerial.begin(9600);
}
 
void loop() // run over and over
{
  // 블루투스 디바이스(SW Serial)로 부터 데이터를 받아 PC(HW Serial)로 보냄
  if (mySerial.available())
    Serial.write(mySerial.read());
 
  // PC로 부터 데이터를 받아 블루투스 디바이스로 보냄
  if (Serial.available())
    mySerial.write(Serial.read());
}
