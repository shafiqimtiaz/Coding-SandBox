// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// RightTriangle.h

#ifndef RightTriangle_h
#define RightTriangle_h

#include <stdio.h>
#include "Shape.h"
#include "Triangle.h"

using std::string;

class RightTriangle: public Triangle {
public:
    // RightTriangle Constructor
    RightTriangle(size_t, char = '*', string = "Ladder");
    
    // RightTriangle Destructor
    virtual ~RightTriangle();
    
    // RightTriangle Mutators
    virtual void setHeight(const size_t&) override;
    virtual void setWidth(const size_t&) override;

    // ** RightTriangle Area & Perimiter Functions for RightTriangle
    // Computes and returns the shape’s geometric perimeter
    virtual double perimeterGeo() override; 

    // Computes and returns the RightTriangle screen area, the number 
    // of characters that forming the textual image of the RightTriangle
    virtual double areaScr() override;

    // Computes and returns the RightTriangle screen perimeter, the number of 
    // characters on the borders of the textual image of the RightTriangle
    virtual double perimeterScr() override; 

    // ** Draw Function
    // Draws a textual image of the RightTriangle on a Canvas object using the shape's pen character
    virtual Canvas draw() const override; 
};

#endif // RightTriangle_h
