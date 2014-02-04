/*
 * tbird.h
 *
 * Created: 2013.11.09. 23:56:20
 *  Author: nemeth
 */ 


#ifndef TBIRD_H_
#define TBIRD_H_

#include "typedefs.h"
#include "hardwareprofile.h"
#include "gpio.h"
#include <avr/interrupt.h>
#include <stdio.h>

#define _USE_BUTTONS
#define _USE_LEDS
//#define _USE_UART
#define _USE_DISPLAY
#define _USE_KEYBOARD
#define _USE_TRIMMER
#define _USE_LM35
#define _USE_RGB
//#define _USE_BUZZER

//TODO Teásember!!!
//#define _USE_LCD

#ifdef _USE_BUTTONS
#include "buttons.h"
#endif // _USE_BUTTONS

#ifdef _USE_LEDS
#include "leds.h"
#endif // _USE_LEDS

#ifdef _USE_UART
#include "uart.h"
#endif // _USE_UART

#ifdef _USE_DISPLAY
#include "display.h"
#endif // _USE_DISPLAY

#ifdef _USE_KEYBOARD
#include "keyboard.h"
#endif // _USE_KEYBOARD

#ifdef _USE_TRIMMER
#ifdef _USE_LCD
#error "LCD and TRIMMER can't work at same time!"
#endif
#include "adc.h"
#include "trimmer.h"
#endif /* _USE_TRIMMER */

#ifdef _USE_LM35
#include "adc.h"
#include "lm35.h"
#endif /* _USE_LM35 */

#ifdef _USE_LCD
#ifdef _USE_TRIMMER
#error "LCD and TRIMMER can't work at same time!"
#endif
#include "lcd.h"
#endif

#ifdef _USE_RGB
#include "rgb.h"
#endif

#if defined(_USE_RGB) && defined(_USE_BUZZER)
#warning "If use buzzer the blue LED will not work!"
#endif

/**
 * A teljes demo board-ot inicializáló függvény.
 */
void InitBoard ( void );
#endif /* TBIRD_H_ */
