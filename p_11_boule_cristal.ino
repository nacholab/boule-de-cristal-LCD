#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Demandez a la ");
  lcd.setCursor(0,1);
  lcd.print("boule de magie ! ");
}

void loop() {
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState)
  {
    if(switchState == LOW)
    {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("La boule dit : ");
      lcd.setCursor(0,1);
      switch (reply)
      {
      case 0:
        lcd.print("Oui");
        break;
      case 1:
        lcd.print("Problablement");
        break;
      case 2:
        lcd.print("Certainement");
        break;
      case 3:
        lcd.print("Sans doute");
        break;
      case 4:
        lcd.print("Pas sur");
        break;
      case 5:
        lcd.print("Redemande");
        break;
      case 6:
        lcd.print("J'en doute");
        break;
      case 7:
        lcd.print("Non");
        break;
      default:
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
