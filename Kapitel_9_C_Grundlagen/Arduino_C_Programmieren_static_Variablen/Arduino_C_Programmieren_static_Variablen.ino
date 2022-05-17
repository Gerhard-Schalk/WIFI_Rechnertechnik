void testFunction()
{
  int i = 25;  // Variable mit automatischen Lebensdauer
  static int j = 25; // Variable mit statische Lebensdauer

  Serial.print("Wert der lokalen Variablen: i="); // Leerzeichen zwischen den Zahlen
  Serial.print(i++); // Leerzeichen zwischen den Zahlen

  Serial.print("  j="); // Leerzeichen zwischen den Zahlen
  Serial.println(j++); // Leerzeichen zwischen den Zahlen
}

void setup() {

  Serial.begin(115200); // serielle Schnittstelle initialisieren

  for(int i = 0; i < 10; i++)
  {
    testFunction();
  }

}

void loop()
{

}
