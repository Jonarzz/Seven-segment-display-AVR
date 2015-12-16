/*
 * main.c
 *
 *  Created on: 12 gru 2015
 *      Author: Jonasz
 */

#include "display.h"
//#include "button.h"
#include "bluetooth.h"

void interrupt_init();

int main() {
	digitNumber = 1;
	secondsCounter = 0;
	cycleCounter = 0;

	interrupt_init();
	initUSART();
	sei();

	initializeDisplay();
	/*initializeButton();*/
	receivedMessage = 0;
	messageStarted = 0;
	messageEnded = 0;
	USARTBufferIndex = 0;

	while (1) {
		if (messageEnded) {
			displayNumber(message);
			wasMessageReceived = 0;
			messageEnded = 0;
			sendMessage("hello");
		}
	}
}

void interrupt_init() {
	TCCR1B |= (1 << CS11) | (1 << WGM12);
	TIMSK |= (1 << OCIE1A);
	OCR1A = 10000;
}

ISR(TIMER1_COMPA_vect) {
	digitNumber++;
	if (digitNumber > 4) {
		digitNumber = 1;
	}

	switch (digitNumber) {
			case 1:
				displayOnes(ones);
				break;
			case 2:
				displayTens(tens);
				break;
			case 3:
				displayHundreds(hundreds);
				break;
			case 4:
				displayThousands(thousands);
				break;
		}
}

ISR(USART0_RX_vect) {
	receivedMessage = UDR0;   //zapamiêtaj odebran¹ liczbê
	if (messageStarted == 0 && receivedMessage == '^') {
		message = 0;
		messageStarted = 1;
	}

	if (messageStarted && receivedMessage != '^' && receivedMessage != '&') {
		receivedMessage -= '0';
		if (message == 0) {
			message += receivedMessage;
		} else if (message < 10) {
			message = message*10 + receivedMessage;
		} else if (message < 100) {
			message = message*10 + receivedMessage;
		} else if (message < 1000) {
			message = message*10 + receivedMessage;
		}
	}

	if (messageStarted == 1 && receivedMessage == '&') {
		messageStarted = 0;
		messageEnded = 1;
	}

	wasMessageReceived = 1; //ustaw flagê odbioru liczby dla main()
}

ISR(USART0_UDRE_vect){
	 if(USARTBuffer[USARTBufferIndex] != 0) {
		 UDR0 = USARTBuffer[USARTBufferIndex++];
	 }
	 else {
		 UCSR0B &= ~(1<<UDRIE);
	 }
}
