#include<Wire.h>
const int MPU=0x68; 
int16_t AcX,AcY,AcZ;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read();
  AcY=Wire.read();
  AcZ=Wire.read();

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ); 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Accelerometer:  "):
  lcd.setCursor(0, 1);
  lcd.print("X="); lcd.print(AcX);
  lcd.print("||Y="); lcd.print(AcY);
  lcd.print("||Z="); lcd.print(AcZ);
  delay(1000);
}
