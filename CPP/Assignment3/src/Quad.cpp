#include "Quad.h"

Quad::Quad(double x1, double x2, double x3, double x4)
{
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

ostream& operator<<(ostream& sout, const Quad& q)
{
	sout << "[ ";
	for (size_t i{}; i < 4; ++i)
	{
		sout << q.quad[i] << " ";
	}
	sout << "]";

	return sout;
}

istream& operator>>(istream& sin, Quad& q)
{
	for (size_t i{}; i < 4; ++i)
	{
		double value{};
		sin >> value;
		q.quad[i] = value;
	}

	return sin;
}