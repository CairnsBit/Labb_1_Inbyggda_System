#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

#define FOSC 16000000
#define BAUD 38400
#define UBRR ((FOSC / 16 / BAUD) -1)

void uart_init(void) {
	UBRR0H = (UBRR >> 8);
	UBRR0L = UBRR;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_putchar(char chr) {
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = chr;
	if (chr == '\r') {
		uart_putchar('\n');
	}
}

void uart_putstr(const char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		uart_putchar(str[i]);
		_delay_ms(200);
	}
}

char uart_getchar(void) {
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void uart_echo(void) {
	char text = uart_getchar();
	uart_putchar(text);
}