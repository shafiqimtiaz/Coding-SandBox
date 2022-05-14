#include <iostream>
#include <cassert>
#include "ArrayList.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Tesing ArrayList!\n";
	ArrayList list{};
	//cout << "list-1 -> " << list << endl;

	cout << list.empty() << endl;
	list.pushBack(1000);
	list.resize();
	list.pushBack(2000);
	//list.pushBack(3);
	cout << list.full() << endl;
	cout << list.getCapacity() << endl;
	//list.pushBack(4);
	//list.pushBack(5);
	//list.pushBack(6);
	cout << list.getCapacity() << endl;
	cout << list.size() << endl;
	cout << list.full() << endl;
	//cout << "list-2 -> " << list << endl;
}
