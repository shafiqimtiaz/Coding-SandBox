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
* @return the inverse of Quad
*/
Quad Quad::inverse() const {
	double beta = (quad[0] * quad[2]) - (quad[1] * quad[3]);
	return (1 / beta) * Quad { quad[2], -quad[1], quad[0], -quad[3] };
}

/*
* @return the absolute value of Quad
*/
double Quad::absoluteValue() const {
	return { abs(quad[0]) + abs(quad[1]) + abs(quad[2]) + abs(quad[3]) };
}

/*
* @return Stream Extraction from Quad q
*/
ostream& operator<<(ostream& sout, const Quad& q) {

	sout << "[  ";
	for (size_t i{}; i < q.quad.size(); ++i) {
		sout << fixed << setprecision(2) << q.quad[i] << "  ";
	}
	sout << "]";

	return sout;
}

/*
* @return Stream Insertion to Quad q
*/
istream& operator>>(istream& sin, Quad& q) {

	for (size_t i{}; i < q.quad.size(); ++i) {
		sin >> q.quad[i];
	}

	return sin;
}

/***************** Member Operator Overloading functions *****************/

/*
* @return Quad = Quad + Quad rhs
*/
Quad& Quad::operator+=(const Quad& rhs) {

	this->quad[0] += rhs.quad[0];
	this->quad[1] += rhs.quad[1];
	this->quad[2] += rhs.quad[2];
	this->quad[3] += rhs.quad[3];

	return *this;
}

/*
* @return Quad = Quad - Quad rhs
*/
Quad& Quad::operator-=(const Quad& rhs) {

	this->quad[0] -= rhs.quad[0];
	this->quad[1] -= rhs.quad[1];
	this->quad[2] -= rhs.quad[2];
	this->quad[3] -= rhs.quad[3];

	return *this;
}

/*
* @return Quad = Quad * Quad rhs
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
* @return Quad = Quad / Quad rhs
*/
Quad& Quad::operator/=(const Quad& rhs) {

	*this *= rhs.inverse();

	return *this;
}

/*
* @return Quad = Quad + double val
*/
Quad& Quad::operator+=(const double& val) {

	this->quad[0] += val;
	this->quad[1] += val;
	this->quad[2] += val;
	this->quad[3] += val;

	return *this;
}

/*
* @return Quad = Quad - double val
*/
Quad& Quad::operator-=(const double& val) {

	this->quad[0] -= val;
	this->quad[1] -= val;
	this->quad[2] -= val;
	this->quad[3] -= val;

	return *this;
}

/*
* @return Quad = Quad * double val
*/
Quad& Quad::operator*=(const double& val) {

	this->quad[0] *= val;
	this->quad[1] *= val;
	this->quad[2] *= val;
	this->quad[3] *= val;

	return *this;
}

/*
* @return Quad = Quad / double val
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
* @return Unary Plus
*/
Quad Quad::operator+() {
	return Quad{ abs(quad[0]), abs(quad[1]), abs(quad[2]),abs(quad[3]) };
}

/*
* @return Unary Minus
*/
Quad Quad::operator-() {

	Quad temp{ *this };
	temp *= -1.0;

	return temp;
}

/*
* @return Prefix increment
*/
Quad& Quad::operator++() {

	*this += 1.0;

	return *this;
}

/*
* @return Prefix decrement
*/
Quad& Quad::operator--() {

	*this -= 1.0;

	return *this;
}

/*
* @return Postfix increment
*/
const Quad Quad::operator++(int) {

	Quad temp{ *this };
	++(*this);

	return temp;
}

/*
* @return Postfix decrement
*/
const Quad Quad::operator--(int) {

	Quad temp{ *this };
	--(*this);

	return temp;
}

/*
* @return Quad[i] subscript - the value at index 1
*/
double& Quad::operator[](size_t index) {
	if (index > 4 || index < 1)
		throw out_of_range("index out of bounds");

	return this->quad[index - 1];
}

/*
* @return const Quad[i] subscript - the value at index 1
*/
const double& Quad::operator[](size_t index) const {
	if (index > 4 || index < 1)
		throw out_of_range("index out of bounds");

	return this->quad[index - 1];
}

// Function Objects

/*
* @return the largest coordinate value of the invoking Quad object
*/
double Quad::operator()() {
	return max({ (*this)[1], (*this)[2], (*this)[3], (*this)[4] });
}

/*
* @return the i’th coordinate values of the invoking Quad object
*/
double Quad::operator()(size_t i) {
	if (i > 4 || i < 1)
		throw out_of_range("index out of bounds");

	return (*this)[i];
}

