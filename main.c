#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
#include "led.h"

void main (void) {
	blink_led();
}
