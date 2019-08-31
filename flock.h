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

	Flock(uint width_, uint height_); //Uso define en vez de los parametros?		//Si este es el constructor, es al pedo width y height
																					//Pero el constructor deberia setear eyesight y randomjjiglelimit y birdcount

	Bird getBird(Bird* birds, uint i);			//Necesaria
	uint getSize();	//Que devuelve?			//CREO QUE ESTA ES AL PEDO
	uint getWidth();						//CREO QUE ESTA ES AL PEDO
	uint getHeight();						//CREO QUE ESTA ES AL PEDO
	double getEyeSight();					//Esta es necesaria
	double getRandomJiggleLimit();			//Esta tmb

	void setEyeSight(double eyeSight_);		//Buena
	void setRandomJiggleLimit(double randomJiggleLimit_);		//Buenarda
	void setBirdCount(uint birdCount_);							//Me gusta

private:

	uint width;								//al pedo
	uint height;							//al pedo
	double eyeSight; //Van aca o en Bird?				Aca
	double randomJiggleLimit; //Van aca o en Bird?		aca
	uint birdCount; //Necesario?						Si
	Bird* birds;

};

#endif // FLOCK_H

