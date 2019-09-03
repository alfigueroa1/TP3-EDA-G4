/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
//
#include <new>
#include <cstdio>
#include <cstdlib>
//
#include "parseCallback.h"
#include "parseLib.h"
#include "frontend.h"

/*******************************************************************************
* CONSTANT AND MACRO DEFINITIONS USING #DEFINE
******************************************************************************/
#define ERROR 0

 /*******************************************************************************
  * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
  ******************************************************************************/
static bool checkInputs(int argc, char** argv, pCallback_t pToCallback, userData_t* inputData);
static void printHelpText(void);

/*********************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/

	/*********************************************************
	*		MAIN TENTATIVO
	**********************************************************/
int main(int argc, char** argv) {

	srand((unsigned int)time(NULL));
	userData_t inputData;

	//Si hubo errores en el input o iniciando el front termina el programa
	if (!initializeFrontend() || (checkInputs(argc, argv, parseCallback, &inputData) == ERROR)) {
		return ERROR;
	}

	//Inicializa Flock con los dtaos correspondientes
	Flock flock(inputData.birds, inputData.eyeSight, inputData.randomJiggleLimit, inputData.mode);

	//Empieza la simulacion
	handleBirdGraph(&flock);

	return 0;
}



 /*********************************************************************************
						LOCAL FUNCTION DEFINITIONS
 *********************************************************************************/

static bool checkInputs(int argc, char** argv, pCallback_t pToCallback, userData_t* inputData) {

	bool ret = false;

	if (parseCmdLine(argc, argv, pToCallback, inputData) == ERR_CODE) {
		printf("INPUT ERROR\n");
	}
	else if (inputData->birds == ERR_CODE) {
		printf("PLEASE ENTER A VALID BIRDS VALUE\n");
	}
	else if (inputData->eyeSight == (double)ERR_CODE) {
		printf("PLEASE ENTER A VALID EYESIGHT VALUE\n");
	}
	else if (inputData->randomJiggleLimit == (double)ERR_CODE) {
		printf("PLEASE ENTER A VALID JIGGLE LIMIT VALUE\n");
	}
	else if (inputData->mode == ERRORMODE) {
		printf("PLEASE ENTER A VALID MODE VALUE\n");
	}
	else ret = true;

	if (!ret) {
		printHelpText();
	}

	return ret;
}

static void printHelpText() {
	printf("****************************** HELP TEXT ******************************\n\n");
	printf("Valid keys: -birds (a value between 1 and %d)\n", MAX_BIRDS);
	printf("	    -eyeSight (a double between 0 and %.2f)\n", MAX_EYE_SIGHT);
	printf("	    -randomJiggleLimit (a double between 0 and %.2f)\n", MAX_JIGGLE_LIMIT);
	printf("	    -mode (1 or 2)\n");
	return;
}