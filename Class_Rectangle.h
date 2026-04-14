#pragma once
#include "Class_Point.h"
#include <iostream>

using namespace std;

/**
* @brief Класс прямоугольника по трем точкам
*/
class Rectangle
{
private:
	/**
	* @param p1, p2, p3 - точки прямоугольника
	*/
	Point p1, p2, p3;

	/**
	* @param side1 - длина первой стороны
	*/
	double side1;

	/**
	* @param side2 - длина второй стороны
	*/
	double side2;

	/**
	* @param diagonal - длина диагонали
	*/
	double diagonal;

	/**
	* @brief Статическая константа для сравнения вещественных чисел
	*/
	static const double EPS;

	/**
	* @brief Функция для первичного расчета сторон и проверки
	*/
	void Init();

public:

	/**
	* @brief Конструктор по-умолчанию
	*/
	Rectangle();

	/**
	* @brief Конструктор с параметрами
	* @param t1, t2, t3 - значения точек, которые передал пользователь
	*/
	Rectangle(Point t1, Point t2, Point t3);

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
