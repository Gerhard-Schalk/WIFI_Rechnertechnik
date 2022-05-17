#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Erzeugt ein Objekt vom Typ LiquidCrystal_I2C
// I2C Adresse = 0x3F, 16 Zeichen, 2 Zeilen
LiquidCrystal_I2C lcd(0x3F, 16, 2);  

void setup()
{
  // LCD initialisieren
  lcd.init();
                        
  // Hintergrundbeleuchtung aktivieren
  lcd.backlight();

  // Cursor auf die 1. Spalte und 1. Reihe setzen 
  lcd.setCursor(0,0);

  // Text ausgeben
  lcd.print("Hello Word!");
  
  // Cursor auf die 1. Spalte und 2. Reihe setzen 
  lcd.setCursor(0,1);

  // Zeichen 'A' ausgeben
  lcd.write('A');

  // Leerzeichen ausgeben
  lcd.write(' ');

  // Zahlen von 0 bis 9 ausgeben
  for(int i = 0; i < 10; i++)
  {
    lcd.write('0' + i);
  }
  
}

void loop()
{
  // statische Variable
  static int counter = 0;

  // Cursor setzen
  lcd.setCursor(12,0);

  // Den aktuellen Inhalt der Variable 
  // counter hexadezimal ausgeben 
  lcd.print(counter++, HEX);
  
  delay(250);
}
