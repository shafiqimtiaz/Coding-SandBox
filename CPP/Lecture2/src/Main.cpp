#include <iostream>
#include "clock.h"

using std::endl;
using std::cin;
using std::cout;

void main()
{
	clock c1;
	clock c2{ 10 };
	clock c3{ c2 };
	c1 = c3;

	clock c4;
	c4 = c1 = c3;
	c1.print(cout);
	cout << c1;
}