void setup() 
{
  
  Serial.begin(115200); // serielle Schnittstelle initialisieren

  Serial.println("Bitte Note von 1 bis 5 eingeben...");
}

void loop()
{
  // Prüfen Sie, ob sich im seriellen Puffer Daten befinden.
  if( Serial.available() )
  {
    // Integer Wert von der seriellen Schnittstelle lesen 
    // und in die Variable number speichern
    int number = Serial.parseInt();
    
    Serial.print(number);

    switch( number )
    {
      case 1: 
        Serial.println(" .. sehr gut");       
        break;
        
      case 2:
        Serial.println(" .. gut");       
        break;
        
       case 3:
        Serial.println(" .. befriedigend");       
        break;
        
       case 4:
        Serial.println(" .. genügend");       
        break;
        
      case 5:
        Serial.println(" .. nicht genügend");       
        break;

      default:
        Serial.println(" .. ist keine gueltige Note!");    
    }
    
    Serial.println(); // zusätzliche Leerzeile
  }
}
