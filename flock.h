#ifndef FLOCK_H
#define FLOCK_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "types.h"
#include "bird.h"

 /*******************************************************************************
  * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
  *****************************************************************************/
typedef enum { ERRORMODE, MODE1, MODE2} modeType;

 /*******************************************************************************
  * CLASS PROTOTYPE
  ******************************************************************************/
class Flock {

public:

	Flock (uint birdCount_, double eyeSight_, double randomJiggleLimit_, modeType mode_);
	~Flock();

	Bird* getBird ();
	uint getBirdCount ();
	double getEyeSight ();
	double getRandomJiggleLimit ();
	modeType getMode ();
	void setEyeSight(double eyeSight_);	
	void setRandomJiggleLimit(double randomJiggleLimit_);
	void setBirdCount(uint birdCount_);
	void setMode(modeType mode_);
	void setBird(Bird* bird_);

	void flockStep();

private:

	modeType mode;
	double eyeSight;
	double randomJiggleLimit;
	uint birdCount;
	Bird *birds;

};

#endif // FLOCK_H