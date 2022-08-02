#include "AcuteTriangle.h"

/**
* Default Constructor
*/
AcuteTriangle::AcuteTriangle(size_t base, char pen, string name)
	: Triangle{ (base + 1) / 2, base % 2 == 1 ? base : base + 1, pen, name } {}

/**
* Default Destructor
*/
AcuteTriangle::~AcuteTriangle() {};

/**
* @return AcuteTriangle geometric perimeter
*/
double AcuteTriangle::perimeterGeo() const {
	return getWidth() + std::sqrt(getWidth() * getWidth() + 4 * getHeight() * getHeight());
}

/**
* @return AcuteTriangle screen area
*/
double AcuteTriangle::areaScr() const {
	return getHeight() * getHeight();
}

/**
* @return AcuteTriangle screen perimeter
*/
double AcuteTriangle::perimeterScr() const {
	if (getHeight() == 1 || getWidth() == 1) return 1;
	else return 4 * (getHeight() - 1);
}

/**
* @return Canvas object with textual image of AcuteTriangle
*/
Canvas AcuteTriangle::draw() const {
	Canvas drawGrid{ static_cast<int>(getHeight()), static_cast<int>(getWidth()) };

	int LSpace, RSpace; // initiallize left blank space and right blank space - col number
	LSpace = RSpace = getWidth() / 2; //  LSpace and RSpace - both will have col number 1/2 of base

	for (int row = 0; row < getHeight(); ++row) {
		for (int col = 0; col <= getWidth(); ++col) {
			if (col >= LSpace && col <= RSpace) { // check if col number pass condition - 'LSpace < col < RSpace'
				drawGrid.put(row, col, pen);
			}
		}
		--LSpace; // left space col number will decrement with increasing row count
		++RSpace; // right space col number will increment with increasing row count
	}
	return drawGrid;
}