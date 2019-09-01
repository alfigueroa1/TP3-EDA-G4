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

#define SPEED 1
#define MAX_SPEED 10
#define MAX_WIDTH 100
#define MAX_HEIGHT 70

//Constructores
Bird::Bird() {
	x = (rand() / ((double)RAND_MAX)) * (double)MAX_WIDTH;
	y = (rand() / ((double)RAND_MAX)) * (double)MAX_HEIGHT;
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
Bird* createBird(Flock& f) {
	Bird* birds = (Bird*) malloc(f.getBirdCount() * sizeof(Bird)); //Va aca o en Flock? //Como uso el constructor?

	return birds;

}

void moveBird(Flock& f) {
	
	for (uint i = 0; i < f.getBirdCount(); i++)
	{
		f.getBird(i).setX((f.getBird(i).getX()) + (f.getBird(i).getSpeed()) * (cos(f.getBird(i).getCurrentDir())));
		f.getBird(i).setY((f.getBird(i).getY()) + (f.getBird(i).getSpeed()) * (sin(f.getBird(i).getCurrentDir())));

		if (f.getBird(i).getX() >= MAX_WIDTH)
		{
			f.getBird(i).setX(f.getBird(i).getX() - MAX_WIDTH);
		}

		else if (f.getBird(i).getX() < 0)
		{
			f.getBird(i).setX((f.getBird(i).getX()) + MAX_WIDTH);
		}

		if (f.getBird(i).getY() >= MAX_HEIGHT)
		{
			f.getBird(i).setY((f.getBird(i).getY()) - MAX_HEIGHT);
		}

		else if (f.getBird(i).getY() < 0)
		{
			f.getBird(i).setY((f.getBird(i).getY()) + MAX_HEIGHT);
		}

	}

}

void updateSpeed(Flock& f, int direction) {

	for (uint i = 0; i < f.getBirdCount(); i++)
	{
		if ((f.getBird(i).getSpeed() + SPEED) < MAX_SPEED && (f.getBird(i).getSpeed() - SPEED) > 0)
		{
			f.getBird(i).setSpeed((f.getBird(i).getSpeed()) + (direction * SPEED));
		}
	}

}

void updateDir(Flock& f) {

	for (uint i = 0; i < f.getBirdCount(); i++)
	{
		double sumsin = 0;
		double sumcos = 0;
		uint counter = 0;

		if (isInSight(f.getBird(i), MAX_WIDTH, MAX_HEIGHT, f.getEyeSight()))
		{
			sumsin += sin(f.getBird(i).getCurrentDir());
			sumcos += cos(f.getBird(i).getCurrentDir());

			counter++;
		}

		f.getBird(i).setNewDir((atan2((sumsin / counter), (sumcos / counter)) + f.getRandomJiggleLimit()));
	}
}


void randSpeed(Flock& f)
{
	for (uint i = 0; i < f.getBirdCount(); i++)
	{
		f.getBird(i).setSpeed((rand() / ((double)RAND_MAX)) * (double)MAX_SPEED);
	}

}

/*
bool Bird::isInSight(Bird& b, uint width, uint height, double eyeSight)
{
	if(x+)
	{ }
	If((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y) <= eyeSight * eyeSight)
	{
		return TRUE;
	}

}
*/