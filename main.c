/*
 * main.c
 *
 *  Created on: 12 gru 2015
 *      Author: Jonasz
 */

#include "display.h"
#include "button.h"


void interrupt_init();

int main() {
	digitNumber = 1;
	secondsCounter = 0;
	cycleCounter = 0;

	interrupt_init();
	sei();

	initializeDisplay();
	initializeButton();

	while (1) {
		displayNumber(secondsCounter);

		if (wasButtonClicked(BUTTON)) {
			secondsCounter = 0;
			cycleCounter = 0;
		}
	}
}

void interrupt_init() {
	TCCR1B |= (1<<CS11) | (1<<WGM12);
	TIMSK |= (1<<OCIE1A);
	OCR1A = 10000;
}

ISR(TIMER1_COMPA_vect) {
	digitNumber++;
	if (digitNumber > 4) {
		digitNumber = 1;
	}

	cycleCounter++;
	if (cycleCounter > 200) {
		cycleCounter = 0;
		secondsCounter++;
	}
}
