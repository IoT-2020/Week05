int swCount = 0;   //스위치 동작 횟수 저장용 변수
int swInput = 7;   // 7번핀을 스위치 입력을 사용

void setup() {
  pinMode(swInput, INPUT);  // swInput 핀 입력모드로 설정 
  Serial.begin(9600); //통신속도 9600으로 하드웨어 시리얼 초기화
  //Serial 포트가 준비될 때까지 대기
  while (!Serial) // Seiral port가 준비되지 않았으면
    ;             // 하는 일 없이 대기.(준비되면 while 종료)
  Serial.println("시리얼 통신 준비 완료!"); //PC에 통신준비 되었음을 알림.
}

void serialEvent() {
  if (Serial.available() > 0) {
    if (Serial.read() == 'C') {
       swCount = 0;  //스위칭 횟수 값을 0으로 초기화
       Serial.println("스위치 누른 회수: 0 으로 초기화");
    } 
  }
}
void loop() {
  if (digitalRead(swInput) == HIGH) { //스위치가 눌러졌으면
    swCount = swCount + 1;  // 누른 횟수 1 증가
    Serial.print("스위치 누른 횟수: ");
    Serial.println(swCount);  //swCount 값 전송
    delay(300); // delay(300)을 생략한 경우 동작 확인.
  }
}
