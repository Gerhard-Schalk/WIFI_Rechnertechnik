#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char lcdBuffer[17]; // String-Puffer

// Erzeugt ein Objekt vom Typ LiquidCrystal_I2C
// I2C Adresse = 0x3F, 16 Zeichen, 2 Zeilen
LiquidCrystal_I2C lcd(0x3F, 16, 2); 

void setup()
{
  // LCD initialisieren
  lcd.init();
  
  // Hintergrundbeleuchtung aktivieren
  lcd.backlight();
}


void loop()
{ 
// Analogwert einlesen
  int adcRawValue = analogRead( A0 );
  
  // Cursor auf die 4. Spalte und 1. Zeile setzen
  lcd.setCursor(4,0);

  // Formatierten String erzeugen
  sprintf(lcdBuffer,"A0:%4d", adcRawValue);

  // Cursor auf die 1. Spalte und 1. Zeile setzen
  lcd.setCursor(0,0);
  
  // Formatierten String ausgeben
  lcd.print(lcdBuffer);
  
  // Spannungswert berechnen
  float voltValue = (5.0 * adcRawValue) / 1023.0;
  
       // Formatierten String erzeugen
  dtostrf(voltValue,  // Gleitkommawert
          4,          // Ausgabe-Breite
          2,          // Genauigkeit
          lcdBuffer); // Zeiger auf String

  // Spannungswert ausgeben
  lcd.setCursor(9,0);
  lcd.print(voltValue);

  lcd.setCursor(13,0);
  lcd.print("V");
}
