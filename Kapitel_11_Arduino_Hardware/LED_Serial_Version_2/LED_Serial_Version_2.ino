const int LED = 13; // LED Pin

void setup() 
{
  pinMode(  LED, OUTPUT); // Pin 13 als Ausgang
  
  // Serielle Schnittstelle initialisieren
  Serial.begin(115200);
}

void loop() 
{

}

// serialEvent wird aufgerufen, wenn Daten verfügbar sind
void serialEvent()
{
    // Zeichen lesen
    char c = Serial.read();

    switch(c)
    {
      case '0': // LED aus
         digitalWrite(LED, LOW); 
         break;

      case '1': // LED ein
        digitalWrite(LED, HIGH);
        break;

      case 'b': // LED zweimal blinken
      case 'B': // LED zweimal blinken
        ledBlink();
        break; 
    }  
}

void ledBlink() 
{
  digitalWrite(LED, HIGH);
  delay(500);
  
  digitalWrite(LED, LOW); 
  delay(500);
  
  digitalWrite(LED, HIGH);
  delay(250);

  digitalWrite(LED, LOW);   
}
