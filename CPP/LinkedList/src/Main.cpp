#include <iostream>
#include "SList.h"

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::move;


int main()
{
	SList s1{};
	s1.push_front(20);
	s1.push_front(10);

	cout << s1 << endl;
	s1.clear();
	cout << "cleared s1: " << s1 << endl;

	s1.push_front(30);
	s1.push_front(40);
	s1.push_front(50);
	s1.push_front(11);
	s1.push_front(44);
	s1.push_front(55);

	cout << s1 << endl;

	s1.pop_front();
	s1.pop_front();

	cout << "s1: " << s1 << endl;

	SList s2{ s1 };

	s2.push_front(100);
	s2.push_front(200);

	cout << "s2: " << s2 << endl;

	SList s3{ move(s2)};

	cout << "s3: " << s3 << endl;
	cout << "after move s2: " << s2 << endl;
}