int value;

void loop()
{
  if( Serial.available())
  {
    char ch = Serial.read();
    if(ch >= '0' && ch <= '9') // is this an ascii digit between 0 and 9?
    {
       value = (value * 10) + (ch - '0'); // yes, accumulate the value
    }
    else if (ch == 10)  // is the character the newline character
    {
       blinkRate = value;  // set blinkrate to the accumulated value
       Serial.println(blinkRate);
       value = 0; // reset val to 0 ready for the next sequence of digits
    }
  }
  blink();
}
