#include "Rectangle.h"

Rectangle::Rectangle(int h, int w, char p, string n)
	: Shape{ p, n }, height{ h }, width{ w } {}

int Rectangle::getHeight() const { return height; }

int Rectangle::getWidth() const { return width; }

double Rectangle::areaGeo() const { return height * width; }

double Rectangle::perimeterGeo() const { return 2 * (height + width); }

double Rectangle::areaScr() const { return areaGeo(); }

double Rectangle::perimeterScr() const { return perimeterGeo() - 4; }

Canvas Rectangle::draw() const
{
	Canvas drawGrid{ getHeight(),getWidth(),' ' };
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			drawGrid.put(row, col, pen);
		}
	}
	return drawGrid;
}