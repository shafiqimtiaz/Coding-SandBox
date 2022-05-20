#include <iostream>

using std::cout;
using std::endl;

void print(int x) // x is passed by value
{
	cout << "print x = " << x << endl;
	x *= 2;
	return;
}
void show(int& x) // x passed by reference
{
	cout << "show x = " << x << endl;
	x *= 2;
	return;
}

int main()
{
	int y{ 10 };
	print(y);
	cout << "y: " << y << endl; //y: 10
	show(y);
	cout << "y: " << y << endl; //y : 20
}