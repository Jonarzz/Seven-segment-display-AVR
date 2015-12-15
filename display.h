/*
 * display.h
 *
 *  Created on: 12 gru 2015
 *      Author: Jonasz
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "microcontroller.h"


volatile uint8_t digitNumber;

volatile uint8_t cycleCounter;
volatile uint8_t secondsCounter;

uint8_t ones;
uint8_t tens;
uint8_t hundreds;
uint8_t thousands;

void initializeDisplay();
void initializeDigitsPort();
void initializeSegmentsPort();

void setUnits();
void setTens();
void setHundreds();
void setThousands();

void displayNumber(uint16_t number);
void displayDigit(uint8_t digit);

void displayOnes(uint8_t ones);
void displayTens(uint8_t tens);
void displayHundreds(uint8_t hundreds);
void displayThousands(uint8_t thousands);

#endif /* DISPLAY_H_ */
