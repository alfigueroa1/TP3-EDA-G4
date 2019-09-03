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
	birds = new(std::nothrow)Bird[birdCount];
	mode = mode_;

	if (mode == MODE2 && birds != NULL) {
		for (uint i = 0; i < birdCount; i++)
			(birds + i)->randSpeed(birds[i]);
	}
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


Flock::~Flock() {
	if (birds != NULL) {

		delete[]birds;
	}
}

void Flock::flockStep() {
	for (uint i = 0; i < birdCount; i++) {
		birds[i].updateDir(birds, birdCount, eyeSight, randomJiggleLimit); 	//Calcula nueva direccion para toda la parvada
	}

	for (uint i = 0; i < birdCount; i++) {

		birds[i].moveBird(birds[i]); //Mueve todos los pajaros

		birds[i].setCurrentDir(birds[i].getNewDir()); //Setea la nueva direccion como principal
	}
}