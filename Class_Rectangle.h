#pragma once
#include "Class_Point.h"

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
	* @brief Константа для безопасного сравнения вещественных чисел 
	*/
	const double EPS = 1e-7;

	/**
	* @brief Вспомогательная функция для получения квадратов сторон 
	* @param s - массив для записи результатов
	*/
	void GetSideSquares(double s[3]) const;

	/**
	* @brief Функция проверки возможности существования прямоугольника
	*/
	void CheckRectangle() const;

public:

	/**
	* @brief Конструктор по-умолчанию
	*/
	Rectangle();

	/**
	* @brief Конструктор с параметрами 
	*/
	Rectangle(const Point p1, const Point p2, const Point p3);

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
