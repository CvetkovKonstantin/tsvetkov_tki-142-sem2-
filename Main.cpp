#include "Class_Rectangle.h"

/**
* @brief Считывает значение введённое с клавиатуры
* @return Значение введённое с клавиатуры, если оно считано правильно
*/
const double GetValue(void);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main(void)
{
	system("chcp 1251");
	system("CLS");

	cout << "Введите координаты 1-й точки (x1, y1): " << endl;
	const double x1 = GetValue();
	const double y1 = GetValue();

	cout << "Введите координаты 2-й точки (x2, y2): " << endl;
	const double x2 = GetValue();
	const double y2 = GetValue();

	cout << "Введите координаты 3-й точки (x3, y3): " << endl;
	const double x3 = GetValue();
	const double y3 = GetValue();

	Rectangle Rec(x1, y1, x2, y2, x3, y3);

	cout << "Площадь прямоугольника: " << Rec.Area() << endl;
	cout << "Радиус описанной окружности: " << Rec.RadiusCircle() << endl;

	return 0;
}

const double GetValue(void)
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
