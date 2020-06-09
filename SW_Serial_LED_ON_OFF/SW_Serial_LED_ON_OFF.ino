#include <SoftwareSerial.h>

#define LedPin 7 

SoftwareSerial mySerial(2, 3); // RX, TX

char value;

void setup()  
{
  // HW Serial 초기화
  Serial.begin(9600);
  Serial.println("Goodnight moon!");

  // LED 설정
  pinMode(LedPin, OUTPUT); 
 
  // SW Serial 초기화
  mySerial.begin(9600);
}
 
void loop() // run over and over
{
  // 블루투스 디바이스(SW Serial)로 부터 데이터를 받아 PC(HW Serial)로 보냄
  if (mySerial.available())
    value = mySerial.read();
    if(value == '1') {
      digitalWrite(LedPin, HIGH);
      Serial.println("LED ON");
    } else if(value == '0'){
      digitalWrite(LedPin, LOW);
      Serial.println("LED OFF");
    }
}
