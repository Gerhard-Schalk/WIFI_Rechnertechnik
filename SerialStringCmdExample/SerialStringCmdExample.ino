#include <Arduino.h>

String cmdString = "";
boolean cmdStringComplete = false;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("Serial Command Example...");
}

void loop() {

  if( cmdStringComplete == true )
  {
    cmdStringComplete = false;


    if( cmdString.substring(0,6).equals("LED ON") ){
      digitalWrite(LED_BUILTIN, HIGH);
    }

    else if( cmdString.substring(0,7).equals("LED OFF") ){
      digitalWrite(LED_BUILTIN, LOW);
    }

    cmdString = "";
  }
}


void serialEvent()
{
  //digitalWrite(LED, LOW);
  while( Serial.available() ){
    // get a new byte
    char inChar = (char)Serial.read();
    cmdString += inChar;


    if( inChar == '\n' ){
      cmdStringComplete = true;

    }
  }
}
