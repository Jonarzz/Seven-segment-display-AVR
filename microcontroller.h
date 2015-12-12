/*
 * microcontroller.h
 *
 *  Created on: 13 gru 2015
 *      Author: Jonasz
 */

#ifndef MICROCONTROLLER_H_
#define MICROCONTROLLER_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


// *** DDR - setting in/out on the pin
#define DDR(x) XDDR(x)
#define XDDR(x) (DDR##x)
// *** PORT - setting logical high/low state on the pin
#define PORT(x) XPORT(x)
#define XPORT(x) (PORT##x)
// *** PIN - reading logical high/low state on the pin
#define PIN(x) XPIN(x)
#define XPIN(x) (PIN##x)
// *** P - definition of the pin and the port (e.g. PB2, PC4)
#define P(x, y) XP(x, y)
#define XP(x, y) (P##x##y)

// the circuit diagram is attached to the project (.jpg file)
// in case of my PCB the ports are described with letter P (PAx, PBx etc.)
#define DIGITS_PORT A
#define DIGIT1 (1<<P(DIGITS_PORT, 0))
#define DIGIT2 (1<<P(DIGITS_PORT, 1))
#define DIGIT3 (1<<P(DIGITS_PORT, 2))
#define DIGIT4 (1<<P(DIGITS_PORT, 3))

// the segments are described in the display scheme attached to the project (.pdf file)
#define SEGMENTS_PORT B
#define SEGMENT_A (1<<P(SEGMENTS_PORT, 0))
#define SEGMENT_B (1<<P(SEGMENTS_PORT, 1))
#define SEGMENT_C (1<<P(SEGMENTS_PORT, 2))
#define SEGMENT_D (1<<P(SEGMENTS_PORT, 3))
#define SEGMENT_E (1<<P(SEGMENTS_PORT, 4))
#define SEGMENT_F (1<<P(SEGMENTS_PORT, 5))
#define SEGMENT_G (1<<P(SEGMENTS_PORT, 6))

#define BUTTON_PORT C
#define BUTTON (1<<P(BUTTON_PORT, 0))

#endif /* MICROCONTROLLER_H_ */
