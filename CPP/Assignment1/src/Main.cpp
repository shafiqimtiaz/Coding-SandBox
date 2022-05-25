#include <iostream>
#include<cassert>

//#include "ArrayList.h"
//#include "Token.h"
#include "TokenList.h"

using std::cin;
using std::cout;
using std::endl;
using std::move;

int main()
{
	/*
	cout << "Testing ArrayList!\n";

	ArrayList list{};
	cout << "list-1 -> " << list << endl;

	assert(list.getCapacity() == 1);
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
	assert(list.getCapacity() == 4);
	assert(list.size() == 3);
	
	list.pushBack(7);
	cout << "list-5 -> " << list << endl;
	assert(list.getCapacity() == 4);
	assert(list.size() == 4);
	
	list.pushBack(18);
	cout << "list-6 -> " << list << endl;
	assert(list.getCapacity() == 8);
	assert(list.size() == 5);

	int a{};
	list.get(3, a);
	cout << "get = " << a << endl;
	
	ArrayList list2 = std::move(list);
	cout << "list-move-ctor -> " << list2 << endl;

	ArrayList list3{};
	list3 = std::move(list2);
	cout << "list-move-op -> " << list3 << endl;

	cout << "\nArrayList Test Successful" << endl;
	*/

	/*
	cout << "Testing an Object of Class Token\n";

	Token t1{ "Hello", 1 };
	cout << "A) t1: " << t1 << endl;
	t1.addLineNumber(11);
	t1.addLineNumber(13);
	t1.addLineNumber(74);
	cout << "B) t1: " << t1 << endl;

	Token t2{ t1 };
	t2.addLineNumber(69);
	t2.addLineNumber(101);
	cout << "C) t2: " << t2 << endl;

	Token t3{"A",1};
	t3 = t2;
	t3.addLineNumber(52);
	t3.addLineNumber(71);
	cout << "D) t3: " << t3 << endl;

	Token t4 = move(t3);
	t4.addLineNumber(99);
	t4.addLineNumber(65);
	cout << "E) t4: " << t4 << endl; 
	cout << "post-t3: " << t3 << endl;


	Token t5{ "A",1 };
	t5 = move(t4);
	t5.addLineNumber(90);
	t5.addLineNumber(36);
	cout << "F) t5: " << t5 << endl;
	cout << "post-t4: " << t4 << endl;

	cout << t5.c_str() << endl;
	cout << t5.size() << endl;
	cout << t5.getNumberList() << endl;

	Token t6{ "HellO", 10 };
	cout << "G) t6: " << t6 << endl;

	cout << t5.compare(t6);
	*/

	TokenList bucket;
	Token t1("Hello", 1);
	bucket.addSorted(t1);
	Token t2("Hello", 11);
	bucket.addSorted(t2);
	Token t3("Hello", 111);
	bucket.addSorted(t3);

	Token tArray[]
	{
		Token("How", 1),
		Token("are", 11),
		Token("you", 2),
		Token("today?", 22),
		Token("#tag", 3),
		Token("bye", 3),
		Token("Hello", 1101)
	};

	for (Token t : tArray)
	{
		bucket.addSorted(t);
	}

	cout << bucket << endl;

	cout << "Front: " << bucket.front() << endl;
	cout << "Back: " << bucket.back() << endl;
	cout << "Size: " << bucket.size() << endl;

	Token t10("How", 10);

	cout << "Search: " << bucket.search(t10) << endl;


	return 0;
}
