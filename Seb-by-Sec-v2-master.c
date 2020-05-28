const int D5 = 2; //1.เลี้ยวขวา
const int D6 = 3; //2.เลี้ยวซ้าย
const int D7 = 4; //3.ไฟหรี่
const int D8 = 5; //4.ไฟฉุกเฉิน
const int D9 = 6; //5.ไฟสูง
const int D10 = 7; //6.ไฟหน้า
const int D11 = 8; //7.ไฟเบรค
const int D12 = 9; //8.ที่ปัดน้ำฝน
const int D13 = 10; //9.แตร
const int D14 = 11; //10.เข็มขัด
const int D15 = 12; //11.
const int D16 = 13; //12.

int stateD5 = 1;
int stateD6 = 1;
int stateD7 = 1;
int stateD8 = 1;
int stateD9 = 1;
int stateD10 = 1;
int stateD11 = 1;
int stateD12 = 1;
int stateD13 = 1;
int stateD14 = 1;
int stateD15 = 1;
int stateD16 = 1;

String prev = "";

byte HEAD = 123; // 0x7B, {
byte TAIL = 126; // 0x7E, ~

void setup(){

  Serial.begin(9600);

  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D8, INPUT);
  pinMode(D9, INPUT);
  pinMode(D10, INPUT);
  pinMode(D11, INPUT);
  pinMode(D12, INPUT);
  pinMode(D13, INPUT);
  pinMode(D14, INPUT);
  pinMode(D15, INPUT);
  pinMode(D16, INPUT);
  
  prev = "";

}

void loop(){

  stateD5 = digitalRead(D5);// == HIGH ? LOW: HIGH;
  stateD6 = digitalRead(D6);// == HIGH ? LOW: HIGH;
  stateD7 = digitalRead(D7); //== HIGH ? LOW: HIGH;
  stateD8 = digitalRead(D8);// == HIGH ? LOW: HIGH;
  stateD9 = digitalRead(D9);// == HIGH ? LOW: HIGH;
  stateD10 = digitalRead(D10);// == HIGH ? LOW: HIGH;
  stateD11 = digitalRead(D11);// == HIGH ? LOW: HIGH;
  stateD12 = digitalRead(D12);// == HIGH ? LOW: HIGH;
  stateD13 = digitalRead(D13);// == HIGH ? LOW: HIGH;
  stateD14 = digitalRead(D14);// == HIGH ? LOW: HIGH;
  stateD15 = digitalRead(D15);
  stateD16 = digitalRead(D16);
  
  byte subcommand = 1;
  byte numInput = 12;
  String cur = "";
  cur = cur+stateD5+stateD6+stateD7+stateD8+stateD9+stateD10+stateD11+stateD12+stateD13+stateD14+stateD15+stateD16;

  if(!cur.equals(prev)){
    prev = cur;
    byte packet[] = {
      HEAD,
      subcommand,
      numInput,
      (byte)stateD5,
      (byte)stateD6,
      (byte)stateD7,
      (byte)stateD8,
      (byte)stateD9,
      (byte)stateD10,
      (byte)stateD11,
      (byte)stateD12,
      (byte)stateD13,
      (byte)stateD14,
      (byte)stateD15,
      (byte)stateD16,
      TAIL
    };
    Serial.write(packet, 16);
    
  }

  delay(1000);
}