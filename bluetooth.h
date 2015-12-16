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
void sendMessage(char *message);

volatile uint8_t receivedMessage;
volatile uint16_t message;
volatile uint8_t messageStarted;
volatile uint8_t messageEnded;
volatile uint8_t wasMessageReceived;
volatile unsigned int USARTBufferIndex;
char USARTBuffer[30];

#endif /* BLUETOOTH_H_ */
