void setup() 
{
  
  Serial.begin(115200); // serielle Schnittstelle initialisieren

  //Mit einer for-Schleife von 0 bis 9 zählen.
  Serial.println("Mit einer for-Schleife von 0 bis 9 zaehlen:");
  
  for(int i = 0; i < 10; i++)
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
  }
  
  Serial.println('\n');  // zwei Zeilenumbrüche

  
  //Mit einer for-Schleife von 1 bis 10 zählen.
  Serial.println("Mit einer for-Schleife von 1 bis 10 zaehlen:");
  for(int i = 1; i <= 10; i++)
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
  }

  Serial.println('\n');  // zwei Zeilenumbrüche


  //Mit einer for-Schleife von 0 bis 9 zählen.
  Serial.println("Mit einer for-Schleife von 0 bis 9 zaehlen:");
  for(int i = 0; i < 10; i++)
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
  }

  Serial.println('\n');  // zwei Zeilenumbrüche


  //Mit einer for-Schleife von 10 bis 1 zählen.
  Serial.println("Mit einer for-Schleife von 10 bis 1 zaehlen:");
  for(int i = 10; i > 0; i--)
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
  }

  Serial.println('\n');  // zwei Zeilenumbrüche


  //Mit einer for-Schleife von 10 bis 0 zählen.
  Serial.println("Mit einer for-Schleife von 10 bis 0 zaehlen:");
  for(int i = 10; i >= 0; i--)
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
  }
}

void loop()
{

}
