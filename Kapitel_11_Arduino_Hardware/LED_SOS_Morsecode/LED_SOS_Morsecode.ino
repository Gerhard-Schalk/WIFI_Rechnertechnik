// Zeitkonstanten für Morseprogramm
#define DOT   200         // Signaldauer für ein kurzes Signal
#define DASH  3 * DOT     // Signaldauer für ein langes Signal
#define CHARACTER_GAP DOT // Signalpause zwischen zwei Zeichen

const int LED = 13; // LED Pin

// Funktion: flash
void flash(int duration)
{
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(LED, HIGH);
    delay(duration);
    digitalWrite(LED, LOW);
    delay(duration);
  }
  delay(CHARACTER_GAP);
}

void setup() 
{
  // Port 13 als Ausgang konfigurieren
  pinMode(LED, OUTPUT);
}

void loop() 
{
    // Morsecode-Zeichen 'S'
    flash(DOT); // Funktion "flash" aufrufen  

    // Morsecode-Zeichen 'O'
    flash(DASH); // Funktion "flash" aufrufen
  
    // Morsecode-Zeichen 'S'
    flash(DOT); // Funktion "flash" aufrufen
  
  delay(3000);
}
