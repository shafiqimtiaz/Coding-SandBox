#include "Rhombus.h"

Rhombus::Rhombus(int d, char p, string n)
	:Shape{ p,n }, d{ d % 2 == 1 ? d : d + 1 }{}

int Rhombus::getHeight() const { return d; }

int Rhombus::getWidth() const { return d; }

double Rhombus::areaGeo() const { return d * d / 2; }

double Rhombus::perimeterGeo() const { return 2.0 * std::sqrt(2) * d; }

double Rhombus::areaScr() const {
	double n = d / 2.0;	// floor rounding value n
	return 2 * n * (n + 1) + 1;
}

double Rhombus::perimeterScr() const { return 2 * (d - 1); }

Canvas Rhombus::draw() const
{
	Canvas drawGrid{ getHeight(), getWidth(),' ' };

	int h = getHeight();

	int LSpace, RSpace; // initiallize left blank space and right blank space - col coordinate
	LSpace = RSpace = h / 2; //  LSpace and RSpace - both will have col number 1/2 of height

	// Upper upright Triangle
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < h; col++)
		{
			if (col >= LSpace && col <= RSpace) // check if col number pass condition - 'LSpace < col < RSpace'
			{
				drawGrid.put(row, col, pen);
			}
		}

		// upper upright triangle
		if (row < h / 2)
		{
			LSpace--; // left space col number will decrement with increasing row count
			RSpace++; // right space col number will increment with increasing row count
		}
		// lower inverted triangle
		else
		{
			LSpace++; // left space col number will increment with increasing row count
			RSpace--; // right space col number will decrement with increasing row count
		}
	}

	return drawGrid;
}