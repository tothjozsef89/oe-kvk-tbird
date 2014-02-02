/*
 * compiletime_diag.h
 *
 *  Created on: 2014.01.31.
 *      Author: nemeth
 */

#ifndef COMPILETIME_DIAG_H_
#define COMPILETIME_DIAG_H_

/* definition to expand macro then apply to pragma message */
#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "="  VALUE(var)

#endif /* COMPILETIME_DIAG_H_ */
