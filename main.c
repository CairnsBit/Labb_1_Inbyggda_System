#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
#include "led.h"


void main (void) {

	char single = 'b';

	char name[10] = "maciej";

	//blink_led();

	uart_init();

	//uart_putchar(single);

	uart_putstr(name);
}
