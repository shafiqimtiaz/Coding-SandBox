#include <iostream>
#include<cassert>
#include<string>
#include <fstream>

#include "ArrayList.h"
#include "Token.h"
#include "TokenList.h"
#include "Dictionary.h"
#include "Driver.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;

/**
* Driver function to test ArrayList
*/
void Driver::Test_ArrrayList()
{
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

	ArrayList list2 = move(list);
	cout << "list-move-ctor -> " << list2 << endl;

	ArrayList list3{};
	list3 = move(list2);
	cout << "list-move-op -> " << list3 << endl;

	cout << "\nArrayList Test Successful" << endl;
}

/**
* Driver function to test Token
*/
void Driver::Test_Token()
{
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

	Token t3{ "A",1 };
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

	cout << t5.compare(t6) << "\n";
}

/**
* Driver function to test TokenList
*/
void Driver::Test_TokenList()
{
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
		Token("~LOL", 69),
		Token("today?", 22),
		Token("!eww", 202),
		Token("#tag", 3),
		Token("Hello", 1),
		Token("Hello", 10),
		Token("bye", 3)
	};

	for (Token t : tArray)
	{
		bucket.addSorted(t);
	}

	cout << bucket << "\n";

	cout << "Front: " << bucket.front() << "\n";
	cout << "Back: " << bucket.back() << "\n";
	cout << "Size: " << bucket.size() << "\n";

	Token tA("today?", 10);
	bucket.addSorted(tA);

	/*Token tB("Shafiq", 300);
	bucket.addAfter(bucket.lookup(tA), tB);
	cout << "\n" << tA << " lookup: " << bucket.size() << "\n\n" << bucket << "\n";

	Token tC("Shafiq", 20);
	cout << tC << "\n" << bucket.lookup(tC)->theToken << "\n";

	bucket.remove(bucket.lookup(tA));
	cout << "\n" << tA << " remove: " << bucket.size() << "\n\n" << bucket << "\n";*/

	cout << "\n" << tA << " search: " << bucket.search(tA) << "\n\n" << bucket << "\n";
}

/**
* Driver function to test Dictionary
*/
void Driver::Test_Dictionary()
{
	cout << "Enter the name of input text file (without '.txt') : ";
	string filename;
	cin >> filename;
	filename.append(".txt");
	Dictionary dictionary(filename);
	cout << dictionary;
}