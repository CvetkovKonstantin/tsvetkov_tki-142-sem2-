#pragma once
#include <string>
#include <iostream>

using namespace std;

/**
* @brief Класс прямоугольника по трем точкам
*/
class Rectangle
{
private:
	/**
	* @param x1, y1 - координаты первой точки
	*/
	double x1, y1;

	/**
	* @param x2, y2 - координаты второй точки
	*/
	double x2, y2;

	/**
	* @param x3, y3 - координаты третьей точки
	*/
	double x3, y3;

	/**
	* @brief Функция проверки возможности существования прямоугольника
	* @param x1, y1, x2, y2, x3, y3 - координаты точек
	*/
	void CheckRectangle(double x1, double y1, double x2, double y2, double x3, double y3);

public:

	/**
	* @brief Конструктор по-умолчанию, задает прямоугольник со сторонами 3 и 4
	*/
	Rectangle();

	/**
	* @brief Конструктор, задаёт координаты точек пользователя
	*/
	Rectangle(double x1, double y1, double x2, double y2, double x3, double y3);

	/**
	* @brief Рассчитывает площадь прямоугольника
	* @return Площадь прямоугольника
	*/
	double Area() const;

	/**
	* @brief Рассчитывает радиус описанной окружности
	* @return Радиус описанной окружности
	*/
	double RadiusCircle() const;
};
