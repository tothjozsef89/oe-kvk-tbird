/*
 * lm35.c
 *
 *  Created on: 2014.02.03.
 *      Author: nemeth
 */

#include "include/lm35.h"

#ifdef _USE_LM35
double TGetTemp(void)
{
	uint16_t uiADCVal = 0;
	double dRetVal;

	ASwitchADCH(__LM35_AN_CH__);
	if (bit_is_set(ADCSRA, ADSC))
		loop_until_bit_is_set(ADCSRA, ADSC);
	uiADCVal = ADC;
	mStartConversion();
	dRetVal = (V_INTERNAL/1024)*(uiADCVal-20); // -20 kompenzáció...
	return dRetVal;
}
#endif
