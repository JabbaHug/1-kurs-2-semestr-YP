#pragma once
#include <cstdint>
#include <string>
#include <iostream>

class Line;

/**
* @brief Класс цвета RGB
*/
class Color
{
public:
	friend std::ostream& operator<<(std::ostream& os, const Line& line);

private:
	/**
	*@param red - Красный цвет
	*/
	uint8_t red;
	/**
	*@param green - Зелёный цвет
	*/
	uint8_t green;
	/**
	*@param blue - Синий цвет
	*/
	uint8_t blue;

	/**
	* @brief Проверяет тип числа
	* @param number - Число
	*/
	void check_uint8_t(const int& number);

	/**
	* @brief Выбрасывает исключение
	* @param text - Текст ошибки
	*/
	static void error(const std::string text);
public:
	/**
	* @brief Конструктор, создающий чёрный цвет
	*/
	Color();

	/**
	* @brief Конструктор, создающий точку по заданными числам
	* @param red - Красный цвет
	* @param green - Зелёный цвет
	* @param blue - Синий цвет
	*/
	Color(const int& red, const int& green, const int& blue);
};

