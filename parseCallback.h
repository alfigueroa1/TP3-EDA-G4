#ifndef PARSECALLBACK_H
#define PARSECALLBACK_H

/***************************************************************************//**
  @file     +parseCallback.h+
  @brief    +valida las entradas del usuario por consola y guarda los datos en la estructura dada.+
  @author   +Grupo 4. TP3.+
 ******************************************************************************/
/*******************************************************************************
* CONSTANT AND MACRO DEFINITIONS USING #DEFINE
******************************************************************************/
#define MAX_H				100
#define MAX_W				70
#define MAX_BIRDS			100
#define MAX_EYE_SIGHT		100.0
#define MAX_JIGGLE_LIMIT	100.0

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef struct
{
	int birds = -1;
	double eyeSight = -1;
	double randomJiggleLimit = -1;
	int mode = -1;
	bool keys[4] = { false, false, false, false };

}userData_t;

enum claves { birds, eyeSight, randomJiggleLimit, mode};

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
int parseCallback(char* key, char* value, void* userData);

#endif