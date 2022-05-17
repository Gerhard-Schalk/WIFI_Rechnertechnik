void setup() 
{
  Serial.begin(115200); // serielle Schnittstelle initialisieren

  //---------------------------------------------------------------
  // Beispiel: Gleitkommazahl (float)
  //---------------------------------------------------------------
  float floatVar = 12.3456;
  
  // Wird die Anzahl der Nachkommastellen nicht definiert,
  // werden immer zwei Nachkommastellen ausgegeben.
  Serial.print("floatVar = ");
  Serial.println(floatVar);
  
  // Den Inhalt von der Variable floatVar
  // mit einer Nachkommastelle ausgeben.
  Serial.print("floatVar = ");
  Serial.println(floatVar, 1);
  
  // Den Inhalt von der Variable floatVar
  // mit drei Nachkommastelle ausgeben.
  Serial.print("floatVar = ");
  Serial.println(floatVar, 3);
  Serial.println(); // zusätzlicher Zeilenumbruch
}
void loop()
{
  
}
