#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Erzeugt ein Objekt vom Typ LiquidCrystal_I2C
// I2C Adresse = 0x3F, 16 Zeichen, 2 Zeilen
LiquidCrystal_I2C lcd(0x3F,16,2); 

// Sonderzeichen defineren
uint8_t myLcdChar[8]  = {0x04,
                         0x0E,
                         0x1F,
                         0x04,
                         0x04,
                         0x1F,
                         0x0E,
                         0x04};

void setup()
{
  // LCD initialisieren
  lcd.init();                  
 
  // Hintergrundbeleuchtung aktivieren
  lcd.backlight();

  // Sonderzeichen 0 in das CG
  lcd.createChar(0, myLcdChar);

  
  // Cursor auf die 1. Spalte und 1. Reihe setzen
  lcd.setCursor(0,0);

  // Sonderzeichen 0 ausgeben
  lcd.write(0);
}

void loop()
{
}
