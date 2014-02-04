/*
 * keyboard.c
 *
 * Created: 2013.11.17. 0:16:00
 *  Author: nemeth
 */

#include "include/keyboard.h"

#ifdef _USE_KEYBOARD
static inline void KStartScan(void);
static inline void KStopScan(void);
static inline base_t KScanKbd(void);

inline void InitKeyboard(void)
{
	DDR_IN(KEYBOARD_PORT, KBD_ALL_COL);
	DDR_OUT(KEYBOARD_PORT, KBD_ALL_ROW);
	KEYBOARD_PORT &= ~(KBD_ALL_ROW);
	xKbd = 12;
}

ISR(TIMER2_OVF_vect)
{
	static base_t xRow = 0;
	//TCNT1 = 0xFB1E;
	TCNT2 = 0xBE;

	if (xKbdStatus == WRITE)
	{
		SET_ROW(xRow);
		xKbdStatus = WAIT;

		if (++xRow == 4)
		{
			xRow = 0;
		}
	}
	else if (xKbdStatus == WAIT)
	{
		xKbdStatus = READ;
	}
	else if (xKbdStatus == READ)
	{
		xKbd = KScanKbd();
	}
}

static inline void KStartScan(void)
{
	/*TCNT1 = 0xFB1E;
	TCCR1B |= _BV(CS11) | _BV(CS10);
	TIMSK |= _BV(TOIE1);*/
	// (16*10^6)/(1024*(255-190)) = 240 Hz
	TCNT2 = 0xBE;	// Érték: 190
	// Előosztó: 1024 (dok. 158.o.)
	TCCR2 = _BV(CS22) | _BV(CS20);
	// Megszakítás engedélyezése
	TIMSK |= _BV(TOIE2);

	xKbdStatus = WRITE;
}

static inline void KStopScan(void)
{
	TCNT2 = 0;
	TIMSK &= ~_BV(TOIE2);
}

static inline base_t KScanKbd(void)
{
	base_t xPortMask;

	xPortMask = PINS(KEYBOARD_PORT, KBD_ALL_ROW|KBD_ALL_COL);

	if (xPortMask == KBD_1)
	{
		xKbdStatus = READY;
		return 1;
	}
	else if (xPortMask == KBD_2)
	{
		xKbdStatus = READY;
		return 2;
	}
	else if (xPortMask == KBD_3)
	{
		xKbdStatus = READY;
		return 3;
	}
	else if (xPortMask == KBD_4)
	{
		xKbdStatus = READY;
		return 4;
	}
	else if (xPortMask == KBD_5)
	{
		xKbdStatus = READY;
		return 5;
	}
	else if (xPortMask == KBD_6)
	{
		xKbdStatus = READY;
		return 6;
	}
	else if (xPortMask == KBD_7)
	{
		xKbdStatus = READY;
		return 7;
	}
	else if (xPortMask == KBD_8)
	{
		xKbdStatus = READY;
		return 8;
	}
	else if (xPortMask == KBD_9)
	{
		xKbdStatus = READY;
		return 9;
	}
	else if (xPortMask == KBD_0)
	{
		xKbdStatus = READY;
		return 0;
	}
	else if (xPortMask == KBD_STAR)
	{
		xKbdStatus = READY;
		return 10;
	}
	else if (xPortMask == KBD_DIESIS)
	{
		xKbdStatus = READY;
		return 11;
	}
	else
	{
		xKbdStatus = WRITE;
		return 12;
	}
}

base_t KWaitForPress(void)
{
	KStartScan();
	do
	{
	} while (xKbdStatus != READY);
	KStopScan();
	while ((PINS(KEYBOARD_PORT, KBD_ALL_COL)) != KBD_ALL_COL);

	return xKbd;
}

void KWaitForPressKey(base_t xKey)
{
	do
	{
		KWaitForPress();
	} while (xKbd != xKey);
	KStopScan();
}
#endif
