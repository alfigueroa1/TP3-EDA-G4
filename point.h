#ifndef POINT_H
#define POINT_H

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class Point: {

public:

	double getX();
	double getY();

	void setX(double x_);
	void setY(double y_);

private:

	double x;
	double y;
}

#endif // POINT_H
