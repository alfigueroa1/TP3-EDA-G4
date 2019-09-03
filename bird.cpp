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

/*********************************************************************************
						  GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/

/**********************
*	CONSTRUCTORS
***********************/

//Constructores
Bird::Bird() {
	do {
		x = (rand() / ((double)RAND_MAX)) * (double)MAX_WIDTH;	//Genera posicion en X aleatoria
	} while (x >= MAX_WIDTH);
	
	do {
		y = (rand() / ((double)RAND_MAX)) * (double)MAX_HEIGHT;	//Genera posicion en Y aleatoria
	} while (y >= MAX_WIDTH);

	do {
		currentDir = ((double)rand() / (double)RAND_MAX) * 360;	//Genera angulo aleatorio
	} while (currentDir >= 360);

	speed = 1;	//Velocidad default
	newDir = 0;

}

/**********************
*	PUBLIC METHODS
***********************/
 
//Getters
double Bird::getCurrentDir() {
	return RADS(currentDir); 
}

double Bird::getNewDir() {
	return newDir;
}

double Bird::getSpeed() {
	return speed;
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

void Bird::setSpeed(double speed_) {
	speed = speed_;

}

void Bird::setX(double x_) {
	x = x_;
}

void Bird::setY(double y_) {
	y = y_;
}


/**********************
*	PRIVATE METHODS
***********************/

//Funciones
void Bird::moveBird(Bird& b) {
	
	b.x = b.x + b.speed * cos(b.getCurrentDir()); //Calcula posicion en X
	b.y = b.y + b.speed * sin(b.getCurrentDir()); //Calcula posicion en Y

	if (b.x >= MAX_WIDTH)	//Si supera el ancho maximo
	{
		b.x = b.x - MAX_WIDTH; //Le resta el ancho para que aparezca a la derecha
	}

	else if (b.x < 0)	//Si supera el minimo
	{
		b.x = b.x + MAX_WIDTH; //Le suma el ancho para que aprezca ala izquierda
	}

	if (b.y >= MAX_HEIGHT)	//Si suoera la altura maxima
	{
		b.y = b.y - MAX_HEIGHT; //Le resta la altura para que aparezaca abajo
	}

	else if (b.y < 0) //Si supera la minima
	{
		b.y = b.y + MAX_HEIGHT;	//Le suma la altura para que aparezca arriba
	}


}

void Bird::updateSpeed(Bird& b, int direction) {

	if (direction == UP_SPEED) {
		if ((b.speed + SPEED) <= MAX_SPEED) {

			b.speed = b.speed + (direction * SPEED);
		}

		else {

			b.speed = MAX_SPEED;
		}

	}

	if (direction == DOWN_SPEED) {
		if ((b.speed - SPEED) >= 0) {

			b.speed = b.speed + (direction * SPEED);
		}
		
		else {

			b.speed = 0;
		}
	}

	return;
}

void Bird::updateDir(Bird *birds, uint birdCount, double eyeSight, double randomJiggleLimit) {

	for (uint i = 0; i < birdCount; i++)
	{
		double sumsin = sin(birds[i].getCurrentDir());
		double sumcos = cos(birds[i].getCurrentDir());
		uint counter = 1;
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
	bird.speed = (rand() / ((double)RAND_MAX)) * (double)MAX_SPEED;	//Genera velocidades aleatorias para los pajaros
}

bool Bird::isInSight(Bird& bird, uint width, uint height, double eyeSight)
{
	return 0;

}

double Bird::getRandomJiggle(double randomJiggleLimit_) {
	double rndJiggle;

	do {

		rndJiggle = (rand() / (double)RAND_MAX) * randomJiggleLimit_;	//Genera un RandomJiggle aleatorio

	} while (rndJiggle > randomJiggleLimit_);

	return rndJiggle;
}