/*
* @return the larger of the i’th and j’th coordinate values of the invoking Quad object
*/
double Quad::operator()(size_t i, size_t j) {
	if (i > 4 || i < 1 || j > 4 || j < 1)
		throw out_of_range("index out of bounds");

	return max({ (*this)[i], (*this)[j] });
}

/*
* @return the largest of the i’th, j’th, and k’th coordinate values of the invoking Quad object
*/
double Quad::operator()(size_t i, size_t j, size_t k) {
	if (i > 4 || i < 1 || j > 4 || j < 1 || k > 4 || k < 1)
		throw out_of_range("index out of bounds");

	return max({ (*this)[i], (*this)[j], (*this)[k] });
}

/*
* @return the largest of the i’th, j’th, k’th, and l’th coordinate values of the invoking Quad object
*/
double Quad::operator()(size_t i, size_t j, size_t k, size_t l) {
	if (i > 4 || i < 1 || j > 4 || j < 1 || k > 4 || k < 1 || l > 4 || l < 1)
		throw out_of_range("index out of bounds");

	return max({ (*this)[i], (*this)[j], (*this)[k], (*this)[l] });
}

/***************** Non-Member Operator Overloading functions *****************/

/*
* @return Quad lhs + Quad rhs
*/
Quad operator+(const Quad& lhs, const Quad& rhs) {

	Quad temp{ lhs };
	temp += rhs;

	return temp;
}

/*
* @return Quad lhs - Quad rhs
*/
Quad operator-(const Quad& lhs, const Quad& rhs) {

	Quad temp{ lhs };
	temp -= rhs;

	return temp;
}

/*
* @return Quad lhs * Quad rhs
*/
Quad operator*(const Quad& lhs, const Quad& rhs) {

	Quad temp{ lhs };
	temp *= rhs;

	return temp;
}

/*
* @return Quad lhs / Quad rhs
*/
Quad operator/(const Quad& lhs, const Quad& rhs) {

	Quad temp{ lhs };
	temp /= rhs;

	return temp;
}

/*
* @return Quad lhs + double rhs
*/
Quad operator+(const Quad& lhs, const double& rhs) {

	Quad temp{ lhs };
	temp += rhs;

	return temp;
}

/*
* @return Quad lhs - double rhs
*/
Quad operator-(const Quad& lhs, const double& rhs) {

	Quad temp{ lhs };
	temp -= rhs;

	return temp;
}

/*
* @return Quad lhs * double rhs
*/
Quad operator*(const Quad& lhs, const double& rhs) {

	Quad temp{ lhs };
	temp *= rhs;

	return temp;
}

/*
* @return Quad lhs / double rhs
*/
Quad operator/(const Quad& lhs, const double& rhs) {

	Quad temp{ lhs };
	temp /= rhs;

	return temp;
}

/*
* @return double lhs + Quad rhs
*/
Quad operator+(const double& lhs, const Quad& rhs) {

	Quad temp{ rhs };
	temp += lhs;

	return temp;
}

/*
* @return double lhs - Quad rhs
*/
Quad operator-(const double& lhs, const Quad& rhs) {

	Quad temp{ lhs - rhs[1], lhs - rhs[2],	lhs - rhs[3],	lhs - rhs[4] };

	return temp;
}

/*
* @return double rhs * Quad rhs
*/
Quad operator*(const double& lhs, const Quad& rhs) {

	Quad temp{ rhs };
	temp *= lhs;

	return temp;
}

/*
* @return double lhs / Quad rhs
*/
Quad operator/(const double& lhs, const Quad& rhs) {

	Quad temp{ rhs.inverse() };
	temp *= lhs;

	return temp;
}

/*
* @return Quad lhs < Quad rhs
*/
bool operator<(const Quad& lhs, const Quad& rhs) {
	return ((lhs != rhs) && (lhs.absoluteValue() < rhs.absoluteValue()));
}


/*
* @return Quad lhs <= Quad rhs
*/
bool operator<=(const Quad& lhs, const Quad& rhs) {
	return ((lhs < rhs) || (lhs == rhs));
}

/*
* @return Quad lhs > Quad rhs
*/
bool operator>(const Quad& lhs, const Quad& rhs) {
	return (lhs.absoluteValue() > rhs.absoluteValue());
}

/*
* @return Quad lhs >= Quad rhs
*/
bool operator>=(const Quad& lhs, const Quad& rhs) {
	return ((lhs > rhs) || (lhs == rhs));
}
/*
* @return Quad lhs == Quad rhs
*/
bool operator==(const Quad& lhs, const Quad& rhs) {
	return (Quad{ lhs - rhs }.absoluteValue() <= Quad::tolerance);
}

/*
* @return Quad lhs != Quad rhs
*/
bool operator!=(const Quad& lhs, const Quad& rhs) {
	return !(lhs == rhs);
}