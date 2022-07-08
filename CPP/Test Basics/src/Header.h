#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::move;
using std::initializer_list;

#define LOG(key, value) cout << key << value << endl;

class Test
{
private:
	int x;
	int y;

public:
	Test() : Test(100, 1000) { cout << "Default constructor" << endl; };

	Test(int a) : Test(a, 0) {}

	Test(int a, int b) : x(a), y(b) {}

	Test(const Test& t)
		:x{ t.x }, y{ t.y }
	{
		cout << "Copy constructor" << endl;
	}

	Test(Test&& t) noexcept
		:x{ t.x }, y{ t.y }
	{
		cout << "Move constructor" << endl;
		t.x = 0;
		t.y = 0;
	}

	Test& operator=(const Test& t)
	{
		cout << "Copy Assignment operator" << endl;
		x = t.x;
		y = t.y;

		return *this;
	}

	Test& operator=(Test&& t) noexcept
	{
		cout << "Move Assignment operator" << endl;
		x = t.x;
		y = t.y;

		t.x = 0;
		t.y = 0;

		return *this;
	}

	void print() const
	{
		cout << "x :" << x << " - y: " << y << "\n";
	}

	const Test& getObj() { return *this; }

	int funXX() { return x * x; }
	int funYY() { return y * y; }

	void setValues(int a, int b)
	{
		x = a;
		y = b;
	}

};

class Foo
{
private:
	int x;
public:
	Foo() :x{ 1 } { cout << "Default Ctor\n"; }
	Foo(const Foo&) { cout << "copy ctor\n"; }
	Foo(Foo&&) { cout << "move ctor\n"; }
	Foo& operator=(const Foo&)
	{
		cout << "copy operator\n";
		return *this;
	}
	Foo& operator=(const Foo&&) noexcept
	{
		cout << "move operator\n";
		return *this;
	}
	~Foo() { cout << "Dtor\n"; }
};

class Parent
{
public:
	Parent()
	{
		cout << "Construct Parent" << endl;
	}

	virtual ~Parent()
	{
		cout << "Destruct Parent" << endl;
	}
};

class Child1 : public Parent
{
public:
	Child1()
	{
		cout << "Construct Child1" << endl;
	}

	Child1(const Parent& other)
	{
		cout << "PtoC1 - Copy constructor called" << endl;
	}

	Child1(Parent&& other) noexcept
	{
		cout << "PtoC1 - Move constructor called" << endl;
	}

	virtual ~Child1()
	{
		cout << "Destruct Child1" << endl;
	}
};

class Child2 : public Child1
{
public:
	Child2()
	{
		cout << "Construct Child2" << endl;
	}

	Child2(const Child1& other)
	{
		cout << "C1toC2 - Copy constructor called" << endl;
	}

	Child2(Child1&& other) noexcept
	{
		cout << "C1toC2 - Move constructor called" << endl;
	}

	virtual ~Child2()
	{
		cout << "Destruct Child2" << endl;
	}
};

void doSomething()
{
	int x{ 1 };
	static int y{ 1 };

	++x;
	++y;

	cout << x << " - " << y << "\n";
}

void func1(int& x)
{
	cout << "void - func_ptr1 " << x << "\n";
}

int func2(int& x)
{
	cout << "int - func_ptr2 " << x << "\n";
	return x;
}

void f(int& x)
{
	cout << "int& " << x << "\n";
}

void f(const int& x)
{
	cout << "const int& " << x << "\n";
}

void f(int&& x)
{
	cout << "int&& " << x << "\n";
}


void f(int* const x)
{
	cout << "int* const " << *x << " ";
	*x = 420;
	cout << " - post change " << *x << "\n";
}

void f(const int* x)
{
	cout << "const int* " << *x << "\n";
}

double average(const initializer_list<int>& list)
{
	int sum{ 0 };
	for (int x : list)
	{
		sum += x;
	}
	return static_cast<double> (sum) / list.size();
}

void doSomethingFun(int a, int fun(int)) { fun(a); }

int* largest_int(int* a, int* b, int* c)
{
	if (*a > *b && *b > *c) return a;
	else if (*b > *a && *b > *c) return b;
	else return c;
}