#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,2,3,4,5);

#define sensor A0
#define led 9
#define buz 9                            
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Alcohol Detector");
  lcd.setCursor(0,1);
  lcd.print(" Circuit Digest ");
  delay(2000);
pinMode(led, OUTPUT);//sets the pin as an output of the arduino

pinMode(12,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
digitalWrite(12,HIGH);
  pinMode(sensor, INPUT);
 
  pinMode(led, OUTPUT);
  lcd.clear();
  
}

void loop() 
{
  float adcValue=0;
  for(int i=0;i<10;i++)
  {
    adcValue+= analogRead(sensor);
    delay(10);
  }
    float v= (adcValue/10) * (5.0/1024.0);
    float mgL= 0.67 * v;
    Serial.print("BAC:");
    Serial.print(mgL);
    Serial.print(" mg/L");
    lcd.setCursor(0,0);
    lcd.print("BAC: ");
    lcd.print(mgL,4);
    lcd.print(" mg/L        ");
    lcd.setCursor(0,1);
   
    if(mgL > 1)
    { 
      lcd.print("Drunk   ");
      Serial.println("    Drunk");
      digitalWrite(buz, HIGH);
      digitalWrite(led, HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
    }
    else if(mgL<1)
    {
      lcd.print("Normal  ");
      Serial.println("    Normal");
      digitalWrite(buz, LOW);
      digitalWrite(led, LOW);
      digitalWrite(10,HIGH); 
      digitalWrite(11,LOW);
    }

    delay(100);
    
}
