/**
 * \file buttons.h
 *
 * \brief A gombok kezeléséhez szükséges fejlécállomány.
 *
 * \author Németh Levente
 * \date 2013.11.08. 23:12:10
 *
 * A gombsoron történő vizsgálatokhoz szükséges header.
 * \sa gombok
 * \sa include/hardwareprofile.h
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "include/hardwareprofile.h" /** \file hardwareprofile.h */
#include "include/gpio.h"

#ifdef _USE_BUTTONS
/**
 * \defgroup gombok Gombok kezelése
 *
 * A nyomógombok a G port alsó 5 bemenetére
 * csatkakoznak, a port beállítását az InitButtons() függvény
 * végzi el. \n Ha a tbird.h fájl tartalmazza a következő sort:
 * \code
 * #define _USE_BUTTONS
 * \endcode
 * akkor az InitBoard() függvény automatikusan meghívja az InitButtons()
 * függvényt. \n
 * A buttons.h állományban definiálva vannak a gombok:
 * 	- \ref K0
 * 	- \ref K1
 * 	- \ref K2
 * 	- \ref K3
 * 	- \ref K4
 *
 * és az azokat kezelő függvények:
 *  - \ref BIsPress
 *  - \ref BIsOnlyPress
 *
 * Példa a használatra:
 * \code
 * #include "tbird.h"
 *
 * // Definiáljuk a K0 gombot egyedi névvel,
 * // hogy könnyebb legyen olvasni és értelmezni a kódot.
 * #define POWER 	K0
 *
 * int main()
 * {
 *		InitBoard();	// Demo panel inicializálása
 *		while(1)
 *		{
 *			if(BIsOnlyPress(POWER))	// Ha lenyomták az adott gombot...
 *			{
 *				while(BIsPress(POWER))
 *				{
 *					// ez fut, amíg nyomjuk a gombot
 *				}
 *				// ez fut le, ha elengedjük a gombot
 *			}
 *		}
 *		return 0;
 * }
 * \endcode
 * Vagy a makró segítségével:
 * \code
 * #include "tbird.h"
 *
 * // Definiáljuk a K0 gombot egyedi névvel,
 * // hogy könnyebb legyen olvasni és értelmezni a kódot.
 * #define POWER 	K0
 *
 * int main()
 * {
 *		InitBoard();	// Demo panel inicializálása
 *		while(1)
 *		{
 *			if(mButtonPressed(POWER)) // Ha lenyomták (és felengedték) a gombot...
 *			{
 *
 *			}
 *		}
 *		return 0;
 * }
 * \endcode
 * \note Egy nyomógomb lenyomását természetesen csak
 * megfelelő hardware-es vagy software-es pergésmentesítés
 * után lehet pontosan detektálni. Ezt \b nem tartalmazza ez a függvénykönyvtár.
 * \sa buttons.h
 */
/**
 *  \page group__gombok Nyomógombok
*/
#define BUTTON_PORT			__BUTTON_PORT__

#define K0 			_BV(__BUTTON0__)	//!< "K0" Nyomógomb
#define K1			_BV(__BUTTON1__) 	//!< "K1" Nyomógomb
#define K2			_BV(__BUTTON2__)	//!< "K2" Nyomógomb
#define K3			_BV(__BUTTON3__) 	//!< "K3" Nyomógomb
#define K4			_BV(__BUTTON4__)	//!< "K4" Nyomógomb
#define ALL_BTNS	(K0|K1|K2|K3|K4)	//!< Az összes nyomógomb

/**
 * \brief Gombsort inicializáló függvény
 *
 * Nyomógombokat inicializáló függvény.
 * \sa \__BUTTON_PORT__
 * \ingroup gombok
 */
void InitButtons ( void );

/**
 * \def mButtonPressed(x) mButtonOPressed(x)
 * Ez a makró segítséget nyújt a könnyebb programíráshoz.
 * Feladata, hogy addig várakoztassa a program futását,
 * amíg a gomb(ok) le van(nak) nyomva.
 *
 * \ingroup gombok
 */
#define mButtonPressed(x) if(BIsPress(x)){while(BIsPress(x)){}}
/**
 * \def mButtonOPressed(x)
 * Hasonlít az \ref mButtonPressed(x) makróhoz, csak ez akkor lép be
 * a várakozásba, ha \b kizárólag a kiválasztott gomb(ok) van(nak) lenyomva.
 *
 * \ingroup gombok
 */
#define mButtonOPressed(x) if(BIsOnlyPress(x)){while(BIsPress(x)){}}
/**
 * \brief Gomb(ok) lenyomását vizsgáló függvény.
 * @param Button Vizsgálandó gomb(ok).\n
 * Használható definíciók:
 * \ref K0, \ref K1, \ref K2, \ref K3, \ref K4, \ref ALL_BTNS
 * @return Ha a gomb(ok) le van(nak) nyomva, akkor \ref true értékkel tér vissza,
 * egyébként \ref false értékkel.
 *
 * Adott gomb(ok) állapotát vizsgálja, függetlenül a többi gomb állapotától.
 * Használata:
 * \code
 * if(BIsPress(K0))
 * {
 * 		//ez fut le, ha K0-t lenyomták
 * }
 * \endcode
 * \code
 * if(BIsPress(K0|K3))
 * {
 * 		//ez fut le, ha K0-t ÉS K3-t is lenyomták
 * }
 * \endcode
 * \ingroup gombok
 */
bool BIsPress ( base_t Button );
/**
 * \brief Gomb(ok) lenyomását vizsgáló függvény.
 * @param Button Vizsgálandó gomb(ok).\n
 * Használható definíciók:
 * \ref K0, \ref K1, \ref K2, \ref K3, \ref K4, \ref ALL_BTNS
 * @return Ha a gomb(ok) le van(nak) nyomva, akkor \ref true értékkel tér vissza
 * egyébként \ref false értékkel.
 *
 * Adott gomb(ok) állapotát vizsgálja, csak akkor tér vissza igaz értékkel,
 * ha csak és kizárólag az(ok) a gomb(ok) van(nak) lenyomva.
 * Használata:
 * \code
 * if(BIsOnlyPress(K1))
 * {
 * 		//ez fut le, ha CSAK K1-t nyomták le
 * }
 * \endcode
 * \code
 * if(BIsOnlyPress(K1|K2))
 * {
 * 		//ez fut le, ha CSAK K1-t ÉS K2-t nyomták le
 * }
 * \endcode
 * \ingroup gombok
 */
bool BIsOnlyPress ( base_t Button );

#endif /* _USE_BUTTONS */
#endif /* BUTTONS_H_ */
