int inByte;   //시리얼 통신으로 수신된 데이터 저장용 변수

void setup() {
  Serial.begin(9600); //통신속도 9600으로 하드웨어 시리얼 초기화
}

void loop() {
  if (Serial.available() > 0) {   //수신된 데이터가 있으면
    
    inByte = Serial.read();       //수신 버퍼에서 1바이트 읽음

    Serial.print("수신 데이터: ");//읽은 1바이트를
    Serial.write(inByte);
  //  Serial.println(inByte, DEC);  //PC로 다시 전송 (10진수)
  //Serial.println(inByte, BIN);   //2진수로 전송
  //Serial.println(inByte, HEX);   //16진수로 전송
  }
}
