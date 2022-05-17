#include <iostream>
#include "ArrayList.h"

/*
* Default Constructor
*/
ArrayList::ArrayList()
	: capacity{0}, used{0}, pArray{ new int[capacity] }
{
}

/*
* Copy Constructor
*/
ArrayList::ArrayList(const ArrayList& source)
{
	std::cout << "Copy Constructor called" << std::endl;
	for (int i = 0; i < used; ++i) {
		pArray[i] = source.pArray[i];
	}
}

/*
* Move Constructor
*/
ArrayList::ArrayList(ArrayList&& source) noexcept
	: pArray{ source.pArray }, capacity{source.capacity}, used{source.used}
{
	std::cout << "Move Constructor called" << std::endl;
	source.used = 0;
	source.capacity = 0;
	source.pArray = nullptr;
}

/*
* Copy Assignment Operator
*/
ArrayList& ArrayList::operator=(const ArrayList& rhs)
{
	std::cout << "Copy Assignment Operator called" << std::endl;
	if (&rhs != this)
	{
		delete[] pArray;

		capacity = rhs.capacity;
		used = rhs.used;
		pArray = new int[capacity];
		for (int k = 0; k < capacity; ++k)
		{
			pArray[k] = rhs.pArray[k];
		}
	}
	return *this;
}

/*
* Move Assignment Operator
*/
ArrayList& ArrayList::operator=(ArrayList&& rhs) noexcept
{
	std::cout << "Move Assignment Operator called" << std::endl;
	if (&rhs != this)
	{
		delete[] pArray;

		capacity = rhs.capacity;
		used = rhs.used;
		pArray = rhs.pArray;

		capacity = 0;
		used = 0;
		pArray = nullptr;
	}
	return *this;
}

ArrayList::~ArrayList()
{
	delete[] pArray;
}



bool ArrayList::empty() const
{
	if (used == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool ArrayList::full() const
{
	if (used == capacity) {
		return true;
	}
	else {
		return false;
	}
}

int ArrayList::size() const
{
	return used;
}

void ArrayList::resize()
{
	int* temp = new int[capacity + 1];

	for (int i = 0; i < capacity; ++i) {
		temp[i] = pArray[i];
	}
	pArray = temp;
	capacity += 1;
}

void ArrayList::pushBack(int x)
{
	if (used == capacity)
	{
		resize();
	}

	pArray[used] = x;
	used++;
}

bool ArrayList::contains(int x) const
{
	for (int i = 0; i < capacity; ++i)
	{
		if (pArray[i] == x)
		{
			return true;
		}
	}
	return false;
}

bool ArrayList::get(int position, int& value) const
{
	if (position > capacity) return false;
	else
	{
		value = pArray[position];
		return true;
	}
}

int ArrayList::getCapacity() const
{
	return capacity;
}

void ArrayList::print(std::ostream& sout) const
{
	if (used > 0) {
		for (int i = 0; i < getCapacity(); ++i) {
			sout << pArray[i] << " ";
		}
	}
	else
	{
		sout << "";
	}
}

std::ostream& operator<<(std::ostream& out, const ArrayList& source)
{
	if (source.used > 0) {
		for (int i = 0; i < source.getCapacity(); ++i) {
			out << source.pArray[i] << " ";
		}
		return out;
	}
	else { return out << ""; }
}