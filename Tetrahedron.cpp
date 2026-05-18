#include "Tetrahedron.h"
#include <cmath>
#include <stdexcept>
#include <cfloat>

using namespace std;

/**
 * @brief Конструктор тетраэдра
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
        throw invalid_argument("Tetrahedron does not exist.");
}

/**
 * @brief Вычисление объёма тетраэдра
 */
double Tetrahedron::volume() const {
    const double ax = B.getX() - A.getX();
    const double ay = B.getY() - A.getY();
    const double az = B.getZ() - A.getZ();

    const double bx = C.getX() - A.getX();
    const double by = C.getY() - A.getY();
    const double bz = C.getZ() - A.getZ();

    const double cx = D.getX() - A.getX();
    const double cy = D.getY() - A.getY();
    const double cz = D.getZ() - A.getZ();

    const double triple =
        ax * (by * cz - bz * cy)
      - ay * (bx * cz - bz * cx)
      + az * (bx * cy - by * cx);

    return fabs(triple) / 6.0;
}
