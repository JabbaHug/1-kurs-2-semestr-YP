#include "Tetrahedron.h"
#include <cmath>
#include <stdexcept>
#include <cfloat>

using namespace std;

/**
 * @brief Конструктор с инициализацией точек
 */
Tetrahedron::Tetrahedron(const Point& A,
                         const Point& B,
                         const Point& C,
                         const Point& D)
    : A(A), B(B), C(C), D(D)
{
    validate();
}

/**
 * @brief Проверка существования тетраэдра
 */
void Tetrahedron::validate() const {
    if (fabs(volume()) < DBL_EPSILON)
        throw invalid_argument("Tetrahedron does not exist (points are coplanar).");
}

/**
 * @brief Вычисление объёма через смешанное произведение
 */
double Tetrahedron::volume() const {
    const double ax = B.x - A.x;
    const double ay = B.y - A.y;
    const double az = B.z - A.z;

    const double bx = C.x - A.x;
    const double by = C.y - A.y;
    const double bz = C.z - A.z;

    const double cx = D.x - A.x;
    const double cy = D.y - A.y;
    const double cz = D.z - A.z;

    const double triple =
        ax * (by * cz - bz * cy)
      - ay * (bx * cz - bz * cx)
      + az * (bx * cy - by * cx);

    return fabs(triple) / 6.0;
}
