#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define OFF 0
#define ON 1

int LED = 13; // LED-Pin
float setPoint = 2.5;  // Sollwert
float deadBand = 0.5f; // Hysterese
int controllerOutput;  // Reglerausgang
char lcdBuffer[17];  // String-Puffer

// Erzeugt ein Objekt vom Typ LiquidCrystal_I2C
// I2C Adresse = 0x3F, 16 Zeichen, 2 Zeilen
LiquidCrystal_I2C lcd(0x3F, 16, 2);  

void setup() {
  pinMode(LED, OUTPUT); // Port D13 als Ausgang konfigurieren
  Serial.begin(115200); // serielle Schnittstelle initialisieren  

  lcd.init(); // LCD initialisieren
  lcd.backlight(); // Hintergrundbeleuchtung aktivieren

  //----------------------------------------
  // Statische Texte auf dem LCD ausgeben
  //----------------------------------------
  lcd.setCursor(0,0);    // Cursor setzen
  lcd.print("SP:"); // Text auf LCD ausgeben
  lcd.setCursor(9,0);    // Cursor setzen
  lcd.print("V"); // Text auf LCD ausgeben
  lcd.setCursor(0,1);    // Cursor setzen
  lcd.print("ACT:"); // Text auf LCD ausgeben
  lcd.setCursor(9,1);    // Cursor setzen
  lcd.print("V"); // Text auf LCD ausgeben
}

void loop() {
  // Istwert: ADC einlesen
  int sensorValue = analogRead(A0);

  // Istwert: Spannungswert berechnen
  float actValue = sensorValue * (5.0 / 1023.0);
 
  // Reglerausgang einschalten wenn: 
  // Istwert > Sollwert
  if( actValue > setPoint)
  {
    digitalWrite(LED, HIGH);
    controllerOutput = ON;
  }

  // Reglerausgang ausschalten wenn:
  // Istwert < (Sollwert - Hysterese)
  if( actValue < (setPoint - deadBand) )
  {
    digitalWrite(LED, LOW);
    controllerOutput = OFF;
  }

  //-------------------------------
  // Sollwert auf LCD ausgeben
  //-------------------------------
  // Formatierten String erzeugen
  dtostrf(setPoint,  // Gleitkommawert
          4,          // Ausgabe-Breite
          2,          // Genauigkeit
          lcdBuffer); // Zeiger auf String
  lcd.setCursor(5,0);   // Cursor setzen
  lcd.print(lcdBuffer); // Wert auf LCD ausgeben

  //-------------------------------
  // Istwert auf LCD ausgeben
  //-------------------------------
  // Formatierten String erzeugen
  dtostrf(actValue,  // Gleitkommawert
          4,          // Ausgabe-Breite
          2,          // Genauigkeit
          lcdBuffer); // Zeiger auf String
  lcd.setCursor(5,1);   // Cursor setzen
  lcd.print(lcdBuffer); // Wert auf LCD ausgeben

  //------------------------------------------
  // Status des digitalen Reglerausgang
  // auf LCD ausgeben
  //------------------------------------------
  lcd.setCursor(13,0);   // Cursor setzen

  if(controllerOutput == ON )
  {
    lcd.print("ON ");
  }
  else
  {
    lcd.print("OFF");    
  }

  //------------------------------------------
  // Alle Werte via serieller Schnittstelle ausgeben
  //------------------------------------------
  Serial.print(setPoint);  // Sollwert ausgeben
  Serial.print(",  "); // Trennzeichen für seriellen Plotter

  Serial.print(setPoint - deadBand);  // Hysterese ausgeben
  Serial.print(",  "); // Trennzeichen für seriellen Plotter

  Serial.print(actValue); // Istwert ausgeben
  Serial.print(",  "); // Trennzeichen für seriellen Plotter
  
   // Der serielle Plotter erwartet für den letzten Wert ein '\n'-Zeichen
  Serial.println(controllerOutput); // Digitalen Reglerausgang ausgeben
} 
                                

void serialEvent() 
{
  if( Serial.available() )
  {
      // Neuen Sollwert setzen
      setPoint = Serial.parseFloat();
  }
}
