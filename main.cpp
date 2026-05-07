#include <iostream>
#include "Tetrahedron.h"

using namespace std;

/**
 * @brief Точка входа в программу.
 *
 * Считывает координаты четырёх точек,
 * создаёт тетраэдр и выводит его объём.
 */
int main() {
    setlocale(LC_ALL, "RU");

    try {
        double x = 0;
        double y = 0;
        double z = 0;

        // Ввод первой точки
        cin >> x >> y >> z;
        Point A(x, y, z);

        // Ввод второй точки
        cin >> x >> y >> z;
        Point B(x, y, z);

        // Ввод третьей точки
        cin >> x >> y >> z;
        Point C(x, y, z);

        // Ввод четвёртой точки
        cin >> x >> y >> z;
        Point D(x, y, z);

        // Создание тетраэдра
        Tetrahedron tetra(A, B, C, D);

        cout << "\nTetrahedron created successfully\n";

        // Вывод данных
        cout << "Point A: ("
             << A.getX() << ", "
             << A.getY() << ", "
             << A.getZ() << ")" << endl;

        cout << "Point B: ("
             << B.getX() << ", "
             << B.getY() << ", "
             << B.getZ() << ")" << endl;

        cout << "Point C: ("
             << C.getX() << ", "
             << C.getY() << ", "
             << C.getZ() << ")" << endl;

        cout << "Point D: ("
             << D.getX() << ", "
             << D.getY() << ", "
             << D.getZ() << ")" << endl;

        cout << "Volume: " << tetra.volume() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
