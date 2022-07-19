//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_RHOMBUS_H
#define ASSIGNMENT04_RHOMBUS_H

#include "Shape.h"

class Rhombus: public Shape{
protected:
    int d;

public:

    // Constructors
    Rhombus(int d, char p = '*', string n = "Rhombus");

    // Accessor Member-function
    // returning a non- negative integer, measuring the height of the shape’s bounding box
    int getHeight() const override;

    // Accessor Member-function
    // returning a non-negative integer, measuring the width of the shape’s bounding box
    int getWidth() const override;

    // Member-function
    // Computes and returns the shape’s geometric area
    double areaGeo() const override;

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


#endif //ASSIGNMENT04_RHOMBUS_H
