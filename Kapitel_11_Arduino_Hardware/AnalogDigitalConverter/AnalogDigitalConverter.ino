void setup() {
  Serial.begin(115200); // Serielle Schnittstelle initialisieren
}

void loop() {
    // ADC einlesen
    int adcRawValue = analogRead( A0 );

    // Spannungswert berechnen
    float analogVoltage = (adcRawValue * 5.0 ) / 1023.0;

    // Ausgabe via serieller Schnittstelle
    Serial.print(adcRawValue); // ADC-Wert ausgeben
    Serial.print(",  "); // Trennzeichen für seriellen Plotter
    Serial.print(analogVoltage); //Spannungswert ausgeben
    Serial.println("V");
    delay(100);
}
