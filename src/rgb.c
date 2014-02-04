/*
 * rgb.c
 *
 *  Created on: 2014.02.03.
 *      Author: nemeth
 */

#include "include/rgb.h"

#ifdef _USE_RGB
void InitRGB(void)
{
	DDR_OUT(RGB_RED_PORT, RGB_RED);
	DDR_OUT(RGB_GREEN_PORT, RGB_GREEN);
#ifndef _USE_BUZZER
	DDR_OUT(RGB_BLUE_PORT, RGB_BLUE);
#endif

	RGB_RED_PORT &= ~RGB_RED;
	RGB_GREEN_PORT &= ~RGB_GREEN;
#ifndef _USE_BUZZER
	RGB_BLUE_PORT &= ~RGB_BLUE;
#endif

	OCR1A = 100;	//red
	OCR1B = 50; 	//green
	OCR1C = 1020;	//blue

	// Megszakítások engedélyezése
	TIMSK |= _BV(OCIE1A) | _BV(OCIE1B);
#ifndef _USE_BUZZER
	ETIMSK |= _BV(OCIE1C);
#endif

	// PWM, Phase Correct, 10-bit (dok. 134.o.)
	TCCR1A |= _BV(WGM10) | _BV(WGM11);

	TCCR1B |= _BV(CS10)| _BV(CS11); // Start Timer

}



void RToggleRGB(base_t xColour)
{
	if (xColour == RGB_RED)
	{
		if (PINS(RGB_RED_PORT, RGB_RED))
		{
			RGB_RED_PORT &= ~RGB_RED;
		}
		else
		{
			RGB_RED_PORT |= RGB_RED;
		}
	}
	else if (xColour == RGB_GREEN)
	{
		if (PINS(RGB_GREEN_PORT, RGB_GREEN))
		{
			RGB_GREEN_PORT &= ~RGB_GREEN;
		}
		else
		{
			RGB_GREEN_PORT |= RGB_GREEN;
		}
	}
#ifndef _USE_BUZZER
	else if (xColour == RGB_BLUE)
	{
		if (PINS(RGB_BLUE_PORT, RGB_BLUE))
		{
			RGB_BLUE_PORT &= ~RGB_BLUE;
		}
		else
		{
			RGB_BLUE_PORT |= RGB_BLUE;
		}
	}
#endif
}

ISR(TIMER1_COMPA_vect)
{
	RToggleRGB(RGB_RED);
}

ISR(TIMER1_COMPB_vect)
{
	RToggleRGB(RGB_GREEN);
}

#ifndef _USE_BUZZER
ISR(TIMER1_COMPC_vect)
{
	RToggleRGB(RGB_BLUE);
}
#endif
#endif
