#include <iostream>
#include "Quad.h"

using std::cout;
using std::cin;
using std::endl;

void test_getter_setter();

void test_insersion_extraction_operator();
void test_constructors_and_equality();
void test_multiplication_and_inverse();
void test_unary_operators();
void test_basic_arithmetic_operators();
void test_compound_assignment_operators();
void test_subscript_operator();
void test_relational_operators();
void test_function_objects();

int main()
{
	//test_getter_setter();

	test_insersion_extraction_operator();
	//test_constructors_and_equality();
	//test_multiplication_and_inverse();
	//test_unary_operators();
	//test_basic_arithmetic_operators();
	//test_compound_assignment_operators();
	//test_subscript_operator();
	//test_relational_operators();
	//test_function_objects();

	return 0;
}

void test_getter_setter()
{
	Quad q1{ 1.1,2.2,3.3,4.4 };
	cout << "get : " << q1.get() << "\n";

	Quad q2{};
	q2.set(Quad{ 2.2,4.5,6.7,8.9 });

	cout << "set : " << q2 << "\n";
	//assert(q == Quad(4.5, 2.5, 7, 5));
}

void test_insersion_extraction_operator()
{
	Quad q;
	cout << "Please enter the numbers 4.5, 2.5, 7, 5, in that order\n\n";
	cin >> q;
	cout << "input = " << q << endl;
	//assert(q == Quad(4.5, 2.5, 7, 5));
}

void test_constructors_and_equality()
{

}

void test_multiplication_and_inverse()
{

}

void test_unary_operators()
{

}

void test_basic_arithmetic_operators()
{

}

void test_compound_assignment_operators()
{

}

void test_subscript_operator()
{

}

void test_relational_operators()
{

}

void test_function_objects()
{

}