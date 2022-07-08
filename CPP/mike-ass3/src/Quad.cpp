#include "Quad.h"

// Normal constructor
Quad::Quad(double x1, double x2, double x3, double x4) : quad{ x1, x2, x3, x4 } {}

//Accessors and Mutators
Quad Quad::get() const {
	return Quad{ this->quad.at(0), this->quad.at(1), this->quad.at(2), this->quad.at(3) };
}

void Quad::set(const Quad& q) {
	this->quad.at(0) = q.quad.at(0);
	this->quad.at(1) = q.quad.at(1);
	this->quad.at(2) = q.quad.at(2);
	this->quad.at(3) = q.quad.at(3);
}

// SOME FUNCTIONS
// Calculate Determinant to be used for Inverse. x1x3 - x2x4 != 0
double Quad::determinant() const {

	return (quad.at(0) * quad.at(2)) - (quad.at(1) * quad.at(3));
}

// Calculate the inverse of the calling object. x1x3 - x2x4 != 0
Quad Quad::inverse() const {

	return (1 / determinant()) * Quad { quad.at(2), -quad.at(1), quad.at(0), -quad.at(3) };
}

// Returns whether or not the invoking object has inverse
double Quad::absoluteValue() const {
	return (std::abs(quad.at(0)) + std::abs(quad.at(1)) + std::abs(quad.at(2)) + std::abs(quad.at(3)));
}

// Member Operator Overloading
// Binary Addition 
Quad& Quad::operator+=(const Quad& Y) {

	this->quad.at(0) = this->quad.at(0) + Y.quad.at(0);
	this->quad.at(1) = this->quad.at(1) + Y.quad.at(1);
	this->quad.at(2) = this->quad.at(2) + Y.quad.at(2);
	this->quad.at(3) = this->quad.at(3) + Y.quad.at(3);

	return *this;
}

// Binary Subtraction 
Quad& Quad::operator-=(const Quad& Y) {

	this->quad.at(0) = this->quad.at(0) - Y.quad.at(0);
	this->quad.at(1) = this->quad.at(1) - Y.quad.at(1);
	this->quad.at(2) = this->quad.at(2) - Y.quad.at(2);
	this->quad.at(3) = this->quad.at(3) - Y.quad.at(3);

	return *this;
}

// Binary Multiplication
Quad& Quad::operator*=(const Quad& Y) {

	double newX1 = quad.at(0) * Y.quad.at(0) + quad.at(1) * Y.quad.at(3);
	double newX2 = quad.at(0) * Y.quad.at(1) + quad.at(1) * Y.quad.at(2);
	double newX3 = quad.at(3) * Y.quad.at(1) + quad.at(2) * Y.quad.at(2);
	double newX4 = quad.at(3) * Y.quad.at(0) + quad.at(2) * Y.quad.at(3);

	quad.at(0) = newX1;
	quad.at(1) = newX2;
	quad.at(2) = newX3;
	quad.at(3) = newX4;

	return *this;
}

// Binary Division 
// Uses the inverse method
Quad& Quad::operator/=(const Quad& Y) {

	*this *= Y.inverse();

	return *this;
}

// Scalar Addition
Quad& Quad::operator+=(const double& a) {

	this->quad.at(0) = this->quad.at(0) + a;
	this->quad.at(1) = this->quad.at(1) + a;
	this->quad.at(2) = this->quad.at(2) + a;
	this->quad.at(3) = this->quad.at(3) + a;

	return *this;
}

// Scalar Substraction 
Quad& Quad::operator-=(const double& a) {

	*this = -(a - *this);

	return *this;
}

// Scalar Multiplication
Quad& Quad::operator*=(const double& a) {

	this->quad.at(0) = this->quad.at(0) * a;
	this->quad.at(1) = this->quad.at(1) * a;
	this->quad.at(2) = this->quad.at(2) * a;
	this->quad.at(3) = this->quad.at(3) * a;

	return *this;
}

