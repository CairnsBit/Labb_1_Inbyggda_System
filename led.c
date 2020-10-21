#include <util/delay.h>
#include <avr/io.h>

#include "led.h"

void blink_led() {

	DDRB |= 0B000010;

	while (1) {
		PORTB |= 0B000010;
		_delay_ms(500);

		PORTB &= ~0B00010;
		_delay_ms(500);
	}
}
