#include <iostream>
#include "ArrayList.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;

/**
* Copy Constructor
* Creates the specified ArrayList object by copying the invoking ArrayList object
*
* @param array - The specified ArrayList object
*/
ArrayList::ArrayList(const ArrayList& array)
	: capacity{ array.capacity }, used{ array.used }, pArray{ new int[array.capacity] }
{
	for (size_t i{ 0 }; i < used; ++i)
	{
		pArray[i] = array.pArray[i];
	}
}


/**
* Move Constructor
* Creates the specified ArrayList object by moving the invoking ArrayList object
*
* @param array - The specified ArrayList object
*/
ArrayList::ArrayList(ArrayList&& array) noexcept
	: capacity{ array.capacity }, used{ array.used }, pArray{ move(array.pArray) }
{
	array.capacity = 1;
	array.used = 0;
	array.pArray = nullptr;
}

/**
* Copy Assignment Operator
* Copies a specified ArrayList object to the invoking ArrayList object
*
* @param rhs - The specified ArrayList object
* @return The invoking ArrayList object
*/
ArrayList& ArrayList::operator=(const ArrayList& rhs)
{
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

/**
* Move Assignment Operator
* Moves a specified ArrayList object to the invoking ArrayList object
*
* @param rhs - The specified ArrayList object
* @return The invoking ArrayList object
*/
ArrayList& ArrayList::operator=(ArrayList&& rhs) noexcept
{
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

/**
* ArrayList Destructor
*
* Destroys the ArrayList object by clearing pArray memory from heap
* at the end of execution scope
*/
ArrayList::~ArrayList()
{
	delete[] pArray;
}


/**
* @return bool if ArrayList is empty or not
*/
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

/**
* @return bool if ArrayList is full or not
*/
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

/**
* @return the the number of elements in the ArrayList
*/
int ArrayList::size() const
{
	return used;
}

/**
* @return the total capacity of the ArrayList
*/
int ArrayList::getCapacity() const
{
	return capacity;
}

/**
* doubles the ArrayList when invoked
*/
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

/**
* @param x - value to be inserted to the ArrayList
*/
void ArrayList::pushBack(int x)
{
	if (used == capacity)
	{
		resize();
	}

	pArray[used] = x;
	used++;
}

/**
* @param x - value to be checked in the ArrayList
* @return bool if int x is present in the ArrayList
*/
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

/**
* @param position - element position in ArrayList
* @param &value - variable ref in which element to be placed
* @return bool if value placed
*/
bool ArrayList::get(int position, int& value) const
{
	if (position > used) return false;
	else
	{
		value = pArray[position];
		return true;
	}
}

/**
* @param sout - the ArrayList ostream to be printed
*/
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

/**
* @param sout - the ArrayList ostream to be printed
* @param source - the ArrayList object ref
* @return ArrayList ostream object ref
*/
ostream& operator<<(ostream& sout, const ArrayList& source)
{
	source.print(sout);
	return sout;
}