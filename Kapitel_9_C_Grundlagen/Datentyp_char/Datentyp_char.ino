void setup() {
  
  Serial.begin(115200); // serielle Schnittstelle initialisieren
  
  //---------------------------------------------------------------
  // Beispiel: Zeichen Variablen
  //---------------------------------------------------------------
  char charVar1 = 49; // ASCII Zeichen '1' (dezimale Konstante)
  char charVar2 = 0b110010; // ASCII Zeichen '2' (binäre Konstante )
  char charVar3 = 063; // ASCII Zeichen '3' (oktale Konstante )
  char charVar4 = 0x34; // ASCII Zeichen '4' (hex Konstante)
  char charVar5 = '5'; // ASCII Zeichen '5' (als Zeichen)
  char charVar6 = 0xE0; // Kein gültiges ASCII Zeichen!
  
  // Hinweis: Variablen vom Typ "char" werden immer als
  // ASCII Zeichen ausgegeben.
  Serial.print("charVar1 bis charVar5 = ");
  Serial.print(charVar1);
  Serial.print(charVar2);
  Serial.print(charVar3);
  Serial.print(charVar4);
  Serial.print(charVar5);
  Serial.println(charVar6);
  Serial.println(); // zusätzlicher Zeilenumbruch

  // Hinweis: Mit Hilfe eines Type-Cast kann man Variablen vom Typ "char"
  // auch als Zahl ausgeben.
  Serial.print("(int)charVar1 = ");
  Serial.println((int)charVar1);
  Serial.print("(int)charVar1 binär ausgeben = ");
  Serial.println((int)charVar1, BIN);
  Serial.println(); // zusätzlicher Zeilenumbruch
  Serial.print("(int)charVar6 = ");
  Serial.println((int)charVar6);
  Serial.print("(int)charVar6 binär ausgeben = ");
  Serial.println((int)charVar6, BIN);
  Serial.println(); // zusätzlicher Zeilenumbruch
}
void loop()
{
}
