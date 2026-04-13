#include "Class_Rectangle.h"
#include <math.h>
#include <algorithm>

void Rectangle::CheckRectangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double d12 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	double d23 = pow(x3 - x2, 2) + pow(y3 - y2, 2);
	double d13 = pow(x3 - x1, 2) + pow(y3 - y1, 2);

	if (d12 == 0 || d23 == 0 || d13 == 0)
	{
		cerr << "Заданы недопустимые значения, точки совпадают!" << endl;
		exit(1);
	}

	double s[3] = { d12, d23, d13 };
	std::sort(s, s + 3);

	if (fabs((s[0] + s[1]) - s[2]) > 1e-7)
	{
		cerr << "Заданы недопустимые значения, точки не образуют прямоугольник!" << endl;
		exit(1);
	}
}

Rectangle::Rectangle()
{
	x1 = 0; y1 = 0;
	x2 = 0; y2 = 4;
	x3 = 3; y3 = 0;
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	this->x1 = x1; this->y1 = y1;
	this->x2 = x2; this->y2 = y2;
	this->x3 = x3; this->y3 = y3;
	CheckRectangle(x1, y1, x2, y2, x3, y3);
}

double Rectangle::Area() const
{
	double d12 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	double d23 = pow(x3 - x2, 2) + pow(y3 - y2, 2);
	double d13 = pow(x3 - x1, 2) + pow(y3 - y1, 2);

	double s[3] = { d12, d23, d13 };
	std::sort(s, s + 3);

	return sqrt(s[0]) * sqrt(s[1]);
}

double Rectangle::RadiusCircle() const
{
	double d12 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	double d23 = pow(x3 - x2, 2) + pow(y3 - y2, 2);
	double d13 = pow(x3 - x1, 2) + pow(y3 - y1, 2);

	double s[3] = { d12, d23, d13 };
	std::sort(s, s + 3);

	return sqrt(s[2]) / 2.0;
}
