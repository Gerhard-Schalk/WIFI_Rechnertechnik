const int LED = 13;
const int PIN_POTI = A0;    // Pin-Nummer Potentiometer

void setup() 
{
  // Port 13 als Ausgang konfigurieren
  pinMode(LED, OUTPUT);
}

void loop() 
{
  // ADC einlesen (0 .. 1023)
  int analogValue = analogRead( PIN_POTI );
  
 
  // ADC Wert in den Bereich 50 bis 2000 umrechnen  
  int delayValue = map(analogValue, 0, 1023, 50, 2000 );

  digitalWrite(LED, HIGH);   // Port 13 auf HIGH setzen
  delay(delayValue);         // delayValue Millisekunden warten
  digitalWrite(LED, LOW);    // Port 13 auf LOW setzen
  delay(delayValue);         // delayValue Millisekunden warten
}
