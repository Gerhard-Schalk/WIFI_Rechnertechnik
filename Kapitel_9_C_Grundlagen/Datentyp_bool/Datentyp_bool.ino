void setup() {
  // serielle Schnittstelle mit 115200 Baud initialisieren
  Serial.begin(115200);
  
  //---------------------------------------------------------------
  // Beispiel: Boolesche Variablen
  //---------------------------------------------------------------
  bool boolVar0 = false;
  bool boolVar1 = true;
  Serial.print("Der Inhalt von der Variable boolVar0 = ");
  Serial.println(boolVar0);
  Serial.print("Der Inhalt von der Variable boolVar1 = ");
  Serial.println(boolVar1);
  Serial.println(); // zusätzlicher Zeilenumbruch
}
void loop()
{
  
}
