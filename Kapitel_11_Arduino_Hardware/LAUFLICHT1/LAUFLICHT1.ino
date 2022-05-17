const int PIN_BTN_S1  = 7;  // Pin-Nummer Taster S1

const int PIN_LED0 = 8;     // Pin-Nummer LED 0
const int PIN_LED1 = 9;     // Pin-Nummer LED 1
const int PIN_LED2 = 10;    // Pin-Nummer LED 2
const int PIN_LED3 = 11;    // Pin-Nummer LED 3

// Im Array werden die LED Pin-Nummern in der korrekten
// Reihenfolge gespeichert
int ledPins[] = {PIN_LED0, PIN_LED1, PIN_LED2, PIN_LED3 };

int numberOfLeds = sizeof( ledPins ) / sizeof( ledPins[0] );

void setup()
{
  // Port 7 als Eingang konfigurieren und
  // internen Pull-Up-Widerstand aktivieren
  pinMode( PIN_BTN_S1, INPUT_PULLUP);

  // Alle LED-Ports als Ausgang konfigurieren
  for( int i = 0; i < numberOfLeds; i++ )
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  // Taste S1 einlesen
  int btn_S1_Value = digitalRead( PIN_BTN_S1 );

  // S1 ist low-aktive
  if ( btn_S1_Value == HIGH )
  {
    // Tast nicht betätigt

    // Lauflicht: rechts -> links
    for( int i = 0; i < numberOfLeds; i++)
    {
      digitalWrite( ledPins[i], HIGH );
      delay(500);
      digitalWrite( ledPins[i], LOW);
    }
  }
  else
  {
    // Taste betätigt

    // Lauflicht: links -> rechts
    for( int i = numberOfLeds; i >= 0; i--)
    {
      digitalWrite( ledPins[i], HIGH );
      delay(500);
      digitalWrite( ledPins[i], LOW);
    }
  }
}
