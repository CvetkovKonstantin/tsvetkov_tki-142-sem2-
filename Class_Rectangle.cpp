#include "Class_Rectangle.h"
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

void Rectangle::GetSideSquares(double s[3]) const
{
	s[0] = pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2);
	s[1] = pow(p3.GetX() - p2.GetX(), 2) + pow(p3.GetY() - p2.GetY(), 2);
	s[2] = pow(p3.GetX() - p1.GetX(), 2) + pow(p3.GetY() - p1.GetY(), 2);
}

void Rectangle::CheckRectangle() const
{
	double s[3];
	GetSideSquares(s);

	if (s[0] < EPS || s[1] < EPS || s[2] < EPS)
	{
		cerr << "Заданы недопустимые значения, точки совпадают!" << endl;
		exit(1);
	}

	std::sort(s, s + 3);

	if (fabs((s[0] + s[1]) - s[2]) > EPS)
	{
		cerr << "Заданы недопустимые значения, это не прямоугольник!" << endl;
		exit(1);
	}
}

Rectangle::Rectangle()
{
	p1 = Point(0, 0);
	p2 = Point(0, 4);
	p3 = Point(3, 0);
}

Rectangle::Rectangle(const Point p1, const Point p2, const Point p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	CheckRectangle();
}

double Rectangle::Area() const
{
	double s[3];
	GetSideSquares(s);
	std::sort(s, s + 3);
	return sqrt(s[0]) * sqrt(s[1]);
}

double Rectangle::RadiusCircle() const
{
	double s[3];
	GetSideSquares(s);
	std::sort(s, s + 3);
	return sqrt(s[2]) / 2.0;
}
