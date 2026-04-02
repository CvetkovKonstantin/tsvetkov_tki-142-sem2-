#include "Class_Rectangle.h"

/**
* @brief Считывает значение координаты с клавиатуры
* @return Значение координаты
*/
const double GetCoord(void);

/**
* @brief Точка входа в программу
* @return Возвращает 0 при корректном завершении
*/
int main(void)
{
	system("chcp 1251");
	system("CLS");

	cout << "Введите x1, y1: ";
	const double x1 = GetCoord(); const double y1 = GetCoord();
	cout << "Введите x2, y2: ";
	const double x2 = GetCoord(); const double y2 = GetCoord();
	cout << "Введите x3, y3: ";
	const double x3 = GetCoord(); const double y3 = GetCoord();

	Rectangle A(x1, y1, x2, y2, x3, y3);

	cout << "Площадь: " << A.Area() << endl;
	cout << "Радиус описанной окружности: " << A.RadiusCircle() << endl;

	return 0;
}

const double GetCoord(void)
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