/*
 * uart.h
 *
 *  Created on: 2014.01.31.
 *      Author: nemeth
 */

#ifndef UART_H_
#define UART_H_


#include "include/hardwareprofile.h"
#include "include/tbird.h"
#include <avr/io.h>
#include <stdio.h>
#ifdef _USE_UART
#define BAUD					9600
#define USE_2X					0
#include <util/setbaud.h>

void InitUART( void);
#endif /* _USE_UART */
#endif /* UART_H_ */
