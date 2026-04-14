#include "Class_Rectangle.h"
#include <math.h>
#include <algorithm>

const double Rectangle::EPS = 1e-7;

void Rectangle::Init()
{
	double d1 = pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2);
	double d2 = pow(p3.GetX() - p2.GetX(), 2) + pow(p3.GetY() - p2.GetY(), 2);
	double d3 = pow(p3.GetX() - p1.GetX(), 2) + pow(p3.GetY() - p1.GetY(), 2);

	if (d1 > d2) swap(d1, d2);
	if (d2 > d3) swap(d2, d3);
	if (d1 > d2) swap(d1, d2);

	if (d1 < EPS || d2 < EPS || d3 < EPS)
	{
		cerr << "Заданы недопустимые значения, точки совпадают!" << endl;
		exit(1);
	}

	if (fabs((d1 + d2) - d3) > EPS)
	{
		cerr << "Заданы недопустимые значения, фигура не образует прямоугольник!" << endl;
		exit(1);
	}

	this->side1 = sqrt(d1);
	this->side2 = sqrt(d2);
	this->diagonal = sqrt(d3);
}

Rectangle::Rectangle()
{
	this->p1 = Point(0, 0);
	this->p2 = Point(0, 3);
	this->p3 = Point(4, 0);
	Init();
}

Rectangle::Rectangle(Point t1, Point t2, Point t3)
{
	this->p1 = t1;
	this->p2 = t2;
	this->p3 = t3;
	Init(); 
}

double Rectangle::Area() const
{
	return side1 * side2;
}

double Rectangle::RadiusCircle() const
{
	return diagonal / 2.0;
}
