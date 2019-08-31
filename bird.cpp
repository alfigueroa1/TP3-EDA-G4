/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bird.h"
#include "flock.h"

/*******************************************************************************
* CONSTANT AND MACRO DEFINITIONS USING #DEFINE
******************************************************************************/
#define PI 3.14159265358979323846
#define RADS(x) ((x)*(PI)/(180)) //Transforma un angulo de grados a radianes

#define MAX_SPEED 10
#define SPEED 1


//Constructores
Bird::Bird(uint width, uint height) //Vale la pena el constructor?
{
	x = (rand() / ((double)RAND_MAX)) * (double)width;
	y = (rand() / ((double)RAND_MAX)) * (double)height;
	currentDir = ((double)rand() / (double)(RAND_MAX)) * 360;
	unitsPerTick = 1;

}
 
//Getters
double Bird::getCurrentDir() {
	return RADS(currentDir); 
}

double Bird::getSpeed() {
	return unitsPerTick;
}

double Bird::getX() { 
	return x; 
}

double Bird::getY() { 
	return y; 
}

//Setters
void Bird::setNewDir(double newDir_) { 
	newDir = newDir_;
}


void Bird::setCurrentDir(double currentDir_) {
	currentDir = currentDir_;
}

void Bird::setSpeed(double unitsPerTick_) {
	unitsPerTick = unitsPerTick_;

}

void Bird::setX(double x_) { 
	x = x_; 
}
void Bird::setY(double y_) { 
	y = y_; 
}

//Funciones
Bird* Bird::createBird(uint birdCount) {
	Bird* birds = (Bird*) malloc(birdCount * sizeof(Bird)); //Va aca o en Flock? //Como uso el constructor?

	return birds;

}

void Bird::moveBird(Bird* birds, uint birdCount, uint width, uint height) {
	
	for (int i = 0; i < birdCount; i++)
	{
		birds[i].setX((birds[i].getX()) + (birds[i].getSpeed()) * (cos(birds[i].getCurrentDir())));
		birds[i].setY((birds[i].getY()) + (birds[i].getSpeed()) * (sin(birds[i].getCurrentDir())));

		if (birds[i].getX() >= width)
		{
			birds[i].setX((birds[i].getX()) - width);
		}

		else if (birds[i].getX() < 0)
		{
			birds[i].setX((birds[i].getX()) + width);
		}

		if (birds[i].getY() >= height)
		{
			birds[i].setY((birds[i].getY()) - height);
		}

		else if (birds[i].getY() < 0)
		{
			birds[i].setY((birds[i].getY()) + height);
		}

	}

}

void Bird::updateSpeed(Bird* birds, uint birdCount) {

	for (int i = 0; i < birdCount; i++)
	{
		if ((birds[i].getSpeed() + SPEED) < MAX_SPEED) 
		{
			birds[i].setSpeed((birds[i].getSpeed() + SPEED)); //La velocidad aumenta de a 1?
		}
	}

}

void Bird::updateDir(Flock& f) {

	for (int i = 0; i < f.getSize(); i++)
	{
		if (isInSight(f.getBird(i), f.getWidth(), f.getHeight(), f.getEyeSight()))
		{
			double tempNewDir += f.getBird(i).getCurrentDir();
			int counter++;
		}
	}
}


void Bird::randSpeed(Bird* birds, uint birdCount)
{
	for (int i = 0; i < birdCount; i++)
	{
		birds[i].setSpeed((rand() / ((double)RAND_MAX)) * (double)MAX_SPEED);
	}
}