#include "RightTriangle.h"

/**
* Default Constructor
*/
RightTriangle::RightTriangle(int base, char pen, string name)
	: Triangle{ base, pen, name } {}

/**
* Default Destructor
*/
RightTriangle::~RightTriangle() {};

/**
* @return height of RightTriangle
*/
int RightTriangle::getHeight() const {
	return base;
}

/**
* @return base width of RightTriangle
*/
int RightTriangle::getWidth() const {
	return base;
}

/**
* @return RightTriangle geometric perimeter
*/
double RightTriangle::perimeterGeo() const {
	return (2 + std::sqrt(2)) * getHeight();
}

/**
* @return RightTriangle screen area
*/
double RightTriangle::areaScr() const {
	return getHeight() * (getHeight() + 1) / 2;
}

/**
* @return RightTriangle screen perimeter
*/
double RightTriangle::perimeterScr() const {
	return 3 * (getHeight() - 1);
}

/**
* @return Canvas object with textual image of RightTriangle
*/
Canvas RightTriangle::draw() const {
	Canvas drawGrid{ getHeight(), getWidth() };

	int height = getHeight();

	for (int row = 0; row < height; ++row) {
		for (int col = 0; col <= row; ++col) {
			drawGrid.put(row, col, pen);
		};
	}

	return drawGrid;
}