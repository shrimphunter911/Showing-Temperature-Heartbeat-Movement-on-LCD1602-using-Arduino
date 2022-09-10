
#include <Wire.h>
#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
   double a=0.75;
   double r=0.0;
   
void setup(void)
{
   pinMode(A1,INPUT);
   lcd.begin(16,2);
   lcd.clear();
   lcd.setCursor(0,0);
}

void loop(void)
{
   static double oV=0;
   static double oR=0;
 
   int beat=analogRead(A1);
  
   double heartvalue=a*oV+(0-a)*beat;
   r=heartvalue-oV;
  
  
 
   lcd.setCursor(0,0);
   lcd.print("Heart Beat"); 
   lcd.setCursor(0,1);
   lcd.print("          ");
   lcd.setCursor(0,1); 
   lcd.print(beat/10);
   oV=heartvalue;
   oR=r;
   delay(200);

  
}
