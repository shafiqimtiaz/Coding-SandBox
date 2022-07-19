#include "RightTriangle.h"

RightTriangle::RightTriangle(int base, char pen, string name) : Triangle{ base, pen, name } {}

int RightTriangle::getHeight() const { return base; }

int RightTriangle::getWidth() const { return base; }

double RightTriangle::perimeterGeo() const { return (2 + std::sqrt(2)) * getHeight(); }

double RightTriangle::areaScr() const { return getHeight() * (getHeight() + 1) / 2; }

double RightTriangle::perimeterScr() const { return 3 * (getHeight() - 1); }

Canvas RightTriangle::draw() const
{
	Canvas drawGrid{ getHeight(), getWidth(),' ' };

	int height = getHeight();

	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y <= x; y++)
		{
			drawGrid.put(x, y, pen);
		}
	}

	return drawGrid;
}