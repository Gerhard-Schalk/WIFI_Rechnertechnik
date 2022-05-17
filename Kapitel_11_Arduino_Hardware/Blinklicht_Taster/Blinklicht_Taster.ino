const int LED = 13;
const int PIN_BTN_S1  = 7;  // Pin-Nummer Taster S1 


void setup() 
{
  // Port 13 als Ausgang konfigurieren
  pinMode(LED, OUTPUT);

  // Port D7 als Eingang konfigurieren und
  // internen Pull-Up-Widerstand aktivieren
  pinMode( PIN_BTN_S1, INPUT_PULLUP);
}

void loop() 
{
  int delayValue = 0;

  int btn_S1_Value = digitalRead( PIN_BTN_S1 ); // Taste S1 einlesen

  if ( btn_S1_Value == LOW )
  {
    // Taste betätigt (negative Logik)
    delayValue = 100;
  }
  else
  {
    // Taste nicht betätigt (negative Logik)
    delayValue = 1000;
  }

  digitalWrite(LED, HIGH);   // Port 13 auf HIGH setzen
  delay(delayValue);         // delayValue Millisekunden warten
  digitalWrite(LED, LOW);    // Port 13 auf LOW setzen
  delay(delayValue);         // delayValue Millisekunden warten
}
