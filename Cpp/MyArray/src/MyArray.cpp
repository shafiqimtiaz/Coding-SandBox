#include "MyArray.h"

MyArray::MyArray(size_t len)
	: pStore{ new ElemType[len] }, length{ len }
{

}

//Copy Constructor
MyArray::MyArray(const MyArray& source)
	: MyArray{ source.length }
{
	std::cout << "copy ctor" << std::endl;
	for (size_t i{ 0 }; i < length; ++i)
	{
		pStore[i] = source.pStore[i];
	}
}

//Move Constructor
MyArray::MyArray(MyArray&& source) noexcept
	: pStore{ source.pStore }, length{ source.length }
{
	std::cout << "move ctor" << std::endl;
	source.length = 0;
	source.pStore = nullptr;
}

//Copy Assignment Operator Overloading
MyArray& MyArray::operator=(const MyArray& rhs)
{
	std::cout << "copy op" << std::endl;
	if (&rhs != this)
	{
		delete[] pStore;

		length = rhs.length;
		pStore = new ElemType[length];
		for (size_t k{ 0 }; k < length; ++k)
		{
			pStore[k] = rhs.pStore[k];
		}
	}
	return *this;
}

//Move Assignment Operator Overloading
MyArray& MyArray::operator=(MyArray&& rhs) noexcept
{
	std::cout << "move op" << std::endl;
	if (&rhs != this)
	{
		delete[] pStore;

		pStore = rhs.pStore;
		length = rhs.length;

		rhs.pStore = nullptr;
		rhs.length = 0;
	}
	return *this;
}

//Destructor
MyArray::~MyArray()
{
	delete[] pStore;
}

// serves non-const MyArray objects
ElemType& MyArray::operator[](size_t index)
{
	if (index >= length)
	{
		throw std::out_of_range{"My Array out of range!"};
	}
	return pStore[index];
}

// serves const MyArray objects
const ElemType& MyArray::operator[](size_t index) const
{
	if (index >= length)
	{
		throw std::out_of_range{ "My Array out of range!" };
	}
	return pStore[index];
}