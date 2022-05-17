void setup() 
{
  Serial.begin(115200); // serielle Schnittstelle initialisieren
  
  //---------------------------------------------------------------
  // Beispiel: Ganzzahl Variable (Integer)
  //---------------------------------------------------------------
  int intVar = 245;
  // Hinweis: Variablen vom Typ "int" werden immer als Zahl ausgegeben.
  Serial.print("Der Inhalt der Variable intVar (dezimal) = ");
  Serial.println(intVar);
  Serial.print("Der Inhalt der Variable intVar (binär) = 0b");
  Serial.println(intVar, BIN);
  Serial.print("Der Inhalt der Variable intVar (oktal) = 0");
  Serial.println(intVar, OCT);
  Serial.print("Der Inhalt der Variable intVar (hexdezimal) = 0x");
  Serial.println(intVar, HEX);
  Serial.println(); // zusätzlicher Zeilenumbruch
}
void loop()
{
}
