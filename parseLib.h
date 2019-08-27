#ifndef PARSELIB_H
#define PARSELIB_H

/*******************************************************************************
* CONSTANT AND MACRO DEFINITIONS USING #DEFINE
******************************************************************************/
#define ERR_CODE	-1
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef int (*pCallback_t) (char*, char*, void*);

enum parseFSM { INIT, KEY, VALUE, PARAM, ERROR };
/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
int parseCmdLine(int argc, char* argv[], pCallback_t p, void* userData);	//Devuelve la cantidad de claves o parametros
																			//En caso de 

#endif
