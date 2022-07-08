#pragma once

#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>

using std::array;
using std::abs;
using std::max;
using std::fixed;
using std::setprecision;
using std::out_of_range;
using std::ostream;
using std::istream;

class Quad {

private:
	array<double, 4> quad{};

public:
	static inline const double tolerance{ 1.0E-6 }; //C++17 and later

	// Normal constructor
	Quad(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

	// Accessor and Mutator member functions
	Quad get() const;
	void set(const Quad&);

	// extraction from Quad object
	friend ostream& operator<<(ostream&, const Quad&);
	// insertion to Quad object
	friend istream& operator>>(istream&, Quad&);

	// Big Five constructors defaulted 
	Quad(const Quad&) = default; // Copy constructor
	Quad(Quad&&) = default; // Move constructor
	Quad& operator=(const Quad&) = default; // Copy assignment operator
	Quad& operator=(Quad&&) = default; // Move assignment operator
	~Quad() = default; // Destructor

	/***************** Member Operator Overloading functions *****************/

	Quad& operator+=(const Quad&);   // Quad = Quad + Quad rhs
	Quad& operator-=(const Quad&);   // Quad = Quad - Quad rhs
	Quad& operator*=(const Quad&);   // Quad = Quad * Quad rhs
	Quad& operator/=(const Quad&);   // Quad = Quad / Quad rhs

	Quad& operator+=(const double&); // Quad = Quad + double val
	Quad& operator-=(const double&); // Quad = Quad - double val
	Quad& operator*=(const double&); // Quad = Quad * double val
	Quad& operator/=(const double&); // Quad = Quad / double val

	Quad operator+();                // unary +
	Quad operator-();                // unary -

	Quad& operator++();             // prefix ++
	Quad& operator--();             // prefix --

	const Quad operator++(int);     // postfix ++
	const Quad operator--(int);     // postfix --

	const double& operator[](size_t) const; // Quad[i] subscript
	double& operator[](size_t);             // const Quad[i] subscript

	// Returns the inverse of Quad
	Quad inverse() const;
	// Returns the absolute value of Quad
	double absoluteValue() const;

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


};

// Free Non-Member Operator Overloading
Quad operator+(const Quad&, const Quad&);     // Quad + Quad
Quad operator-(const Quad&, const Quad&);     // Quad - Quad
Quad operator*(const Quad&, const Quad&);     // Quad * Quad
Quad operator/(const Quad&, const Quad&);     // Quad / Quad

Quad operator+(const Quad&, const double&);   // Quad + double
Quad operator-(const Quad&, const double&);   // Quad - double
Quad operator*(const Quad&, const double&);   // Quad * double
Quad operator/(const Quad&, const double&);   // Quad / double

Quad operator+(const double&, const Quad&);   // double + Quad
Quad operator-(const double&, const Quad&);   // double - Quad
Quad operator*(const double&, const Quad&);   // double * Quad
Quad operator/(const double&, const Quad&);   // double / Quad

bool operator==(const Quad&, const Quad&);    // Quad == Quad
bool operator!=(const Quad&, const Quad&);    // Quad != Quad
bool operator<(const Quad&, const Quad&);     // Quad <	Quad
bool operator<=(const Quad&, const Quad&);    // Quad <= Quad
bool operator>(const Quad&, const Quad&);     // Quad > Quad
bool operator>=(const Quad&, const Quad&);    // Quad >= Quad