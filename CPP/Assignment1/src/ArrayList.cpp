#include <iostream>
#include "ArrayList.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;

/*
* Default Constructor
*/
ArrayList::ArrayList()
	: capacity{ 1 }, used{ 0 }, pArray{ new int[1] }
{
}

/*
* Copy Constructor
*/
ArrayList::ArrayList(const ArrayList& array)
{
	//cout << "ArrayList Copy Ctor" << endl;

	for (size_t i = 0; i < used; ++i)
	{
		pArray[i] = array.pArray[i];
	}
}

/*
* Move Constructor
*/
ArrayList::ArrayList(ArrayList&& array) noexcept
	: capacity{ array.capacity}, used{ array.used}, pArray{ array.pArray }
{
	//cout << "ArrayList Move Ctor" << endl;

	array.capacity = 0;
	array.used = 0;
	array.pArray = nullptr;
}

/*
* Copy Assignment Operator
*/
ArrayList& ArrayList::operator=(const ArrayList& rhs)
{
	//cout << "ArrayList Copy Ass Op" << endl;
	if (&rhs != this)
	{
		delete[] pArray;

		capacity = rhs.capacity;
		used = rhs.used;
		pArray = new int[capacity];
		for (size_t k = 0; k < capacity; ++k)
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
		pArray = rhs.pArray;

		rhs.capacity = 0;
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

void ArrayList::print(ostream& sout) const
{
	if (used > 0)
	{
		for (size_t i = 0; i < used; ++i)
		{
			sout << pArray[i] << " ";
		}
	}
	else
	{
		sout << "";
	}
}

ostream& operator<<(ostream& sout, const ArrayList& source)
{
	source.print(sout);
	return sout;
}