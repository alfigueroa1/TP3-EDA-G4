#ifndef BIRD_H
#define BIRD_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "types.h"
//#include "flock.h"

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
	//bool isInSight(const Bird& b, uint width, uint height, double eyeSight);

private:

	double x;
	double y;
	double currentDir;
	double newDir;
	double unitsPerTick;

};

#endif // BIRD_H


