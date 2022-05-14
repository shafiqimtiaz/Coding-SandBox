#include "ArrayList.h"

ArrayList::ArrayList()
{
    capacity = 1;
    used = 0;
    pArray = new int[capacity];
}

ArrayList::ArrayList(const ArrayList& arr)
{
	for (int i = 0; i < used; i++) {
		pArray[i] = arr.pArray[i];
	}
}

void ArrayList::pushBack(int value)
{
	if (used >= capacity)
	{
		ArrayList::resize();
		pArray[used] = value;
		used++;
	}
	else {
		pArray[used] = value;
		used++;
	}

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
	temp = new int[capacity * 2];
	ArrayList temp = pArray;
	pArray = new int[capacity * 2];
	ArrayList pArray = temp;
}

void ArrayList::print()
{
	for (int i = 0; i < used; i++) {
		std::cout << pArray[i] << " " << std::endl;
	}
}

int ArrayList::getCapacity() const
{
	return capacity;
}

ArrayList::~ArrayList()
{
    delete[] pArray;
}