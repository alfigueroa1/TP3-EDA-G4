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

	Bird* createBird(Flock& f);
	void moveBird(Flock& f);
	void updateDir(Flock& f);
	void updateSpeed(Flock& f, int direction);
	void randSpeed(Flock& f);

private:

	double x;
	double y;
	double currentDir;
	double newDir;
	double unitsPerTick;

};

#endif // BIRD_H
