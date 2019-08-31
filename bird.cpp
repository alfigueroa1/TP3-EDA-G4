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
Bird::Bird() {
	Point p;
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

Point Bird::getPoint() {
	return p;
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

void Bird::setPoint(double x_, double y_) {
	p.setX(x_);
	p.setY(y_);
}

//Funciones
Bird* Bird::createBird(uint birdCount) {
	Bird* birds = (Bird*) malloc(birdCount * sizeof(Bird)); //Va aca o en Flock? //Como uso el constructor?

	return birds;

}

void Bird::moveBird(Bird* birds, uint birdCount, uint width, uint height) {
	
	for (int i = 0; i < birdCount; i++)
	{
		birds[i].setPoint((birds[i].getPoint().getX()) + (birds[i].getSpeed()) * (cos(birds[i].getCurrentDir())), (birds[i].getPoint().getY()) + (birds[i].getSpeed()) * (sin(birds[i].getCurrentDir())));

		if (birds[i].getPoint().getX() >= width)
		{
			birds[i].getPoint().setX(birds[i].getPoint().getX - width);
		}

		else if (birds[i].getPoint().getX() < 0)
		{
			birds[i].getPoint.setX((birds[i].getPoint().getX()) + width);
		}

		if (birds[i].getPoint().getY() >= height)
		{
			birds[i].getPoint().setY((birds[i].getPoint().getY()) - height);
		}

		else if (birds[i].getPoint().getY() < 0)
		{
			birds[i].getPoint().setY((birds[i].getPoint().getY()) + height);
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