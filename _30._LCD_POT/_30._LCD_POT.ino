#include <LiquidCrystal.h>

int time = 0;

LiquidCrystal lcd(2,3,7,6,5,4);

void setup()   
{
  lcd.begin(16,2);
}

void loop()
{   
   lcd.print("Bismillah");
   delay(5000);
   lcd.setCursor(0,1);
   //lcd.print(time);
   //delay(1000);
}
