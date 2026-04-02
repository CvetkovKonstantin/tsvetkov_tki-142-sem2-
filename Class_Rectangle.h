#pragma once
#include <string>
#include <iostream>

using namespace std;

/**
* @brief Класс прямоугольника
*/
class Rectangle
{
private:
	/**
	* @param side_one - длина первой стороны
	*/
	double side_one;

	/**
	* @param side_two - длина второй стороны
	*/
	double side_two;

	/**
	* @param diagonal - длина диагонали
	*/
	double diagonal;

	/**
	* @brief Проверка, образуют ли 3 точки прямоугольный угол
	*/
	void CheckRectangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);

public:

	/**
	* @brief Конструктор по-умолчанию
	*/
	Rectangle();

	/**
	* @brief Конструктор по координатам трех точек
	*/
	Rectangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);

	/**
	* @brief Рассчитывает радиус описанной окружности
	* @return Радиус
	*/
	double RadiusCircle() const;

	/**
	* @brief Рассчитывает площадь прямоугольника
	* @return Площадь
	*/
	double Area() const;
};
