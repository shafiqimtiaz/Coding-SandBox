#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using ElemType = int;

class MyArray
{
public:
	MyArray() = delete;
	explicit MyArray(size_t len);

	MyArray(const MyArray& source);
	MyArray(MyArray&& source) noexcept;
	MyArray& operator=(const MyArray& rhs);
	MyArray& operator=(MyArray&& rhs) noexcept;
	virtual ~MyArray();

	ElemType& operator[](size_t index);
	const ElemType& operator[] (size_t index) const;

private:
	ElemType* pStore;
	size_t length;
};

#endif