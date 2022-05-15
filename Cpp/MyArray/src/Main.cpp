#include <iostream>
#include "MyArray.h"

using std::cout;
using std::endl;

int main()
{
	MyArray a{ 10 };
	MyArray b{ a };

	MyArray c{ MyArray {20} };
	a = c;
	b = { MyArray{30} };

	const MyArray d{ 40 };
	cout << d[0] << endl;
	a[0] = 99;
	cout << a[0] << endl;
}