#include <string>
#include <iostream>

using std::cout;
using std::endl;

class Test
{
public:
	Test() {}

	Test(const Test& t)
	{
		cout << "Copy constructor called" << endl;
	}

	Test& operator = (const Test& t)
	{
		cout << "Assignment operator called" << endl;
		return *this;
	}
};

int main()
{
	Test t1, t2;

	t2 = t1;
	Test t3 = t1;

	return 0;
}