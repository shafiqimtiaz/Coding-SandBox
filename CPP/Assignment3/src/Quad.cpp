#include "Quad.h"



Quad::Quad(double x1, double x2, double x3, double x4) {
	quad[0] = x1;
	quad[1] = x2;
	quad[2] = x3;
	quad[3] = x4;
}

Quad Quad::get() const
{
	return *this;
}

void Quad::set(const Quad& q)
{
	this->quad[0] = q.quad[0];
	this->quad[1] = q.quad[1];
	this->quad[2] = q.quad[2];
	this->quad[3] = q.quad[3];
}

ostream& operator<<(ostream& sout, const Quad& q) {
	sout << "[ ";
	for (size_t i{}; i < 4; ++i) sout << q.quad[i] << " ";
	sout << "]";
	return sout;
}

istream& operator>>(istream& sin, Quad& q) {
	for (size_t i{}; i < 4; ++i) sin >> q.quad[i];
	return sin;
}

Quad Quad::inverse() const {
	double beta = (this->quad[0] * this->quad[2]) - (this->quad[1] * this->quad[3]);
	return Quad(this->quad[2] / beta, -1 * this->quad[1] / beta, this->quad[0] / beta, -1 * this->quad[3] / beta);
}



double Quad::absoluteValue() const {
	double abs1 = this->quad[0] >= 0 ? this->quad[0] : 0 - this->quad[0];
	double abs2 = this->quad[1] >= 0 ? this->quad[1] : 0 - this->quad[1];
	double abs3 = this->quad[2] >= 0 ? this->quad[2] : 0 - this->quad[2];
	double abs4 = this->quad[3] >= 0 ? this->quad[3] : 0 - this->quad[3];
	return { abs1 + abs2 + abs3 + abs4 };
}


Quad Quad::operator+=(const Quad& rhs) {
	this->quad[0] += rhs.quad[0];
	this->quad[1] += rhs.quad[1];
	this->quad[2] += rhs.quad[2];
	this->quad[3] += rhs.quad[3];

	return *this;
}

Quad Quad::operator+=(double value) {
	this->quad[0] += value;
	this->quad[1] += value;
	this->quad[2] += value;
	this->quad[3] += value;

	return *this;
}

Quad Quad:: operator-=(const Quad& rhs) {
	this->quad[0] -= rhs.quad[0];
	this->quad[1] -= rhs.quad[1];
	this->quad[2] -= rhs.quad[2];
	this->quad[3] -= rhs.quad[3];

	return *this;
}

Quad Quad::operator-=(double value) {
	this->quad[0] -= value;
	this->quad[1] -= value;
	this->quad[2] -= value;
	this->quad[3] -= value;

	return *this;
}

Quad Quad:: operator*=(const Quad& rhs) {
	this->quad[0] = (this->quad[0] * rhs.quad[0]) + (this->quad[1] * rhs.quad[3]);
	this->quad[1] = (this->quad[0] * rhs.quad[1]) + (this->quad[1] * rhs.quad[2]);
	this->quad[2] = (this->quad[3] * rhs.quad[1]) + (this->quad[2] * rhs.quad[2]);
	this->quad[3] = (this->quad[3] * rhs.quad[0]) + (this->quad[2] * rhs.quad[3]);

	return *this;
}

Quad Quad::operator*=(double value) {
	this->quad[0] *= value;
	this->quad[1] *= value;
	this->quad[2] *= value;
	this->quad[3] *= value;

	return *this;
}

Quad Quad::operator/=(double value) {
	this->quad[0] *= (1 / value);
	this->quad[1] *= (1 / value);
	this->quad[2] *= (1 / value);
	this->quad[3] *= (1 / value);

	return *this;
}

Quad Quad:: operator/=(const Quad& rhs) {
	Quad rhsInv = rhs.inverse();

	this->quad[0] = (this->quad[0] * rhsInv.quad[0]) + (this->quad[1] * rhsInv.quad[3]);
	this->quad[1] = (this->quad[0] * rhsInv.quad[1]) + (this->quad[1] * rhsInv.quad[2]);
	this->quad[2] = (this->quad[3] * rhsInv.quad[1]) + (this->quad[2] * rhsInv.quad[2]);
	this->quad[3] = (this->quad[3] * rhsInv.quad[0]) + (this->quad[2] * rhsInv.quad[3]);

	return *this;
}

Quad operator+(const Quad& lhs, const Quad& rhs) {
	double x1 = (lhs.quad[0] + rhs.quad[0]);
	double x2 = (lhs.quad[1] + rhs.quad[1]);
	double x3 = (lhs.quad[2] + rhs.quad[2]);
	double x4 = (lhs.quad[3] + rhs.quad[3]);
	return Quad(x1, x2, x3, x4);
}

