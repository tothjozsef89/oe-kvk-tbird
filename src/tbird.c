/*
 * tbird.c
 *
 * Created: 2013.11.09. 23:56:39
 *  Author: nemeth
 */ 
#include "include/tbird.h"
#include <avr/interrupt.h>

void InitBoard ( void )
{
#ifdef _USE_BUTTONS
	InitButtons();
#endif // _USE_BUTTONS

#ifdef _USE_LEDS
	InitLEDs();
#endif // _USE_LEDS

#ifdef _USE_UART
	InitUART();
#endif // _USE_UART

#ifdef _USE_DISPLAY
	InitDisplay();
#endif // _USE_DISPLAY

#ifdef _USE_KEYBOARD
	InitKeyboard();
#endif // _USE_KEYBOARD
	sei();
}
