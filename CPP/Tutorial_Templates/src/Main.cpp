#include <iostream>
#include <string>
#include <vector>
#include <array>

using std::cout;
using std::ostream;
using std::string;

template <typename T>
T sum(const T& x, const T& y)
{
	return x + y;
}

template <typename T>
T good_max(const T& a, const T& b)
{
	if (a < b)
		return b;
	return a;
}

template <typename T, size_t N>
T get_min(T const (&array)[N])
{
	T min{ array[0] };
	for (size_t k = 1; k < N; k++)
		if (array[k] < min)
		{
			min = array[k];
		}
	return min;
}

/********************************************************/

class Number
{
private:
	int value{ 0 };
public:
	Number() = default;
	// all defaulted special memebr functions; omitted for brevity
	explicit Number(int value) : value{ value } {}
	int get() const { return value; }  // getter
	void set(int val) { value = val; } // setter
};

ostream& operator<<(ostream& sout, const Number& n)
{
	sout << n.get();
	return sout;
}

template <>
Number sum<Number>(const Number& value1, const Number& value2)
{
	int v1 = value1.get();
	int v2 = value2.get();
	return Number(v1 + v2);
}

std::string sum(const char* str1, const char* str2)
{
	std::string result{ str1 };
	result += str2;
	return result;
}

/********************************************************/

template <typename T>
class Point
{
private:
	T x_coord, y_coord;
public:
	Point() : x_coord{}, y_coord{} {}
	Point(const T& x, const T& y) : x_coord{ x }, y_coord{ y } {}
	void print() {
		cout << x_coord << " " << y_coord << "\n";
	}
	//...
};

/********************************************************/

template<typename T1, typename T2>
class Pair
{
	T1 first;
	T2 second;
public:
	Pair();
	Pair(const T1& x, const T2& y);
	T1 getFirst() const;
	T2 getSecond() const;
	//...
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair() : first{}, second{} { }

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& x, const T2& y)
	: first(x), second(y) { }

template<typename T1, typename T2>
T1 Pair<T1, T2>::getFirst() const { return first; }

template<typename T1, typename T2>
T2 Pair<T1, T2>::getSecond() const { return second; }

/********************************************************/

// T is a type parameter
// StackSize is a non-type parameter, with a default value
template < class T, int StackSize = 100>
class Stack {
	T stack[StackSize];
	int top;
public:
	Stack() : top(0), stack() {}
	void push(const T& e) {
		if (top == StackSize)
			throw std::overflow_error("Stack overflow");
		stack[top++] = e;
	}
	T pop() {
		if (top == 0)
			throw std::underflow_error("Stack underflow");
		return stack[--top];

	}
};

struct Equal_Sensitive
{
	bool operator()(char x, char y) { return x == y; }
};

struct Equal_Insensitive
{
	bool operator()(char x, char y) {
		return tolower(x) == tolower(y);
	}
};

template < class Comparator>
bool compare(const string& str1, const string& str2)
{
	int minLength = std::min(str1.length(), str2.length());
	Comparator comp;
	for (int i = 0; i < minLength; i++)
		if (!comp(str1[i], str2[i]))// use this object's comparison policy
			return false;
	return true;
}

/********************************************************/

int main()
{
	cout << sum(3, 4) << " " << sum(2.2, 8.9) << "\n";
	cout << sum(string("Hi"), string(" Mom")) << "\n";

	size_t x{ 2 }, y{ 3 };

	cout << sum(x, y) << "\n";

	// cout << sum(2, 7.9) << "\n";
	cout << sum<double>(2, 7.9) << "\n";

	cout << good_max(x, y) << "\n";

	cout << "******************\n";

	int a[5]{ 61, 42, 33, 14, 25 };
	cout << get_min(a) << '\n';
	// or equivalently
	cout << get_min<int, 5>(a) << '\n';

	int b[7]{ 61, 42, 33, 14, 25, 29, 33 };
	cout << get_min(b) << '\n';
	// or equivalently
	cout << get_min<int, 7>(b) << '\n';

	// Error: cannot convert from 'int [7]' to 'const T [3]'
	// cout << get_min<int, 3>(b) << '\n';

	cout << "******************\n";

	Number n1{ 12 }, n2{ 24 };
	cout << sum(n1, n2) << '\n';

	cout << "******************\n";

	Point<int> p1{ 1, 2 };
	Point<double> p2{ 1.5, 6.7 };
	std::array<int, 15> numz = { {1, 2, 3, 4, 5} };
	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	p1.print();
	p2.print();

	cout << "******************\n";

	Stack<double> dstack;
	Stack<string, 50> name_stack;
	Stack<char, 100> cstack;

	name_stack.push("John Doe");
	cout << name_stack.pop() << "\n";

	cout << "******************\n";

	string str1{ "hello" };
	string str2{ "Hello" };
	bool b1 = compare<Equal_Sensitive>(str1, str2);
	cout << b1 << '\n'; // false
	bool b2 = compare<Equal_Insensitive>(str1, str2);
	cout << b2 << '\n'; // true
}