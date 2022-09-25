void setup() {
  pinMode(2,INPUT);     //数字2口读入摇杆的按键值
  pinMode(9,OUTPUT);    //RGB LED灯 R值输出口
  pinMode(10,OUTPUT);   //RGB LED灯 G值输出口
  pinMode(11,OUTPUT);   //RGB LED灯 B值输出口
  Serial.begin(9600);   //串口波特率9600
}

void loop() {
  
  int X = 0;        //初始化摇杆数据X的读入值 范围：0-1023
  int Y = 0;        //初始化摇杆数据X的读入值 范围：0-1023
  int Button = 0;   //初始化摇杆按键的值 范围：0或1
  
  int Rvalue = 0;   //初始化RGB LED灯 R 值
  int Gvalue = 0;   //初始化RGB LED灯 G 值
  int Bvalue = 0;   //初始化RGB LED灯 B 值
  
  X = analogRead(A0);   //读摇杆X的值
  Y = analogRead(A1);   //读摇杆X的值
  Button = digitalRead(2);    //读摇杆按键的值
  
  Serial.print("X = ");      //在串口中输出X、Y、Button的值，用于调试
  Serial.print(X);
  Serial.print(";  Y = ");
  Serial.print(Y);
  Serial.print(";  Button = ");
  Serial.println(Button);

  Rvalue = X / 4;         //计算R、G、B三个颜色值
  Gvalue = Y / 4;
  Bvalue = Button * 128;

  analogWrite(9,Rvalue);    //显示R、G、B三个颜色
  analogWrite(10,Gvalue);
  analogWrite(11,Bvalue);
  
  delay(10);

}
