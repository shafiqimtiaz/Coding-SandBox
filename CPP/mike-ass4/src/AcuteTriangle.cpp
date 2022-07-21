// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// AcuteTriangle.cpp

#include <cmath>
#include "AcuteTriangle.h"

// AcuteTriangle Constructor
AcuteTriangle::AcuteTriangle(size_t base, char pen, string name): Triangle{ (base + 1) / 2, base, pen, name } {
  if (base % 2 == 0) {
      setHeight((base + 2) / 2);
      setWidth(base + 1);
  }
}

// AcuteTriangle Destructor
AcuteTriangle::~AcuteTriangle() {};

// AcuteTriangle Mutators
void AcuteTriangle::setHeight(const size_t& height) {
  this->height = height;
  width = 2 * height - 1;
}

void AcuteTriangle::setWidth(const size_t& base) {
  width = base;
  height = (base + 1) / 2;
}

// ** AcuteTriangle Area & Perimeter Functions
// Computes and returns the AcuteTriangle geometric perimeter
double AcuteTriangle::perimeterGeo() {
  return getWidth() + sqrt( getWidth() * getWidth() + 4 * getHeight() * getHeight() );
}

// Computes and returns the AcuteTriangle screen area, 
// the number of characters that form the textual image of the AcuteTriangle
double AcuteTriangle::areaScr() {
return getHeight() * getHeight();
}

// Computes and returns the AcuteTriangle screen perimeter, 
// the number of characters on the borders of the textual image of AcuteTriangle
double AcuteTriangle::perimeterScr() {
  return 4 * ( getHeight() - 1 );
}

// *** AcuteTriangle Draw Function
// Draws a textual image of the AcuteTriangle on a Canvas object using the shape's pen character
Canvas AcuteTriangle::draw() const {
  Canvas aCanvas{ getHeight(), getWidth() };
  
  for (size_t r = 0; r < getHeight(); ++r) {
      size_t numPen = 2 * r + 1;
      size_t numSpaces = (getWidth() - numPen) / 2;
      for (size_t c = 0; c < getWidth(); ++c) {
          if (c >= numSpaces && numPen > 0) {
              aCanvas.put(r, c, getPen());
              --numPen;
          }
      }
  }
  return aCanvas;
}

