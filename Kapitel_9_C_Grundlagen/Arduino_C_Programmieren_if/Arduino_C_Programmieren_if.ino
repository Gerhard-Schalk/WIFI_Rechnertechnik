void setup() {
  
  Serial.begin(115200); // serielle Schnittstelle initialisieren
  Serial.println("Bitte Zahlen eingeben...");
}

void loop()
{
  // Prüfen Sie, ob sich im seriellen Puffer Daten befinden.
  if( Serial.available() )
  {
    // Integer Wert von der seriellen Schnittstelle lesen
    // und in die Variable number speichern
    int number = Serial.parseInt();

    Serial.print("number = ");
    Serial.print(number);

    if(number > 0)
    {
      Serial.print(" ist eine positive Zahl\n");
    }
    
    Serial.println();  //Zeilenumbruch
  }
}
