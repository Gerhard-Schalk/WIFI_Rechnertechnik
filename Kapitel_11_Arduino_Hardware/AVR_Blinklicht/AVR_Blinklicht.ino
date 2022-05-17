#include <avr/io.h>
#include <util/delay.h>

#define ON_BOARD_LED_PORTB_PIN  5

int main() 
{
  // Portpin PB5 (Arduino Pin 13)  
  // Port Richtungsregister auf Ausgang setzten
  DDRB |= (1 << DDB5);

  while (true) 
  {
    // Portpin PB5 setzen (LED ein)
    PORTB |= (1 << PORTB5);

    // 1000 ms warten
    _delay_ms(1000);
    
    // Portpin PB5 löschen (LED ein)
    PORTB &= ~(1 << PORTB5);
    
    // 1000 ms warten
    _delay_ms(1000);
  }
}
