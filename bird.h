#ifndef BIRD_H
#define BIRD_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "types.h"

 /*******************************************************************************
  * CLASS PROTOTYPE
  ******************************************************************************/
class Bird {

public:

	Bird(uint width, uint height);

	double getCurrentDir();
	double getSpeed();
	//Estos dos prodrian ser una sola funcion segun agus
	double getX();
	double getY();

	void setNewDir(double newDir_);
	void setCurrentDir(double currentDir_);
	void setSpeed(double unitsPerTick_);
	//Set x y set y podrian ser una sola funcion nos dijo Agus
	void setX(double x_);
	void setY(double y_);

	Bird* createBird(uint birdCount);
	void moveBird(Bird* birds, uint birdCount, uint width, uint height);
	void updateDir(Flock& f);
	void updateSpeed(Bird* birds, uint birdCount);
	void randSpeed(Bird* birds, uint birdCount);

private:

	double x;
	double y;
	double currentDir;
	double newDir;
	double unitsPerTick;

};

#endif // BIRD_H
