#ifndef BIRD_H
#define BIRD_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "types.h"

 /*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define SPEED		0.1
#define JIGGLE_INC	0.05
#define MAX_JIGGLE	50
#define SIGHT_INC	0.1
#define MAX_SIGHT	50
#define MAX_SPEED	10
#define UP_SPEED	1
#define DOWN_SPEED -1
#define MAX_WIDTH	100
#define MAX_HEIGHT	70

 /*******************************************************************************
  * CLASS PROTOTYPE
  ******************************************************************************/
class Bird {

public:

	Bird();
	double getCurrentDir();
	double getSpeed();
	double getX();
	double getY();
	void setNewDir(double newDir_);
	void setCurrentDir(double currentDir_);
	void setSpeed(double unitsPerTick_);
	void setX(double x_);
	void setY(double y_);

	Bird* createBird(Bird* birds, uint birdCount);	//Devuelve NULL si hay error
	void moveBird(Bird& bird);
	void updateDir(Bird* birds, uint birdCount, double eyeSight, double randomJiggleLimit);
	void updateSpeed(Bird& bird,int direction);
	void randSpeed(Bird& bird);
	bool isInSight(Bird& bird, uint width, uint height, double eyeSight); //Devuelve 1 si exito, sino devuelve 0.

private:

	double x;
	double y;
	double currentDir;
	double newDir;
	double unitsPerTick;

};


double getRandomJiggle(double randomJiggleLimit_);

#endif // BIRD_H
