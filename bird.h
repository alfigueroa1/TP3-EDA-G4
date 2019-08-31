#ifndef BIRD_H
#define BIRD_H

class Bird {

public:

	Bird();

	double getCurrentDir();
	double getSpeed();
	double getX();
	double getY();

	void setNewDir(double newDir_, double randomJiggleLimit);
	void setSpeed(double unitsPerTick_);
	void setX(double x_);
	void setY(double y_);

	void createBird();
	void moveBird(Bird* birds, uint birdCount, uint width, uint height);
	void updateDir(Flock& f);
	void updateSpeed(Bird* birds, uint birdCount);

private:

	double x;
	double y;
	double currentDir;
	double newDir;
	double unitsPerTick;

};

#endif // BIRD_H
