#include "Quad.h"
#include <cmath>
#include <algorithm>

using std::cout;
using std::endl;
using std::round;

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

double Quad::getTolerance() const {
	return this->tolerance;
}

ostream& operator<<(ostream& sout, const Quad& q) {
	sout << "[ ";
	for (size_t i{}; i < 4; ++i) {
		sout << q.quad[i] << " ";
	}
	sout << "]";

	return sout;
}

istream& operator>>(istream& sin, Quad& q) {

	for (size_t i{}; i < 4; ++i) {
		sin >> q.quad[i];
	}

	return sin;
}

Quad Quad::inverse() const {
	Quad lhs = *this;
	cout << "origin:" << lhs << endl;

	double b = (lhs.quad[0] * lhs.quad[2]) - (lhs.quad[1] * lhs.quad[3]);

	Quad inverseQ(lhs.quad[2] / b,
		-1 * lhs.quad[1] / b,
		lhs.quad[0] / b,
		-1 * lhs.quad[3] / b);

	cout << "inversed:" << inverseQ << endl;

	return inverseQ;
}



double Quad::absoluteValue() const {
	Quad current = *this;

	double abs1 = current.quad[0] >= 0 ? current.quad[0] : 0 - current.quad[0];
	double abs2 = current.quad[1] >= 0 ? current.quad[1] : 0 - current.quad[1];
	double abs3 = current.quad[2] >= 0 ? current.quad[2] : 0 - current.quad[2];
	double abs4 = current.quad[3] >= 0 ? current.quad[3] : 0 - current.quad[3];

	double absoluteValueSum{ abs1 + abs2 + abs3 + abs4 };

	return absoluteValueSum;
}


Quad Quad::operator+=(const Quad& rhs) {
	this->quad[0] += rhs.quad[0];
	this->quad[1] += rhs.quad[1];
	this->quad[2] += rhs.quad[2];
	this->quad[3] += rhs.quad[3];

	return *this;
}

Quad Quad::operator+=(double val) {
	this->quad[0] += val;
	this->quad[1] += val;
	this->quad[2] += val;
	this->quad[3] += val;

	return *this;
}

Quad Quad:: operator-=(const Quad& rhs) {
	this->quad[0] -= rhs.quad[0];
	this->quad[1] -= rhs.quad[1];
	this->quad[2] -= rhs.quad[2];
	this->quad[3] -= rhs.quad[3];

	return *this;
}

Quad Quad::operator-=(double val) {
	this->quad[0] -= val;
	this->quad[1] -= val;
	this->quad[2] -= val;
	this->quad[3] -= val;

	return *this;
}

Quad Quad:: operator*=(const Quad& rhs) {
	this->quad[0] = (this->quad[0] * rhs.quad[0]) + (this->quad[1] * rhs.quad[3]);
	this->quad[1] = (this->quad[0] * rhs.quad[1]) + (this->quad[1] * rhs.quad[2]);
	this->quad[2] = (this->quad[3] * rhs.quad[1]) + (this->quad[2] * rhs.quad[2]);
	this->quad[3] = (this->quad[3] * rhs.quad[0]) + (this->quad[2] * rhs.quad[3]);

	return *this;
}

Quad Quad::operator*=(double val) {
	this->quad[0] *= val;
	this->quad[1] *= val;
	this->quad[2] *= val;
	this->quad[3] *= val;

	return *this;
}

Quad Quad::operator/=(double val) {
	this->quad[0] *= (1 / val);
	this->quad[1] *= (1 / val);
	this->quad[2] *= (1 / val);
	this->quad[3] *= (1 / val);

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

	Quad addedQ(x1, x2, x3, x4);
	return addedQ;
}

Quad operator+(const Quad& lhs, double val) {
	double x1 = (lhs.quad[0] + val);
	double x2 = (lhs.quad[1] + val);
	double x3 = (lhs.quad[2] + val);
	double x4 = (lhs.quad[3] + val);

	Quad addedQ(x1, x2, x3, x4);
	return addedQ;
}

