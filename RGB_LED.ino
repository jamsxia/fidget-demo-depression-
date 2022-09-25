void setup() {
  Serial.begin(9600); // 打开串口,用于打印调试信息，设置波特率为9600 bps

  pinMode(3, OUTPUT);               //设置红色LED灯引脚为输出模式
  pinMode(5, OUTPUT);               //设置绿色LED灯引脚为输出模式
  pinMode(6, OUTPUT);               //设置蓝色LED灯引脚为输出模式
  
  pinMode(9, OUTPUT);               //设置彩色LED灯引脚为输出模式
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  //分别读出三个模拟端口的数值，数据范围0-1024
  int sensorValue1 = analogRead(A0); //传感器接于模拟口0
  int sensorValue2 = analogRead(A1); //传感器接于模拟口1
  int sensorValue3 = analogRead(A2); //传感器接于模拟口2

  //处理读入数据，将R、G、B三个参数范围控制在0-255
  int Rvalue = sensorValue1 / 4;
  int Gvalue = sensorValue2 / 4;
  int Bvalue = sensorValue3 / 4;

  //在串口监视器中显示R、G、B三个参数值
  Serial.print("Rvalue = ");
  Serial.println(Rvalue);
  Serial.print("Gvalue = ");
  Serial.println(Gvalue);
  Serial.print("Bvalue = ");
  Serial.println(Bvalue);


  //分别显示三个单色
  analogWrite(3, Rvalue);
  analogWrite(5, Gvalue);
  analogWrite(6, Bvalue);

  //显示混合颜色
  analogWrite(9, Rvalue);
  analogWrite(10, Gvalue);
  analogWrite(11, Bvalue);

  delay(100); //延时100ms，让程序不要运行太快

}
