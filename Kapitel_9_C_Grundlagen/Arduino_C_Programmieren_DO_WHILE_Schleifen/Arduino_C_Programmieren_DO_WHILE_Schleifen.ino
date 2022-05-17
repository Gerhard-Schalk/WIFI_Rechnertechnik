void setup() 
{
  
  Serial.begin(115200); // serielle Schnittstelle initialisieren

  //Mit einer do-while-Schleife von 0 bis 9 zählen.
  Serial.println("Mit einer do-while-Schleife von 0 bis 9 zaehlen:");

  int i = 0;
  do
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
    i++;
  }while(i < 10);
  
  Serial.println('\n');  // zwei Zeilenumbrüche

  
  //Mit einer do-while-Schleife von 1 bis 10 zählen.
  Serial.println("Mit einer do-while-Schleife von 1 bis 10 zaehlen:");

  i = 1;
  do
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
    i++;
  }while(i < 11);

  Serial.println('\n');  // zwei Zeilenumbrüche


  //Mit einer do-while-Schleife von 10 bis 1 zählen.
  Serial.println("Mit einer do-while-Schleife von 10 bis 1 zaehlen:");
  i = 10;
  do
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
    i--;
  }while(i > 0);

  Serial.println('\n');  // zwei Zeilenumbrüche


  //Mit einer do-while-Schleife von 10 bis 0 zählen.
  Serial.println("Mit einer do-while-Schleife von 10 bis 0 zaehlen:");
  i = 10;
  do
  {
    Serial.print(i);   // aktuellen Schleifenzähler ausgeben
    Serial.print(" "); // Leerzeichen zwischen den Zahlen
    i--;
  }while(i >= 0);
}

void loop()
{

}
