/*
 * header.c
 *
 *  Created on: 12 gru 2015
 *      Author: Jonasz
 */

#include "display.h"
#include "digits.h"


void initializeDisplay() {
	initializeDigitsPort();
	initializeSegmentsPort();
}

void initializeDigitsPort() {
	DDR(DIGITS_PORT) |= DIGIT1;
	DDR(DIGITS_PORT) |= DIGIT2;
	DDR(DIGITS_PORT) |= DIGIT3;
	DDR(DIGITS_PORT) |= DIGIT4;

	PORT(DIGITS_PORT) |= DIGIT1;
	PORT(DIGITS_PORT) |= DIGIT2;
	PORT(DIGITS_PORT) |= DIGIT3;
	PORT(DIGITS_PORT) |= DIGIT4;
}

void initializeSegmentsPort() {
	DDR(SEGMENTS_PORT) |= SEGMENT_A;
	DDR(SEGMENTS_PORT) |= SEGMENT_B;
	DDR(SEGMENTS_PORT) |= SEGMENT_C;
	DDR(SEGMENTS_PORT) |= SEGMENT_D;
	DDR(SEGMENTS_PORT) |= SEGMENT_E;
	DDR(SEGMENTS_PORT) |= SEGMENT_F;
	DDR(SEGMENTS_PORT) |= SEGMENT_G;

	PORT(SEGMENTS_PORT) &= ~SEGMENT_A;
	PORT(SEGMENTS_PORT) &= ~SEGMENT_B;
	PORT(SEGMENTS_PORT) &= ~SEGMENT_C;
	PORT(SEGMENTS_PORT) &= ~SEGMENT_D;
	PORT(SEGMENTS_PORT) &= ~SEGMENT_E;
	PORT(SEGMENTS_PORT) &= ~SEGMENT_F;
	PORT(SEGMENTS_PORT) &= ~SEGMENT_G;
}

void setUnits() {
	PORT(DIGITS_PORT) |= DIGIT1;
	PORT(DIGITS_PORT) &= ~DIGIT2;
	PORT(DIGITS_PORT) &= ~DIGIT3;
	PORT(DIGITS_PORT) &= ~DIGIT4;
}

void setTens() {
	PORT(DIGITS_PORT) &= ~DIGIT1;
	PORT(DIGITS_PORT) |= DIGIT2;
	PORT(DIGITS_PORT) &= ~DIGIT3;
	PORT(DIGITS_PORT) &= ~DIGIT4;
}

void setHundreds() {
	PORT(DIGITS_PORT) &= ~DIGIT1;
	PORT(DIGITS_PORT) &= ~DIGIT2;
	PORT(DIGITS_PORT) |= DIGIT3;
	PORT(DIGITS_PORT) &= ~DIGIT4;
}

void setThousands() {
	PORT(DIGITS_PORT) &= ~DIGIT1;
	PORT(DIGITS_PORT) &= ~DIGIT2;
	PORT(DIGITS_PORT) &= ~DIGIT3;
	PORT(DIGITS_PORT) |= DIGIT4;
}

void displayNumber(uint16_t number) {
	ones = number % 10;
	number /= 10;
	tens = number % 10;
	number /= 10;
	hundreds = number % 10;
	number /= 10;
	thousands = number % 10;
}

void displayOnes(uint8_t ones) {
	setUnits();
	displayDigit(ones);
}

void displayTens(uint8_t tens) {
	setTens();
	displayDigit(tens);
}

void displayHundreds(uint8_t hundreds) {
	setHundreds();
	displayDigit(hundreds);
}

void displayThousands(uint8_t thousands) {
	setThousands();
	displayDigit(thousands);
}

void displayDigit(uint8_t digit) {
	switch (digit) {
		case 0:
			setZero();
			break;
		case 1:
			setOne();
			break;
		case 2:
			setTwo();
			break;
		case 3:
			setThree();
			break;
		case 4:
			setFour();
			break;
		case 5:
			setFive();
			break;
		case 6:
			setSix();
			break;
		case 7:
			setSeven();
			break;
		case 8:
			setEight();
			break;
		case 9:
			setNine();
			break;
	}
}
