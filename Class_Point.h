#pragma once

/**
* @brief Класс точка для хранения координат
*/
class Point
{
private:
	/**
	* @param x - координата X
	*/
	double x;

	/**
	* @param y - координата Y
	*/
	double y;

public:
	/**
	* @brief Конструктор по-умолчанию
	*/
	Point();

	/**
	* @brief Конструктор с параметрами
	* @param x - координата X
	* @param y - координата Y
	*/
	Point(const double x, const double y);

	/**
	* @brief Геттер координаты X
	*/
	double GetX() const;

	/**
	* @brief Геттер координаты Y
	*/
	double GetY() const;
};
