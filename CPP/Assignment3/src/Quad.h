#pragma once

#include <iostream>
#include <array>
#include <cassert>

using std::cin;
using std::cout;
using std::array;
using std::ostream;
using std::istream;

class Quad
{
private:
	array <double, 4> quad{};
public:
	static inline const double tolerance{ 1.0E-6 };

	Quad get() const;
	void set(const Quad&);

	explicit Quad(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

	Quad(const Quad&) = default; // copy ctor
	Quad(Quad&&) = default; // move ctor
	Quad& operator=(const Quad&) = default; // copy op=
	Quad& operator=(Quad&&) = default; // move op=
	~Quad() = default; // the dtor

	friend ostream& operator<<(ostream& sout, const Quad& q);
	friend istream& operator>>(istream& sin, Quad& q);
};