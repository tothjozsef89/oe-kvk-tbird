/*
 * gpio.h
 *
 *  Created on: 2013.12.31.
 *      Author: nemeth
 */

#ifndef GPIO_H_
#define GPIO_H_

#define DDR(x) (*(&x - 1))      /* address of data direction register of port x */
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
/* on ATmega64/128 PINF is on port 0x00 and not 0x60 */
	#define PIN(x) ( &PORTF==&(x) ? _SFR_IO8(0x00) : (*(&x - 2)) )
#else
	#define PIN(x) (*(&x - 2))    /* address of input register of port x          */
#endif

#define DDR_IN(port, bits)	DDR(port) &= ~(bits)
#define DDR_OUT(port, bits)	DDR(port) |= (bits)
#define PINS(port, bits)	PIN(port) & (bits)

#endif /* GPIO_H_ */
