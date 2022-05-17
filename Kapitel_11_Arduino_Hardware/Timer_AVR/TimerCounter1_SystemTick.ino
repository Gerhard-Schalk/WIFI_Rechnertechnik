
const int LED = 13; // LED Pin
const int TIMER_START_VALUE = 49910;

void setup() 
{
  pinMode(LED, OUTPUT); // Port 13 als Ausgang konfigurieren

  // Alle Interrupts deaktivieren stellt sicher,
  // das während der Konfiguration ein Interrupt
  // ausgelöst wird.
  noInterrupts(); 
  
  // Timer/Counter 1 Control Register A/B 
  // vor der Konfiguration auf 0 setzten
  TCCR1A = 0;  
  TCCR1B = 0; 

  // Timer/Counter 1 Zählregister = Startwert 
  TCNT1 = TIMER_START_VALUE;
  
  // Timer/Counter 1 Prescaler = 1024
  TCCR1B |= _BV(CS10);
  TCCR1B |= _BV(CS12);

  // Timer/Counter 1 Overflow Interrupt aktivieren
  TIMSK1 |= _BV(TOIE1);
  
  interrupts(); // Alle Interrupts wieder aktivieren
}

// Timer Overflow ISR
ISR(TIMER1_OVF_vect) 
{
  // Timer/Counter Zählregister Startwert setzen
  TCNT1 = TIMER_START_VALUE;

  //Aktuellen LED Zustand lesen und invertieren
  digitalWrite(LED, !digitalRead(LED));
}

void loop() 
{

}
