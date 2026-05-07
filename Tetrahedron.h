#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

/**
 * @class Point
 * @brief Класс точки в трёхмерном пространстве
 */
class Point {
private:
    double x; ///< координата X
    double y; ///< координата Y
    double z; ///< координата Z

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

/**
 * @class Tetrahedron
 * @brief Класс, описывающий тетраэдр
 *
 * Тетраэдр задаётся четырьмя точками в пространстве.
 */
class Tetrahedron {
private:
    Point A; ///< первая вершина
    Point B; ///< вторая вершина
    Point C; ///< третья вершина
    Point D; ///< четвёртая вершина

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
