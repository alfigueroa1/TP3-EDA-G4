/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

//Constructor
Point::Point() {
	x = (rand() / ((double)RAND_MAX)) * (double)MAX_WIDTH;
	y = (rand() / ((double)RAND_MAX)) * (double)MAX_HEIGHT;
}

//Getters
double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

//Setters
void Point::setX(double x_) {
	x = x_;
}

void Point::setY(double y_) {
	y = y_;
}