#include "Rectangle.h"

/**
* Default Constructor
*/
Rectangle::Rectangle(int h, int w, char p, string n)
	: Shape{ p, n }, height{ h }, width{ w } {}

/**
* Default Destructor
*/
Rectangle::~Rectangle() {};

/**
* @return height of Rectangle
*/
int Rectangle::getHeight() const {
	return height;
}

/**
* @return width of Rectangle
*/
int Rectangle::getWidth() const {
	return width;
}

/**
* @return Rectangle geometric area
*/
double Rectangle::areaGeo() const {
	return height * width;
}

/**
* @return Rectangle geometric perimeter
*/
double Rectangle::perimeterGeo() const {
	return 2 * (height + width);
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
	return perimeterGeo() - 4;
}

/**
* @return Canvas object with textual image of Rectangle
*/
Canvas Rectangle::draw() const {
	Canvas drawGrid{ getHeight(),getWidth() };

	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			drawGrid.put(row, col, pen);
		}
	}
	return drawGrid;
}