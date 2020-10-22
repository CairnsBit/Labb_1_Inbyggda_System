#include <util/delay.h>
#include <avr/io.h>

#include "led.h"

void blink_led() {

	DDRB |= 0B001000;	//RED
	DDRB |= 0B000100;	//BLUE
	DDRB |= 0B000010;	//GREEN


	while (1) {
		PORTB |= 0B001000;
		_delay_ms(500);
		PORTB &= ~ 0B001000;
		_delay_ms(500);
		PORTB |= 0B000100;
		_delay_ms(500);
		PORTB &= ~ 0B000100;
		_delay_ms(500);
		PORTB |= 0B000010;
		_delay_ms(500);
		PORTB &= ~ 0B000010;
		_delay_ms(500);
	}
}
