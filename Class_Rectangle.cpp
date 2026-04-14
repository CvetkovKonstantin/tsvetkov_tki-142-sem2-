#include "Class_Rectangle.h"
#include <iostream>
#include <math.h>
#include <algorithm> 

using namespace std;

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
		cerr << "Ошибка: точки совпадают!" << endl;
		exit(1);
	}

	if (fabs((d1 + d2) - d3) > EPS)
	{
		cerr << "Ошибка: это не прямоугольник!" << endl;
		exit(1);
	}
		
	side1 = sqrt(d1);
	side2 = sqrt(d2);
	diagonal = sqrt(d3);
}

Rectangle::Rectangle()
{
	p1 = Point(0, 0);
	p2 = Point(0, 3);
	p3 = Point(4, 0);
	Init();
}

Rectangle::Rectangle(Point t1, Point t2, Point t3)
{
	p1 = t1;
	p2 = t2;
	p3 = t3;
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
