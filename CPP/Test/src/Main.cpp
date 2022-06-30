#include <iostream>
#include <string>

#pragma warning(disable : 4996)

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
	/*int var{ 0 };
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
	Test t3 = t1;*/


	/*int a[5]{ 1,2,3,4,5 };

	cout << *(a + 2) << " " << a[2] << "\n";
	cout << (a + 1) << " " << &a[2] << "\n";

	for (int i{}; i < (sizeof(a) / sizeof(a[0])); ++i)
	{
		int* p{ &a[i] };
		cout << p << "\n";
	}*/

	/*int* p{ new int[5] {1,2,3,4,5} };

	p[2] = 100;

	for (int i{}; i < 5; ++i)
	{
		cout << p[i] << "\n";
	}

	delete[] p;*/

	/*int x{ 10 };
	int* p{ &x };
	int*& refp{ p };

	int** q{ &p };
	int**& refq{ q };

	int*** r{ &q };
	int***& refr{ r };


	cout << *p << " " << **q << " " << ***r << "\n" << *refp << " " << **refq << " " << ***refr;*/

	/*const char* src{ "Joe" };
	char* dest{ new char[strlen(src) + 1] };

	strcpy(dest, src);

	for (size_t i = 0; i < strlen(dest); i++)
	{
		cout << dest[i] << " ";
	}

	delete[] dest;*/


	return 0;
}