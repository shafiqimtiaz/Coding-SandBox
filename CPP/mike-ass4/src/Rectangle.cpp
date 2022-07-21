// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// Rectangle.cpp

#include <string>
#include "Rectangle.h"

using std::string;

// Rectangle Constructor
Rectangle::Rectangle(size_t height, size_t width, char pen, string name): Shape{ height, width, pen, name } {};

// Rectangle Destructor
Rectangle::~Rectangle() {};

// Rectangle Mutators
void Rectangle::setHeight(const size_t& height) {
  this->height = height;
}

void Rectangle::setWidth(const size_t& width) {
  this->width = width;
}

// ** Rectangle Area & Perimeter Function
// Computes and returns the Rectangle geometric area
double Rectangle::areaGeo() {
  return getHeight() * getWidth();
}

// Computes and returns the Rectangle geometric perimeter
double Rectangle::perimeterGeo() {
  return 2 * ( getHeight() + getWidth() );
}

// Computes and returns the Rectangle screen area, 
// the number of characters forming the textual image of the Rectangle
double Rectangle::areaScr() {
  return getHeight() * getWidth();
}

// Computes and returns the Rectangle screen perimeter, 
// the number of characters on the borders of the textual image of the Rectangle
double Rectangle::perimeterScr() {
  return 2 * ( getHeight() + getWidth() ) - 4;
}

// ** Rectangle Draw Function
// Draws a textual image of the Rectangle on a Canvas object using the shape's pen character
Canvas Rectangle::draw() const {
  Canvas aCanvas { getHeight(), getWidth() };
  
  for (int r = 0; r < getHeight(); ++r) {
    for (int c = 0; c < getWidth(); ++c) {
      aCanvas.put(r, c, getPen());
    }
  }

  return aCanvas;
}
