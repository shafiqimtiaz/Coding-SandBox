// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// Rhombus.cpp

#include <cmath>
#include "Rhombus.h"

// Rhombus Constructor
Rhombus::Rhombus(size_t diagonal, char pen, string name): Shape { diagonal, diagonal, pen, name } {
  if (diagonal % 2 == 0) {
    setHeight(diagonal + 1);
    setWidth(diagonal + 1);
  }
}

// Rhombus Destructor
Rhombus::~Rhombus() {};

// Rhombus Mutators
void Rhombus::setHeight(const size_t& diagonal) {
  height = width = diagonal;
}

void Rhombus::setWidth(const size_t& diagonal) {
  width = height = diagonal;
}

// ** Rhombus Area & Perimeter Functions
// Returns the Rhombus geometric area
double Rhombus::areaGeo() {
  return ( getHeight() * getWidth() ) / 2;}

// Computes and returns the Rhombus geometric perimeter
double Rhombus::perimeterGeo() {
  return (2 * sqrt(2)) * 2;
}

// Computes and returns the Rhombus screen area,
// The number of characters forming the textual image of the Rhombus
double Rhombus::areaScr() { 
  double n = floor( getHeight()/2 );
  return 2 * n * (n + 1) + 1;
}

// Computes and returns the Rhombus screen perimeter, 
// the number of characters on the borders of the textual image of the Rhombus
double Rhombus::perimeterScr() {
  return 2 * ( getHeight() - 1 );
} 

// ** Rhombus Draw Function
// Draws a textual image of the Rhombus on a Canvas object using the Rhombus pen character
Canvas Rhombus::draw() const { 
  Canvas aCanvas{ getHeight(), getWidth() };
  
  size_t numSpaces = (getWidth() - 1) / 2;
  size_t numStars = 1;
  
  for (int r = 0; r < getHeight(); ++r) {
    for (int c = 0; c < numStars; ++c) {
      aCanvas.put(r, c + numSpaces, getPen());
    }

    if (r < getHeight() / 2){
      numSpaces -= 1;
      numStars  += 2;
    } else {
        numSpaces += 1;
        numStars  -= 2;
    }
  }

  return aCanvas;
}
