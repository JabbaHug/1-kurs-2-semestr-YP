#include "../Solver/LineStyle.h"

void LineStyle::error(const std::string text)
{
	throw std::runtime_error(text);
}

LineStyle::LineStyle()
{
	this->color = Color();
	this->type = LineType::Solid;
	this->thickness = 1;
}

LineStyle::LineStyle(const Color& color, LineType type, const int& thickness)
{
	if (thickness <= 0)
	{
		error("Толщина линии должна быть больше нуля");
	}
    
	this->color = color;
	this->type = type;
	this->thickness = thickness;
}

std::string LineStyle::getType() const
{
    switch (type)
    {
    case LineType::Solid:
        return "solid";

    case LineType::Dash:
        return "dash";

    case LineType::Dot:
        return "dot";

    case LineType::DashDot:
        return "dash-dot";

    case LineType::DashDotDot:
        return "dashdotdot";
    }
}
