/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "flock.h"

 /*********************************************************************************
						   GLOBAL FUNCTION DEFINITIONS
  ********************************************************************************/

//Constructor
Flock::Flock (uint birdCount_, double eyeSight_, double randomJiggleLimit_) {
	birdCount = birdCount_;
	eyeSight = eyeSight_;
	randomJiggleLimit = randomJiggleLimit_;
	birds = NULL;
	mode = ERRORMODE;
}

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
