/**
 * \file hardwareprofile.h
 *
 * \brief A hardware jellemzésére szolgáló fejlécállomány.
 *
 * \author Németh Levente
 * \date 2013.11.08. 23:13:15
 *
 * Ebben a fájlban kell megadni, hogy mekkora az órajel frekvencia (\ref F_CPU),
 * mely portokhoz csatlakoznak a különböző perifériák, pl.: nyomógombok (\ref \__BUTTON_PORT__),
 * LED-ek, 7 szegmenses kijelző,
 * tasztatúra, stb.
 */


#ifndef HARDWERPROFILE_H_
#define HARDWERPROFILE_H_

#include <avr/io.h>

/**
 * \def F_CPU
 * Órajel frekvencia Hz-ben.
 */
#define F_CPU					16000000UL

/**
 * \def __BUTTON_PORT__
 * Nyomógombok portja
 */
#define __BUTTON_PORT__			PORTG
#define __BUTTON0__				0
#define __BUTTON1__				1
#define __BUTTON2__				2
#define __BUTTON3__				3
#define __BUTTON4__				4

/**
 * \def __LEDS_PORT_LOW__
 * Alsó 4 LED portja
 */
#define __LEDS_PORT_LOW__		PORTB
#define __LED0__				4
#define __LED1__				5
#define __LED2__				6
#define __LED3__				7
/**
 * \def __LEDS_PORT_HIGH__
 * Felső 4 LED portja
 */
#define __LEDS_PORT_HIGH__		PORTD
#define __LED4__				4
#define __LED5__				5
#define __LED6__				6
#define __LED7__				7
/**
 * \def	__DISPLAY_PORT__
 * Hétszegmenses kijelző portja
 */
#define __DISPLAY_PORT__		PORTA
#define __DISPLAY_MULTI_MODE__

// TODO A tasztatúra univerzálissá tétele
/**
 * \def __KEYBOARD_PORT__
 * Tasztatúra portja
 */
#define __KEYBOARD_PORT__		PORTC
#define __KBD_ROW0__			3
#define __KBD_ROW1__			4
#define __KBD_ROW2__			5
#define __KBD_ROW3__			6
#define __KBD_COL_LEFT__		0
#define __KBD_COL_MIDDLE__		1
#define __KBD_COL_RIGHT__		2

#define __VREF_INTERNAL__		(_BV(REFS1) | _BV(REFS0))
#define __VREF_AVCC__			_BV(REFS0)
#define __LM35_AN_CH__			0
#define __TRIMMER_AN_CH__		1

#define __RGB_RED_PORT__		PORTC
#define __RGB_RED__				7
#define __RGB_GREEN_PORT__		PORTE
#define __RGB_GREEN__			2
#define __RGB_BLUE_PORT__		PORTE
#define __RGB_BLUE__			3

#endif /* HARDWERPROFILE_H_ */
