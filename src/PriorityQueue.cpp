#include "../Solver/PriorityQueue.h"

#include <stdexcept>

void PriorityQueue::error(const std::string text)
{
	throw std::runtime_error(text);
}

void PriorityQueue::reserve(const size_t newSize)
{
	if (newSize <= capacity)
	{
		return;
	}

	size_t newCapacity = capacity == 0 ? 1 : capacity;
	while (newCapacity < newSize)
	{
		newCapacity *= 2;
	}

	int* newData = new int[newCapacity];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCapacity;
}

size_t PriorityQueue::getInsertIndex(const int value) const
{
	size_t index = 0;
	while (index < size && data[index] <= value)
	{
		index++;
	}
	return index;
}

PriorityQueue::PriorityQueue()
{
	this->data = nullptr;
	this->size = 0;
	this->capacity = 0;
}

PriorityQueue::PriorityQueue(const std::initializer_list<int> initList): PriorityQueue()
{
	for (const int value : initList)
	{
		push(value);
	}
}

PriorityQueue::PriorityQueue(const PriorityQueue& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = nullptr;

	if (capacity != 0)
	{
		this->data = new int[capacity];
		for (size_t i = 0; i < size; i++)
		{
			this->data[i] = other.data[i];
		}
	}
}

PriorityQueue::PriorityQueue(PriorityQueue&& other) noexcept
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

PriorityQueue::~PriorityQueue()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

PriorityQueue& PriorityQueue::operator = (const PriorityQueue& other)
{
	if (this == &other)
	{
		return *this;
	}

	int* newData = nullptr;
	if (other.capacity != 0)
	{
		newData = new int[other.capacity];
		for (size_t i = 0; i < other.size; i++)
		{
			newData[i] = other.data[i];
		}
	}

	delete[] data;
	data = newData;
	size = other.size;
	capacity = other.capacity;

	return *this;
}

PriorityQueue& PriorityQueue::operator = (PriorityQueue&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	delete[] data;
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;

	return *this;
}

void PriorityQueue::push(const int value)
{
	reserve(size + 1);

	const size_t index = getInsertIndex(value);
	for (size_t i = size; i > index; i--)
	{
		data[i] = data[i - 1];
	}

	data[index] = value;
	size++;
}

void PriorityQueue::insert(const int value)
{
	push(value);
}

int PriorityQueue::popMin()
{
	if (isEmpty())
	{
		error("Очередь пустая");
	}

	const int value = data[0];
	for (size_t i = 1; i < size; i++)
	{
		data[i - 1] = data[i];
	}
	size--;

	return value;
}

int PriorityQueue::popMax()
{
	if (isEmpty())
	{
		error("Очередь пустая");
	}

	size--;
	return data[size];
}

int PriorityQueue::peekMin() const
{
	if (isEmpty())
	{
		error("Очередь пустая");
	}
	return data[0];
}

int PriorityQueue::peekMax() const
{
	if (isEmpty())
	{
		error("Очередь пустая");
	}
	return data[size - 1];
}

void PriorityQueue::remove(const int value)
{
	const int index = find(value);
	if (index == -1)
	{
		error("Элемент не найден");
	}

	for (size_t i = static_cast<size_t>(index) + 1; i < size; i++)
	{
		data[i - 1] = data[i];
	}
	size--;
}

int PriorityQueue::find(const int value) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == value)
		{
			return static_cast<int>(i);
		}

		if (data[i] > value)
		{
			return -1;
		}
	}
	return -1;
}

bool PriorityQueue::contains(const int value) const
{
	return find(value) != -1;
}

bool PriorityQueue::isEmpty() const
{
	return size == 0;
}

size_t PriorityQueue::getSize() const
{
	return size;
}

int PriorityQueue::operator [] (const size_t index) const
{
	if (index >= size)
	{
		error("Индекс вышел за границы очереди");
	}
	return data[index];
}

PriorityQueue& PriorityQueue::operator << (const int value)
{
	push(value);
	return *this;
}

PriorityQueue& PriorityQueue::operator >> (int& value)
{
	value = popMax();
	return *this;
}

void PriorityQueue::clear()
{
	size = 0;
}

std::string PriorityQueue::toString() const
{
	std::string result = "[";
	for (size_t i = 0; i < size; i++)
	{
		result += std::to_string(data[i]);
		if (i + 1 < size)
		{
			result += ", ";
		}
	}
	result += "]";
	return result;
}
