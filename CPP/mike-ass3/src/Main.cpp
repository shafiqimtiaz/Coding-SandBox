#include "Quad.h"
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
/*
Tests class Quad. Specifically, tests:
overloaded constructors, overloaded compound assignment operator,
overloadedbasic arithmetic operator, overloaded unaryoperators,
overloaded pre/post-increment/decrement, overloaded subscripts,
overloaded function objects, overloaded input/output operators,
and overloaded relational operators.
@return 0 to indicate success.
*/
// function prototypes
void test_insersion_extraction_operator();
void test_constructors_and_equality();
void test_multiplication_and_inverse();
void test_unary_operators();
void test_basic_arithmetic_operators();
void test_compound_assignment_operators();
void test_subscript_operator();
void test_relational_operators();
void test_function_objects();
void test_accessor_mutator();

int main()
{
	//test_insersion_extraction_operator();
	test_constructors_and_equality();
	test_multiplication_and_inverse();
	test_unary_operators();
	test_basic_arithmetic_operators();
	test_compound_assignment_operators();
	test_subscript_operator();
	test_relational_operators();
	test_function_objects();
	test_accessor_mutator();

	cout << "Test completed successfully!" << endl;
	return 0;
}

void test_insersion_extraction_operator()
{
	Quad q;

	cout << "Please enter the numbers 4.5, 2.5, 7, 5, in that order\n\n";
	cin >> q;
	cout << "input = " << q << endl;
	assert(q == Quad(4.5, 2.5, 7, 5));
}

void test_constructors_and_equality()
{
	const Quad ZERO;
	// must not compile, because zero is const
	//ZERO[1] = 0;
	//ZERO[2] = 0;
	//ZERO[3] = 0;
	//ZERO[4] = 0;

	Quad q1a;                           // default ctor
	cout << "q1a = " << q1a << endl;    // cout << Quad
	assert(q1a == ZERO);                // Quad == Quad

	Quad q1b(2);                        // normal ctor with 1 arg
	cout << "q1b = " << q1b << endl;
	assert(q1b == Quad(2, 0, 0, 0));

	Quad q1c(2, 3);                     // normal ctor with 2 args
	cout << "q1c = " << q1c << endl;
	assert(q1c == Quad(2, 3, 0, 0));

	Quad q1d(2, 3, 8);                  // normal ctor with 3 args
	cout << "q1d = " << q1d << endl;
	assert(q1d == Quad(2, 3, 8, 0));

	Quad q1(2.5, 3.6, 8.7, 5.8);        // normal ctor with 4 args
}

void test_multiplication_and_inverse()
{
	const Quad IDENTITY(1, 0, 1, 0);

	Quad q1(2.5, 3.6, 8.7, 5.8);                 // normal ctor with 4 args
	Quad q1_inverse = q1.inverse();              // inverse, copy ctor

	cout << q1_inverse << endl;

	cout << q1 << endl;


	Quad q1_inverse_times_q1 = q1_inverse * q1;   // Quad * Quad

	cout << q1_inverse_times_q1 << endl;

	assert(q1_inverse_times_q1 == IDENTITY);      // invariant, must hold     

	Quad q1_times_q1_inverse = q1 * q1_inverse;
	assert(q1_times_q1_inverse == IDENTITY);      // invariant, must hold
}

void test_unary_operators()
{
	Quad q(2.5, 3.6, 8.7, 5.8);          // normal ctor with 4 args

	assert(+q == -(-q));                 // +Quad, -Quad
	Quad t = q;
	++q;                                 // ++Quad
	assert(q == t + 1);
	--q;                                 // --Quad
	assert(q == t);

	Quad q_post_inc = q++;               // Quad++
	assert(q_post_inc == t);
	assert(q == t + 1);

	Quad q_post_dec = q--;               // Quad--
	assert(q_post_dec == t + 1);
	assert(q == t);

	Quad q2 = q++;                       //Quad++
	cout << "q = " << q << endl;
	cout << "q2 = " << q2 << endl;
	assert(q2 == q - Quad(1, 1, 1, 1));  // Quad - Quad

	Quad q3 = --q;                       // --Quad4D
	cout << "q = " << q << endl;
	cout << "q3 = " << q3 << endl;
	assert(q3 == q);

}

