/*
 * trimmer.c
 *
 *  Created on: 2014.02.02.
 *      Author: nemeth
 */

#include "include/trimmer.h"

#ifdef _USE_TRIMMER

double TGetTrimmerVal(void)
{
	uint16_t uiADCVal = 0;
	double dRetVal;

	ASwitchADCH(__TRIMMER_AN_CH__);
	if (bit_is_set(ADCSRA, ADSC))
		loop_until_bit_is_set(ADCSRA, ADSC);
	uiADCVal = ADC;
	mStartConversion();
	dRetVal = (V_AVCC/1024)*uiADCVal;
	return dRetVal;
}
#endif /* _USE_TRIMMER */
