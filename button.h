/*
 * button.h
 *
 *  Created on: 13 gru 2015
 *      Author: Jonasz
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "microcontroller.h"


#define BUTTON_DELAY 20

uint8_t clicksCounter;

void initializeButton();
uint8_t wasButtonClicked(uint8_t buttonPin);

#endif /* BUTTON_H_ */
