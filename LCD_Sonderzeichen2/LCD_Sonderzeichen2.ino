#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Erzeugt ein Objekt vom Typ LiquidCrystal_I2C
// I2C Adresse = 0x3F, 16 Zeichen, 2 Zeilen
LiquidCrystal_I2C lcd(0x3F,16,2);  

// Sonderzeichen defineren
uint8_t myLcdChar[8]  = {0b00000,
                         0b11011,
                         0b11011,
                         0b00000,
                         0b00100,
                         0b00000,
                         0b01110,
                         0b10001};


// Sonderzeichen defineren
uint8_t myLcdChar1[8]  = {0b00000,
                         0b11011,
                         0b11011,
                         0b00000,
                         0b00100,
                         0b10001,
                         0b01110,
                         0b00000};

void setup()
{
  // LCD initialisieren
  lcd.init();                  
 
  // Hintergrundbeleuchtung aktivieren
  lcd.backlight();

  // Sonderzeichen 0 in das CG
  lcd.createChar(0, myLcdChar);
  
  // Sonderzeichen 1 in das CG
  lcd.createChar(1, myLcdChar1);
  



}

void loop()
{
    // Cursor auf die 1. Spalte und 1. Reihe setzten
  lcd.setCursor(0,0);
  
  // Sonderzeichen 0 ausgeben
  lcd.write(0);
  delay(500);
  
  // Cursor auf die 1. Spalte und 1. Reihe setzten
  lcd.setCursor(0,0);
  
  lcd.write(1);
  delay(500);

      // Cursor auf die 1. Spalte und 1. Reihe setzten
  lcd.setCursor(1,0);
  
  // Sonderzeichen 0 ausgeben
  lcd.write(0);
  delay(500);
  
  // Cursor auf die 1. Spalte und 1. Reihe setzten
  lcd.setCursor(1,0);
  
  lcd.write(1);
  delay(500);
  
}
