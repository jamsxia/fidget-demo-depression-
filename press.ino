//薄膜压力传感器

int press_value = 0;          //定义压力传感器原始输入值
int actuator_value = 0;       //定义执行器输出数值

void setup() {
  Serial.begin(9600);         //设置波特率为9600
  pinMode(9,OUTPUT);          //LED灯或者蜂鸣器引脚
}

void loop() {
  
  press_value = analogRead(A0);       //读压力传感器数值
       
//  press_value = 1000 - press_value;   //规范范围，使压力传感器输入的值变换到0-255区间中
//  actuator_value = press_value / 3;        
//  if (actuator_value > 255)               
//    actuator_value = 255;
//  if (actuator_value < 0)
//    actuator_value = 0;

  actuator_value = map(press_value,1024,0,0,255);
  
  Serial.println(actuator_value);          //输出调试信息
  analogWrite(9,actuator_value);          //让LED灯或者蜂鸣器响应
 
  delay(50);                          //让程序不要跑太快
}
