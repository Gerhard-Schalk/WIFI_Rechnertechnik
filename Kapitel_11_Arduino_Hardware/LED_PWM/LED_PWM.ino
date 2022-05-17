const int PWM_LED = 5;

void setup()
{
  pinMode(PWM_LED, OUTPUT); // Pin 5 als Ausgang konfigurieren

  // Serielle Schnittstelle initialisieren
  Serial.begin(115200);
}

void loop()
{
  int adcRawValue;

  for( int i =  0; i < 256; i += 5)
  {
    analogWrite(PWM_LED, i); // PWM ausgeben
    //printPWM_DutyCycle(i);

    printAnalogVoltage(A0);

    delay(50);
  }

  for( int i = 255; i >= 0; i -= 5)
  {
    analogWrite(PWM_LED, i); // PWM ausgeben
    //printPWM_DutyCycle(i);

    printAnalogVoltage(A0);

    delay(50);
  }
}

// Aktuellen Tastgrad via serieller
// Schnittstelle ausgeben
void printPWM_DutyCycle(int value)
{
    // Auf 0 .. 100 Prozent umrechnen
    float dutyCycle = (value * 100.0) / 255.0;

    Serial.print("DutyCycle = ");
    Serial.print( dutyCycle, 1 );
    Serial.println(" %");
}

// Analoge Spannung messen und via serieller
// Schnittstelle ausgeben
void printAnalogVoltage(int pin)
{
    int adcRawValue = analogRead( pin );

    // Auf 0 .. 100 Prozent umrechnen
    float analogVoltage = (adcRawValue * 5.0 ) / 1023.0;

    Serial.print("Voltage = ");
    Serial.print( analogVoltage, 1 );
    Serial.println(" V");
    Serial.println();
}
