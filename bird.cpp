#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bird.h"
#include "flock.h"

#define PI 3.14159265358979323846
#define RADS(x) ((x)*(PI)/(180)) //Transforma un angulo de grados a radianes

#define MAX_SPEED 1000

//Constructores
Bird::Bird()
{
	//Faltan cosas
	x = (double) rand();
	y = (double) rand() ;
	currentDir = (double) rand();
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
void Bird::setNewDir(double newDir_, double randomJiggleLimit) { 
	newDir = newDir_;
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
void Bird::createBird() {

}

void Bird::moveBird(Bird* birds, uint birdCount, uint width, uint height) {
	
	for (int i = 0; i < birdCount; i++)
	{
		birds[i].setX((birds[i].getX) + (birds[i].getSpeed) * (cos(birds[i].getCurrentDir()))); 
		birds[i].setY((birds[i].getY) + (birds[i].getSpeed) * (sin(birds[i].getCurrentDir())));

		if (birds[i].getX >= width)
		{
			birds[i].setX((birds[i].getX) - width);
		}

		else if (birds[i].getX < 0)
		{
			birds[i].setX((birds[i].getX) + width);
		}

		if (birds[i].getY >= height)
		{
			birds[i].setY((birds[i].getY) - height);
		}

		else if (birds[i].getY < 0)
		{
			birds[i].setY((birds[i].getY) + height);
		}

	}

}

void Bird::updateSpeed(Bird* birds, uint birdCount) {

	for (int i = 0; i < birdCount; i++)
	{
		birds[i].setSpeed((birds[i].getSpeed + 1));
	}

}

void Bird::updateDir(Flock& f) {

	for (int i = 0; i < f.getSize(); i++)
	{
		if (isInSight(f.getBird(i), f.getWidth, f.getHeight, f.getEyeSight))
		{
			double tempNewDir += f.getBird(i).getCurrentDir();
			int counter++;
		}
	}
}


