#include "TimerOne.h"  //Include Timer Funktionen

volatile boolean timerFlag = false; // Globales Timer-Interrupt-Flag

char strBuffer[17]; // String-Puffer

void setup() 
{
  // Timer initialisieren - Periodendauer 1s 
  Timer1.initialize(1000000);    

  // Timer1_ISR als Timer Callback-Funktion registrieren 
  Timer1.attachInterrupt(Timer1_ISR); //  Timer
  
  // Serielle Schnittstelle initialisieren (115200 baud)
  Serial.begin(115200);
}

void loop() {
  // Globales Timer-Interrupt-Flag auswerten
  if( timerFlag == true)
  {
    // Globales Timer-Interrupt-Flag löschen
    timerFlag = false; 
    
    // Analogwert einlesen
    int adcRawValue = analogRead( A0 );
    
    // ADC Value via serieller Schnittstelle ausgeben
    Serial.print("ADC: ");
    sprintf(strBuffer,"A0:%4d", adcRawValue);
    Serial.print(strBuffer);  
    Serial.print("   ");

    // Spannungswert berechnen
    float voltValue = (5.0 * adcRawValue) / 1023.0;

    // Spannungswert via serieller Schnittstelle ausgeben
    Serial.print(voltValue,2);
    Serial.println("V");
  }
}

// Die Timer Callback-Funktion wird periodisch aufgerufen
void Timer1_ISR() 
{ 
  // Globales Timer-Interrupt-Flag setzen
  timerFlag = true;
}
