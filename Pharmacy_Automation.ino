/*
Ce223 236B
Pill Me 
1640900393 กฤตินี อรรถเวชกุล
1640902191 กฤติญาณี ครองสัตย์ 
1640902142 อรพรรณ หนองเทา
*/

#include <Servo.h>
Servo sv1;
int b1 = 4;
int b2 = 5;
int sensor = 12;                                          ;
int color[] = {9,10,11}; // Array
void green(); // Function สีเขียว
void red(); // Function สีแดง
void yellow(); // Function สีเหลือง

void setup() {

  for(int index = 0; index <= 3 ;index++) //  For Loop ประกาศค่า  Output
  {
  pinMode(color[index], OUTPUT);
  }

  pinMode(b1,INPUT);
  pinMode(b2,INPUT);

  analogWrite(color[0], 255); // ไปบอกสถานะเปิด สีน้ำเงิน
  analogWrite(color[1], 255);
  analogWrite(color[2], 0);
  delay(1000);

  sv1.attach(13); // ขา pin servo
  sv1.write(90); // เริ่มต้นที่ 90 องศา
  Serial.begin(9600);
}

void loop() { 

  int val = digitalRead(sensor); //รับค่าจาก Sensor
  Serial.print ("val : ");
  Serial.println(val);

delay(100);
if( val == 0) //เงื่อนไข ถ้ามีแก้ว
{  
  green(); // LCD สีเขียวติด

  if(digitalRead(b1)==HIGH) //เงื่อนไข ถ้าปุ่ม 1 กด
  {
    yellow(); // LCD สีเหลืองติด
    
  	sv1.write(0); // หมุนไปที่ 0 องศา
    Serial.println("0");
    delay(2000);
  }
  if(digitalRead(b1)==LOW) //เงื่อนไข ถ้าปุ่ม 1 ไม่ได้กด
  {
  	sv1.write(90); // หมุนไปที่ 90 องศา
  }
   if(digitalRead(b2)==HIGH) //เงื่อนไข ถ้าปุ่ม 2 กด
  {
    yellow(); // LCD สีเหลืองติด
    
  	sv1.write(180); // หมุนไปที่ 180 องศา
    Serial.println("180");
    delay(2000);
  }
  if(digitalRead(b2)==LOW) //เงื่อนไข ถ้าปุ่ม 2 ไม่ได้กด
  {
  	sv1.write(90); // หมุนไปที่ 90 องศา
  }
}else{ //เงื่อนไข ถ้าไม่มีแก้ว
  
  red(); // LCD สีแดงติด
  
  Serial.println("Cup please");
    delay(1000);
    }
}
void green()
{
  analogWrite(color[0], 255);
  analogWrite(color[1], 0);
  analogWrite(color[2], 255);
  delay(100);
}
void red()
{
  analogWrite(color[0], 0);
  analogWrite(color[1], 255);
  analogWrite(color[2], 255);
  delay(100);
}
void yellow()
{
  analogWrite(color[0], 0);
  analogWrite(color[1], 0);
  analogWrite(color[2], 255);
  delay(100);
}
