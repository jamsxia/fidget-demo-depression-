#include"LedControl.h"

LedControl Ic = LedControl(12, 11, 10, 1);
unsigned long time;           //系统计时
unsigned long start_time;     //计时开始时间
unsigned long d_time;         //计时时长
unsigned long temp_time;         //计时时长
boolean isStart = true;


void setup()
{
  Serial.begin(9600);
  delay(500);
  Ic.shutdown(0, false);
  Ic.setIntensity(0, 15);
  Ic.clearDisplay(0);             //用于数码管的配置

  pinMode(5, INPUT);              //配置按键为5号引脚，模式为输入模式
}




void loop() {
  if (digitalRead(5) == HIGH) {
    if (isStart == true) {
      start_time = millis();            //设置开始时间
      isStart = false;                  //下一次按键设置为结束
      Serial.println("计时开始：");
      Ic.clearDisplay(0);
      while (digitalRead(5));           //消除按键延时
    } else {
      d_time = millis() - start_time;   //计算时间差
      isStart = true;                   //下一次按键设置为开始
      Serial.print("计时结束： ");
      Serial.println(d_time);
      
      display_second(d_time);        //显示数字

      while (digitalRead(5));           //消除按键延时

      if (d_time > 950 && d_time < 1050) {
        display_666();                  //达到目标后，显示666
        display_second(d_time);        //显示数字
      }
      
    }
  }

  delay(5);         //延时5s
}

void displaynumber(void)
{
  Ic.setChar(0, 0, 6, false);
  Ic.setChar(0, 1, 6, false);
  Ic.setChar(0, 2, 6, false);
  Ic.setChar(0, 3, 6, false);
  Ic.setChar(0, 4, 6, false);
  Ic.setChar(0, 5, 6, false);
  Ic.setChar(0, 6, 6, false);
  Ic.setChar(0, 7, 6, false);
}


void display_666() {
  delay(1000);
  displaynumber();
  delay(300);
  Ic.clearDisplay(0);
  delay(300);
  displaynumber();
  delay(300);
  Ic.clearDisplay(0);
  delay(300);
  displaynumber();
  delay(300);
  Ic.clearDisplay(0);
  delay(300);
  displaynumber();
  delay(300);
  Ic.clearDisplay(0);
  delay(300);
}

void display_second(unsigned long temp_time) {
  int pos = 0;
  Ic.clearDisplay(0);
  while (temp_time) {
    Serial.println(temp_time % 10);
    if (pos == 3) {
      Ic.setChar(0, pos, temp_time % 10 , true);
    } else {
      Ic.setChar(0, pos, temp_time % 10 , false);
    }
    temp_time /= 10;
    pos++;
  }
}
