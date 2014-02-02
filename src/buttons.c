/*
 * buttons.c
 *
 * Created: 2013.11.08. 23:11:22
 *  Author: nemeth
 */

#include "include/buttons.h"
#include "include/hardwareprofile.h"

#ifdef _USE_BUTTONS

void inline InitButtons(void)
{
	DDR_IN(BUTTON_PORT, ALL_BTNS);
}

static inline base_t BGetPortValue(void)
{
	return PINS(BUTTON_PORT, ALL_BTNS);
}

bool BIsPress(base_t Button)
{
	if (BGetPortValue() & Button)
	{
		return true;
	}
	return false;
}

bool BIsOnlyPress(base_t Button)
{
	if (Button == BGetPortValue())
	{
		return true;
	}
	return false;
}
#endif
