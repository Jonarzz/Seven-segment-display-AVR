/*
 * button.c
 *
 *  Created on: 13 gru 2015
 *      Author: Jonasz
 */

#include "button.h"


void initializeButton() {
	DDR(BUTTON_PORT) &= ~BUTTON;
	PORT(BUTTON_PORT) |= BUTTON;
}

uint8_t wasButtonClicked(uint8_t buttonPin) {
	if (!(PIN(BUTTON_PORT) & buttonPin)) {
		// the delay is added to avoid the influence of mechanical oscillation in the button
		_delay_ms(BUTTON_DELAY);

		while (!(PIN(BUTTON_PORT) & buttonPin)) {
			_delay_ms(BUTTON_DELAY);
        }

		return 1;
	}

	return 0;
}
