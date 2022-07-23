#include "Rhombus.h"

/**
* Default Constructor
*/
Rhombus::Rhombus(int d, char p, string n)
	:Shape{ p,n }, diagonal{ d % 2 == 1 ? d : d + 1 }{}

/**
* Default Destructor
*/
Rhombus::~Rhombus() {};

/**
* @return height of Rhombus
*/
int Rhombus::getHeight() const {
	return diagonal;
}

/**
* @return width of Rhombus
*/
int Rhombus::getWidth() const {
	return diagonal;
}

/**
* @return Rhombus geometric area
*/
double Rhombus::areaGeo() const {
	return diagonal * diagonal / 2;
}

/**
* @return Rhombus geometric perimeter
*/
double Rhombus::perimeterGeo() const {
	return 2 * std::sqrt(2) * diagonal;
}

/**
* @return Rhombus screen area
*/
double Rhombus::areaScr() const {
	double n = floor(diagonal / 2);
	return 2 * n * (n + 1) + 1;
}

/**
* @return Rhombus screen perimeter
*/
double Rhombus::perimeterScr() const {
	return 2 * (diagonal - 1);
}

/**
* @return Canvas object with textual image of Rhombus
*/
Canvas Rhombus::draw() const {
	Canvas drawGrid{ getHeight(), getWidth() };

	int h = getHeight();

	int LSpace, RSpace; // initiallize left blank space and right blank space - col coordinate
	LSpace = RSpace = h / 2; //  LSpace and RSpace - both will have col number 1/2 of height

	for (int row = 0; row < h; ++row) {

		// Draw Triangle
		for (int col = 0; col < h; ++col) {
			if (col >= LSpace && col <= RSpace) { // check if col number pass condition - 'LSpace < col < RSpace'
				drawGrid.put(row, col, pen);
			}
		}

		// upper upright triangle
		if (row < h / 2) {
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