/*
 * bluetooth.h
 *
 *  Created on: 15 gru 2015
 *      Author: Jonasz
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "microcontroller.h"

void initUSART();

volatile uint8_t receivedMessage;
volatile uint16_t message;
volatile uint8_t messageStarted;
volatile uint8_t messageEnded;
volatile uint8_t wasMessageReceived;

#endif /* BLUETOOTH_H_ */
