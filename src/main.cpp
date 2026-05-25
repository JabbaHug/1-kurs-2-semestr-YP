#include <cstdlib>
#include <iostream>

#include "../Solver/PriorityQueue.h"

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
		PriorityQueue queue = { 15, 4, 23, 8, 1 };

		std::cout << "Очередь с приоритетом: " << queue.toString() << std::endl;
		std::cout << "Минимальный приоритет: " << queue.peekMin() << std::endl;
		std::cout << "Максимальный приоритет: " << queue.peekMax() << std::endl;

		queue << 10;
		std::cout << "После добавления элемента: " << queue.toString() << std::endl;

		int value = 0;
		queue >> value;
		std::cout << "Удалён элемент с наибольшим приоритетом: " << value << std::endl;
		std::cout << "Очередь: " << queue.toString() << std::endl;

		value = queue.popMin();
		std::cout << "Удалён элемент с наименьшим приоритетом: " << value << std::endl;
		std::cout << "Очередь: " << queue.toString() << std::endl;

		queue.remove(8);
		std::cout << "После удаления элемента 8: " << queue.toString() << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cout << "error: " << error.what() << std::endl;
	}

	return 0;
}
