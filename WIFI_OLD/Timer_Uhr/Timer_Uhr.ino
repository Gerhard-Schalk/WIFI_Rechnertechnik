////////////////////////////////////////////////////////////////////
//
//                      Wifi Elektronik 4 / Rechnertechnik
//                      Copyright (c) 2017 Gerhard Schalk
//
////////////////////////////////////////////////////////////////////
// Projekt: Digital Uhr
////////////////////////////////////////////////////////////////////
#include "TimerOne.h"  //Include Timer Funktionen

//---------------------------------------------------------------------
//  Globale Variablen 
//---------------------------------------------------------------------
unsigned char hour;
unsigned char min;
unsigned char sec;
char secFlag;         // Sekunden Flag


void setup() 
{
  // Timer initialisieren - Periodendauer 1s 
  Timer1.initialize(1000000);    

  // Timer1_ISR als Timer Callback-Funktion registrieren 
  Timer1.attachInterrupt(Timer1_ISR); //  Timer
  
  // Serielle Schnittstelle initialisieren (9600 baud)
  Serial.begin(9600);

  hour = 19;
  min = 59;
  sec = 55;
  secFlag = 0;
}


void loop() 
{
  if(secFlag == 1)
  {
      secFlag = 0;  // Sekunden Flag zurücksetzen
      Serial.print("Uhrzeit: ");
      
      if(hour < 10) 
      {
        Serial.print("0");
      }
      Serial.print(hour);
      Serial.print(":");

      if(min < 10) 
      {
        Serial.print("0");
      }
      Serial.print(min);
      Serial.print(":");

      if(sec < 10) 
      {
        Serial.print("0");
      }
      Serial.println(sec);
  }
}

// Die Timer Callback-Funktion wird periodisch aufgerufen
void Timer1_ISR() 
{   
    secFlag = 1;// Sekunden Flag setzen
    sec++;
      
    // Prüfen, ob sec gleich 60 ist
    if(sec == 60)
    {
        sec = 0;    // sec auf 0 setzen
        min++;      // Wert von min um 1 erhöhen
        
    }
    
    // Prüfen, ob min gleich 60 ist
    if(min == 60)
    {
        min = 0;    // min auf 0 setzen
        hour++;      // Wert von hour um 1 erhöhen
    }
    
    // Prüfen, ob hour den Wert 24 hat
    if(hour == 24)
    {
        hour = 0;    // hour auf 0 setzen
    }
}
