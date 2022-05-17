////////////////////////////////////////////////////////////////////
//
//                      Wifi Elektronik 4 / Rechnertechnik
//                      Copyright (c) 2017 Gerhard Schalk
//
////////////////////////////////////////////////////////////////////
//  Projekt Dispaly a Serial Waveform via Arduino Serial Plotter
//  Connect pin 0 and 2
////////////////////////////////////////////////////////////////////
const int onBoardLed = 13; // LED Pin
const byte ISR_Pin2 = 2; // Interrupt 0

const byte RX_Pin = 0;

const int SAMPLES = 1024;
byte signal[SAMPLES];
boolean measurmentDone;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(  onBoardLed, OUTPUT); // Pin 13 als Ausgang
  digitalWrite(onBoardLed, LOW);
  pinMode(ISR_Pin2, INPUT_PULLUP);  // Serial input triggers logging
  pinMode(7, INPUT_PULLUP);      //    Key to sendout the result to graph


  // RISING or FALLING or CHANGE
  attachInterrupt(digitalPinToInterrupt( ISR_Pin2), Int0_ISR, FALLING);
  measurmentDone = false;
}

// the loop routine runs over and over again forever:
void loop() 
{
  if(measurmentDone == true)
  {
    
    int keyValue = digitalRead( 7 );
    if(keyValue == 0)
    {
      measurmentDone = false;
      digitalWrite(onBoardLed, LOW);
      Serial.begin(115200);
      for(int i = 0; i < SAMPLES; i++)
      {
        Serial.println( signal[i] );
        //Serial.print(",  ");   
      }
      Serial.end();
    }
  }
}


void Int0_ISR()
{
  noInterrupts();
  for(int i = 0; i < SAMPLES; i++)
  {
    signal[i] = digitalRead(ISR_Pin2);    
  }
  measurmentDone = true;
  digitalWrite(onBoardLed, HIGH);
  interrupts();
  
  
 }
