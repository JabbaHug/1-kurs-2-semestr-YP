#pragma once

#include <initializer_list>
#include <string>

/**
* @brief Класс очереди с приоритетом с двусторонним доступом
*/
class PriorityQueue
{
private:
	/**
	* @param data - Массив элементов очереди
	*/
	int* data;

	/**
	* @param size - Количество элементов очереди
	*/
	size_t size;

	/**
	* @param capacity - Вместимость очереди
	*/
	size_t capacity;

	/**
	* @brief Выбрасывает исключение
	* @param text - Текст ошибки
	*/
	static void error(const std::string text);

	/**
	* @brief Увеличивает вместимость очереди
	* @param newSize - Требуемый размер очереди
	*/
	void reserve(const size_t newSize);

	/**
	* @brief Возвращает позицию для вставки элемента
	* @param value - Значение элемента
	* @return Позиция для вставки элемента
	*/
	size_t getInsertIndex(const int value) const;

public:
	/**
	* @brief Конструктор, создающий пустую очередь
	*/
	PriorityQueue();

	/**
	* @brief Конструктор со списком инициализации
	* @param initList - Список инициализации
	*/
	PriorityQueue(const std::initializer_list<int> initList);

	/**
	* @brief Конструктор копирования
	* @param other - Очередь, из которой копируются элементы
	*/
	PriorityQueue(const PriorityQueue& other);

	/**
	* @brief Конструктор перемещения
	* @param other - Очередь, из которой перемещаются элементы
	*/
	PriorityQueue(PriorityQueue&& other) noexcept;

	/**
	* @brief Деструктор
	*/
	~PriorityQueue();

	/**
	* @brief Оператор присваивания
	* @param other - Очередь, элементы которой присваиваются текущей очереди
	* @return Ссылка на текущую очередь
	*/
	PriorityQueue& operator = (const PriorityQueue& other);

	/**
	* @brief Оператор перемещающего присваивания
	* @param other - Очередь, элементы которой перемещаются в текущую очередь
	* @return Ссылка на текущую очередь
	*/
	PriorityQueue& operator = (PriorityQueue&& other) noexcept;

	/**
	* @brief Добавляет элемент в очередь
	* @param value - Значение элемента
	*/
	void push(const int value);

	/**
	* @brief Добавляет элемент в очередь
	* @param value - Значение элемента
	*/
	void insert(const int value);

	/**
	* @brief Удаляет элемент с наименьшим приоритетом
	* @return Удалённый элемент
	*/
	int popMin();

	/**
	* @brief Удаляет элемент с наибольшим приоритетом
	* @return Удалённый элемент
	*/
	int popMax();

	/**
	* @brief Возвращает элемент с наименьшим приоритетом
	* @return Элемент с наименьшим приоритетом
	*/
	int peekMin() const;

	/**
	* @brief Возвращает элемент с наибольшим приоритетом
	* @return Элемент с наибольшим приоритетом
	*/
	int peekMax() const;

	/**
	* @brief Удаляет элемент по значению
	* @param value - Значение удаляемого элемента
	*/
	void remove(const int value);

	/**
	* @brief Ищет элемент по значению
	* @param value - Искомое значение
	* @return Индекс элемента или -1 при отсутствии
	*/
	int find(const int value) const;

	/**
	* @brief Проверяет наличие элемента в очереди
	* @param value - Искомое значение
	* @return true, если элемент найден, иначе false
	*/
	bool contains(const int value) const;

	/**
	* @brief Проверяет очередь на пустоту
	* @return true, если очередь пустая, иначе false
	*/
	bool isEmpty() const;

	/**
	* @brief Возвращает количество элементов очереди
	* @return Количество элементов очереди
	*/
	size_t getSize() const;

	/**
	* @brief Возвращает элемент по индексу
	* @param index - Индекс элемента
	* @return Значение элемента
	*/
	int operator [] (const size_t index) const;

	/**
	* @brief Добавляет элемент в очередь
	* @param value - Значение элемента
	* @return Ссылка на текущую очередь
	*/
	PriorityQueue& operator << (const int value);

	/**
	* @brief Удаляет элемент с наибольшим приоритетом
	* @param value - Переменная, в которую записывается удалённый элемент
	* @return Ссылка на текущую очередь
	*/
	PriorityQueue& operator >> (int& value);

	/**
	* @brief Очищает очередь
	*/
	void clear();

	/**
	* @brief Возвращает очередь в виде строки
	* @return Строка с элементами очереди
	*/
	std::string toString() const;
};
