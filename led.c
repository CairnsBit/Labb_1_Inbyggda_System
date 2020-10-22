#include <util/delay.h>
#include <avr/io.h>

#include "led.h"

void blink_led() {

	DDRB |= (1 << PB3);	//RED
	DDRB |= (1 << PB2);	//BLUE
	DDRB |= (1 << PB1);	//GREEN


	while (1) {
		PORTB |= (1 << PB3);
		_delay_ms(500);
		PORTB &= ~(1 << PB3);
		_delay_ms(500);
		PORTB |= (1 << PB1);
		_delay_ms(500);
		PORTB &= ~(1 << PB1);
		_delay_ms(500);
		PORTB |= (1 << PB2);
		_delay_ms(500);
		PORTB &= ~(1 << PB2);
		_delay_ms(500);
	}
}
