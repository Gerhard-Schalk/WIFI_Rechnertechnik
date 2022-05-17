#define DEBOUNCE_TIME 100

const int PIN_BTN_S1  = 7;  // Pin-Nummer Taster S1
bool btn_S1_PreviousState = HIGH;
unsigned int counter;

void setup()
{
  Serial.begin(115200); // Serielle Schnittstelle initialisieren

  // Port 7 als Eingang konfigurieren und
  // internen Pull-Up-Widerstand aktivieren
  pinMode( PIN_BTN_S1, INPUT_PULLUP);

  counter = 0;
}

void loop()
{
  // Taste S1 einlesen
  int btn_S1_Value = digitalRead( PIN_BTN_S1 );

  // Flankenerkennung (negative Flanke)
  if(  btn_S1_Value != btn_S1_PreviousState &&
       btn_S1_Value == LOW)
  {
    // Solange warten bis die Taste nicht mehr prellt.
    delay( DEBOUNCE_TIME );

//    btn_S1_Value = digitalRead( PIN_BTN_S1 );
//
//    if(  btn_S1_Value == LOW)
//    {
      // Taste wurde betätigt
      counter++;
      Serial.println(counter);
//    }
  }
  btn_S1_PreviousState = btn_S1_Value;
}
