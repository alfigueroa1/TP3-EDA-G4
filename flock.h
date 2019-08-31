#ifndef FLOCK_H
#define FLOCK_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "types.h"

 /*******************************************************************************
  * CLASS PROTOTYPE
  ******************************************************************************/
//Esta bien esta clase? O la hice al re pedo?
class Flock {

public:

	Flock(uint width_, uint height_); //Uso define en vez de los parametros?

	Bird getBird(Bird* birds, uint i);
	uint getSize();	//Que devuelve?
	uint getWidth();
	uint getHeight();
	double getEyeSight();
	double getRandomJiggleLimit();

	void setEyeSight(double eyeSight_);
	void setRandomJiggleLimit(double randomJiggleLimit_);
	void setBirdCount(uint birdCount_);

private:

	uint width;
	uint height;
	double eyeSight; //Van aca o en Bird?
	double randomJiggleLimit; //Van aca o en Bird?
	uint birdCount; //Necesario?
	Bird* birds;

};

#endif // FLOCK_H

