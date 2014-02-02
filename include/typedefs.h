/**
 * \file typedefs.h
 *
 * \brief Ebben a fájlban találhatóak azok a változótípusok,
 * amiket a függvények használnak.
 *
 * \author Németh Levente
 * \date 2013.11.08. 23:17:17
 *
 * Változótípusokat definiáló fejlécállomány, implementáció során
 * ebben kell átírni az alaptípust.
 */


#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

/**
 * \typedef base_t
 * \brief ATmega128 környezetben használatos alaptípus.
 *
 * 8 bites jelöletlen változótípus.
 */
typedef		unsigned char	base_t;

/**
 * \typedef bool
 *
 * Logikai változótípus.
 */
typedef		base_t			bool;

/**
 * \def true
 *
 * Igaz érték (definíció a \ref bool típushoz)
 */
#define		true			1

/**
 * \def false
 *
 * Hamis érték (definíció a \ref bool típushoz)
 */
#define		false			0


#endif /* TYPEDEFS_H_ */
