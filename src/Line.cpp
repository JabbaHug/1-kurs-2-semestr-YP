#include "../Solver/Line.h"

void Line::error(const std::string text)
{
	throw std::runtime_error(text);
}

Line::Line(): first(0,0), second(1, 1)
{
}

Line::Line(const Point& first, const Point& second)
{
	if (first == second)
	{
		error("Точки не могут совпадать");
	}

	this->first = first;
	this->second = second;
	this->style = LineStyle();
}

Line::Line(const Point& first, const Point& second, const LineStyle& style)
{
	if (first == second)
	{
		error("Точки не могут совпадать");
	}

	this->first = first;
	this->second = second;
	this->style = style;
}

void Line::setStyle(const LineStyle& style)
{
	this->style = style;
}

void Line::setColor(const Color& color)
{
	this->style = LineStyle(color, this->style.type, this->style.thickness);
}

Line Line::read(std::istream& is)
{

        Point first;
        Point second;

        int red = 0;
        int green = 0;
        int blue = 0;

        int lineType = 1;
        int thickness = 1;

        std::cout << "Введите координаты первой точки x y: ";
        is >> first;

        std::cout << "Введите координаты второй точки x y: ";
        is >> second;

        if (first == second)
        {
            error("Точки не могут совпадать");
        }

        std::cout << "Введите цвет линии RGB от 0 до 255: ";
        is >> red >> green >> blue;

        if (!is)
        {
            error("Ошибка ввода");
        }

        Color color(red, green, blue);

        enum line {
            Solid = 1,
            Dash,
            Dot,
            DashDot,
            DashDotDot
        };

        std::cout << "Выберите тип линии:" << std::endl;
        std::cout << Solid << " - solid" << std::endl;
        std::cout << Dash << " - dash" << std::endl;
        std::cout << Dot << " - dot" << std::endl;
        std::cout << DashDot << " - dash-dot" << std::endl;
        std::cout << DashDotDot << " - dashdotdot" << std::endl;

        std::cout << "Введите тип линии: ";
        is >> lineType;

        std::cout << "Введите толщину линии: ";
        is >> thickness;

        if (!is)
        {
            error("Ошибка ввода");
        }

        if (lineType < 1 || lineType > 5)
        {
            error("Неверный тип линии");
        }

        LineStyle style(color, static_cast<LineStyle::LineType>(lineType), thickness);

        return Line(first, second, style);
}

std::ostream& operator<<(std::ostream& os, const Line& line)
{
    os << "Линия:" << std::endl;

    os << "Первая точка: "
        << "(" << line.first.getX() << "; " << line.first.getY() << ")"
        << std::endl;

    os << "Вторая точка: "
        << "(" << line.second.getX() << "; " << line.second.getY() << ")"
        << std::endl;

	os << "Тип линии: "
		<< line.style.getType()
		<< std::endl;

    os << "Толщина линии: "
        << line.style.thickness
        << std::endl;

    os << "Цвет линии: RGB("
        << (int)line.style.color.red << ", "
        << (int)line.style.color.green << ", "
        << (int)line.style.color.blue<< ")"
        << std::endl;

    return os;
}
