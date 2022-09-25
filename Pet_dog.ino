#include "SR04.h"
#define TRIG_PIN 2
#define ECHO_PIN 3
SR04 mysr04 = SR04(ECHO_PIN,TRIG_PIN);

void setup() {
  pinMode(5,INPUT);           //鼻子触摸端口
  pinMode(6,INPUT_PULLUP);    //舌头微动端口
  pinMode(9,OUTPUT);          //振动传感器端口
  Serial.begin(9600);
  delay(1000);
}

void loop() {
 int a = mysr04.Distance();   //超声波距离
 int b = digitalRead(5);      //鼻子开关读数
 int c = digitalRead(6);      //舌头开关读数

 Serial.print(a);
 Serial.println("cm");
 
 if(c == 0){
  //舌头被按压，振动传感器振动
  analogWrite(9,200);  //传感器振动
  delay(400);
  analogWrite(9,0);
 }else if(b == 0){
  //鼻子被触摸，振动传感器有频率的振动
  for(int i=0;i<100;i++){
    analogWrite(9,i);
    delay(15);
  }
  for(int i = 100;i >= 0;i--){
    analogWrite(9,i);
    delay(5);
  }
 }else if(a < 10 && a>0){
  //如果靠近超声波传感器，振动传感器模拟狗叫
  analogWrite(9,255);
  delay(300);
  analogWrite(9,0);
  delay(700);
 }

 Serial.print("a=");
 Serial.print(a);
 Serial.println("cm");
 Serial.print("b=");
 Serial.print(b);
 Serial.println("");
 Serial.print("c=");
 Serial.print(c);
 Serial.println("");
 //delay(50); 
}
