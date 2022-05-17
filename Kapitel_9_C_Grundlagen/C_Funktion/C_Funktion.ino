void setup() 
{
  // Serielle Schnittstelle initialisieren
  Serial.begin(115200);
  Serial.println("Bitte geben Sie zwei Zahlen ein: ");
}

void loop() 
{
  if(Serial.available())
  {    
    // Zwei Parameter via serieller Schnittstelle lesen
    int a = Serial.parseInt();
    int b = Serial.parseInt();

    // Funktion add aufrufen
    int c = add(a, b);

    // Ergebnis via serieller Schnittstelle ausgeben
    Serial.print("Das Ergebnis von ");
    Serial.print(a);
    Serial.print(" + ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.println(c);    
    
    Serial.println("Bitte geben Sie zwei Zahlen ein: ");
  }
}

// Funktion add
int add(int value1, int value2)
{
  int result = value1 + value2;

  return result;
}
