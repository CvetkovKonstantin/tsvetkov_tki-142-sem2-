#include "Class_Rectangle.h"
#include <math.h>

void Rectangle::CheckRectangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
{
	double d1 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	double d2 = pow(x3 - x2, 2) + pow(y3 - y2, 2);
	double d3 = pow(x3 - x1, 2) + pow(y3 - y1, 2);

	diagonal = sqrt(max(max(d1, d2), d3));

	if (abs((d1 + d2 + d3) - 2 * pow(diagonal, 2)) > 1e-9)
	{
		cerr << "Точки не образуют прямоугольник!" << endl;
		exit(1);
	}

	double sum_sq = d1 + d2 + d3 - pow(diagonal, 2);
	side_one = sqrt(min(d1, min(d2, d3)));
	side_two = sqrt(sum_sq - pow(side_one, 2));
}

Rectangle::Rectangle() : side_one(3), side_two(4), diagonal(5) {}

Rectangle::Rectangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
{
	CheckRectangle(x1, y1, x2, y2, x3, y3);
}

double Rectangle::RadiusCircle() const
{
	return diagonal / 2.0;
}

double Rectangle::Area() const
{
	return side_one * side_two;
}