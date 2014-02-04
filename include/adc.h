/*
 * adc.h
 *
 *  Created on: 2014.02.02.
 *      Author: nemeth
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include "hardwareprofile.h"

#if defined(_USE_LM35)  || defined(_USE_TRIMMER)

#define mStartConversion()	ADCSRA |= _BV(ADSC)
#define mEnableADC()		ADCSRA |= _BV(ADEN)
#define mDisableADC()		ADCSRA &= (~(_BV(ADEN)))

#define VREF_INTERNAL		__VREF_INTERNAL__
#define V_INTERNAL			2.560

#define VREF_AVCC			__VREF_AVCC__
#define V_AVCC				4.840

void InitADC(void);
void ASwitchADCH(base_t xChannel);
uint16_t AGetADCVal(base_t xSDChannel);

#endif

#endif /* ADC_H_ */
