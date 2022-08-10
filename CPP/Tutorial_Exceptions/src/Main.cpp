#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Foo
{
	std::string message;
	Foo(const std::string& message) : message{ message }
	{
		cout << "Foo ctor: " + message << '\n';
	}
	~Foo()
	{
		cout << "Foo dtor: " + message << '\n';
	}
};
void f3()
{
	Foo foo31{ "foo3 in f3" };
	cout << "In f3" << endl;
	cout << "f3 throws runtime_error exception" << endl;
	throw std::runtime_error("runtime_error in f3");
	cout << "back to f2 from f3" << endl;
}
void f2()
{
	Foo foo21{ "foo2 in f2" };
	cout << "f3 is called inside f2" << endl;
	f3();
	cout << "back to f1 from f3" << endl;
}
void f1()
{
	Foo foo11{ "foo1 in f1" };
	cout << "f2 is called inside f1" << endl;
	f2();
	cout << "back to f1 from f2" << endl;
}

struct Moo
{
	std::string message;
	Moo(const std::string& message) : message{ message }
	{
		cout << "Moo ctor: " + message << '\n';
	}
	~Moo() { cout << "Moo dtor: " + message << '\n'; }
};
void g3()
{
	Moo moo3{ "moo3 in g3" };
	cout << "In g3" << endl;
	cout << "g3 throws runtime_error exception" << endl;
	throw std::runtime_error("runtime_error in g3");
	cout << "back to g2 from g3" << endl;
}
void g2()
{
	Moo moo2{ "moo2 in g2" };
	cout << "g3 is called inside g2" << endl;
	g3();
	cout << "back to g1 from g3" << endl;
}
void g1()
{
	Moo moo1{ "moo1 in g1" };
	try
	{
		cout << "g2 is called inside g1" << endl;
		g2();
		cout << "back to g1 from g2" << endl;
	}
	catch (std::runtime_error& error) // handle runtime error
	{
		cout << "Exception caught in g1: " << error.what() << endl;
		cout << "Exception handled in g1" << endl;
	}
}

class exception {
public:
	exception() noexcept;
	exception(const exception&) noexcept;
	exception& operator=(const exception&) noexcept;
	virtual ~exception();
	virtual const char* what() const noexcept;
};

class MyException : public std::exception
{
public:
	MyException(string message) : mMessage(message) {}
	virtual const char* what() const noexcept override {
		return mMessage.c_str();
	}
private: string mMessage;
};

int main()
{
	/*
	int score{};
	cout << "enter a score in the range [0,100]\n";
	try
	{
		// loop until invalid score
		while (true) {
			cin >> score;
			// Code that may throw exceptions must be in a try block...
			if (score < 0 || score > 100)
			{
				// Throws an exception of type std::string
				throw "invalid test score: " + std::to_string(score);
			}
			// This code only executes if the exception is not thrown...
		}
	}
	catch (const std::string& message)
	{
		// Code to handle the exception...
		// ...which only executes if an exception of type std::string
		// or 'const std::string ', or 'char*', or 'const char*' is thrown
		std::cout << message << std::endl;
		// exception is now considered handled
	}
	// execution resumes here
	*/

	/*
	int score{};
	for (int k = 0; k < 3; ++k)
	{
		cout << "enter a score in the range [0,100]\n";
		cin >> score;
		try
		{
			if (score < 0)
			{
				throw std::to_string(score);
			}
			cout << "no exception thrown because score is >=0: " << score << endl;
			if (score > 100)
			{
				throw score;
			}
			cout << "no exception thrown because score is <= 100: " << score << endl;
		}
		catch (int n) // Catch exceptions of type int
		{
			cout << "n caught - n is " << n << endl;
		}
		catch (const std::string& msg) // Catch exceptions of C++ or C string
		{
			cout << "msg caught - msg is \"" << msg << '"' << endl;
		}
	}
	std::cout << "End of the for loop body. score is " << score << std::endl;
	cout << "bye\n";
	*/

	/*
	Foo foo_main{ "foo main in main" };
	try
	{
		cout << "f1 is called inside main" << endl;
		f1();
		cout << "back to main from f1" << endl;
	}
	catch (std::runtime_error& error) // handle runtime error
	{
		cout << "Exception caught: " << error.what() << endl;
		cout << "Exception handled in main" << endl;
	}
	cout << "bye" << endl;
	*/

	/*
	Moo moo_main{ "moo_main in main" };
	cout << "g1 is called inside main" << endl;
	g1();
	cout << "back to main from g1" << endl;
	cout << "bye" << endl;
	*/

	try {
		MyException myex("MyException");
		throw myex;
	}
	// polymorphically catch any exception derived from the base class exception
	catch (exception& e)
	{
		cout << "Caught an exception polymorphically "
			<< e.what() << '\n';
	}
	catch (...) // catch a thrown value of any type
	{
		cout << "Caught an unknown exception\n";
	}
}