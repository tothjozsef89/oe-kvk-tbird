/*
 * uart.h
 *
 *  Created on: 2014.01.31.
 *      Author: nemeth
 */

#ifndef UART_H_
#define UART_H_

#include "include/tbird.h"

#ifdef _USE_UART
#define BAUD					9600
#define USE_2X					0
#include <util/setbaud.h>

void InitUART( void);
#endif /* _USE_UART */
#endif /* UART_H_ */
