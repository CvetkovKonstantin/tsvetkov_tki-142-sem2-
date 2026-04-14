#include "Class_Rectangle.h"
#include <iostream>

using namespace std;

/**
* @brief Считывает вещественное число
*/
const double GetValue();

/**
* @brief Считывает данные для точки 
*/
const Point GetPoint(int number);

int main(void)
{
	system("chcp 1251");
	system("CLS");

	const Point p1 = GetPoint(1);
	const Point p2 = GetPoint(2);
	const Point p3 = GetPoint(3);

	Rectangle Rec(p1, p2, p3);

	cout << "Площадь прямоугольника: " << Rec.Area() << endl;
	cout << "Радиус описанной окружности: " << Rec.RadiusCircle() << endl;

	return 0;
}

const Point GetPoint(int number)
{
	cout << "Введите координаты " << number << "-й точки (x, y): " << endl;
	const double x = GetValue();
	const double y = GetValue();
	return Point(x, y); 
}

const double GetValue()
{
	double number = 0;
	cin >> number;
	if (cin.fail())
	{
		cout << "Ошибка ввода!";
		exit(1);
	}
	return number;
}
