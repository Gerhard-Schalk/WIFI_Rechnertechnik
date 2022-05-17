#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte INT0_PIN = 2; // Pin-Nummer Interrupt 0

// Globales Interrupt-Flag
volatile boolean keyPressedFlag = false; 

// String-Puffer
char lcdBuffer[17]; 

// Erzeugt ein Objekt vom Typ LiquidCrystal_I2C
// I2C Adresse = 0x3F, 16 Zeichen, 2 Zeilen
LiquidCrystal_I2C lcd(0x3F, 16, 2);  


void setup() {
  // Port D2 (INT0) als Eingang konfigurieren und
  // internen Pull-Up-Widerstand aktivieren
  pinMode(INT0_PIN, INPUT_PULLUP); 

  // RISING or FALLING or CHANGE
  attachInterrupt(
    digitalPinToInterrupt( INT0_PIN), // Interrupt Nummer
    Int0_ISR, // Interrupt Service Routine
    FALLING); // Interrupt bei fallender Flanke triggern

  // LCD initialisieren
  lcd.init();
  
  // Hintergrundbeleuchtung aktivieren
  lcd.backlight();

}

void loop() {
  static int counter = 0;

  // Globales Interrupt-Flag auswerten
  if(keyPressedFlag == true)
  {
    // Globales Interrupt-Flag löschen
    keyPressedFlag = false;  

    counter++; // Zähler erhöhen

    // Formatierten String erzeugen
    sprintf(lcdBuffer,"INT CNT: %4d", counter);

    // Cursor auf die 1. Spalte und 1. Zeile setzen
    lcd.setCursor(0,0);
  
    // Formatierten String ausgeben
    lcd.print(lcdBuffer);
  }
}

void Int0_ISR()
{
  // Globales Interrupt-Flag setzen
  keyPressedFlag = true;
}
