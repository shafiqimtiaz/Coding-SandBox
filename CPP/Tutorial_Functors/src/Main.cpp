#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stod;


class Average {

private:
	double curr_avg;
	int curr_count;
public:
	Average() { curr_avg = 0; curr_count = 0; }

	int sum(int x[], int n) {
		int s = 0;
		for (int i = 0; i < n; i++) s += x[i];
		return s;
	}

	double operator()(int x[], int m) {
		int s = sum(x, m);
		curr_avg = (curr_count * curr_avg + s) / (m + curr_count);
		curr_count += m;
		return curr_avg;
	}

	double operator()(int x) {
		curr_avg = (curr_count * curr_avg + x) / (1 + curr_count);
		curr_count++;
		return curr_avg;
	}
};

template <typename T>
T add(T a, T b) {
	return a + b;
}

template <class T, class E>
E add(T a, E b) {
	return a + b;
}

double get_avg(const int arr[], int n) {
	int s = 0;
	for (int i = 0; i < n; ++i) s += arr[i];
	return s / n;
}

int RandomNumber() { return (std::rand() % 1000); }

// C-style of specifying a "function" as a function parameter
int evaluate_c_style(int (*f)(int, int), int x, int y) {
	return f(x, y);
}

// modern style of specifying a "function" as a function parameter
int evaluate_m_style(std::function<int(int, int)> f, int x, int y) {
	return f(x, y);
}

int add(int x, int y) { return x + y; }

// converts a string to double returning the result
double stringToDouble(const string& str) { return stod(str); }

class StrToDouble {
public:
	double operator()(const string& str) { return stod(str); }
};

int main()
{
	/*int x[3] = { 1,2,3 };
	int y[1] = { 4 };
	int z[3] = { 5,6,7 };
	Average a;
	cout << a(x, 3) << " " << a(1) << " " << a(z, 3) << "\n";*/

	/*int x = 2;
	double y = 10.0;
	cout << add(x, x) << " " << add(x, y) << " " << add(string("Hello"), string("Mom")) << "\n";*/

	/*std::vector<int> v{ 1,2,3,4,5,6,7 };
	std::for_each(v.begin(), v.end(), [](int& value) { value *= 2; });
	std::for_each(v.begin(), v.end(), [&](int value) { v.push_back(value); });
	std::for_each(v.begin(), v.end(), [](int& value) { cout << value << " "; });

	int x[3] = { 1,2,3 };

	auto f1 = [=]() {
		//x[2] = 1000; doesnt work since capture is by value
		return get_avg(x, 3);
	};

	auto f2 = [&]() {
		x[2] = 1000; // works and can change the capture list elements
		return get_avg(x, 3);
	};

	auto f3 = []() {
		//x[2] = 1000;
		int x[3] = { 10,20,30 }; // cant work with external items, variables inside scope can be used
		return get_avg(x, 3);
	};

	cout << f1() << " " << f2() << " " << f3() << endl;
	*/

	/****************************************************/

	std::plus<> add; // add is an object of type std::plus<int>,
	std::minus<> sub; // sub is an object of type std::minus<long>,
	std::multiplies<> mul; // and so on
	std::divides<> div;
	std::modulus<> mod;
	std::negate<> neg;
	std::equal_to<> equ;

	// these are just examples of trivial and unrealistic
	// applications of functions objects
	int x1 = add(1, 2); // x1 = 3
	long x2 = sub(23L, 2L); // x2 = 25
	float x3 = mul(23.0F, 2.0F); // x3 = 25.0
	double x4 = div(3, 1.5); // x4 = 2.0
	int x5 = neg(x1); // x5 = -3
	std::string word = "nice";
	bool condition = equ(word, "nice"); // true

	cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << " " << condition << "\n";

	/****************************************************/

	int m{ 7 }; // any integer
	vector<int> vec{}; // an empty vector of integers

	std::srand(unsigned(std::time(0))); // seed the random number generator
	// a lambda that takes a local vec by reference and local m by value
	auto push_mutiples_of_m = [&vec, m](int x)
	{
		if (x % m == 0) vec.push_back(x);
	};
	// Fill vec with 10 random number that are multiples of m
	while (vec.size() < 10)
	{
		int x = RandomNumber();
		push_mutiples_of_m(x);
	}
	for (auto it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	/****************************************************/

	auto fun = [](int x, int y) { return x + y; };
	cout << evaluate_c_style(fun, 10, 20) << endl; // prints 30
	cout << evaluate_m_style(fun, 10, 20) << endl; // prints 30

	/****************************************************/

	std::function<int(int, int)> doSomething; // declare a function
	// variable that takes
	// two int parameters
	// and returns an int
	doSomething = add; // Initialize our function variable "doSomething";
	// set it to an actual callable with exact same
	// signature (here a free function);
	std::cout << doSomething(12, 34) << std::endl;

	/****************************************************/

	std::function<double(const string&)> doSomethingAgain;

	doSomethingAgain = stringToDouble; // Initialize our function variable
	// "doSomething"; set it to an actual
	// callable with exact same signature
	// (here a free function);
	cout << doSomethingAgain("-12.345") << endl;

	// reset doSomething to another callable with exact same signature;
	// use a lambda here
	doSomethingAgain = [](const string& str) {return stod(str); };
	cout << doSomethingAgain("-12.345") << endl;

	// reset doSomething to another callable with exact same signature;
	// use a function object here
	doSomethingAgain = StrToDouble{};
	cout << doSomethingAgain("-12.345") << endl;

	return 0;
}