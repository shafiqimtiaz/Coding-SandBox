#include "Header.h"

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

	cout << endl;*/

	/**********************************************************/

	/*int a[5]{ 1,2,3,4,5 };

	cout << *(a + 2) << " " << a[2] << "\n";
	cout << (a + 1) << " " << &a[2] << "\n";

	for (int i{}; i < (sizeof(a) / sizeof(a[0])); ++i)
	{
		int* p{ &a[i] };
		cout << p << "\n";
	}*/

	/**********************************************************/

	/*int* p{ new int[5] {1,2,3,4,5} };

	p[2] = 100;

	for (int i{}; i < 5; ++i)
	{
		cout << p[i] << "\n";
	}

	delete[] p;*/

	/**********************************************************/

	/*int x{ 10 };
	int* p{ &x };
	int*& refp{ p };

	int** q{ &p };
	int**& refq{ q };

	int*** r{ &q };
	int***& refr{ r };

	cout << *p << " " << **q << " " << ***r << "\n" << *refp << " " << **refq << " " << ***refr;*/

	/**********************************************************/

	/*const char* src{ "Joe" };
	char* dest{ new char[strlen(src) + 1] };

	strcpy(dest, src);

	for (size_t i = 0; i < strlen(dest); i++)
	{
		cout << dest[i] << " ";
	}

	delete[] dest;*/

	/**********************************************************/

	/*Child1 c1;
	Child2 c2;*/

	/**********************************************************/

	/*doSomething();
	doSomething();
	doSomething();
	doSomething();*/

	/**********************************************************/

	/*int a{ 100 };
	const int b{ 200 };
	int* ptr1 = &a;
	const int* ptr2 = &b;

	f(a);
	f(b);
	f(300);
	f(ptr1);
	f(move(a));
	f(ptr2);

	int c{ 900 };
	void(*fun1) (int&) = func1;
	fun1(c);
	int(*fun2) (int&) = func2;
	fun2(c);*/

	/**********************************************************/

	/*initializer_list<int> list{ 1,2,3,4,5,6 };
	cout << "average{ 1,2,3,4,5,6 } : " << average(list) << "\n";

	double avg2{ average({11,12,13,12,20}) };
	cout << "average{11,12,13,12,20} : " << avg2 << "\n";

	double avg3{ 0.0 };
	avg3 = average({ 2, 3, 5, 51, 200 });
	cout << "average{2,3,5,51,200} : " << avg3 << "\n";*/

	/**********************************************************/

	/*string line{};
	cout << "Full Sentence: ";
	getline(cin, line);
	string word{};
	cout << "Only first word (until whitespace): ";
	cin >> word;
	cout << line << " - " << word;*/

	/**********************************************************/

	/*Test t1(100);
	Test t2(900, 200);

	t1.print();
	t2.print();

	t2 = t1;
	t2.print();

	Test t3{ t2 };
	t3.print();

	Test t4{ move(t1) };
	t1.print();
	t4.print();

	Test t5;
	t5 = move(t2);
	t2.print();
	t5.print();

	Test t6(10000, 20000);

	Test t7{ t6 };
	t7.print();

	t6.setValues(35, 59);
	t6.print();
	t6.getObj().print();
	t6.getObj().setValues(5, 9);*/

	/**********************************************************/

	/*int (*funPtr)(int);
	funPtr = valSquare;
	cout << funPtr(90) << "\n";*/

	/**********************************************************/

	/*int x{ 100 };
	int y{ 200 };
	int z{ 500 };

	int* largest = largest_int(&x, &y, &z);
	cout << *largest << "\n";*/

	/**********************************************************/

	return 0;
}