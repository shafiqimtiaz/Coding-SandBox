#include "Quad.h"

/*
* Normal constructor
*/
Quad::Quad(double x1, double x2, double x3, double x4)
	: quad{ x1, x2, x3, x4 } {}

/*
* Accessors
*/
Quad Quad::get() const {

	//return *this;
	return Quad{ this->quad[0], this->quad[1], this->quad[2], this->quad[3] };
}

/*
* Mutators
*/
void Quad::set(const Quad& q) {
	this->quad[0] = q.quad[0];
	this->quad[1] = q.quad[1];
	this->quad[2] = q.quad[2];
	this->quad[3] = q.quad[3];
}

/*
* Returns the inverse of Quad
*/
Quad Quad::inverse() const {
	double beta = (quad[0] * quad[2]) - (quad[1] * quad[3]);
	return (1 / beta) * Quad { quad[2], -quad[1], quad[0], -quad[3] };
}

/*
* Returns the absolute value of Quad
*/
double Quad::absoluteValue() const {
	return { abs(quad[0]) + abs(quad[1]) + abs(quad[2]) + abs(quad[3]) };
}

/*
*  extraction from Quad q
*/
ostream& operator<<(ostream& sout, const Quad& q) {

	sout << "[  ";
	for (size_t i{}; i < 4; ++i) {
		sout << fixed << setprecision(2) << q.quad[i] << "  ";
	}
	sout << "]";

	return sout;
}

/*
*  insertion to Quad q
*/
istream& operator>>(istream& sin, Quad& q) {

	for (size_t i{}; i < 4; ++i) {
		sin >> q.quad[i];
	}

	return sin;
}

/***************** Member Operator Overloading functions *****************/

/*
* Quad = Quad + Quad rhs
*/
Quad& Quad::operator+=(const Quad& rhs) {

	this->quad[0] += rhs.quad[0];
	this->quad[1] += rhs.quad[1];
	this->quad[2] += rhs.quad[2];
	this->quad[3] += rhs.quad[3];

	return *this;
}

/*
* Quad = Quad - Quad rhs
*/
Quad& Quad::operator-=(const Quad& rhs) {

	this->quad[0] -= rhs.quad[0];
	this->quad[1] -= rhs.quad[1];
	this->quad[2] -= rhs.quad[2];
	this->quad[3] -= rhs.quad[3];

	return *this;
}

/*
* Quad = Quad * Quad rhs
*/
Quad& Quad::operator*=(const Quad& rhs) {

	double x1 = quad[0] * rhs.quad[0] + quad[1] * rhs.quad[3];
	double x2 = quad[0] * rhs.quad[1] + quad[1] * rhs.quad[2];
	double x3 = quad[3] * rhs.quad[1] + quad[2] * rhs.quad[2];
	double x4 = quad[3] * rhs.quad[0] + quad[2] * rhs.quad[3];

	this->quad[0] = x1;
	this->quad[1] = x2;
	this->quad[2] = x3;
	this->quad[3] = x4;

	return *this;
}

/*
* Quad = Quad / Quad rhs
*/
Quad& Quad::operator/=(const Quad& rhs) {

	*this *= rhs.inverse();

	return *this;
}

/*
* Quad = Quad + double val
*/
Quad& Quad::operator+=(const double& val) {

	this->quad[0] += val;
	this->quad[1] += val;
	this->quad[2] += val;
	this->quad[3] += val;

	return *this;
}

/*
* Quad = Quad - double val
*/
Quad& Quad::operator-=(const double& val) {

	this->quad[0] -= val;
	this->quad[1] -= val;
	this->quad[2] -= val;
	this->quad[3] -= val;

	return *this;
}

/*
* Quad = Quad * double val
*/
Quad& Quad::operator*=(const double& val) {

	this->quad[0] *= val;
	this->quad[1] *= val;
	this->quad[2] *= val;
	this->quad[3] *= val;

	return *this;
}

/*
* Quad = Quad / double val
*/
Quad& Quad::operator/=(const double& val) {

	if (val == 0) throw std::runtime_error("Cannot divide by Zero\n");

	this->quad[0] *= (1.0 / val);
	this->quad[1] *= (1.0 / val);
	this->quad[2] *= (1.0 / val);
	this->quad[3] *= (1.0 / val);

	return *this;

}

/*
* Unary Plus
*/
Quad Quad::operator+() {
	return Quad{ abs(quad[0]), abs(quad[1]), abs(quad[2]),abs(quad[3]) };
}

/*
* Unary Minus
*/
Quad Quad::operator-() {

	Quad temp{ *this };
	temp *= -1.0;

	return temp;
}

/*
* Prefix increment
*/
Quad& Quad::operator++() {

	*this += 1.0;

	return *this;
}

/*
* Prefix decrement
*/
Quad& Quad::operator--() {

	*this -= 1.0;

	return *this;
}

/*
* Postfix increment
*/
const Quad Quad::operator++(int) {

	Quad temp{ *this };
	++(*this);

	return temp;
}

/*
* Postfix decrement
*/
const Quad Quad::operator--(int) {

	Quad temp{ *this };
	--(*this);

	return temp;
}

/*
* Quad[i] subscript
*/
double& Quad::operator[](size_t index) {
	if (index > 4 || index < 1)
		throw out_of_range("index out of bounds");

	return this->quad[index - 1];
}

