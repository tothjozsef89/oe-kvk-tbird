/*
 * uart.c
 *
 *  Created on: 2014.01.31.
 *      Author: nemeth
 */
#include "include/uart.h"

#ifdef _USE_UART
static int UPutChar(char cChar, FILE *stream)
{

    if (cChar == '\n')
    	UPutChar('\r',stream);
    loop_until_bit_is_set(UCSR0A, UDRE);
    UDR0 = cChar;
    return 0;
}

static int UGetChar(FILE *stream) {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}

FILE uart = FDEV_SETUP_STREAM(UPutChar, UGetChar, _FDEV_SETUP_RW);

inline void InitUART( void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
#if USE_2X
   UCSR0A |= (1 << U2X);
#else
   UCSR0A &= ~(1 << U2X);
#endif
   stdout = &uart;
   stdin = &uart;
   UCSR0B = (1<<RXEN)|(1<<TXEN);
   UCSR0C = (1<<UCSZ00 | 1<<UCSZ01);
}
#endif

