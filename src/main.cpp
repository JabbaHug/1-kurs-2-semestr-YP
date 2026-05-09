#include <iostream>
#include "../Solver/Line.h"

/**
* @brief Точка входа в программу
* @return Если программа выполнена корректно - 0, иначе 1
*/
int main()
{
	system("chcp 1251");
	system("CLS");

    try
    {
        Line line = Line::read(std::cin);

        std::cout << std::endl;
        std::cout << line << std::endl;
    }
    catch (const std::exception& error)
    {
        std::cout << "error: " << error.what() << std::endl;
    }

	return 0;
}
