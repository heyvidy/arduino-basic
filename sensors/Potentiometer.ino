//analogReference() - Configures the ref volt
//analogRead(PIN) - Read the value form analog sensors

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

float potPin = A0;
float potValue1 = 0;
float potValue2 = 0;

void setup() {
  lcd.begin(16,2);
  lcd.print("POTENTIOMETER");
}

void loop() {
  potValue1 = analogRead(A0);
  potValue2 = potValue1 *5/1024;
  lcd.setCursor(0,1);
  lcd.print(potValue2);
  delay(100);
 
}
