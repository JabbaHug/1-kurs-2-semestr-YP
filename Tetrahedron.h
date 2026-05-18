#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Point.h"

/**
 * @class Tetrahedron
 * @brief Класс, описывающий тетраэдр
 *
 * Тетраэдр задаётся четырьмя точками в пространстве.
 */
class Tetrahedron {
private:
    Point A;
    Point B;
    Point C;
    Point D;

    /**
     * @brief Проверяет существование тетраэдра
     */
    void validate() const;

public:
    /**
     * @brief Конструктор тетраэдра
     * @param A первая точка
     * @param B вторая точка
     * @param C третья точка
     * @param D четвёртая точка
     */
    Tetrahedron(const Point& A,
                const Point& B,
                const Point& C,
                const Point& D);

    /**
     * @brief Вычисляет объём тетраэдра
     * @return объём тетраэдра
     */
    double volume() const;
};

#endif