/*
* const Quad[i] subscript
*/
const double& Quad::operator[](size_t index) const {
	if (index > 4 || index < 1)
		throw out_of_range("index out of bounds");

	return this->quad[index - 1];
}

// Function Objects

/*
* Returns the largest coordinate value of the invoking Quad object
*/
double Quad::operator()() {
	return max({ (*this)[1], (*this)[2], (*this)[3], (*this)[4] });
}


/*
* Returns the i’th coordinate values of the invoking Quad object
*/
double Quad::operator()(size_t i) {
	if (i > 4 || i < 1)
		throw out_of_range("index out of bounds");

	return (*this)[i];
}


/*
* Returns the larger of the i’th and j’th coordinate values of the invoking Quad object
*/
double Quad::operator()(size_t i, size_t j) {
	if (i > 4 || i < 1 || j > 4 || j < 1)
		throw out_of_range("index out of bounds");

	return max({ (*this)[i], (*this)[j] });
}

/*
* Returns the largest of the i’th, j’th, and k’th coordinate values of the invoking Quad object
*/
double Quad::operator()(size_t i, size_t j, size_t k) {
	if (i > 4 || i < 1 || j > 4 || j < 1 || k > 4 || k < 1)
		throw out_of_range("index out of bounds");

	return max({ (*this)[i], (*this)[j], (*this)[k] });
}

/*
* Returns the largest of the i’th, j’th, k’th, and l’th coordinate values of the invoking Quad object
*/
double Quad::operator()(size_t i, size_t j, size_t k, size_t l) {
	if (i > 4 || i < 1 || j > 4 || j < 1 || k > 4 || k < 1 || l > 4 || l < 1)
		throw out_of_range("index out of bounds");

	return max({ (*this)[i], (*this)[j], (*this)[k], (*this)[l] });
}

/***************** Non-Member Operator Overloading functions *****************/

/*
*  Quad lhs + Quad rhs
*/
Quad operator+(const Quad& lhs, const Quad& rhs) {

	Quad temp{ lhs };
	temp += rhs;

	return temp;
}

/*
*  Quad lhs - Quad rhs
*/
Quad operator-(const Quad& lhs, const Quad& rhs) {

	Quad temp{ lhs };
	temp -= rhs;

	return temp;
}

/*
*  Quad lhs * Quad rhs
*/
Quad operator*(const Quad& lhs, const Quad& rhs) {

	Quad temp{ lhs };
	temp *= rhs;

	return temp;
}

/*
*  Quad lhs / Quad rhs
*/
Quad operator/(const Quad& lhs, const Quad& rhs) {

	Quad temp{ lhs };
	temp /= rhs;

	return temp;
}

/*
*  Quad lhs + double rhs
*/
Quad operator+(const Quad& lhs, const double& rhs) {

	Quad temp{ lhs };
	temp += rhs;

	return temp;
}

/*
*  Quad lhs - double rhs
*/
Quad operator-(const Quad& lhs, const double& rhs) {

	Quad temp{ lhs };
	temp -= rhs;

	return temp;
}

/*
*  Quad lhs * double rhs
*/
Quad operator*(const Quad& lhs, const double& rhs) {

	Quad temp{ lhs };
	temp *= rhs;

	return temp;
}

/*
*  Quad lhs / double rhs
*/
Quad operator/(const Quad& lhs, const double& rhs) {

	Quad temp{ lhs };
	temp /= rhs;

	return temp;
}

/*
*  double lhs + Quad rhs
*/
Quad operator+(const double& lhs, const Quad& rhs) {

	Quad temp{ rhs };
	temp += lhs;

	return temp;
}

/*
*  double lhs - Quad rhs
*/
Quad operator-(const double& lhs, const Quad& rhs) {

	Quad temp{ lhs - rhs[1], lhs - rhs[2],	lhs - rhs[3],	lhs - rhs[4] };

	return temp;
}

/*
*  double rhs * Quad rhs
*/
Quad operator*(const double& lhs, const Quad& rhs) {

	Quad temp{ rhs };
	temp *= lhs;

	return temp;
}

/*
*  double lhs / Quad rhs
*/
Quad operator/(const double& lhs, const Quad& rhs) {

	Quad temp{ rhs.inverse() };
	temp *= lhs;

	return temp;
}

/*
*  Quad lhs < Quad rhs
*/
bool operator<(const Quad& lhs, const Quad& rhs) {
	return ((lhs != rhs) && (lhs.absoluteValue() < rhs.absoluteValue()));
}


/*
*  Quad lhs <= Quad rhs
*/
bool operator<=(const Quad& lhs, const Quad& rhs) {
	return ((lhs < rhs) || (lhs == rhs));
}

/*
*  Quad lhs > Quad rhs
*/
bool operator>(const Quad& lhs, const Quad& rhs) {
	return (lhs.absoluteValue() > rhs.absoluteValue());
}

/*
*  Quad lhs >= Quad rhs
*/
bool operator>=(const Quad& lhs, const Quad& rhs) {
	return ((lhs > rhs) || (lhs == rhs));
}
/*
*  Quad lhs == Quad rhs
*/
bool operator==(const Quad& lhs, const Quad& rhs) {
	return (Quad{ lhs - rhs }.absoluteValue() <= Quad::tolerance);
}

/*
*  Quad lhs != Quad rhs
*/
bool operator!=(const Quad& lhs, const Quad& rhs) {
	return !(lhs == rhs);
}