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
	Test() : Test(420, 619) {};

	Test(int a) : Test(a, 0) {}

	Test(int a, int b) : x(a), y(b) {}

	Test(const Test& t)
	{
		cout << "Copy constructor called" << endl;
		x = t.x;
		y = t.y;
	}

	Test(Test&& t) noexcept
	{
		cout << "Move constructor called" << endl;
		x = t.x;
		y = t.y;

		t.x = 0;
		t.y = 0;
	}

	Test& operator=(const Test& t)
	{
		cout << "Copy Assignment operator called" << endl;
		x = t.x;
		y = t.y;

		return *this;
	}

	Test& operator=(Test&& t) noexcept
	{
		cout << "Move Assignment operator called" << endl;
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


int valSquare(int a) { return a * a; }

void doSomethingFun(int a, int fun(int)) { fun(a); }

int* largest_int(int* a, int* b, int* c)
{
	if (*a > *b && *b > *c) return a;
	else if (*b > *a && *b > *c) return b;
	else return c;
}