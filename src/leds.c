/*
 * leds.c
 *
 * Created: 2013.11.09. 23:48:12
 *  Author: nemeth
 */ 

#include "include/leds.h"
#include "include/hardwareprofile.h"
#include "include/gpio.h"

#ifdef _USE_LEDS
void inline InitLEDs ( void )
{
	DDR_OUT(LEDS_PORT_LOW, LED0|LED1|LED2|LED3);
	DDR_OUT(LEDS_PORT_HIGH, LED4|LED5|LED6|LED7);
	LEDS_PORT_LOW		&= ~(LED0|LED1|LED2|LED3);
	LEDS_PORT_HIGH		&= ~(LED4|LED5|LED6|LED7);
}
void LShow (base_t xValue)
{
	LEDS_PORT_LOW = ((LEDS_PORT_LOW & ~(LED0|LED1|LED2|LED3)) | ((xValue & 0x0F)<<4));
	LEDS_PORT_HIGH = ((LEDS_PORT_HIGH & ~(LED4|LED5|LED6|LED7)) | (xValue & 0xF0));
}

static inline base_t LGetValue (void)
{
	base_t Value;

	Value = PIN(LEDS_PORT_HIGH) & (LED4|LED5|LED6|LED7);
	Value |= ((PIN(LEDS_PORT_LOW) & (LED0|LED1|LED2|LED3))>>4);
	return Value;
}

void LTurnOn ( base_t xLED )
{
	LShow( LGetValue() | xLED );
}

void LTurnOff ( base_t xLED )
{
	LShow( LGetValue() & (~xLED) );
}

void LToggle ( base_t xLED )
{
	if( LGetValue() & xLED )
	{
		LTurnOff(xLED);
	}
	else
	{
		LTurnOn(xLED);
	}
}
#endif