Quad operator+(const Quad& lhs, double value) {
	double x1 = (lhs.quad[0] + value);
	double x2 = (lhs.quad[1] + value);
	double x3 = (lhs.quad[2] + value);
	double x4 = (lhs.quad[3] + value);
	return Quad(x1, x2, x3, x4);
}

Quad operator+(double value, const Quad& rhs) {
	double x1 = (value + rhs.quad[0]);
	double x2 = (value + rhs.quad[1]);
	double x3 = (value + rhs.quad[2]);
	double x4 = (value + rhs.quad[3]);
	return Quad(x1, x2, x3, x4);
}

Quad operator-(const Quad& lhs, const Quad& rhs) {
	double x1 = (lhs.quad[0] - rhs.quad[0]);
	double x2 = (lhs.quad[1] - rhs.quad[1]);
	double x3 = (lhs.quad[2] - rhs.quad[2]);
	double x4 = (lhs.quad[3] - rhs.quad[3]);
	return Quad(x1, x2, x3, x4);
}

Quad operator-(const Quad& lhs, double value) {
	double x1 = (lhs.quad[0] - value);
	double x2 = (lhs.quad[1] - value);
	double x3 = (lhs.quad[2] - value);
	double x4 = (lhs.quad[3] - value);
	return Quad(x1, x2, x3, x4);
}

Quad operator-(double value, const Quad& rhs) {
	double x1 = (value - rhs.quad[0]);
	double x2 = (value - rhs.quad[1]);
	double x3 = (value - rhs.quad[2]);
	double x4 = (value - rhs.quad[3]);
	return Quad(x1, x2, x3, x4);
}


Quad operator*(const Quad& lhs, const Quad& rhs) {
	double x1 = (lhs.quad[0] * rhs.quad[0]) + (lhs.quad[1] * rhs.quad[3]);
	double x2 = (lhs.quad[0] * rhs.quad[1]) + (lhs.quad[1] * rhs.quad[2]);
	double x3 = (lhs.quad[3] * rhs.quad[1]) + (lhs.quad[2] * rhs.quad[2]);
	double x4 = (lhs.quad[3] * rhs.quad[0]) + (lhs.quad[2] * rhs.quad[3]);
	return Quad(x1, x2, x3, x4);
}

Quad operator*(const Quad& lhs, double value) {
	double x1 = (lhs.quad[0] * value);
	double x2 = (lhs.quad[1] * value);
	double x3 = (lhs.quad[2] * value);
	double x4 = (lhs.quad[3] * value);
	return Quad(x1, x2, x3, x4);
}

Quad operator*(double value, const Quad& lhs) {
	double x1 = (value * lhs.quad[0]);
	double x2 = (value * lhs.quad[1]);
	double x3 = (value * lhs.quad[2]);
	double x4 = (value * lhs.quad[3]);
	return Quad(x1, x2, x3, x4);
}

Quad operator/(const Quad& lhs, const Quad& rhs) {
	Quad invRhs = rhs.inverse();
	double x1 = (lhs.quad[0] * invRhs.quad[0]) + (lhs.quad[1] * invRhs.quad[3]);
	double x2 = (lhs.quad[0] * invRhs.quad[1]) + (lhs.quad[1] * invRhs.quad[2]);
	double x3 = (lhs.quad[3] * invRhs.quad[1]) + (lhs.quad[2] * invRhs.quad[2]);
	double x4 = (lhs.quad[3] * invRhs.quad[0]) + (lhs.quad[2] * invRhs.quad[3]);
	return Quad(x1, x2, x3, x4);
}

Quad operator/(const Quad& lhs, double value) {
	double x1 = lhs.quad[0] * (1 / value);
	double x2 = lhs.quad[1] * (1 / value);
	double x3 = lhs.quad[2] * (1 / value);
	double x4 = lhs.quad[3] * (1 / value);
	return Quad(x1, x2, x3, x4);
}

Quad operator/(double value, const Quad& rhs) {
	Quad invRhs = rhs.inverse();
	double x1 = value * (invRhs.quad[0]);
	double x2 = value * (invRhs.quad[1]);
	double x3 = value * (invRhs.quad[2]);
	double x4 = value * (invRhs.quad[3]);
	return Quad(x1, x2, x3, x4);
}


