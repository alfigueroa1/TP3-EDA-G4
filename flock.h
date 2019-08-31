#ifndef FLOCK_H
#define FLOCK_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "types.h"

 /*******************************************************************************
  * CLASS PROTOTYPE
  ******************************************************************************/

class Flock {

public:

	Flock(uint birdCount_, double eyeSight_, double randomJiggleLimit_);

	Bird getBird(Bird* birds, uint i);
	uint getBirdCount();
	double getEyeSight();
	double getRandomJiggleLimit();

	void setEyeSight(double eyeSight_);	
	void setRandomJiggleLimit(double randomJiggleLimit_);
	void setBirdCount(uint birdCount_);

private:

	double eyeSight;
	double randomJiggleLimit;
	uint birdCount;
	Bird* birds;

};

#endif // FLOCK_H

