/*
 * rgb.h
 *
 *  Created on: 2014.02.03.
 *      Author: nemeth
 */

#ifndef RGB_H_
#define RGB_H_

#include "hardwareprofile.h"
#include "gpio.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define RGB_RED_PORT	__RGB_RED_PORT__
#define RGB_RED			_BV(__RGB_RED__)
#define RGB_GREEN_PORT	__RGB_GREEN_PORT__
#define RGB_GREEN		_BV(__RGB_GREEN__)

#ifndef _USE_BUZZER
#define RGB_BLUE_PORT	__RGB_BLUE_PORT__
#define RGB_BLUE		_BV(__RGB_BLUE__)
#endif

void InitRGB(void);
#endif /* RGB_H_ */
