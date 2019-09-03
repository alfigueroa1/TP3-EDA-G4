/***************************************************************************//**
  @file     +parseCallback.cpp+
  @brief    +valida las entradas del usuario por consola y guarda los datos en la estructura dada.+
  @author   +Grupo 4. TP3.+
 ******************************************************************************/

 /*******************************************************************************
  * INCLUDE HEADER FILES
  ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parseCallback.h"
#include "flock.h"

/*******************************************************************************
* CONSTANT AND MACRO DEFINITIONS USING #DEFINE
******************************************************************************/
#define NRO_CLAVES	4
#define INVALID		-1

#define CLAVES		0
#define TIPOS		1
#define LISTAS		2

/*******************************************************************************
* ENUMERATIONS AND STRUCTURES AND TYPEDEFS
******************************************************************************/
typedef const char* lista_t[];	//arreglo de punteros a string
typedef lista_t* pToLista_t[];	//arreglo de punteros a arreglos de punteros a string

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static int check(const char* palabra, const char* lista[], int items);
static int adminKeys(int* ptKeyPlace, userData_t* pointerData);
static int checkForZero(char* cadena);
static int saveNumber(userData_t* pointerData, int opNumber, double number);

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
 /*OPCIONES: en la primera fila están las claves, en la segunda, el tipo de dato (num o word) y en la tercera si el dato es libre o está en una lista.
			 Si el dato está en una lista, figura el número de lista*/
static const char* opciones[][NRO_CLAVES] = {
	{"birds",   "eyeSight",     "randomJiggleLimit",	"mode"},
	{"num",		"num",			"num",					"num"},
	{"any",		"any",			"any",					"any"}
};

/*******************************************************************************
 *******************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

 /************************************  parseCallback  ***********************************
 Recibe tres punteros. Los dos primeros apuntas a datos ingresados por el usuario.
 key apunta a la clave si la hay, y sino es NULL
 value es el valor de la clave si esta existe o un parámetro aislado si key es NULL
 userData apunta a la estructura de datos
 Devuelve un int: 0 si hay errores y 1 sino.
 ****************************************************************************************/
int parseCallback(char* key, char* value, void* userData) {

	userData_t* pointerData = (userData_t*)userData;	//puntero a la estructura datos

	int keyPlace = INVALID;			//lugar de la clave en el arreglo de opciones
	int valuePlace = INVALID;			//lugar del valor en una lista
	int parameterPlace = INVALID;		//lugar del parámetro en el arreglo de parámetros
	int numberList = INVALID;
	int ret = 0;
	double valor = 0;			//valor numérico ingresado por el usuario

	//CLAVE
	keyPlace = check(key, opciones[CLAVES], sizeof(opciones[CLAVES]) / sizeof(char*));	//lugar de la clave en el arreglo de claves 

	if (key != NULL)
	{
		if (keyPlace == INVALID) {}
		else if (adminKeys(&keyPlace, pointerData) == 0) {} 	//si hay un error con la clave
		else {
			if ((strcmp("num", opciones[TIPOS][keyPlace]) == 0) && (strcmp("any", opciones[LISTAS][keyPlace])) == 0)  	//si el valor debe ser un número cualquiera
			{
				if ((strcmp("birds", opciones[CLAVES][keyPlace]) == 0) && (valor = checkForZero(value)) == 0) {			//
				}										//si se piden 0 pajaros, es un error
				else if ((valor = atof(value)) == 0) {}	//si no, se guarda el numero ingresado con atof (devuelve 0 si no se pudo hacer la conversión--> caso valor inválido)
				else if (saveNumber(pointerData, keyPlace, valor) == 0) {}
				else
					ret = 1;
			}
		}
	}	
	return ret;
}



/*******************************************************************************
 *******************************************************************************
						LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

 //verifica si la palabra está o no en una lista de palabras. Devuelve el lugar del item correspondiente si está y -1 sino.
static int check(const char* palabra, const char* lista[], int items) {

	for (int i = 0; i < items; i++) {
		if (strcmp(palabra, *(lista + i)) == 0)		//si la palabra está en la lista
			return i;								//devuelve el lugar en la lista
	}
	return INVALID;		//si la palabra no está en la lista.
}

static int adminKeys(int* ptKeyPlace, userData_t* pointerData) {
	int keyState = *ptKeyPlace;
	int verify = 0;
	if (keyState == birds) {
		if (pointerData->keys[birds] == true)
			verify = 0;
		else{
			pointerData->keys[birds] = true;
			verify = 1;
		}
	}
	else if (keyState == eyeSight) {
		if (pointerData->keys[eyeSight] == true)
			verify = 0;
		else {
			pointerData->keys[eyeSight] = true;
			verify = 1;
		}
	}
	else if (keyState == randomJiggleLimit) {
		if (pointerData->keys[randomJiggleLimit] == true)
			verify = 0;
		else {
			pointerData->keys[randomJiggleLimit] = true;
			verify = 1;
		}
	}
	else if (keyState == mode) {
		if (pointerData->keys[mode] == true)
			verify = 0;
		else {
			pointerData->keys[mode] = true;
			verify = 1;
		}
	}
	return verify;
}

//Verifica si el usuario ingresó como valor numérico el cero. En tal caso devuelve cero. Caso contrario devuelve 1.
static int checkForZero(char* cadena) {
	bool point = 0;
	bool cero = 0;
	while (*cadena != '\0') {
		if (*cadena != '0') {
			if ((*cadena == '.') && (point == 0))
				point = 1;
			else
				return 1;		//no es cero
		}
		else
			cero = 1;
		cadena++;
	}
	if (cero == 1)
		return 0;	//es cero
	else
		return 1;
}
//guarda el valor numérico según la çlave. Recibe un puntero a la estructura de datos, el lugar de la clave en el arreglo y el número.
static int saveNumber(userData_t* pointerData, int opNumber, double number){
	int result = 0;
	if (opNumber == birds) {
		if ((floor(number) > 0) && (floor(number) <= MAX_BIRDS)) {
			result = 1;
			pointerData->birds = floor(number);
		}
		else 
			printf("Please enter a valid amount of birds.\n");
	}
	else if (opNumber == eyeSight) {
		if ((number >= 0.0) && (number <= MAX_EYE_SIGHT)) {
			result = 1;
			pointerData->eyeSight = number;
		}
		else if (number == 0) {
			result = 1;
			printf("eyeSight = 0.0!");
			pointerData->eyeSight = number;
		}
		else 
			printf("Please enter a valid eyeSight value.\n");
	}
	else if (opNumber == randomJiggleLimit) {
		if ((number >= 0.0) && (number <= MAX_JIGGLE_LIMIT)) {
			result = 1;
			pointerData->randomJiggleLimit = number;
		}
		else
			printf("Please enter a valid randomJiggleLimit value.\n");
	}
	else if (opNumber == mode) {
		if ((floor(number) > 0) && (floor(number) <= 2)) {
			result = 1;
			if(floor(number) == 1)
				pointerData->mode = MODE1;
			else
				pointerData->mode = MODE2;
		}
		else
			printf("Please enter a valid mode value.\n");
	}
	return result;
}