Quad operator+(double val, const Quad& rhs) {
	double x1 = (val + rhs.quad[0]);
	double x2 = (val + rhs.quad[1]);
	double x3 = (val + rhs.quad[2]);
	double x4 = (val + rhs.quad[3]);

	Quad addedQ(x1, x2, x3, x4);
	return addedQ;
}

Quad operator-(const Quad& lhs, const Quad& rhs) {
	double x1 = (lhs.quad[0] - rhs.quad[0]);
	double x2 = (lhs.quad[1] - rhs.quad[1]);
	double x3 = (lhs.quad[2] - rhs.quad[2]);
	double x4 = (lhs.quad[3] - rhs.quad[3]);

	Quad subtractedQ(x1, x2, x3, x4);
	return subtractedQ;
}

Quad operator-(const Quad& lhs, double val) {
	double x1 = (lhs.quad[0] - val);
	double x2 = (lhs.quad[1] - val);
	double x3 = (lhs.quad[2] - val);
	double x4 = (lhs.quad[3] - val);

	Quad subtractedQ(x1, x2, x3, x4);
	return subtractedQ;
}

Quad operator-(double val, const Quad& rhs) {
	double x1 = (val - rhs.quad[0]);
	double x2 = (val - rhs.quad[1]);
	double x3 = (val - rhs.quad[2]);
	double x4 = (val - rhs.quad[3]);

	Quad subtractedQ(x1, x2, x3, x4);
	return subtractedQ;
}


Quad operator*(const Quad& lhs, const Quad& rhs) {
	double x1 = (lhs.quad[0] * rhs.quad[0]) + (lhs.quad[1] * rhs.quad[3]);
	double x2 = (lhs.quad[0] * rhs.quad[1]) + (lhs.quad[1] * rhs.quad[2]);
	double x3 = (lhs.quad[3] * rhs.quad[1]) + (lhs.quad[2] * rhs.quad[2]);
	double x4 = (lhs.quad[3] * rhs.quad[0]) + (lhs.quad[2] * rhs.quad[3]);

	Quad multipliedQ(x1, x2, x3, x4);
	return multipliedQ;
}

Quad operator*(const Quad& lhs, double val) {
	double x1 = (lhs.quad[0] * val);
	double x2 = (lhs.quad[1] * val);
	double x3 = (lhs.quad[2] * val);
	double x4 = (lhs.quad[3] * val);

	Quad multipliedQ(x1, x2, x3, x4);
	return multipliedQ;
}

Quad operator*(double val, const Quad& lhs) {
	double x1 = (val * lhs.quad[0]);
	double x2 = (val * lhs.quad[1]);
	double x3 = (val * lhs.quad[2]);
	double x4 = (val * lhs.quad[3]);

	Quad multipliedQ(x1, x2, x3, x4);
	return multipliedQ;
}

Quad operator/(const Quad& lhs, const Quad& rhs) {
	Quad rhsInv = rhs.inverse();
	cout << "inv:" << rhsInv << endl;

	double x1 = (lhs.quad[0] * rhsInv.quad[0]) + (lhs.quad[1] * rhsInv.quad[3]);
	double x2 = (lhs.quad[0] * rhsInv.quad[1]) + (lhs.quad[1] * rhsInv.quad[2]);
	double x3 = (lhs.quad[3] * rhsInv.quad[1]) + (lhs.quad[2] * rhsInv.quad[2]);
	double x4 = (lhs.quad[3] * rhsInv.quad[0]) + (lhs.quad[2] * rhsInv.quad[3]);

	Quad dividedQ(x1, x2, x3, x4);
	cout << "dividedQ:" << dividedQ << endl;
	return dividedQ;
}

Quad operator/(const Quad& lhs, double val) {
	double x1 = lhs.quad[0] * (1 / val);
	double x2 = lhs.quad[1] * (1 / val);
	double x3 = lhs.quad[2] * (1 / val);
	double x4 = lhs.quad[3] * (1 / val);

	Quad dividedQ(x1, x2, x3, x4);
	cout << "dividedQ:" << dividedQ << endl;
	return dividedQ;
}

