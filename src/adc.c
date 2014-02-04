/*
 * adc.c
 *
 *  Created on: 2014.02.03.
 *      Author: nemeth
 */
#include "include/adc.h"

#if defined(_USE_LM35)  || defined(_USE_TRIMMER)
void InitADC(void)
{
	DDRF &= 0x0E;
	PORTF &= 0xFE;
	ADMUX |= VREF_AVCC;
	ADCSRA |= (_BV(ADPS1) | _BV(ADEN) | _BV(ADSC));
}

void ASwitchADCH(base_t xChannel)
{
	if (xChannel == __TRIMMER_AN_CH__)
	{
		if (((ADMUX & 7) != __TRIMMER_AN_CH__) || ((ADMUX & 0xC0) != VREF_AVCC))
		{
			mDisableADC();
			ADMUX |= __TRIMMER_AN_CH__ | VREF_AVCC;
			mEnableADC();
			mStartConversion();
			loop_until_bit_is_set(ADCSRA, ADSC);
			mStartConversion();
		}
	}
	else if (xChannel == __LM35_AN_CH__)
	{
		if (((ADMUX & 7) != __LM35_AN_CH__)
				|| ((ADMUX & 0xC0) != VREF_INTERNAL))
		{
			mDisableADC();
			ADMUX |= __LM35_AN_CH__ | VREF_INTERNAL;
			mEnableADC();
			mStartConversion();
			loop_until_bit_is_set(ADCSRA, ADSC);
			mStartConversion();
		}
	}

}

uint16_t AGetADCVal(base_t xADChannel)
{
	uint16_t uiRetVal = 0;

	ASwitchADCH(xADChannel);
	if (bit_is_set(ADCSRA, ADSC))
			loop_until_bit_is_set(ADCSRA, ADSC);
	uiRetVal = ADC;
	mStartConversion();
	return uiRetVal;
}
#endif
