#ifndef LEDS_H_
#define LEDS_H_

/**
 * \file include/leds.h
 *
 * \brief A LED-ek kezeléséhez szükséges fejlécállomány.
 *
 * \author Németh Levente
 * \date 2013.11.09. 23:47:59
 *
 * LED-eket manipuláló függvények gyűjteménye.
 *
 * \sa ledek
 */

/**
 * \defgroup ledek LED-ek kezelése
 *
 * A LED-ek csatlakozása a portokhoz:
 * \image html t_bird_led.jpg
 *
 * A felső 4 LED (LED7...LED4) a D port felső 4 bitjére, az alsó 4 LED (LED3...LED0) \n
 * a B port felső 4 bitjére csatkakoznak, a portok beállítását az InitLEDs() függvény
 * végzi el. \n Ha a tbird.h fájl tartalmazza a következő sort:
 * \code
 * #define _USE_LEDS
 * \endcode
 * akkor az InitBoard() függvény automatikusan meghívja az InitLEDs()
 * függvényt. \n
 * A include/leds.h állományban definiált LED-ek:
 * 	- LED0
 * 	- LED1
 * 	- LED2
 * 	- LED3
 * 	- LED4
 * 	- LED5
 * 	- LED6
 * 	- LED7
 *
 * és az azokat kezelő függvények:
 *  - LShow()
 *  - LTurnOn()
 *  - LTurnOff()
 *  - LToggle()
 *
 * Példa a használatra:
 *
 * \code
 * #include "include/tbird.h"
 *
 * // Definiáljuk a 4. LED-et egyedi névvel,
 * // hogy könnyebb legyen olvasni és értelmezni a kódot.
 * #define 	PWR_LED	 	LED3
 *
 * int main()
 * {
 *		InitBoard();	// Demo panel inicializálása
 *		while(1)
 *		{
 *			if(valamilyen_feltetel)
 *			{
 *				LToggle(PWR_LED);	// Ha a feltétel teljesült, PWR_LED állapota
 *									// az ellentettjére változik.
 *			}
 *		}
 *		return 0;
 * }
 * \endcode
 * \sa include/leds.h
 * \sa include/hardwareprofile.h
 * \sa \__LEDS_PORT_LOW__
 * \sa \__LEDS_PORT_HIGH__
 */

/**
 *  \page group__ledek LED-ek
 */
#include "include/hardwareprofile.h" /** \file include/hardwareprofile.h */

#ifdef _USE_LEDS
#define LEDS_PORT_LOW		__LEDS_PORT_LOW__
#define LEDS_PORT_HIGH		__LEDS_PORT_HIGH__

#define LED0			_BV(__LED0__)	//!< LED0, 1. LED
#define LED1			_BV(__LED1__)	//!< LED1, 2. LED
#define LED2			_BV(__LED2__)	//!< LED2, 3. LED
#define LED3			_BV(__LED3__)	//!< LED3, 4. LED
#define LED4			_BV(__LED4__)	//!< LED4, 5. LED
#define LED5			_BV(__LED5__)	//!< LED5, 6. LED
#define LED6			_BV(__LED6__)	//!< LED6, 7. LED
#define LED7			_BV(__LED7__)	//!< LED7, 8. LED

/**
 * \brief LED-eket inicializáló függvény.
 *
 * \ingroup ledek
 */
void InitLEDs ( void );
/**
 * \brief 8 bites érték megjelenítése a LED-eken.
 * @param xValue 8 bites érték
 *
 * \ingroup ledek
 */
void LShow ( base_t xValue );
/**
 * \brief LED(ek) bekapcsolása.
 * @param xLED Bekapcsolni kívánt LED.
 *
 * \code
 * LTurnOn(LED0|LED5);	//1. és 4. LED bekapcsolása
 * \endcode
 *
 * \ingroup ledek
 */
void LTurnOn ( base_t xLED );
/**
 * \brief LED(ek) kikapcsolása.
 * @param xLED Kikapcsolni kívánt LED.
 *
 * \code
 * LTurnOff(LED2|LED7); // 3. és 8. LED kikapcsolása
 * \endcode
 *
 * \ingroup ledek
 */
void LTurnOff ( base_t xLED );
/**
 * \brief LED(ek) állapotának megváltoztatása.
 * @param xLED Változtatni kívánt LED
 *
 * \code
 * LToggle(LED3|LED1); //4. és 2. LED állapotának megváltoztatása
 * \endcode
 *
 * \ingroup ledek
 */
void LToggle ( base_t xLED );

#endif /* _USE_LEDS */
#endif /* LEDS_H_ */
