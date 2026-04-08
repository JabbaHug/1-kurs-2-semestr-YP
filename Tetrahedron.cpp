#include "Tetrahedron.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

/**
 * @brief Реализация конструктора с проверкой корректности параметров.
 */
Tetrahedron::Tetrahedron(double ax, double ay, double az,
                         double bx, double by, double bz,
                         double cx, double cy, double cz,
                         double dx, double dy, double dz)
    : x1(ax), y1(ay), z1(az),
      x2(bx), y2(by), z2(bz),
      x3(cx), y3(cy), z3(cz),
      x4(dx), y4(dy), z4(dz)
{
    validate();
}

/**
 * @brief Проверяет, что точки не лежат в одной плоскости.
 */
void Tetrahedron::validate() const {
    if (abs(volume()) < 1e-9)
        throw invalid_argument("Points must not be coplanar.");
}

/**
 * @brief Вычисляет объём тетраэдра через смешанное произведение.
 */
double Tetrahedron::volume() const {
    double ax = x2 - x1;
    double ay = y2 - y1;
    double az = z2 - z1;

    double bx = x3 - x1;
    double by = y3 - y1;
    double bz = z3 - z1;

    double cx = x4 - x1;
    double cy = y4 - y1;
    double cz = z4 - z1;

    double triple =
        ax * (by * cz - bz * cy)
      - ay * (bx * cz - bz * cx)
      + az * (bx * cy - by * cx);

    return abs(triple) / 6.0;
}

/**
 * @brief Печатает параметры тетраэдра и его объём.
 */
void Tetrahedron::print() const {
    cout << "Point A: (" << x1 << ", " << y1 << ", " << z1 << ")" << endl;
    cout << "Point B: (" << x2 << ", " << y2 << ", " << z2 << ")" << endl;
    cout << "Point C: (" << x3 << ", " << y3 << ", " << z3 << ")" << endl;
    cout << "Point D: (" << x4 << ", " << y4 << ", " << z4 << ")" << endl;
    cout << "Volume: " << volume() << endl;
}