Quad operator/(double val, const Quad& rhs) {
	cout << "ori:" << rhs << endl;
	Quad inversedRhs = rhs.inverse();
	double x1 = val * (inversedRhs.quad[0]);
	double x2 = val * (inversedRhs.quad[1]);
	double x3 = val * (inversedRhs.quad[2]);
	double x4 = val * (inversedRhs.quad[3]);

	Quad dividedQ(x1, x2, x3, x4);
	cout << "dividedQ:" << dividedQ << endl;
	return dividedQ;
}


//binary isEqual
bool operator==(const Quad& lhs, const Quad& rhs) {
	//get the difference btwn lhs and rhs quad values
	double d1 = lhs.quad[0] - rhs.quad[0];
	double d2 = lhs.quad[0] - rhs.quad[0];
	double d3 = lhs.quad[0] - rhs.quad[0];
	double d4 = lhs.quad[0] - rhs.quad[0];

	//getting absolute value
	d1 = d1 < 0 ? d1 *= -1 : d1;
	d2 = d2 < 0 ? d2 *= -1 : d2;
	d3 = d3 < 0 ? d3 *= -1 : d3;
	d4 = d4 < 0 ? d4 *= -1 : d4;

	//the epsilon of the comparison is set in Quad as 'tolerance'
	double epsilon = Quad::tolerance;

	return (d1 <= epsilon &&
		d1 <= epsilon &&
		d3 <= epsilon &&
		d4 <= epsilon);
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
	//X < Y or X = Y
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
	Quad posQ(x1, x2, x3, x4);
	return posQ;
}

//unary negative
Quad Quad::operator-() {
	double x1 = this->quad[0];
	double x2 = this->quad[1];
	double x3 = this->quad[2];
	double x4 = this->quad[3];
	Quad negQ(x1 * -1.0, x2 * -1.0, x3 * -1.0, x4 * -1.0);
	return negQ;
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
	Quad incrementQ(x1++, x2++, x3++, x4++);
	this->quad[0] += 1.0;
	this->quad[1] += 1.0;
	this->quad[2] += 1.0;
	this->quad[3] += 1.0;
	return incrementQ;
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
	Quad decrementQ(x1--, x2--, x3--, x4--);
	this->quad[0] -= 1.0;
	this->quad[1] -= 1.0;
	this->quad[2] -= 1.0;
	this->quad[3] -= 1.0;
	return decrementQ;
}

double& Quad::operator[](int index) {
	if (index > 4 || index < 1) {
		throw std::out_of_range("index out of bounds");
	}
	return this->quad[index - 1];
}

const double& Quad::operator[](int index) const {

	if (index > 4 || index < 1) {
		throw std::out_of_range("index out of bounds");
	}
	return this->quad[index - 1];
}

double Quad::operator()() {
	return std::max({ (*this)[1], (*this)[2], (*this)[3], (*this)[4] });
}

double Quad::operator()(size_t i) {
	if (i > 4 || i < 1) {
		throw std::out_of_range("index out of bounds");
	}
	return (*this)[i];
}

double Quad::operator()(size_t i, size_t j) {
	if (i > 4 || i < 1 || j > 4 || j < 1) {
		throw std::out_of_range("index out of bounds");
	}
	return std::max({ (*this)[i], (*this)[j] });
}

double Quad::operator()(size_t i, size_t j, size_t k) {
	if (i > 4 || i < 1 || j > 4 || j < 1 || k > 4 || k < 1) {
		throw std::out_of_range("index out of bounds");
	}
	return std::max({ (*this)[i], (*this)[j], (*this)[k] });
}

double Quad::operator()(size_t i, size_t j, size_t k, size_t l) {
	if (i > 4 || i < 1 || j > 4 || j < 1 || k > 4 || k < 1 || l > 4 || l < 1) {
		throw std::out_of_range("index out of bounds");
	}
	return std::max({ (*this)[i], (*this)[j], (*this)[k], (*this)[l] });
}
