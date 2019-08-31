#ifndef FLOCK_H
#define FLOCK_H

typedef unsigned int uint;

class Flock {

public:


	Bird getBird(uint i);
	getSize();
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
	double eyeSight;
	double randomJiggleLimit;
	uint birdCount;
	Bird* birds;

};
#endif // FLOCK_H

