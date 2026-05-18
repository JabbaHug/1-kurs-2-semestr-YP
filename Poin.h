#ifndef POINT_H
#define POINT_H

/**
 * @class Point
 * @brief Класс точки в трёхмерном пространстве
 */
class Point {
private:
    double x;
    double y;
    double z;

public:
    /**
     * @brief Конструктор точки
     * @param x координата X
     * @param y координата Y
     * @param z координата Z
     */
    Point(const double x = 0,
          const double y = 0,
          const double z = 0);

    /**
     * @brief Получить координату X
     * @return координата X
     */
    double getX() const;

    /**
     * @brief Получить координату Y
     * @return координата Y
     */
    double getY() const;

    /**
     * @brief Получить координату Z
     * @return координата Z
     */
    double getZ() const;
};

#endif
