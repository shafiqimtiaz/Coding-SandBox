#include "RightTriangle.h"

/**
* Default Constructor
*/
RightTriangle::RightTriangle(size_t base, char pen, string name)
	: Triangle{ base, base, pen, name } {}

/**
* Default Destructor
*/
RightTriangle::~RightTriangle() {};

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
	Canvas drawGrid{ static_cast<int>(getHeight()), static_cast<int>(getWidth()) };

	for (int row = 0; row < getHeight(); ++row) {
		for (int col = 0; col <= row; ++col) {
			drawGrid.put(row, col, pen);
		};
	}

	return drawGrid;
}