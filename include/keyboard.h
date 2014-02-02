/**
 * \file keyboard.h
 *
 * \brief Tasztatúra beolvasásához szükséges fejlécállomány.
 *
 * \author Németh Levente
 * \date 2013.11.17. 0:16:20
 *
 * A tasztatúra lenyomott billentyűjének beolvasása.
 */
/**
 * \defgroup tasztatura Tasztatúra kezelése
 *
 * \warning \b FIGYELEM! A tasztatúra beolváshoz a \b Timer1 időzítő \b megszakítással van használva!
 *
 * A tasztatúra csatlakozása a C porthoz:
 * \image html bill_matrix.jpg
 *
 * A tasztaúra a C porthoz csatlakozik oly módon, hogy az alsó 3 bit az oszlopokat,
 * míg a [6..3] bitek a sorokat reprezentáják. Minden egyes oszlop kivezetése egy NPN tranzisztor
 * bázisára van kapcsolva
 */
/**
 * \page group__tasztatura Tasztatúra
 */
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "include/hardwareprofile.h" /** \file hardwareprofile.h */
#include "include/typedefs.h" 	/** \file typedefs.h */

#define KEYBOARD_PORT			__KEYBOARD_PORT__

#define KBD_ROW0				_BV(__KBD_ROW0__)
#define KBD_ROW1				_BV(__KBD_ROW1__)
#define KBD_ROW2				_BV(__KBD_ROW2__)
#define KBD_ROW3				_BV(__KBD_ROW3__)
#define KBD_ALL_ROW				(KBD_ROW0|KBD_ROW1|KBD_ROW2|KBD_ROW3)
#define KBD_COL_L				_BV(__KBD_COL_LEFT__)
#define KBD_COL_M				_BV(__KBD_COL_MIDDLE__)
#define KBD_COL_R				_BV(__KBD_COL_RIGHT__)
#define KBD_ALL_COL				(KBD_COL_L|KBD_COL_M|KBD_COL_R)

#define KBD_MSK					(KBD_ALL_ROW|KBD_ALL_COL)
#define KBD_1					(KBD_ROW0|(KBD_ALL_COL & ~KBD_COL_L))
#define KBD_2					(KBD_ROW0|(KBD_ALL_COL & ~KBD_COL_M))
#define KBD_3					(KBD_ROW0|(KBD_ALL_COL & ~KBD_COL_R))
#define KBD_4					(KBD_ROW1|(KBD_ALL_COL & ~KBD_COL_L))
#define KBD_5					(KBD_ROW1|(KBD_ALL_COL & ~KBD_COL_M))
#define KBD_6					(KBD_ROW1|(KBD_ALL_COL & ~KBD_COL_R))
#define KBD_7					(KBD_ROW2|(KBD_ALL_COL & ~KBD_COL_L))
#define KBD_8					(KBD_ROW2|(KBD_ALL_COL & ~KBD_COL_M))
#define KBD_9					(KBD_ROW2|(KBD_ALL_COL & ~KBD_COL_R))
#define KBD_STAR				(KBD_ROW3|(KBD_ALL_COL & ~KBD_COL_L))
#define KBD_0					(KBD_ROW3|(KBD_ALL_COL & ~KBD_COL_M))
#define KBD_DIESIS				(KBD_ROW3|(KBD_ALL_COL & ~KBD_COL_R))

enum {WRITE, WAIT, READ, READY}KBD_STATUS;
	
#define SET_ROW(x)				KEYBOARD_PORT &= ~(KBD_ALL_ROW); \
								KEYBOARD_PORT |= _BV(__KBD_ROW0__ + x);
 
volatile base_t xKbdStatus;
volatile base_t xKbd;
/**
 * \brief A tasztatúra inicializálását végző függvény.
 */
void InitKeyboard(void);
base_t KWaitForPress(void);
void KWaitForPressKey(base_t xKey);
#endif /* KEYBOARD_H_ */
