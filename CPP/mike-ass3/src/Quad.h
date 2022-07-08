#pragma once

#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>

using std::array;
using std::initializer_list;
using std::ostream;
using std::istream;

class Quad {

private:
	array<double, 4> quad{};

public:
	static inline const double tolerance{ 1.0E-6 }; //C++17 and later

	// Accessor and Mutator member functions
	Quad get() const;
	void set(const Quad&);

	// Normal constructor
	Quad(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

	// Defaulted Big Five constructors
	Quad(const Quad&) = default; // Copy constructor
	Quad(Quad&&) = default; // Move constructor
	Quad& operator=(const Quad&) = default; // Copy assignment operator
	Quad& operator=(Quad&&) = default; // Move assignment operator
	~Quad() = default; // Destructor

	// Begin Member Function Operator Overloading 
	Quad& operator+=(const Quad&);   // += assignment operator overloading for Quad
	Quad& operator-=(const Quad&);   // -= assignment operator overloading for Quad
	Quad& operator*=(const Quad&);   // *= assignment operator overloading for Quad
	Quad& operator/=(const Quad&);   // /= assignment operator overloading for Quad

	Quad& operator+=(const double&); // += assignment operator overloading for double
	Quad& operator-=(const double&); // -= assignment operator overloading for double
	Quad& operator*=(const double&); // *= assignment operator overloading for double
	Quad& operator/=(const double&); // /= assignment operator overloading for double

	Quad operator+();                // unary + operator overloading
	Quad operator-();                // unary - operator overloading

	Quad& operator++();             // prefix ++ operator overloading
	Quad& operator--();             // prefix -- operator overloading

	const Quad operator++(int);     // postfix ++ operator overloading
	const Quad operator--(int);     // postfix -- operator overloading

	const double& operator[](size_t) const; // Return an element of the Quad found at a specific index
	double& operator[](size_t);             // Return an element of the Quad found at a specific index

	// Special Functions
	Quad inverse() const;                   // Calculate the inverse of the calling Quad obect
	double determinant() const;             // Calculate the determinant of the calling object

	// Function Objects
	// Returns the largest coordinate values of the invoking Quad object
	double operator()();
	// Returns the i’th coordinate value of the invoking Quad object
	double operator()(size_t i);
	// Returns the larger of the i’th and j’th coordinate values of the invoking Quad object
	double operator()(size_t i, size_t j);
	// Returns the largest of the i’th, j’th, and k’th coordinate values of the invoking Quad object
	double operator()(size_t i, size_t j, size_t k);
	// Returns the largest of the i’th, j’th, k’th, and l’th coordinate values of the invoking Quad object
	double operator()(size_t i, size_t j, size_t k, size_t l);

	// Computes and returns the absolute value of the invoking object
	double absoluteValue() const;

};

// Free Non-Member Operator Overloading
Quad operator+(const Quad&, const Quad&);     // + operator overloading
Quad operator-(const Quad&, const Quad&);     // - operator overloading
Quad operator*(const Quad&, const Quad&);     // * operator overloading
Quad operator/(const Quad&, const Quad&);     // / operator overloading

Quad operator+(const Quad&, const double&);   // addition operator overloading
Quad operator-(const Quad&, const double&);   // substraction operator overloading
Quad operator*(const Quad&, const double&);   // multiplication operator overloading
Quad operator/(const Quad&, const double&);   // division operator overloading

Quad operator+(const double&, const Quad&);   // addition operator overloading
Quad operator-(const double&, const Quad&);   // substraction operator overloading
Quad operator*(const double&, const Quad&);   // multiplication operator overloading
Quad operator/(const double&, const Quad&);   // division operator overloading

bool operator==(const Quad&, const Quad&);    // == to operator overloading
bool operator!=(const Quad&, const Quad&);    // != to operator overloading
bool operator<(const Quad&, const Quad&);     // < operator overloading
bool operator<=(const Quad&, const Quad&);    // <= to operator overloading
bool operator>(const Quad&, const Quad&);     // > than operator overloading
bool operator>=(const Quad&, const Quad&);    // >= operator overloading

ostream& operator<<(ostream&, const Quad&);   // Read Quad object from Input Stream
istream& operator>>(istream&, Quad&);         // Write Quad object from Input Stream