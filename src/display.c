/*
 * display.c
 *
 * Created: 2013.11.10. 0:20:42
 *  Author: nemeth
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include "include/display.h"
#include "include/hardwareprofile.h"

#ifdef _USE_DISPLAY
void InitDisplay()
{
	DDR_OUT(DISP_PORT, 0xFF);
	DISP_PORT = 0x00;
#ifdef __DISPLAY_MULTI_MODE__
	DISP_OFF();

	TCNT0 = 6;
	TIMSK |= _BV(TOIE0);
	TCCR0 |= _BV(CS02);
#endif
}
#ifdef __DISPLAY_MULTI_MODE__
/**
 * \brief Adott szám megjelenítése adott kijelzőn.
 *
 * \param xNumber Kijelző száma (számozás 1-től indul)
 * \param xDig Megjelenítendő szám
 *
 * Ez a függvény annyiban különbözik a DISP_PRINT(x,y) makrótól, hogy ez csak egy globális tömbben tárolja el a számot,
 * a megjelenítés valójában a megszakítást kezelő rutinban történik.
 */
static void DPutDig(base_t xNumber, base_t xDig)
{
	switch (xDig)
	{
		case 1: DIGIT1 = xNumber; break;
		case 2: DIGIT2 = xNumber; break;
		case 3: DIGIT3 = xNumber; break;
		case 4: DIGIT4 = xNumber; break;
		default: break;
	}
}

void DPutDigs(base_t d4, base_t d3, base_t d2, base_t d1)
{
	DPutDig(d1, 1);
	DPutDig(d2, 2);
	DPutDig(d3, 3);
	DPutDig(d4, 4);
}

static inline base_t Dec4ToDigs(unsigned int uiNum, int *Digits)
{
	if (uiNum <= 9 && uiNum >= 0)
	{
		Digits[0] = uiNum % 10;
		Digits[1] = 10;
		Digits[2] = 10;
		Digits[3] = 10;
		return 1;
	}
	else if (uiNum <= 99 && uiNum >= 10)
	{
		Digits[0] = uiNum % 10;
		Digits[1] = (uiNum / 10) % 10;
		Digits[2] = 10;
		Digits[3] = 10;
		return 2;
	}
	else if (uiNum <= 999 && uiNum >= 100)
	{
		Digits[0] = uiNum % 10;
		Digits[1] = (uiNum / 10) % 10;
		Digits[2] = (uiNum / 100) % 10;
		Digits[3] = 10;
		return 3;
	}
	else if (uiNum <= 9999 && uiNum >= 1000)
	{
		Digits[0] = uiNum % 10;
		Digits[1] = (uiNum / 10) % 10;
		Digits[2] = (uiNum / 100) % 10;
		Digits[3] = (uiNum / 1000) % 10;
		return 4;
	}
	else
	{
		return 0;
	}
}

/**
 * \brief
 *
 * \param uiNum
 * \param xDigit
 *
 * \return base_t
 */
base_t DPrintToDisplay(unsigned int uiNum, uint8_t xDigit)
{
	int Digits[4];
	base_t DigsNeed = 0;

	DigsNeed = Dec4ToDigs(uiNum, Digits);

	if (DigsNeed == 1)
	{
		if (xDigit == 2)
		{
			DPutDigs(DP_OFF, DP_OFF, 0, Digits[0]);
		}
		else if (xDigit == 3)
		{
			DPutDigs(DP_OFF, 0, 0, Digits[0]);
		}
		else if (xDigit == 4)
		{
			DPutDigs(0, 0, 0, Digits[0]);
		}
		else
		{
			DPutDigs(DP_OFF, DP_OFF, DP_OFF, Digits[0]);
		}
	}
	else if (DigsNeed == 2)
	{
		if (xDigit == 3)
		{
			DPutDigs(DP_OFF, 0, Digits[1], Digits[0]);
		}
		else if (xDigit == 4)
		{
			DPutDigs(0, 0, Digits[1], Digits[0]);
		}
		else
		{
			DPutDigs(DP_OFF, DP_OFF, Digits[1], Digits[0]);
		}
	}
	else if (DigsNeed == 3)
	{
		if (xDigit == 4)
		{
			DPutDigs(0, Digits[2], Digits[1], Digits[0]);
		}
		else
		{
			DPutDigs(DP_OFF, Digits[2], Digits[1], Digits[0]);
		}
	}
	else if (DigsNeed <= 0 || DigsNeed >= 5)
	{
		return 0;
	}
	else
	{
		DPutDigs(Digits[3], Digits[2], Digits[1], Digits[0]);
	}
	return 1;
}

ISR (TIMER0_OVF_vect)
{
	static base_t xDigit = 0;
	TCNT0 = 6;
	if (xDigit == 4 && !(xNum[4]))
	{
	}
	else
	{
		DISP_PRINT(xDigit, xNum[xDigit]);
	}
	if (++xDigit == 5)
	{
		xDigit = 0;
	}
}
#endif
#endif /* USE_DISPLAY */
