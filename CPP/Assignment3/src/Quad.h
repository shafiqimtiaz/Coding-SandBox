#pragma once

#include <iostream>
#include <array>
#include <cassert>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::array;
using std::ostream;
using std::istream;
using std::max;
using std::out_of_range;

class Quad
{
private:
	array <double, 4> quad{};
public:
	static inline const double tolerance{ 1.0E-6 };

	Quad get() const;
	void set(const Quad&);
	Quad(double x1 = 0.0, double
		x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

	Quad(const Quad&) = default; // copy constructor
	Quad(Quad&&) = default; // move constructor
	Quad& operator=(const Quad&) = default; // copy op=
	Quad& operator=(Quad&&) = default; // move op=
	~Quad() = default; // destructor

	friend ostream& operator<<(ostream& sout, const Quad& q);
	friend istream& operator>>(istream& sin, Quad& q);

	Quad inverse() const;
	double absoluteValue() const;

	//Compound assignment operators - member func
	Quad operator+=(const Quad& rhs);
	Quad operator-=(const Quad& rhs);
	Quad operator*=(const Quad& rhs);
	Quad operator/=(const Quad& rhs);

	Quad operator+=(double value);
	Quad operator-=(double value);
	Quad operator*=(double value);
	Quad operator/=(double value);

	//Arithmetic binary operators - free func
	friend Quad operator+(const Quad& lhs, const Quad& rhs);
	friend Quad operator+(const Quad& lhs, double value);
	friend Quad operator+(double value, const Quad& rhs);

	friend Quad operator-(const Quad& lhs, const Quad& rhs);
	friend Quad operator-(const Quad& lhs, double value);
	friend Quad operator-(double value, const Quad& rhs);

	friend Quad operator*(const Quad& lhs, const Quad& rhs);
	friend Quad operator*(const Quad& lhs, double value);
	friend Quad operator*(double value, const Quad& rhs);

	friend Quad operator/(const Quad& lhs, const Quad& rhs);
	friend Quad operator/(const Quad& lhs, double value);
	friend Quad operator/(double value, const Quad& rhs);


	//binary - free func
	friend bool operator==(const Quad& lhs, const Quad& rhs);
	friend bool operator!=(const Quad& lhs, const Quad& rhs);
	friend bool operator<(const Quad& lhs, const Quad& rhs);
	friend bool operator<=(const Quad& lhs, const Quad& rhs);
	friend bool operator>(const Quad& lhs, const Quad& rhs);
	friend bool operator>=(const Quad& lhs, const Quad& rhs);

	//Unary operators - member func
	Quad operator+(); //prefix positive
	Quad operator-(); //prefix negative
	Quad operator++(); //prefix
	Quad operator++(int); //postfix
	Quad operator--(); //prefix
	Quad operator--(int); //postfux

	//subscript operators
	double& operator[](int index);
	const double& operator[](int index) const;

	//function objects
	double operator()();
	double operator()(size_t i);
	double operator()(size_t i, size_t j);
	double operator()(size_t i, size_t j, size_t k);
	double operator()(size_t i, size_t j, size_t k, size_t l);
};