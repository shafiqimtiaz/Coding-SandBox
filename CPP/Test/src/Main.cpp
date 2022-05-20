#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

#define LOG(key, value) cout << key << value << endl;

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
	int var{ 0 };
	cout << "Input1: ";
	cin >> var;

	int* ptr{ &var };
	int& ref{ var };

	LOG("var = ", var);

	LOG("ptr = ", ptr);
	LOG("*ptr = ", *ptr);

	LOG("ref = ", ref);
	LOG("&ref = ", &ref);

	cout << "Input2: ";
	cin >> ref;
	LOG("new1 ref = ", ref);
	LOG("new1 var = ", var);
	LOG("new1 *ptr = ", *ptr);

	cout << "Input3: ";
	cin >> *ptr;
	LOG("new2 ref = ", ref);
	LOG("new2 var = ", var);
	LOG("new2 *ptr = ", *ptr);

	cout << endl;

	Test t1, t2;

	t2 = t1;
	Test t3 = t1;

	cin.get();
}