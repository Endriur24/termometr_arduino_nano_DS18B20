
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 6
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(2, 0);
  lcd.print("Pomiar temp.");
  sensors.begin();
}

void loop() {
  delay(100);
  sensors.requestTemperatures();
  lcd.setCursor(5, 1);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.setCursor(10, 1);
  lcd.print((char)223);
  lcd.setCursor(11, 1);
  lcd.print("C");
 
  

  
}