// Scalar Division 
// 1st make sure we're not divding by Zero.
Quad& Quad::operator/=(const double& a) {

	if (a == 0)
		throw std::runtime_error("Division error: Attempted to divide by Zero\n");

	this->quad.at(0) = this->quad.at(0) * (1.0 / a);
	this->quad.at(1) = this->quad.at(1) * (1.0 / a);
	this->quad.at(2) = this->quad.at(2) * (1.0 / a);
	this->quad.at(3) = this->quad.at(3) * (1.0 / a);

	return *this;

}

// Prefix increment operator overloading
Quad& Quad::operator++() {

	*this += 1.0;

	return *this;
}

// Postfix increment operator overloading
const Quad Quad::operator++(int) {

	Quad tempQuad{ *this };
	++(*this);

	return tempQuad;
}

// Prefix decrement operator overloading
Quad& Quad::operator--() {

	*this -= 1.0;

	return *this;
}

// Postfix decrement operator overloading
const Quad Quad::operator--(int) {

	Quad tempQuad{ *this };
	--(*this);

	return tempQuad;
}

// Unary Plus Operator 
Quad Quad::operator+() {

	return Quad{ std::abs(quad.at(0)), std::abs(quad.at(1)), std::abs(quad.at(2)), std::abs(quad.at(3)) };
}

// Unary Minus Operator
// Convert Quad to - valued by multiplying it by -1.0
Quad Quad::operator-() {

	Quad tempQuad{ *this };
	tempQuad *= -1.0;

	return tempQuad;
}

// Returns an element of the matrix found at a specific index
const double& Quad::operator[](size_t index) const {

	if (index == 1) return quad.at(0);
	else
		if (index == 2) return quad.at(1);
		else
			if (index == 3) return quad.at(2);
			else
				if (index == 4) return quad.at(3);
				else
					throw std::invalid_argument("index is out of bounds");
}

// Returns an element of the matrix found at a specific index
double& Quad::operator[](size_t index) {

	if (index == 1) return quad.at(0);
	else
		if (index == 2) return quad.at(1);
		else
			if (index == 3) return quad.at(2);
			else
				if (index == 4) return quad.at(3);
				else
					throw std::invalid_argument("index out of bounds");
}

// Function Objects
// Returns the largest coordinate value of the invoking Quad object.
double Quad::operator()() {
	return std::max({ (*this)[1], (*this)[2], (*this)[3], (*this)[4] });
}

double Quad::operator()(size_t i) {

	if (i < 1 || i>4) throw std::invalid_argument("index is out of bounds");

	return (*this)[i];
}

// Returns the larger of the i’th and j’th coordinate values of the invoking Quad object.
double Quad::operator()(size_t i, size_t j) {

	if (i < 1 || i>4) throw std::invalid_argument("index is out of bounds");
	if (j < 1 || j>4) throw std::invalid_argument("index is out of bounds");

	return std::max({ (*this)[i], (*this)[j] });
}

// Returns the largest of the i’th, j’th, and k’th coordinate values of the invoking Quad object.
double Quad::operator()(size_t i, size_t j, size_t k) {

	if (i < 1 || i>4) throw std::invalid_argument("index is out of bounds");
	if (j < 1 || j>4) throw std::invalid_argument("index is out of bounds");
	if (k < 1 || k>4) throw std::invalid_argument("index is out of bounds");

	return std::max({ (*this)[i], (*this)[j], (*this)[k] });
}

// Returns the largest of the i’th, j’th, k’th, and l’th coordinate values of the invoking Quad object
double Quad::operator()(size_t i, size_t j, size_t k, size_t l) {

	if (i < 1 || i>4) throw std::invalid_argument("index is out of bounds");
	if (j < 1 || j>4) throw std::invalid_argument("index is out of bounds");
	if (k < 1 || k>4) throw std::invalid_argument("index is out of bounds");
	if (l < 1 || l>4) throw std::invalid_argument("index is out of bounds");

	return std::max({ (*this)[i], (*this)[j], (*this)[k], (*this)[j] });
}

