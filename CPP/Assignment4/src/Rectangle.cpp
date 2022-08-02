#include "Rectangle.h"

/**
* Default Constructor
*/
Rectangle::Rectangle(size_t h, size_t w, char p, string n)
	: Shape{ h, w, p, n } {}

/**
* Default Destructor
*/
Rectangle::~Rectangle() {};

/**
* @return Rectangle geometric area
*/
double Rectangle::areaGeo() const {
	return getHeight() * getWidth();
}

/**
* @return Rectangle geometric perimeter
*/
double Rectangle::perimeterGeo() const {
	return 2 * (getHeight() + getWidth());
}

/**
* @return Rectangle screen area
*/
double Rectangle::areaScr() const {
	return areaGeo();
}

/**
* @return Rectangle screen perimeter
*/
double Rectangle::perimeterScr() const {
	if (getHeight() == 1 || getWidth() == 1) return areaGeo();
	else return perimeterGeo() - 4;
}

/**
* @return Canvas object with textual image of Rectangle
*/
Canvas Rectangle::draw() const {
	Canvas drawGrid{ static_cast<int>(getHeight()),static_cast<int>(getWidth()) };

	for (int row = 0; row < getHeight(); ++row) {
		for (int col = 0; col < getWidth(); ++col) {
			drawGrid.put(row, col, pen);
		}
	}
	return drawGrid;
}