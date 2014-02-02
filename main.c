/*
 * main.c
 *
 *  Created on: 2013.12.31.
 *      Author: nemeth
 */

#include "include/tbird.h"
#include <avr/io.h>
#include "include/lcd.h"

int main(void)
{
	base_t szam;
	InitBoard();
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	while (1)
	{
		/*szam = KWaitForPress();
		DPrintToDisplay(szam, 1);
		switch (szam)
		{
		case 10:
			printf("Tasztatúra: *\n");
			break;
		case 11:
			//printf("Tasztatúra: #\n");
			puts("Tasztatúra: #");
			break;
		default:
			printf("Tasztatúra: %d\n", szam);
		}
		LShow(getchar());*/
		lcd_putc(getchar());
	}
}
