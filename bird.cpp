/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bird.h"
#include "flock.h"
//
#include <new>
#include <cstdio>
#include <cstdlib>
//
using namespace std;

/*******************************************************************************
* CONSTANT AND MACRO DEFINITIONS USING #DEFINE
******************************************************************************/
#define PI 3.14159265358979323846
#define RADS(x) ((x)*(PI)/(180)) //Transforma un angulo de grados a radianes

/*********************************************************************************
						  GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
//Constructores
Bird::Bird() {
	do {
		x = (rand() / ((double)RAND_MAX)) * (double)MAX_WIDTH;	//Genera posicion en X aleatoria
	} while (x >= MAX_WIDTH);
	
	do {
		y = (rand() / ((double)RAND_MAX)) * (double)MAX_HEIGHT;	//Genera posicion en Y aleatoria
	} while (y >= MAX_WIDTH);

	currentDir = ((double)rand() / (double)RAND_MAX) * 360;	//Genera angulo aleatorio
	unitsPerTick = 1;	//Velocidad default
	newDir = 0;

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
	birds = new(std::nothrow)Bird[birdCount];

	if (birds == NULL) {
		printf("Could not allocate memory for Flock\n");
	}

	return birds;

}

void Bird::moveBird(Bird& bird) {
	
	bird.setX((bird.getX()) + (bird.getSpeed()) * (cos(bird.getCurrentDir())));	//Calcula posicion en X
	bird.setY((bird.getY()) + (bird.getSpeed()) * (sin(bird.getCurrentDir())));	//Calcula posicion en Y

	if (bird.getX() >= MAX_WIDTH)	//Si supera el ancho maximo
	{
		bird.setX(bird.getX() - MAX_WIDTH); //Le resta el ancho para que aparezca a la derecha
	}

	else if (bird.getX() < 0)	//Si supera el minimo
	{
		bird.setX((bird.getX()) + MAX_WIDTH); //Le suma el ancho para que aprezca ala izquierda
	}

	if (bird.getY() >= MAX_HEIGHT)	//Si suoera la altura maxima
	{
		bird.setY((bird.getY()) - MAX_HEIGHT); //Le resta la altura para que aparezaca abajo
	}

	else if (bird.getY() < 0) //Si supera la minima
	{
		bird.setY((bird.getY()) + MAX_HEIGHT);	//Le suma la altura para que aparezca arriba
	}


}

void Bird::updateSpeed(Bird& bird, int direction) {

	if (direction == UP_SPEED) {
		if ((bird.getSpeed() + SPEED) <= MAX_SPEED) {

			bird.setSpeed((bird.getSpeed()) + (direction * SPEED));
		}

		else {

			bird.setSpeed(MAX_SPEED);
		}

	}

	if (direction == DOWN_SPEED) {
		if ((bird.getSpeed() - SPEED) >= 0) {

			bird.setSpeed((bird.getSpeed()) + (direction * SPEED));
		}
		
		else {

			bird.setSpeed(0);
		}
	}

	return;
}

void Bird::updateDir(Bird *birds, uint birdCount, double eyeSight, double randomJiggleLimit) {

	for (uint i = 0; i < birdCount; i++)
	{
		double sumsin = 0;
		double sumcos = 0;
		uint counter = 0;
		double newDir_ = 0;

		if (isInSight(birds[i], MAX_WIDTH, MAX_HEIGHT, eyeSight))
		{
			sumsin += sin(birds[i].getCurrentDir());	//Suma de todos los sin de los pajaros en radio
			sumcos += cos(birds[i].getCurrentDir());	//Suma de todos los cos de los pajaros en radio

			counter++;	//Aumento contador de pajaros
		}

		newDir_ = atan2((sumsin / counter), (sumcos / counter)) - getRandomJiggle(randomJiggleLimit) + getRandomJiggle(randomJiggleLimit); //Formula para calcular el promedio de los angulos 
		if (newDir_ < 0)
		{
			newDir_ = 360 - newDir_;
		}

		birds[i].setNewDir(newDir_);
	}
}


void Bird::randSpeed(Bird& bird)
{
	bird.setSpeed((rand() / ((double)RAND_MAX)) * (double)MAX_SPEED);	//Genera velocidades aleatorias para los pajaros
}

bool Bird::isInSight(Bird& bird, uint width, uint height, double eyeSight)
{
	return 1;

}

double getRandomJiggle(double randomJiggleLimit_) {
	double rndJiggle;

	do {

		rndJiggle = (rand() / ((double)RAND_MAX)) * (double)MAX_WIDTH;	//Genera un RandomJiggle aleatorio

	} while (rndJiggle >= randomJiggleLimit_);

	return rndJiggle;
}