//binary isEqual
bool operator==(const Quad& lhs, const Quad& rhs) {
	//get the difference btwn lhs and rhs quad valueues
	double d1 = lhs.quad[0] - rhs.quad[0];
	double d2 = lhs.quad[0] - rhs.quad[0];
	double d3 = lhs.quad[0] - rhs.quad[0];
	double d4 = lhs.quad[0] - rhs.quad[0];

	//getting absolute valueue
	d1 = d1 < 0 ? d1 *= -1 : d1;
	d2 = d2 < 0 ? d2 *= -1 : d2;
	d3 = d3 < 0 ? d3 *= -1 : d3;
	d4 = d4 < 0 ? d4 *= -1 : d4;

	//the epsilon of the comparison is set in Quad as 'tolerance'
	double tol = Quad::tolerance;

	return (d1 <= tol && d1 <= tol && d3 <= tol && d4 <= tol);
}

bool operator!=(const Quad& lhs, const Quad& rhs) {
	return (lhs == rhs) ? false : true;
}


bool operator<(const Quad& lhs, const Quad& rhs) {
	double lhsAbsSum = lhs.absoluteValue();
	double rhsAbsSum = rhs.absoluteValue();

	return (!(lhs == rhs) && lhsAbsSum < rhsAbsSum);
}


bool operator<=(const Quad& lhs, const Quad& rhs) {
	return (lhs < rhs || lhs == rhs);
}

bool operator>(const Quad& lhs, const Quad& rhs) {
	return (rhs < lhs);
}

bool operator>=(const Quad& lhs, const Quad& rhs) {
	return (lhs < rhs) ? false : true;
}

//unary positive
Quad Quad::operator+() {
	double x1 = this->quad[0] *= 1.0;
	double x2 = this->quad[1] *= 1.0;
	double x3 = this->quad[2] *= 1.0;
	double x4 = this->quad[3] *= 1.0;

	return Quad(x1, x2, x3, x4);
}

//unary negative
Quad Quad::operator-() {
	double x1 = this->quad[0];
	double x2 = this->quad[1];
	double x3 = this->quad[2];
	double x4 = this->quad[3];

	return Quad(x1 * -1.0, x2 * -1.0, x3 * -1.0, x4 * -1.0);;
}

//prefix increment
Quad Quad::operator++() {
	this->quad[0] += 1.0;
	this->quad[1] += 1.0;
	this->quad[2] += 1.0;
	this->quad[3] += 1.0;
	return *this;
}

//postfix increment
Quad Quad::operator++(int) {
	double x1 = this->quad[0];
	double x2 = this->quad[1];
	double x3 = this->quad[2];
	double x4 = this->quad[3];

	this->quad[0] += 1.0;
	this->quad[1] += 1.0;
	this->quad[2] += 1.0;
	this->quad[3] += 1.0;

	return Quad(x1++, x2++, x3++, x4++);
}

//prefix decrement
Quad Quad::operator--() {
	this->quad[0] -= 1.0;
	this->quad[1] -= 1.0;
	this->quad[2] -= 1.0;
	this->quad[3] -= 1.0;
	return *this;
}

//postfix decrement
Quad Quad::operator--(int) {
	double x1 = this->quad[0];
	double x2 = this->quad[1];
	double x3 = this->quad[2];
	double x4 = this->quad[3];

	this->quad[0] -= 1.0;
	this->quad[1] -= 1.0;
	this->quad[2] -= 1.0;
	this->quad[3] -= 1.0;

	return Quad(x1--, x2--, x3--, x4--);
}

double& Quad::operator[](int index) {
	if (index > 4 || index < 1) {
		throw out_of_range("index out of bounds");
	}
	return this->quad[index - 1];
}

const double& Quad::operator[](int index) const {

	if (index > 4 || index < 1) {
		throw out_of_range("index out of bounds");
	}
	return this->quad[index - 1];
}

double Quad::operator()() {
	return max({ (*this)[1], (*this)[2], (*this)[3], (*this)[4] });
}

double Quad::operator()(size_t i) {
	if (i > 4 || i < 1) {
		throw out_of_range("index out of bounds");
	}
	return (*this)[i];
}

double Quad::operator()(size_t i, size_t j) {
	if (i > 4 || i < 1 || j > 4 || j < 1) {
		throw out_of_range("index out of bounds");
	}
	return max({ (*this)[i], (*this)[j] });
}

double Quad::operator()(size_t i, size_t j, size_t k) {
	if (i > 4 || i < 1 || j > 4 || j < 1 || k > 4 || k < 1) {
		throw out_of_range("index out of bounds");
	}
	return max({ (*this)[i], (*this)[j], (*this)[k] });
}

double Quad::operator()(size_t i, size_t j, size_t k, size_t l) {
	if (i > 4 || i < 1 || j > 4 || j < 1 || k > 4 || k < 1 || l > 4 || l < 1) {
		throw out_of_range("index out of bounds");
	}
	return max({ (*this)[i], (*this)[j], (*this)[k], (*this)[l] });
}