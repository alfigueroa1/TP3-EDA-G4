/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "flock.h"
#include "bird.h"


//Constructor
Flock::Flock(uint width_, uint height_) {
	width = width_;
	height = height_;
}

//Getters
Bird Flock::getBird(Bird* birds, uint i) { 
	return birds[i]; 
}

uint Flock::getSize() {
	return birdCount;	//Esta bien?
}

uint Flock::getWidth() { 
	return width; 
}

uint Flock::getHeight() {
	return height; 
}

double Flock::getEyeSight() { 
	return eyeSight; 
}

double Flock::getRandomJiggleLimit() { 
	return randomJiggleLimit; 
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

