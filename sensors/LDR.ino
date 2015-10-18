//analogReference() - Configures the ref volt
//analogRead(PIN) - Read the value form analog sensors

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

float potPin = A1;
float potValue1 = 0;
float potValue2 = 0;

void setup() {
  lcd.begin(16,2);
  lcd.print("Luminosity");
  pinMode(6, OUTPUT);
}

void loop() {
  potValue1 = analogRead(A0);
  potValue2 = potValue1 *5/340;
  lcd.setCursor(0,1);
  lcd.print(potValue2);
  delay(100);

  if(potValue2 > 5000){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6,LOW);
    delay(100);
    digitalWrite(6, HIGH);
    lcd.setCursor(0,0);
    lcd.print("....Stay away...Aye!");
    lcd.scrollDisplayLeft();

  }
  else {
    digitalWrite(6,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Luminosity");
    lcd.setCursor(0,1);
    lcd.print(potValue2);

  }  
}

