#include "../Solver/Color.h"

void Color::check_uint8_t(const int& number)
{
	if (number > 255 || number < 0)
	{
		error("Выход за пределы цветового охвата");
	}
}

void Color::error(const std::string text)
{
	throw std::runtime_error(text);
}

Color::Color() :red(0), green(0), blue(0)
{
}

Color::Color(const int& red, const int& green, const int& blue)
{
	check_uint8_t(red);
	this->red = red;

	check_uint8_t(green);
	this->green = green;

	check_uint8_t(blue);
	this->blue = blue;
}
