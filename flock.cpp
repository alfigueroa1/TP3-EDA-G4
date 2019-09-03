/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "flock.h"
 //
#include <new>
#include <cstdio>
#include <cstdlib>
//
using namespace std;

 /*********************************************************************************
						   CLASS METHOD DEFINITIONS
  ********************************************************************************/

  /**********************
  *	   CONSTRUCTORS
  ***********************/

//Constructor
Flock::Flock (uint birdCount_, double eyeSight_, double randomJiggleLimit_, modeType mode_) {
	birdCount = birdCount_;
	eyeSight = eyeSight_;
	randomJiggleLimit = randomJiggleLimit_;
	birds = NULL;
	mode = mode_;
}

/**********************
*	 PUBLIC METHODS
***********************/

//Getters
Bird* Flock::getBird () { 
	return birds;
}

uint Flock::getBirdCount() {
	return birdCount;
}

double Flock::getEyeSight() { 
	return eyeSight; 
}

double Flock::getRandomJiggleLimit() { 
	return randomJiggleLimit; 
}

modeType Flock::getMode() {
	return mode;
}

//Setters
void Flock::setEyeSight(double eyeSight_){
	eyeSight = eyeSight_;
}

void Flock::setRandomJiggleLimit(double randomJiggleLimit_) {
	randomJiggleLimit = randomJiggleLimit_;
}

void Flock::setBirdCount(uint birdCount_) {
	birdCount = birdCount_;
}

void Flock::setMode(modeType mode_) {
	mode = mode_;
}

void Flock::setBird(Bird* bird_) {
	birds = bird_;
}

Bird* Flock::createBirds() {

	birds = new(std::nothrow)Bird[birdCount];

	if (birds == NULL) {
		printf("Could not allocate memory for Flock\n");
	}

	return birds;

}

void Flock::destroyBirds() {
	if (birds != NULL) {

		delete[]birds;
	}
}

void Flock::flockStep() {
	for (uint i = 0; i < birdCount; i++) {
		birds[i].updateDir(birds, birdCount, eyeSight, randomJiggleLimit); 	//Calcula nueva direccion para toda la parvada
	}

	for (uint i = 0; i < birdCount; i++) {
		birds[i].setCurrentDir(birds[i].getNewDir()); //Setea la nueva direccion como principal

		birds[i].moveBird(birds[i]); //Mueve todos los pajaros

	}
}