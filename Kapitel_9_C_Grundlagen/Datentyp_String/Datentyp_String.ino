void setup() {
  // serielle Schnittstelle mit 115200 Baud initialisieren
  Serial.begin(115200);
  
  // Text (String) via serieller Schnittstelle ausgeben
  // (ohne Zeilenumbruch)
  Serial.print("Das Programm ");
  
  // Text (String) und Zeilenumbruch (New-Line) via serieller
  // Schnittstelle ausgeben
  Serial.println("wurde gestartet! ...");
  Serial.println(); // zusätzlicher Zeilenumbruch
  
  //===============================================================
  // Variablen deklarieren, initialisieren und
  // über die serielle Schnittstelle ausgeben
  //===============================================================
  
  //---------------------------------------------------------------
  // Beispiel: C++ String Klasse
  //---------------------------------------------------------------
  String text = "Hello World!";
  Serial.print("Der Inhalt von der Variable text = ");
  Serial.println(text);
  
  //---------------------------------------------------------------
  // Beispiel: C-String Klasse
  //---------------------------------------------------------------
  char baText[] = "Hello Arduino!";
  Serial.print("Der Inhalt von der Variable baText = ");
  Serial.println(baText);
}
void loop()
{
  
}
