#pragma once
#include "Class_Point.h"

class Rectangle
{
private:
	Point p1, p2, p3;

	double side1, side2, diagonal;

	static const double EPS;


	void Init();

public:
	Rectangle();
	Rectangle(Point t1, Point t2, Point t3);

	double Area() const;
	double RadiusCircle() const;
};
