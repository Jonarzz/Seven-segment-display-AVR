/*
 * bluetooth.c
 *
 *  Created on: 15 gru 2015
 *      Author: Jonasz
 */

#include "bluetooth.h"

void initUSART() {
	#define BAUD 9600
	#define CLOCK_FREQ 16000000
	#include <util/setbaud.h>
	#define UBRR ((CLOCK_FREQ/16/BAUD)-1)

	UBRR0H = UBRR>>8;
	UBRR0L = UBRR;

	UCSR0B = (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);
	UCSR0C = (1<<UCSZ1) | (1<<UCSZ0);
}
