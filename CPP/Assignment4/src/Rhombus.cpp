#include "Rhombus.h"

/**
* Default Constructor
*/
Rhombus::Rhombus(size_t d, char p, string n)
	:Shape{ d % 2 == 1 ? d : d + 1, d % 2 == 1 ? d : d + 1, p, n } {}

/**
* Default Destructor
*/
Rhombus::~Rhombus() {};

/**
* @return Rhombus geometric area
*/
double Rhombus::areaGeo() const {
	return (getHeight() * getWidth()) / 2;
}

/**
* @return Rhombus geometric perimeter
*/
double Rhombus::perimeterGeo() const {
	return 2 * std::sqrt(2) * getHeight();
}

/**
* @return Rhombus screen area
*/
double Rhombus::areaScr() const {
	double n = floor(getHeight() / 2);
	return 2 * n * (n + 1) + 1;
}

/**
* @return Rhombus screen perimeter
*/
double Rhombus::perimeterScr() const {
	return 2 * (getHeight() - 1);
}

/**
* @return Canvas object with textual image of Rhombus
*/
Canvas Rhombus::draw() const {
	Canvas drawGrid{ static_cast<int>(getHeight()), static_cast<int>(getWidth()) };

	int LSpace, RSpace; // initiallize left blank space and right blank space - col coordinate
	LSpace = RSpace = getHeight() / 2; //  LSpace and RSpace - both will have col number 1/2 of height

	for (int row = 0; row < getHeight(); ++row) {

		// Draw Triangle
		for (int col = 0; col < getHeight(); ++col) {
			if (col >= LSpace && col <= RSpace) { // check if col number pass condition - 'LSpace < col < RSpace'
				drawGrid.put(row, col, pen);
			}
		}

		// upper upright triangle
		if (row < getHeight() / 2) {
			--LSpace; // left space col number will decrement with increasing row count
			++RSpace; // right space col number will increment with increasing row count
		}
		// lower inverted triangle
		else {
			++LSpace; // left space col number will increment with increasing row count
			--RSpace; // right space col number will decrement with increasing row count
		}
	}

	return drawGrid;
}