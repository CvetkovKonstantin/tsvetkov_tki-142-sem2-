#include "Class_Point.h"

Point::Point()
{
	x = 0.0;
	y = 0.0;
}

Point::Point(const double x, const double y)
{
	this->x = x;
	this->y = y;
}

double Point::GetX() const
{
	return x;
}

double Point::GetY() const
{
	return y;
}
