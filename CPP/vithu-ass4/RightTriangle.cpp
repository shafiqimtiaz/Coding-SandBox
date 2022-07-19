//
// Created by Vithu Maheswaran on 2022-07-11.
//

#include "RightTriangle.h"

// Constructors
RightTriangle::RightTriangle(int base, char pen, string name) : Triangle{base, pen, name} {}

// Accessor Member-function
// returning a non- negative integer, measuring the height of the shape’s bounding box
int RightTriangle::getHeight() const { return base; }

// Accessor Member-function
// returning a non-negative integer, measuring the width of the shape’s bounding box
int RightTriangle::getWidth() const { return base; }

// Member-function
// Computes and returns the shape’s geometric perimeter
double RightTriangle::perimeterGeo() const { return (2 + std::sqrt(2)) * getHeight(); }

// Member-function
// Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
int RightTriangle::areaScr() const { return getHeight() * (getHeight() + 1) / 2; }

// Member-function
// Computes and returns the shape’s screen perimeter, the number of characters on the borders of the textual image of the shape
int RightTriangle::perimeterScr() const { return 3 * (getHeight() - 1); }

Canvas RightTriangle::draw() const {
    Canvas can{getHeight(),getWidth(),' '};
    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getHeight(); j++) {
            if (j <= i) {
                can.put(i ,j ,pen);
            }
        }
    }
    return can;
}