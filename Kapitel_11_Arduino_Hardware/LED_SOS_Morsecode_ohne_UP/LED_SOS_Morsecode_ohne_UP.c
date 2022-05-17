// Zeitkonstanten für Morseprogramm
#define DOT   200         // Signaldauer für ein kurzes Signal
#define DASH  3 * DOT     // Signaldauer für ein langes Signal
#define CHARACTER_GAP DOT // Signalpause zwischen zwei Zeichen

const int LED = 13; // LED Pin

void setup() 
{
  // Port 13 als Ausgang konfigurieren
  pinMode(LED, OUTPUT);
}

void loop() 
{
    // Morsecode-Zeichen 'S' (3 x kurzes Signal)
    digitalWrite(LED, HIGH);
    delay(DOT);
    digitalWrite(LED, LOW);
    delay(DOT);
    delay(CHARACTER_GAP);

    digitalWrite(LED, HIGH);
    delay(DOT);
    digitalWrite(LED, LOW);
    delay(DOT);
    delay(CHARACTER_GAP);

    digitalWrite(LED, HIGH);
    delay(DOT);
    digitalWrite(LED, LOW);
    delay(DOT);
    delay(CHARACTER_GAP);
    
    // Morsecode-Zeichen 'O' (3 x langes Signal)
    digitalWrite(LED, HIGH);
    delay(DASH);
    digitalWrite(LED, LOW);
    delay(DASH);
    delay(CHARACTER_GAP);

    digitalWrite(LED, HIGH);
    delay(DASH);
    digitalWrite(LED, LOW);
    delay(DASH);
    delay(CHARACTER_GAP);

    digitalWrite(LED, HIGH);
    delay(DASH);
    digitalWrite(LED, LOW);
    delay(DASH);
    delay(CHARACTER_GAP);
  
    // Morsecode-Zeichen 'S' (3 x kurzes Signal)
    digitalWrite(LED, HIGH);
    delay(DOT);
    digitalWrite(LED, LOW);
    delay(DOT);
    delay(CHARACTER_GAP);

    digitalWrite(LED, HIGH);
    delay(DOT);
    digitalWrite(LED, LOW);
    delay(DOT);
    delay(CHARACTER_GAP);

    digitalWrite(LED, HIGH);
    delay(DOT);
    digitalWrite(LED, LOW);
    delay(DOT);
    delay(CHARACTER_GAP);
    
    delay(3000);
}
