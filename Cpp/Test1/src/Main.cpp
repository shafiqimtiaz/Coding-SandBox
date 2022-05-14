#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define LOG(key, value) cout << key << value << endl;

int main()
{
	int var{ 0 };
	cout << "Input: ";
	cin >> var;

	int* ptr{ &var };
	int& ref{ var };

	LOG("var = ", var);
	
	LOG("ptr = ", ptr);
	LOG("*ptr = ", *ptr);

	LOG("ref = ", ref);
	LOG("&ref = ", &ref);

	cin >> ref;
	LOG("new1 ref = ", ref);
	LOG("new1 var = ", var);
	LOG("new1 *ptr = ", *ptr);

	cin >> *ptr;
	LOG("new2 ref = ", ref);
	LOG("new2 var = ", var);
	LOG("new2 *ptr = ", *ptr);

	cin.get();
}