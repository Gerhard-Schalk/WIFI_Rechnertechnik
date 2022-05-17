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

    // Mit dem Zeichen '0' LED ausschalten
    if( c == '0')
    {
      // LED aus
      digitalWrite(LED, LOW);
    }

    // Mit dem Zeichen '1' LED einschalten
    else if( c == '1')
    {
      // LED ein
      digitalWrite(LED, HIGH);
    }

    // Mit dem Zeichen 'b' oder 'B' zweimal blinken
    else if( c == 'b' || c == 'B')
    {
      // LED zweimal blinken
      digitalWrite(LED, HIGH);
      delay(250);
      digitalWrite(LED, LOW);
      delay(250);
      digitalWrite(LED, HIGH);
      delay(250);
      digitalWrite(LED, LOW);
    }
}
