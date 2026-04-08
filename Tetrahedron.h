#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

/**
 * @class Tetrahedron
 * @brief Класс, описывающий геометрический тетраэдр.
 * Тетраэдр задаётся координатами четырёх точек в пространстве.
 */
class Tetrahedron {
private:
    /**
     * @brief Координаты первой точки
     */
    double x1, y1, z1;

    /**
     * @brief Координаты второй точки
     */
    double x2, y2, z2;

    /**
     * @brief Координаты третьей точки
     */
    double x3, y3, z3;

    /**
     * @brief Координаты четвёртой точки
     */
    double x4, y4, z4;

    /**
     * @brief validate - проверка корректности данных
     */
    void validate() const;

public:
    /**
     * @brief Конструктор класса Tetrahedron.
     * @param ax, ay, az Координаты первой точки
     * @param bx, by, bz Координаты второй точки
     * @param cx, cy, cz Координаты третьей точки
     * @param dx, dy, dz Координаты четвёртой точки
     */
    Tetrahedron(double ax, double ay, double az,
                double bx, double by, double bz,
                double cx, double cy, double cz,
                double dx, double dy, double dz);

    /**
     * @brief Вычисляет объём тетраэдра.
     * @return Объём
     */
    double volume() const;

    /**
     * @brief Выводит информацию о тетраэдре в консоль.
     */
    void print() const;
};

#endif