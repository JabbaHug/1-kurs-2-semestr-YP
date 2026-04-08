#include <iostream>
#include "Tetrahedron.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    try {
        double x1 = 0, y1 = 0, z1 = 0;
        double x2 = 0, y2 = 0, z2 = 0;
        double x3 = 0, y3 = 0, z3 = 0;
        double x4 = 0, y4 = 0, z4 = 0;

        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        cin >> x3 >> y3 >> z3;
        cin >> x4 >> y4 >> z4;

        Tetrahedron tetra(x1, y1, z1,
                          x2, y2, z2,
                          x3, y3, z3,
                          x4, y4, z4);

        cout << "\n Tetrahedron created successfully\n";
        tetra.print();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}