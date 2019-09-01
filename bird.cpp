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

//Constructores
Bird::Bird() {
	x = (rand() / ((double)RAND_MAX)) * (double)MAX_WIDTH;
	while (x >= MAX_WIDTH) x = (rand() / ((double)RAND_MAX)) * (double)MAX_WIDTH;
	y = (rand() / ((double)RAND_MAX)) * (double)MAX_HEIGHT;
	while (y >= MAX_WIDTH) y = (rand() / ((double)RAND_MAX)) * (double)MAX_WIDTH;
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
Bird* Bird::createBird(Bird *birds, uint birdCount) {
	birds = (Bird*) malloc(birdCount * sizeof(Bird)); //Va aca o en Flock? //Como uso el constructor?

	return birds;

}

void Bird::moveBird(Bird *birds, uint birdCount) {
	
	for (uint i = 0; i < birdCount; i++)
	{
		birds[i].setX((birds[i].getX()) + (birds[i].getSpeed()) * (cos(birds[i].getCurrentDir())));
		birds[i].setY((birds[i].getY()) + (birds[i].getSpeed()) * (sin(birds[i].getCurrentDir())));

		if (birds[i].getX() >= MAX_WIDTH)
		{
			birds[i].setX(birds[i].getX() - MAX_WIDTH);
		}

		else if (birds[i].getX() < 0)
		{
			birds[i].setX((birds[i].getX()) + MAX_WIDTH);
		}

		if (birds[i].getY() >= MAX_HEIGHT)
		{
			birds[i].setY((birds[i].getY()) - MAX_HEIGHT);
		}

		else if (birds[i].getY() < 0)
		{
			birds[i].setY((birds[i].getY()) + MAX_HEIGHT);
		}

	}

}

void Bird::updateSpeed(Bird *birds, uint birdCount, int direction) {

	for (uint i = 0; i < birdCount; i++)
	{
		if ((birds[i].getSpeed() + SPEED) <= MAX_SPEED && direction == 1)
			birds[i].setSpeed((birds[i].getSpeed()) + (direction * SPEED));
		else if ((birds[i].getSpeed() - SPEED) >= 0 && direction == -1)
			birds[i].setSpeed((birds[i].getSpeed()) + (direction * SPEED));
	}

}

void Bird::updateDir(Bird *birds, uint birdCount, double eyeSight, double randomJiggleLimit) {

	for (uint i = 0; i < birdCount; i++)
	{
		double sumsin = 0;
		double sumcos = 0;
		uint counter = 0;

		if (isInSight(birds[i], MAX_WIDTH, MAX_HEIGHT, eyeSight))
		{
			sumsin += sin(birds[i].getCurrentDir());
			sumcos += cos(birds[i].getCurrentDir());

			counter++;
		}

		birds[i].setNewDir((atan2((sumsin / counter), (sumcos / counter)) + randomJiggleLimit));
	}
}


void Bird::randSpeed(Bird* birds, uint birdCount)
{
	for (uint i = 0; i < birdCount; i++)
	{
		birds[i].setSpeed((rand() / ((double)RAND_MAX)) * (double)MAX_SPEED);
	}

}

bool Bird::isInSight(const Bird& b, uint width, uint height, double eyeSight)
{
	return 1;

}
