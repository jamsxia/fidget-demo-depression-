  
/*
OpenJumper
蜂鸣器+触摸模块 制作简易电子琴  
奈何col
*/
#include "pitches.h"            //引入音调函数
int mode = 0;                   //设置播放模式
 
void setup() {
  pinMode(2,INPUT);             //设置七个按键引脚为输入模式
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
}
 
void loop() {
  if(mode == 0){                //模式0为弹钢琴模式
    if(digitalRead(2)){
      tone(10, NOTE_C5, 10);    //使用tone函数发出对应音调
    }
    if(digitalRead(3)){
      tone(10, NOTE_D5, 10); 
    }
    if(digitalRead(4)){
      tone(10, NOTE_E5, 10);
    }
    if(digitalRead(5)){
      tone(10, NOTE_F5, 10);
    }
    if(digitalRead(6)){
      tone(10, NOTE_G5, 10);
    }
    if(digitalRead(7)){
      tone(10, NOTE_A5, 10);
    }
    if(digitalRead(8)){
      tone(10, NOTE_B5, 10);
    }
  }else if(mode == 1){        //模式1为放音乐
    play();
  }
}

int melody[] = {
NOTE_G4,//5  
NOTE_G4,//5
NOTE_A4,//6
NOTE_G4,//5
NOTE_C5,//1.
NOTE_B4,//7
0,
NOTE_G4,//5
NOTE_G4,//5
NOTE_A4,//6
NOTE_G4,//5
NOTE_D5,//2.
NOTE_C5,//1.
0,
NOTE_G4,//5
NOTE_G4,//5
NOTE_G5,//5.
NOTE_E5,//3.
NOTE_C5,//1.
NOTE_B4,//7
NOTE_A4,//6
0,
NOTE_F5,//4.
NOTE_F5,//4.
NOTE_E5,//3.
NOTE_C5,//1.
NOTE_D5,//2.
NOTE_C5,//1.
0,
};

int noteDurations[] = {
  8,8,4,4,4,4,
  4,
  8,8,4,4,4,4,
  4,
  8,8,4,4,4,4,2,
  8,
  8,8,4,4,4,2,
  4,
};

void play()
{
    for (int thisNote = 0; thisNote < 29; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(10, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
