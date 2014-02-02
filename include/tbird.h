/*
 * tbird.h
 *
 * Created: 2013.11.09. 23:56:20
 *  Author: nemeth
 */ 


#ifndef TBIRD_H_
#define TBIRD_H_

#include "include/typedefs.h"
#include "include/hardwareprofile.h"

#define _USE_BUTTONS
#define _USE_LEDS
#define _USE_UART
#define _USE_DISPLAY
#define _USE_KEYBOARD

#ifdef _USE_BUTTONS
#include "include/buttons.h"
#endif // _WITH_BUTTONS

#ifdef _USE_LEDS
#include "leds.h"
#endif // _WITH_LEDS

#ifdef _USE_UART
#include "uart.h"
#endif // _WITH_UART

#ifdef _USE_DISPLAY
#include "display.h"
#endif // _WITH_DISPLAY

#ifdef _USE_KEYBOARD
#include "keyboard.h"
#endif // _WITH_KEYBOARD

/**
 * A teljes demo board-ot inicializáló függvény.
 */
void InitBoard ( void );
#endif /* TBIRD_H_ */
