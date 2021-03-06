/*	Author: bshu005
 *  	Partner(s) Name: None
 *	Lab Section: 22
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B = PB0
	unsigned char tmpA1 = 0x00; //temp var to hold value of A2 = PA1;
	unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A1 = PA0 
	while(1) {
		// 1) Read input
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		// 2) Perform computation
		// if PA0 is 1 and PA1 = 0, set PB0 = 1, else PB0 = 0;
		if (tmpA0 == 0x01 && tmpA1 == 0x00) { // True if PA0 is 1 and PA1 = 0
			tmpB = (tmpB & 0xFE) | 0x01; // Sets tmpB to bbbbbbb1
							 // (clear rightmost 2 bits, then set to 01)
		} else {
			tmpB = (tmpB & 0x00); // Sets tmpB to bbbbbb00
							 
		}	
		// 3) Write output
		PORTB = tmpB;	
	}
	return 1;
}
