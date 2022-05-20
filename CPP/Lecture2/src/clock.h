#ifndef CLOCK_H_
#define CLOCK_H_

class clock
{
private:
	int hh;
	int mm;
	int ss;

public:
	clock& operator = (const clock& src);
	void print(const ostream& sout);

	clock(int h, int m, int s);
	clock(const clock& src);
};

ostream& operator << (ostream& sout, const clock& clk)
{
	clk.print(sout);
	return sout;
}

#endif