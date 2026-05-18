#include "Point.h"

/**
 * @brief Конструктор точки
 */
Point::Point(const double x,
             const double y,
             const double z)
    : x(x), y(y), z(z)
{
}

/**
 * @brief Получить координату X
 */
double Point::getX() const {
    return x;
}

/**
 * @brief Получить координату Y
 */
double Point::getY() const {
    return y;
}

/**
 * @brief Получить координату Z
 */
double Point::getZ() const {
    return z;
}
