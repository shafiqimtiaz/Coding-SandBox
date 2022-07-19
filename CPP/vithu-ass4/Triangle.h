//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_TRIANGLE_H
#define ASSIGNMENT04_TRIANGLE_H

#include "Shape.h"

class Triangle: public Shape {
protected:
    int base;
public:
    Triangle(int b, char p = '*', string n = "Triangle");

    // Member-function
    // Computes and returns the shape’s geometric area
    double areaGeo() const;
};


#endif //ASSIGNMENT04_TRIANGLE_H
