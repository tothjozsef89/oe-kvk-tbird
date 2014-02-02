/**
 * \file include/display.h
 *
 * \brief A hétszegmenses kijelzők kezelését segítő fejléc állomány.
 *
 * \author Németh Levente
 * \date 2013.11.10. 0:17:12
 *
 * A hétszegmenses kijelzők vezérléséhez szükséges fejlécállomány.
 * \sa kijelzo
 *
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "include/hardwareprofile.h" /** \file hardwareprofile.h */
#include "include/gpio.h" /** \file gpio.h */

/**
 * \defgroup kijelzo Hétszegmenses kijelzők
 *
 * \warning \b FIGYELEM! Ha a
 * \code
 * #define __DISPLAY_MULTI_MODE__
 * \endcode
 * definíció létezik a \ref hardwareprofile.h állományban, akkor a kijelzés a \b Timer0 időzítőt
 * \b megszakítással használja! \n
 * Ha a fent említett definíció nem létezik, akkor \b CSAK a DISP_PRINT(x,y) makró használható
 * a megjelnítéshez.
 *
 * A hétszegmenses kijelzők szegmensei egy driver IC-hez csatlakoznak, amelynek 4 bemente van,
 * ez a mikrovezérlő A portjának alsó 4 bitjére csatlakozik. A port következő 3 bitje egy demultiplexerre van
 * kötve, ami a kijelzők (és kettőspont) anódjait vezérli cím alapján, az MSB bit pedig ugyenezen demux ENABLE lábára van kötve.
 * PA3...PA0 -> megjelenítendő szám BCD kódolásban
 * PA4...PA6 -> cím (000 => 1.kijelző, 001 => 2.kijelző, ... 100 => kettőspont)
 * PA7 -> ENABLE.
 * Tehát ha az A portra a következő értéket írjuk ki: 0b10100111, akkor 3.kijelzőn egy 7-es szám jelenik meg.
 * \n\n A kijelző csatlakozása az A portra:
 * \image html porta.bmp
 * Ha egyszerre több kijelzőn akarunk adatot megjeleníteni, akkor időmultiplex módon kell vezérelni.
 * \image html 7_segment.bmp
 * \n Ha a tbird.h fájl tartalmazza a következő sort:
 * \code
 * #define _USE_DISPLAY
 * \endcode
 * akkor az InitBoard() függvény automatikusan meghívja az InitDisplay() függvényt.
 *
 *  \page group__kijelzo Hétszegmenses kijelzők
*/

#ifdef _USE_DISPLAY

#define DISP_PORT		__DISPLAY_PORT__

#ifdef __DISPLAY_MULTI_MODE__
volatile base_t		xNum[5];

#define 	DIGIT1			xNum[0]
#define 	DIGIT2			xNum[1]
#define 	DIGIT3			xNum[2]
#define 	DIGIT4			xNum[3]
#define 	COLON 			xNum[4]
#define		DP_OFF			10
/**
 * \def DISP_OFF()
 *
 * \brief Kijelző kikapcsolása
 *
 *Kikapcs.
 * \ingroup kijelzo
 */
#define 	DISP_OFF()  	DIGIT1 = DP_OFF; \
							DIGIT2 = DP_OFF; \
							DIGIT3 = DP_OFF; \
							DIGIT4 = DP_OFF; \
							COLON =  0
/**
 * \def COL_ON()
 * \brief Kettőspont bekapcsolása
 */
#define		COL_ON()		COLON = 1
/**
 * \def COL_OFF()
 * \brief Kettőspont kikapcsolása
 */
#define		COL_OFF()		COLON = 0
/**
 * \def DISP_PRINT(x,y)
 *
 * \param x Kijelző sorszáma
 * \param y BCD kódolású szám
 *
 * \brief Nyers adat kiküldése a kijelzőre.
 *
 * Ezen makró segítségével egy adott kijelzőn egy számot lehet megjeleníteni.\n
 * Használata:
 *
 * \code
 * DISP_PRINT(1,5); // 5-ös megjelnítése a 2.kijelzőn
 * \endcode
 *
 * A kijelzők számozása 0-tól indul (x), a megjelenítendő szám BCD kódolásu (y).
 */
#endif
#define 	DISP_PRINT(x,y) DISP_PORT = (_BV(7) | (x<<4) | (y & 0x0F))

/**
 * \brief A kijelzők inicializálását végző függvény.
 */
void InitDisplay(void);
#ifdef __DISPLAY_MULTI_MODE__
/**
 * \brief Kiíratást valósít meg több kijelzőn.
 *
 * \param d4 Balról az 1. digit
 * \param d3 Balról a 2. digit
 * \param d2 Balról a 3. digit
 * \param d1 Balról a 4. digit
 *
 * Példa a használatra:
 * \code
 * DPutDigs(5,7,2,4);	// 5724 kiíratása a hétszegmenses kijelzőkre
 * \endcode
 * \ingroup kijelzo
 */
void DPutDigs(base_t d4, base_t d3, base_t d2, base_t d1);
base_t DPrintToDisplay (unsigned int, uint8_t);
#endif /* __DISPLAY_MULTI_MODE__*/
#endif /* _USE_DISPLAY */
#endif /* DISPLAY_H_ */
