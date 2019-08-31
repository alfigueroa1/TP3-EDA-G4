/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "flock.h"
#include "bird.h"


//Constructor
Flock::Flock(uint birdCount_, double eyeSight_, double randomJiggleLimit_) {
	birdCount = birdCount_;
	eyeSight = eyeSight_;
	randomJiggleLimit = randomJiggleLimit_;
}

//Getters
Bird Flock::getBird(uint i) { 
	return birds[i]; 
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

