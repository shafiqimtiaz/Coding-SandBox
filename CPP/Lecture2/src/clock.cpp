#include "clock.h"

clock::clock(int h, int m, int s) : hh{h},mm{m},ss{s}{}
clock::clock(const clock& src) : hh{src.h}, mm{ src.m }, ss{ src.s }{}

clock& clock::operator=(clock& src)
{
	if (this == &src) return *this;

	hh = src.hh;
	mm = src.mm;
	ss = src.ss;
	return *this;
}
void clock::print(ostream& sout) const
{
	sout << hh << ":" << mm << ":" << ss << endl;
}