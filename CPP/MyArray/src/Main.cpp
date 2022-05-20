#include <iostream>
#include <vector>
#include "MyArray.h"

using std::vector;
using std::cout;
using std::endl;

int main()
{
	MyArray a(10);
	a[0] = 100;

	MyArray b(a);
	cout << b[0] << endl;
	cout << sizeof(b)/sizeof(b[0]) << endl;

	cout << "-----" << endl;

	b[0] = 200;
	MyArray c(10);
	c = b;
	cout << c[0] << endl;
	cout << sizeof(c)/sizeof(c[0]) << endl;

	cout << "-----" << endl;

	vector <MyArray> v;
	v.push_back(MyArray(20));

	cout << "-----" << endl;

	MyArray d(10);
	d = MyArray(30);
}