#include<LiquidCrystal.h>

LiquidCrystal lcd(11,10,5,4,3,2);

const int currentPin = A0;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;
 
void setup() 
{
  lcd.begin(16,2);
}
 
void loop()
{
  
  adcValue = analogRead(currentPin); // 0-1024
  adcVoltage = (adcValue / 1024.0) * 5000; 
  currentValue = ( (adcVoltage - offsetVoltage) / sensitivity );
  int loadvoltage = currentValue * 12;
  int power = loadvoltage*currentValue*currentValue;
  

  lcd.print("Current = ");
  lcd.print(currentValue,2);
  lcd.print(" A");
  lcd.setCursor(0,1);
  lcd.print("Voltage = ");
  lcd.print(loadvoltage);
  lcd.print(" V");
  lcd.setCursor(0,0);

  delay(800);

  lcd.print("Power = ");
  lcd.print(power);
  lcd.print(" Watt       ");
  lcd.setCursor(0,1);
  lcd.print("                     ");
  lcd.setCursor(0,0);
  
  delay(1000);
}
