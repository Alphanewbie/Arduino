#include <LiquidCrystal.h>        // LiquidCrystal.h 라이브러리를 포함한다.

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);       // LCD가 연결된 핀을 설정한다.

int trig = 7;           // 변수 trig를 생성하고 9를 대입한다
int echo = 6;          // 변수 echo를 생성하고 8을 대입한다
int led = 8;
int PIR = 9;     // 정수형 변수 PIR를 생성하고 9를 대입한다.
int val = 0;      // 정수형 변수 val를 생성하고 0을 대입한다.
int person=0;
int con=0;

String S_E;

// 시작했을때 시작했음을 알리고, 입력 출력 핀들을 정한다.
void setup() {       
    unsigned long prev_time = 0;

    lcd.begin(16, 2);                      // LCD의 크기를 설정한다.
    lcd.print("hello, world!");  
    Serial.begin(9600);         

    pinMode(trig, OUTPUT);  // trig(2)핀을 출력모드로 설정한다
    pinMode(echo, INPUT);  // echo(3)핀을 입력모드로 설정한다 
    pinMode(8, OUTPUT);
    pinMode(PIR, INPUT);         // PIR(9)핀을 입력모드로 설정 

}

// 시작 이후에 계속 반복할 부분
void loop() {                                
//lcd.print(distance);
//lcd.print("cm");   // 문자열 cm을 출력하고 줄바꿈
    val=digitalRead(PIR);
    if(val==HIGH) {
        unsigned long current_time = millis();

        unsigned long prev_time = current_time;

        while(current_time - prev_time < 3000) {
            digitalWrite(trig, HIGH);  // trig(2)핀에 HIGH신호를 보낸다
            delayMicroseconds(10);  // 10마이크로초(1/100,000초) 동안
            digitalWrite(trig, LOW);  // trig(2)핀에 LOW신호를 보낸다
            int distance = pulseIn(echo, HIGH) * 17 / 1000;
            if(distance<15) {
                person=person-1;
            break;
            }
            current_time = millis();
        }
    }

    digitalWrite(trig, HIGH);  // trig(2)핀에 HIGH신호를 보낸다
    delayMicroseconds(10);  // 10마이크로초(1/100,000초) 동안
    digitalWrite(trig, LOW);  // trig(2)핀에 LOW신호를 보낸다

    int distance = pulseIn(echo, HIGH) * 17 / 1000; 
    // 변수 distance = echo핀이 다시 HIGH신호를 받기까지의 시간 * 17/1000
    if(distance<15) {

    unsigned long current_time = millis();
    unsigned long prev_time = current_time;
    while(current_time - prev_time < 3000) {
        val=digitalRead(PIR);
            if(val==HIGH) {      
                person=person+1;
                break;
            }
        current_time = millis();
        }
    }

    if(Serial.available()>0) {
        con=Serial.parseInt();

        if(con!=0){
            person=con;
        }
    }   

    if(person<0) person=0;
    lcd.clear();
    lcd.print("person :");
    lcd.print(person);
    Serial.print("person :");
    Serial.println(person);
    if(person>0) {
        digitalWrite(led,HIGH);
    }
    if(person==0) {
        digitalWrite(led,LOW);
    }
    delay(2000); // 딜레이 0.5초
} 