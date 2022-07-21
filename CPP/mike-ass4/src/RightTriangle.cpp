// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// RightTriangle.cpp

#include <cmath>
#include "RightTriangle.h"

// ** RightTriangle Constructor
RightTriangle::RightTriangle(size_t base, char pen, string name) : Triangle { base, base, pen, name } {};

// ** RightTriangle Destructor
RightTriangle::~RightTriangle() {};

// ** RightTriangle height and width mutators
void RightTriangle::setHeight(const size_t& base) {
  height = width = base;
}

void RightTriangle::setWidth(const size_t& base) {
  width = height = base;
}

// ** RightTriangle Area & Perimiter Functions
// Computes and returns the shape’s geometric perimeter
double RightTriangle::perimeterGeo() {
  return (2 + sqrt(2)) * getHeight();
} 

// Computes and returns the RightTriangle screen area, the number 
// of characters that forming the textual image of the RightTriangle
double RightTriangle::areaScr() {
  return getHeight() * (getHeight() + 1) / 2;
}

// Computes and returns the RightTriangle screen perimeter, the number of 
// characters on the borders of the textual image of the RightTriangle
double RightTriangle::perimeterScr() {
  return 3 * (getHeight() - 1);
} 

// ** RightTriangle Draw Function
// Draws a textual image of the right triangle on a Canvas object using the shape's pen character
Canvas RightTriangle::draw() const { 
  Canvas aCanvas{ getHeight(), getWidth() };
  
  for (int r = 0; r < getHeight(); ++r){
      for (int c = 0; c < getWidth(); ++c){
          if(c <= r) aCanvas.put(r, c, getPen());
      }
  }
  
  return aCanvas;
}
