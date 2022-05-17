////////////////////////////////////////////////////////////////////
//
//            Beispiel: Zweipunktregler
//
//          Copyright (c) Gerhard Schalk
//
////////////////////////////////////////////////////////////////////
const int ON_BOARD_LED = 13;  // LED Pin
float setPoint = 2.5; // Sollwert
int ledStatus;        // LED status

void setup() {
  pinMode(ON_BOARD_LED, OUTPUT); // Pin 13 als Ausgang
  // Serielle Schnittstelle initialisieren (9600 baud)
  Serial.begin(9600);
}

void loop() {
  
  int sensorValue = 0;
  
  // Sensor einlesen 
  sensorValue = analogRead(A1);
  
  // ADC Wert in einen Spannungswert konvertieren 
  float actValue = sensorValue * (5.0 / 1023.0);

  // Prüfen ob der aktuelle Wert größer als der Sollwert ist
  if( actValue > setPoint)
  {
    digitalWrite(ON_BOARD_LED, LOW);
    ledStatus = 0;
  }
  else
  {
    digitalWrite(ON_BOARD_LED, HIGH);
    ledStatus = 1;
  }

  
  // Ausgabe des Sollwerts + Trennzeichen für seriellen Plotter
  Serial.print(setPoint);
  Serial.print(",  ");

  // Ausgabe des LED Status + Trennzeichen für seriellen Plotter
  Serial.print(ledStatus);
  Serial.print(",  ");

  // Ausgabe des aktuellen LDR Wertes
  Serial.println(actValue);
  delay(100);
}

void serialEvent()
{
  if( Serial.available() )
  {
    // Sollwert via serielle Schnittstelle setzen
    setPoint = Serial.parseFloat();
  }
}
