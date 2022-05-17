const int onBoardLed = 13;   // LED
const byte interruptPin = 2; // Interrupt 0


// the setup routine runs once when you press reset:
void setup() {
  pinMode(  onBoardLed, OUTPUT); 
  pinMode(interruptPin, INPUT_PULLUP);

  // RISING or FALLING or CHANGE
  attachInterrupt(digitalPinToInterrupt(interruptPin), Int0_ISR, RISING);  
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

}

void Int0_ISR()
{
    int onBoardLedValue = digitalRead(onBoardLed);
  
    if( onBoardLedValue == LOW )
    {
      digitalWrite(onBoardLed, HIGH); 
    }
    else
    {
     digitalWrite(onBoardLed, LOW);  
    } 
}

