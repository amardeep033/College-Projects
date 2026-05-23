#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int R1=2;
const int R2=4;
const int R3=6;
const int R4=A0;

const int G1=3;
const int G2=5;
const int G3=7;
const int G4=A1;

const int IR=A2;
const int RAIN=A3;

const int modee=A5;



String inputString="";

void setup() {
  // put your setup code here, to run once:
pinMode(R1,OUTPUT);
pinMode(R2,OUTPUT);
pinMode(R3,OUTPUT);
pinMode(R4,OUTPUT);

pinMode(G1,OUTPUT);
pinMode(G2,OUTPUT);
pinMode(G3,OUTPUT);
pinMode(G4,OUTPUT);
pinMode(RAIN,INPUT);
pinMode(IR,INPUT);
pinMode(modee,INPUT);



digitalWrite(R1,LOW);
digitalWrite(R2,LOW);
digitalWrite(R3,LOW);
digitalWrite(R4,LOW);

digitalWrite(G1,LOW);
digitalWrite(G2,LOW);
digitalWrite(G3,LOW);
digitalWrite(G4,LOW);

digitalWrite(R1,HIGH);
digitalWrite(R2,HIGH);
digitalWrite(R3,HIGH);
digitalWrite(R4,HIGH);
digitalWrite(G1,LOW);
digitalWrite(G2,LOW);
digitalWrite(G3,LOW);
digitalWrite(G4,LOW);
delay(1000);

Serial.begin(1200);
lcd.begin(16,2);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TRAFFIC TWO ");
      lcd.setCursor(0,1);
      lcd.print("SIDE");
      delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly:
/*  while (Serial.available())
  {
    if(Serial.available())
  {  
inputString=Serial.readString();
Serial.println(inputString);
  }}}*/
while(1)
{
  if(digitalRead(modee)==HIGH)
  {
  while (Serial.available())
  {
    if(Serial.available())
  {  
inputString=Serial.readString();

  if(inputString.substring(0,1)=="N")
  {
  inputString="";
    digitalWrite(R1,LOW);//1
digitalWrite(R2,HIGH);
digitalWrite(R3,HIGH);
digitalWrite(R4,HIGH);
digitalWrite(G1,HIGH);
digitalWrite(G2,LOW);
digitalWrite(G3,LOW);
digitalWrite(G4,LOW);
lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NORTH SIDE ");
      lcd.setCursor(0,1);
      lcd.print("AMBULANCE COMING");Serial.print("AMBULANCE AT TRAFFIC TWO");
      
delay(5000);
     
      }
  if(inputString.substring(0,1)=="S")
  {
  inputString="";
digitalWrite(R1,HIGH);//2
digitalWrite(R2,LOW);
digitalWrite(R3,HIGH);
digitalWrite(R4,HIGH);
digitalWrite(G1,LOW);
digitalWrite(G2,HIGH);
digitalWrite(G3,LOW);
digitalWrite(G4,LOW);
lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SOUTH SIDE ");
      lcd.setCursor(0,1);
      lcd.print("AMBULANCE COMING");Serial.print("AMBULANCE AT TRAFFIC TWO");
delay(5000);
      }

  if(inputString.substring(0,1)=="E")
  {
  inputString="";
 digitalWrite(R1,HIGH);//3
digitalWrite(R2,HIGH);
digitalWrite(R3,LOW);
digitalWrite(R4,HIGH);
digitalWrite(G1,LOW);
digitalWrite(G2,LOW);
digitalWrite(G3,HIGH);
digitalWrite(G4,LOW);
lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("EAST SIDE ");
      lcd.setCursor(0,1);
      lcd.print("AMBULANCE COMING");Serial.print("AMBULANCE AT TRAFFIC TWO");
delay(5000);
      }

  if(inputString.substring(0,1)=="W")
  {
  inputString="";
digitalWrite(R1,HIGH);//4
digitalWrite(R2,HIGH);
digitalWrite(R3,HIGH);
digitalWrite(R4,LOW);
digitalWrite(G1,LOW);
digitalWrite(G2,LOW);
digitalWrite(G3,LOW);
digitalWrite(G4,HIGH);
lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("WEST  SIDE ");
      lcd.setCursor(0,1);
      lcd.print("AMBULANCE COMING");Serial.print("AMBULANCE AT TRAFFIC TWO");
delay(5000);
     
      }
}
  }



digitalWrite(R1,LOW);//1
digitalWrite(R2,HIGH);
digitalWrite(R3,HIGH);
digitalWrite(R4,HIGH);
digitalWrite(G1,HIGH);
digitalWrite(G2,LOW);
digitalWrite(G3,LOW);
digitalWrite(G4,LOW);
delay(1000);

digitalWrite(R1,HIGH);//2
digitalWrite(R2,LOW);
digitalWrite(R3,HIGH);
digitalWrite(R4,HIGH);
digitalWrite(G1,LOW);
digitalWrite(G2,HIGH);
digitalWrite(G3,LOW);
digitalWrite(G4,LOW);
delay(1000);

digitalWrite(R1,HIGH);//3
digitalWrite(R2,HIGH);
digitalWrite(R3,LOW);
digitalWrite(R4,HIGH);
digitalWrite(G1,LOW);
digitalWrite(G2,LOW);
digitalWrite(G3,HIGH);
digitalWrite(G4,LOW);
delay(1000);

digitalWrite(R1,HIGH);//4
digitalWrite(R2,HIGH);
digitalWrite(R3,HIGH);
digitalWrite(R4,LOW);
digitalWrite(G1,LOW);
digitalWrite(G2,LOW);
digitalWrite(G3,LOW);
digitalWrite(G4,HIGH);
delay(1000);

}
if(digitalRead(modee)==LOW)
{
rain_read();
ir_read();
}
}
}
void rain_read()
{
  if(digitalRead(RAIN)==LOW)
  {
   
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" RAIN DETCTED");
      lcd.setCursor(0,1);
      lcd.print("WAY BLOCK");
      Serial.println("RAIN DETECTED UNDERGROUND WAY BLOCK");
      delay(2000);
   
    
    }
  if(digitalRead(RAIN)==HIGH)
  {
    lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" NO RAIN");
      lcd.setCursor(0,1);
      lcd.print("DETECTED");
      Serial.println("NO RAIN DETECTED");
      delay(2000);
   
    
    }
  
  }
  void ir_read()
{
  if(digitalRead(IR)==LOW)
  {
   
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" WORK IN ");
      lcd.setCursor(0,1);
      lcd.print("PROGRESS WAY BLOCK");
      Serial.println(" WORK IN PROGRESS WAY BLOCK");
      delay(2000);
   
    
    }
  if(digitalRead(IR)==HIGH)
  {
    lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" ALL GOOD");
      lcd.setCursor(0,1);
      lcd.print("");
      Serial.println("NO RAIN DETECTED");
      delay(2000);
   
    
    }
  
  }