// Non-Member Operator Overloading
// Insertion operator
ostream& operator<<(ostream& sout, const Quad& q) {

	sout << std::fixed << std::setprecision(2)
		<< "[" << q[1]
		<< ", " << q[2]
		<< ", " << q[3]
		<< ", " << q[4]
		<< "]";

	return sout;
}

// Extraction operator overloading
istream& operator>>(istream& sin, Quad& q) {

	double x1, x2, x3, x4;

	if (sin >> x1 >> x2 >> x3 >> x4) {
		q[1] = x1;
		q[2] = x2;
		q[3] = x3;
		q[4] = x4;
	}

	return sin;
}

// Addition operator overloading
Quad operator+(const Quad& lhs, const Quad& rhs) {

	Quad tempQuad{ lhs };
	tempQuad += rhs;

	return tempQuad;
}

// Substraction operator overloading
Quad operator-(const Quad& lhs, const Quad& rhs) {

	Quad tempQuad{ lhs };
	tempQuad -= rhs;

	return tempQuad;
}

// Multiplication operator overloading
Quad operator*(const Quad& lhs, const Quad& rhs) {

	Quad tempQuad{ lhs };
	tempQuad *= rhs;

	return tempQuad;
}

// Division operator overloading
Quad operator/(const Quad& lhs, const Quad& rhs) {

	Quad tempQuad{ lhs };
	tempQuad /= rhs;

	return tempQuad;
}

Quad operator+(const Quad& lhs, const double& rhs) { // addition operator overloading

	Quad temp{ lhs };
	temp += rhs;

	return temp;
}

Quad operator-(const Quad& lhs, const double& rhs) { // substraction operator overloading
	Quad temp{ lhs };

	temp -= rhs;
	return temp;
}

Quad operator*(const Quad& lhs, const double& rhs) { // multiplication operator overloading

	Quad temp{ lhs };
	temp *= rhs;

	return temp;
}

Quad operator/(const Quad& lhs, const double& rhs) { // division operator overloading

	Quad temp{ lhs };
	temp /= rhs;

	return temp;
}

Quad operator+(const double& lhs, const Quad& rhs) { // addition operator overloading

	Quad temp{ rhs };
	temp += lhs;

	return temp;
}

Quad operator-(const double& lhs, const Quad& rhs) { // substraction operator overloading

	Quad temp{ lhs - rhs[1], lhs - rhs[2], lhs - rhs[3], lhs - rhs[4] };

	return temp;
}

Quad operator*(const double& lhs, const Quad& rhs) { // multiplication operator overloading

	Quad temp{ rhs };
	temp *= lhs;

	return temp;
}

Quad operator/(const double& lhs, const Quad& rhs) { // division operator overloading

	Quad temp{ rhs.inverse() };
	temp *= lhs;

	return temp;
}

// Less Than operator overloading
bool operator<(const Quad& lhs, const Quad& rhs) {

	if (operator!=(lhs, rhs) && (lhs.absoluteValue() < rhs.absoluteValue()))
		return true;
	else
		return false;
}


// Less than or equal to operator overloading
bool operator<=(const Quad& lhs, const Quad& rhs) {
	return operator<(lhs, rhs) || operator==(lhs, rhs);
}

// Greater than operator overloading
bool operator>(const Quad& lhs, const Quad& rhs) {
	if (lhs.absoluteValue() > rhs.absoluteValue())
		return true;
	else
		return false;
}

// Greater than or equal operator overloading
bool operator>=(const Quad& lhs, const Quad& rhs) {
	return operator>(lhs, rhs) || operator==(lhs, rhs);
}

// Equal to operator overloading
bool operator==(const Quad& lhs, const Quad& rhs) {

	Quad tempQuad = lhs - rhs;

	if (tempQuad.absoluteValue() <= Quad::tolerance)
		return true;
	else
		return false;
}

// Not equal to operator overloading
bool operator!=(const Quad& lhs, const Quad& rhs) {
	return !operator==(lhs, rhs);
}


