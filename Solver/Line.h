#pragma once
#include <iostream>
#include <string>

#include "Point.h"
#include "LineStyle.h"


/**
* @brief Класс, описывающий линию
*/
class Line
{
private:
    /**
    * @param first - Первая точка
    */
    Point first;

    /**
    * @param second - Вторая точка
    */
    Point second;

    /**
    * @param style - Стиль линии
    */
    LineStyle style;

    /**
    * @brief Выбрасывает исключение
    * @param text - Текст ошибки
    */
    static void error(const std::string text);
public:
    /**
    * @brief Конструктор, создающий линию по умолчанию
    */
    Line();

    /**
    * @brief Конструктор, создающий линию по умолчанию, но проходящую через указанные точки
    */
    Line(const Point& first, const Point& second);

    /**
     * @brief Конструктор, создающий линию с заданными точками, стилем и цветом
     * @param firstPoint - Первая точка линии
     * @param secondPoint - Вторая точка линии
     * @param style - Стиль линии
     * @param color - Цвет линии
     */
    Line(const Point& first, const Point& second, const LineStyle& style);

    /**
     * @brief Изменяет стиль линии
     * @param style - Новый стиль линии
     * p.s. Нужен по заданию
     */
    void setStyle(const LineStyle& style);

    /**
     * @brief Изменяет цвет линии
     * @param color - Новый цвет линии
     * p.s. Нужен по заданию
     */
    void setColor(const Color& color);

    /**
    * @brief Считывает линию из входного потока
    * @param is - Входной поток
    * @return Объект класса Line
    */
    static Line read(std::istream& is);

    /**
    * @brief Выводит информацию о линии в выходной поток
    * @param os - Выходной поток
    * @param line - Линия
    * @return Выходной поток
    */
    friend std::ostream& operator<<(std::ostream& os, const Line& line);
};

