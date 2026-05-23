#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 

const int SWN=4;
const int SWS=5;
const int SWE=6;
const int SWW=7;

const int HOS1=2;
const int HOS2=3;

const int LED1=A0;
const int LED2=A1;

void setup() {
  // put your setup code here, to run once:
pinMode(SWN,INPUT);
pinMode(SWS,INPUT);
pinMode(SWE,INPUT);
pinMode(SWW,INPUT);
pinMode(HOS1,INPUT);
pinMode(HOS2,INPUT);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);

digitalWrite(SWN,LOW);
digitalWrite(SWS,LOW);
digitalWrite(SWE,LOW);
digitalWrite(SWW,LOW);
digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
Serial.begin(1200);
lcd.begin(16,2);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("AMBULANCE SIDE");
      lcd.setCursor(0,1);
      lcd.print("SENDING DATA");
      delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(SWN)==HIGH)
{
  
  Serial.println("N");delay(500);
   Serial.println("N");delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NORTH SIDE");
      lcd.setCursor(0,1);
      lcd.print("SENDING DATA");
      delay(1000);
  /*Serial.println("N");delay(500);
  Serial.println("N");delay(500);
  Serial.println("N");
delay(500);*/
}
if(digitalRead(SWS)==HIGH)
{
  
  Serial.println("S");delay(500);
 // Serial.println("S");delay(500);
 // Serial.println("S");delay(500);
 // Serial.println("S");
//delay(500);
lcd.begin(16,2);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SOUTH SIDE");
      lcd.setCursor(0,1);
      lcd.print("SENDING DATA");
      delay(1000);
}
if(digitalRead(SWE)==HIGH)
{
  
  Serial.println("E");delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("EAST SIDE");
      lcd.setCursor(0,1);
      lcd.print("SENDING DATA");
      delay(1000);
//  Serial.println("E");delay(500);
//  Serial.println("E");delay(500);
//  Serial.println("E");
//delay(500);
}
if(digitalRead(SWW)==HIGH)
{
  
  Serial.println("W");delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("WEST SIDE");
      lcd.setCursor(0,1);
      lcd.print("SENDING DATA");
      delay(1000);;
  
 // Serial.println("W");delay(500);
//  Serial.println("W");delay(500);
 // Serial.println("W");
//delay(500);
}
if(digitalRead(HOS1)==HIGH)
{
  
       lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("HOSPITAL1 RESPONDED");
      lcd.setCursor(0,1);
      lcd.print("TAKE THERE");digitalWrite(LED1,HIGH);
      delay(1000);;
  
 // Serial.println("W");delay(500);
//  Serial.println("W");delay(500);
 // Serial.println("W");
//delay(500);
}
if(digitalRead(HOS1)==LOW)
{
  
       lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NO RESPONE");
      lcd.setCursor(0,1);
      lcd.print("");digitalWrite(LED1,LOW);
      delay(1000);;
  
 // Serial.println("W");delay(500);
//  Serial.println("W");delay(500);
 // Serial.println("W");
//delay(500);
}
if(digitalRead(HOS2)==HIGH)
{
  
       lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("HOSPITAL2 RESPONE");
      lcd.setCursor(0,1);
      lcd.print("TAKE THERE");digitalWrite(LED2,HIGH);
      delay(1000);;
  
 // Serial.println("W");delay(500);
//  Serial.println("W");delay(500);
 // Serial.println("W");
//delay(500);
}
if(digitalRead(HOS2)==LOW)
{
  
       lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NO RESPONE");
      lcd.setCursor(0,1);
      lcd.print("");digitalWrite(LED2,LOW);
      delay(1000);;
  
 // Serial.println("W");delay(500);
//  Serial.println("W");delay(500);
 // Serial.println("W");
//delay(500);
}

}
