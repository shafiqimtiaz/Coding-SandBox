//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_RIGHTTRIANGLE_H
#define ASSIGNMENT04_RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle: public Triangle{

public:

    // Constructors
    RightTriangle(int b, char p = '*', string n = "Ladder");

    // Accessor Member-function
    // returning a non- negative integer, measuring the height of the shape’s bounding box
    int getHeight() const override;

    // Accessor Member-function
    // returning a non-negative integer, measuring the width of the shape’s bounding box
    int getWidth() const override;

    // Member-function
    // Computes and returns the shape’s geometric perimeter
    double perimeterGeo() const override;

    // Member-function
    // Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
    int areaScr() const override;

    // Member-function
    // Computes and returns the shape’s screen perimeter, the number of characters on the borders of the textual image of the shape
    int perimeterScr() const override;

    Canvas draw() const override;
};


#endif //ASSIGNMENT04_RIGHTTRIANGLE_H
