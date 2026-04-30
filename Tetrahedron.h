#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

/**
 * @struct Point
 * @brief Точка в трёхмерном пространстве
 */
struct Point {
    double x;
    double y;
    double z;
};

/**
 * @class Tetrahedron
 * @brief Класс, описывающий тетраэдр
 */
class Tetrahedron {
private:
    Point A, B, C, D;

    /**
     * @brief Проверяет корректность тетраэдра (точки не должны лежать в одной плоскости)
     */
    void validate() const;

public:
    /**
     * @brief Конструктор
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
     * @return объём
     */
    double volume() const;
};

#endif
