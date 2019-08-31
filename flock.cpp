#include <stdio.h>
#include "flock.h"
#include "bird.h"


//Constructor

Bird Flock::getBird(uint i) { 
	return; 
}

//Getters
Flock::getSize() {

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

