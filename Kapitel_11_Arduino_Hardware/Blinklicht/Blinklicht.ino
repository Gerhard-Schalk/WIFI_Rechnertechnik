const int LED = 13; 

void setup() 
{
  // Port 13 als Ausgang konfigurieren
  pinMode(LED, OUTPUT);
}

void loop() 
{
  digitalWrite(LED, HIGH);   // Port 13 auf HIGH setzen
  delay(1000);               // 1000 Millisekunden warten
  digitalWrite(LED, LOW);    // Port 13 auf LOW setzen
  delay(1000);               // 1000 Millisekunden warten
}
