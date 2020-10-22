#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
#include "led.h"


void main (void) {

	char single = 'b';

	char name[10] = "maciej\r";

	uart_init();

	blink_led();

	//uart_putchar(single);

	//uart_putstr(name);

	while (1) {
		uart_echo();			// echo lyssnar för input 24/7
	}
}