void test_basic_arithmetic_operators()
{
	Quad q1(2.5, 3.6, 8.7, 5.8);          // normal ctor with 4 args
	Quad q2(2, 3, 8);                     // normal ctor with 3 args

	cout << "\n";
	q2 += Quad(0, 0, 0, 5);               // Quad += Quad
	Quad q3 = q2 + 1.0;                   // Quad = Quad4D + int
	assert(q3 == Quad(3, 4, 9, 6));
	cout << "q3 = " << q3 << endl;

	q3 = 1 + q2;                          // Quad = double + Quad4D;
	assert(q3 == Quad(3, 4, 9, 6));

	Quad q4 = q3 - 1.0;                   // Quad = Quad4D - double
	assert(q4 == q2);
	cout << "q4 = " << q4 << endl;

	Quad q5 = 1.0 - q4;                   // Quad = double - Quad4D 
	cout << "q5 = " << q5 << endl;
	assert(q5 == Quad(-1, -2, -7, -4));


	Quad q6 = q5 * 2.0;                   // Quad = Quad4D * double
	cout << "q6 = " << q6 << endl;
	assert(q6 == Quad(-2, -4, -14, -8));

	Quad q7 = -1 * q6;                    // Quad = double * Quad4D
	cout << "q7 = " << q7 << endl;
	assert(q7 == Quad(2, 4, 14, 8));
	assert(q7 / -1.0 == q6);              // Quad = Quad4D / double
	assert(1 / q7 == 1 * q7.inverse());   // double / Quad4D, inverse
	assert(-1.0 * q5 * 2.0 == q7);        // double * Quad4D * double 

	Quad q8 = q1++;                       //Quad++
	Quad q9 = --q1;                       // --Quad4D
	q9--;                                 // Quad4D--
	cout << "q9 = " << q9 << endl;
	assert(q1 == 1 + q9);                 // double + Quad
	assert(q1 - 1 == q9);
	assert(-q1 + 1 == -q9);
	assert(2 * q1 == q9 + q1 + 1);
	assert(q1 * q1 == q1 * (1 + q9));

}
void test_compound_assignment_operators()
{
	Quad q1{ 3, 1, 7, 4 };
	q1 += q1;
	cout << "q1 = " << q1 << endl;
	assert(q1 == 2 * Quad(3, 1, 7, 4));

	Quad q2;
	q2 += (q1 / 2);
	cout << "q2 = " << q2 << endl;
	assert(q2 == Quad(3, 1, 7, 4));

	q2 *= 2;
	cout << "q2 = " << q2 << endl;
	assert(q2 == q1);

	q2 /= 2;
	cout << "q2 = " << q2 << endl;
	assert(q2 == q1 / 2);

	q2 += 10;
	cout << "q2 = " << q2 << endl;
	assert(q2 == (q1 + 20) / 2);

	q2 -= 10;
	cout << "q2 = " << q2 << endl;
	assert(q2 == 0.5 * q1);
}

void test_subscript_operator()
{
	Quad q(123, 6, 6, 4567.89);
	cout << "q = " << q << endl;

	// subscripts (non-const)
	q[1] = 3;
	q[2] = 1;
	q[3] = 7;
	q[4] = 4;

	cout << "q = " << q << endl;
	assert(q == Quad(3, 1, 7, 4));

	// subscripts (const)
	const Quad cq{ q };
	assert(cq == Quad(3, 1, 7, 4));
	assert(q == Quad(cq[1], cq[2], cq[3], cq[4]));
}

void test_relational_operators()
{
	Quad q{ 3, 1, 7, 4 };
	// relational operators
	double smallTol = Quad::tolerance / 10.0;
	Quad qNeighbor(3 - smallTol, 1 + smallTol, 7 - smallTol, 4 + smallTol);
	assert(q == qNeighbor);

	double tol = Quad::tolerance;
	assert(q != (q + tol));
	assert(q != (q + 0.25 * tol));
	assert(q == (q + 0.15 * tol));
	assert(q == q);

	assert(q < (q + 0.001));
	assert(q <= (q + 0.001));
	assert((q + 0.001) <= (q + 0.001));

	assert((q + 0.001) > q);
	assert((q + 0.001) >= q);
	assert((q + 0.001) >= (q + 0.001));

}

void test_function_objects()
{
	Quad q = Quad{ 4.5, 2.5, 7, 5 };

	// function objects
	assert(q() == 7.0);
	assert(q(1) == 4.5);
	assert(q(1, 4) == 5);
	assert(q(1, 2, 1) == 4.5);
	assert(q(2, 1, 3, 4) == 7);
}

void test_accessor_mutator()
{
	Quad q{ 4.5, 2.5, 7, 5 };
	Quad p{ q * 2 };

	assert(p.get() == q + q);
	p.set(q *= 2);
	assert(-q / 4 + p == +q * 3 / 4);
}
