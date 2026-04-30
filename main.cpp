#include <iostream>
#include "Tetrahedron.h"

using namespace std;

/**
 * @brief Точка входа в программу.
 * Считывает координаты четырёх точек,
 * создаёт тетраэдр и выводит его объём.
 */
int main() {
    setlocale(LC_ALL, "RU");

    try {
        Point A, B, C, D;

        // Ввод координат точек
        cin >> A.x >> A.y >> A.z;
        cin >> B.x >> B.y >> B.z;
        cin >> C.x >> C.y >> C.z;
        cin >> D.x >> D.y >> D.z;

        // Создание тетраэдра
        Tetrahedron tetra(A, B, C, D);

        cout << "\nTetrahedron created successfully\n";

        // Вывод данных
        cout << "Point A: (" << A.x << ", " << A.y << ", " << A.z << ")" << endl;
        cout << "Point B: (" << B.x << ", " << B.y << ", " << B.z << ")" << endl;
        cout << "Point C: (" << C.x << ", " << C.y << ", " << C.z << ")" << endl;
        cout << "Point D: (" << D.x << ", " << D.y << ", " << D.z << ")" << endl;

        cout << "Volume: " << tetra.volume() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
