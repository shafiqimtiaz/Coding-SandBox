#include <iostream>
#include "ArrayList.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;

/*
* Copy Constructor
*/
ArrayList::ArrayList(const ArrayList& array) 
	: capacity{ array.capacity }, used{ array.used }, pArray{ new int[array.capacity] }
{
	//cout << "ArrayList Copy Ctor: " << array << endl;

	for (size_t i{ 0 }; i < used; ++i)
	{
		pArray[i] = array.pArray[i];
	}
}

/*
* Move Constructor
*/
ArrayList::ArrayList(ArrayList&& array) noexcept
	: capacity{ array.capacity }, used{ array.used }, pArray{ move(array.pArray) }
{
	//cout << "ArrayList Move Ctor" << endl;
	array.capacity = 1;
	array.used = 0;
	array.pArray = nullptr;
}

/*
* Copy Assignment Operator
*/
ArrayList& ArrayList::operator=(const ArrayList& rhs)
{
	//cout << "ArrayList Copy Ass Op: " << rhs << endl;
	if (&rhs != this)
	{
		delete[] pArray;

		capacity = rhs.capacity;
		used = rhs.used;
		pArray = new int[capacity];

		for (size_t k{ 0 }; k < used; ++k)
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
	//cout << "ArrayList Move Ass Op" << endl;
	if (&rhs != this)
	{
		delete[] pArray;

		capacity = rhs.capacity;
		used = rhs.used;
		pArray = move(rhs.pArray);

		rhs.capacity = 1;
		rhs.used = 0;
		rhs.pArray = nullptr;
	}
	return *this;
}

/*
* Destructor
*/
ArrayList::~ArrayList()
{
	delete[] pArray;
}



bool ArrayList::empty() const
{
	if (used == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArrayList::full() const
{
	if (used == capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ArrayList::size() const
{
	return used;
}

int ArrayList::getCapacity() const
{
	return capacity;
}

void ArrayList::resize()
{
	int cap = capacity * 2;
	int* temp = new int[cap * 2];

	for (size_t i = 0; i < capacity; ++i)
	{
		temp[i] = pArray[i];
	}

	pArray = temp;
	capacity = cap;
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
	for (size_t i = 0; i < capacity; ++i)
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
	if (position > used) return false;
	else
	{
		value = pArray[position];
		return true;
	}
}

void ArrayList::print(ostream& sout) const
{
	if (used > 0)
	{
		for (size_t i = 0; i < used; ++i)
		{
			sout << pArray[i] << " ";
		}
	}
}

ostream& operator<<(ostream& sout, const ArrayList& source)
{
	source.print(sout);
	return sout;
}