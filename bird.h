#ifndef BIRD_H
#define BIRD_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "types.h"
#include "point.h"

 /*******************************************************************************
  * CLASS PROTOTYPE
  ******************************************************************************/
class Bird {

public:

	Bird();

	double getCurrentDir();
	double getSpeed();
	Point getPoint();

	void setNewDir(double newDir_);
	void setCurrentDir(double currentDir_);
	void setSpeed(double unitsPerTick_);
	void setPoint(double x_, double y_);

	Bird* createBird(uint birdCount);
	void moveBird(Bird* birds, uint birdCount, uint width, uint height);
	void updateDir(Flock& f);
	void updateSpeed(Bird* birds, uint birdCount);
	void randSpeed(Bird* birds, uint birdCount);

private:

	Point p;
	double currentDir;
	double newDir;
	double unitsPerTick;

};

#endif // BIRD_H
