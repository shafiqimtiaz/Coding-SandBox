#include "AcuteTriangle.h"

AcuteTriangle::AcuteTriangle(int b, char p, string n)
	: Triangle{ b % 2 == 1 ? b : b + 1, p, n } {}

int AcuteTriangle::getHeight() const { return (base + 1) / 2; }

int AcuteTriangle::getWidth() const { return base; }

double AcuteTriangle::perimeterGeo() const {
	return base + std::sqrt(base * base + 4 * getHeight() * getHeight());
}

double AcuteTriangle::areaScr() const { return getHeight() * getHeight(); }

double AcuteTriangle::perimeterScr() const { return 4 * (getHeight() - 1); }

Canvas AcuteTriangle::draw() const
{
	Canvas drawGrid{ getHeight(), getWidth(),' ' };

	int h = getHeight();
	int b = getWidth();

	int LSpace, RSpace; // initiallize left blank space and right blank space - col number
	LSpace = RSpace = b / 2; //  LSpace and RSpace - both will have col number 1/2 of base

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col <= b; col++)
		{
			if (col >= LSpace && col <= RSpace) // check if col number pass condition - 'LSpace < col < RSpace'
			{
				drawGrid.put(row, col, pen);
			}
		}
		LSpace--; // left space col number will decrement with increasing row count
		RSpace++; // right space col number will increment with increasing row count
	}

	return drawGrid;
}