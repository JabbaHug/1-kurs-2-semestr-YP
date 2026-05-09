#pragma once

#include <string>
#include <ostream>
#include "Color.h"


/**
* @brief Класс, описывающий стиль линии
*/
class LineStyle
{
public:
    friend class Line;
    friend std::ostream& operator<<(std::ostream& os, const Line& line);

    /**
    * @brief Тип линии
    */
    enum class LineType
    {
        Solid = 1,
        Dash,
        Dot,
        DashDot,
        DashDotDot
    };

private:
    /**
    * @param Цвет линии
    */
    Color color;

    /**
    * @param Тип линии
    */
    LineType type;

    /**
    * @param Толщина линии
    */
    int thickness;

    /**
    * @brief Выбрасывает исключение
    * @param text - Текст ошибки
    */
    static void error(const std::string text);
public:
    /**
    * @brief Конструктор, создающий стиль линии по умолчанию
    */
    LineStyle();

    /**
    * @brief Конструктор, создающий стиль линии с заданными параметрами
    * @param color - Цвет линии
    * @param type - Тип линии
    * @param thickness - Толщина линии
    */
    LineStyle(const Color& color, LineType type, const int& thickness);

    /**
    * @brief Возвращает тип линии в виде текста
    * @return Тип линии в виде текста
    */
    std::string getType() const;
};

