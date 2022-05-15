#include <iostream>
#include<cassert>
#include "ArrayList.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Testing ArrayList!\n";
	ArrayList list{};
	cout << "list-1 -> " << list << endl;

	assert(list.getCapacity() == 0);
	assert(list.size() == 0);

	list.pushBack(19);
	cout << "list-2 -> " << list << endl;
	assert(list.getCapacity() == 1);
	assert(list.size() == 1);
	
	list.pushBack(32);
	cout << "list-3 -> " << list << endl;
	assert(list.getCapacity() == 2);
	assert(list.size() == 2);
	
	list.pushBack(21);
	cout << "list-4 -> " << list << endl;
	assert(list.getCapacity() == 3);
	assert(list.size() == 3);
	
	list.pushBack(7);
	cout << "list-5 -> " << list << endl;
	assert(list.getCapacity() == 4);
	assert(list.size() == 4);
	
	list.pushBack(18);
	cout << "list-6 -> " << list << endl;
	assert(list.getCapacity() == 5);
	assert(list.size() == 5);


	cout << list.contains(21) << endl;
	cout << list.contains(100) << endl;
	int a{};
	cout << list.get(3, a) << endl;
	cout << "get = " << a << endl;

	list.print(cout);
	
	cout << "\nArrayList Test Successful" << endl;
	return 0;
}
