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

using namespace std;

 /*******************************************************************************
  * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
  ******************************************************************************/
static bool checkInputs(int argc, char** argv, pCallback_t pToCallback, userData_t* inputData);
static void printHelpText(void);
/*********************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
int main(int argc, char** argv) {
	pCallback_t pToCallback = parseCallback;
	userData_t inputData;
	//if (!initializeFrontend())
	//	return 0;

	srand((unsigned int)time(NULL));

	if (checkInputs(argc, argv, pToCallback, &inputData) == 0)
		return 0;

	Flock flock(inputData.birds, inputData.eyeSight, inputData.randomJiggleLimit);
	flock.setMode(inputData.mode);

	Bird* birdStarter = new(std::nothrow)Bird[inputData.birds];
	if (birdStarter == NULL) {
		printf("Could not allocate memory for Flock\n");
		return 0;
	}
	flock.setBird(birdStarter);
	
	handleBirdGraph(&flock);

	/*********************************************************
	*		MAIN TENTATIVO
	**********************************************************/
/*	//Llamar constructor de flock con los datos
	//Construir birds segun datos
	//while(run){
		graph();
		simulationStep();
		getKeyboard();			?
	}
	//destroyEverything();
	*/

	delete[]birdStarter;
	printf("CORRECT EXECUTION!\n");
	return 0;
}


 /*********************************************************************************
						LOCAL FUNCTION DEFINITIONS
 *********************************************************************************/
static bool checkInputs(int argc, char** argv, pCallback_t pToCallback, userData_t* inputData) {
	bool ret = 0;
	if (parseCmdLine(argc, argv, pToCallback, inputData) == -1)
		printf("INPUT ERROR\n");
	else if (inputData->birds == ERR_CODE)
		printf("PLEASE ENTER A VALID BIRDS VALUE\n");
	else if (inputData->eyeSight == (double)ERR_CODE) 
		printf("PLEASE ENTER A VALID EYESIGHT VALUE\n");
	else if (inputData->randomJiggleLimit == (double)ERR_CODE)
		printf("PLEASE ENTER A VALID JIGGLE LIMIT VALUE\n");
	else if (inputData->mode == ERRORMODE)
		printf("PLEASE ENTER A VALID MODE VALUE\n");
	else ret = 1;
	if (!ret)
		printHelpText();
	return ret;
}

static void printHelpText() {
	printf("****************************** HELP TEXT ******************************\n\n");
	printf("Valid keys: -birds (a value between 0 and %d)\n", MAX_BIRDS);
	printf("	    -eyeSight (a double between 0 and %.2f)\n", MAX_EYE_SIGHT);
	printf("	    -randomJiggleLimit (a double between 0 and %.2f)\n", MAX_JIGGLE_LIMIT);
	printf("	    -mode (1 or 2)\n");
	return;
}