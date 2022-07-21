// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// Rectangle.h


#ifndef Rectangle_h
#define Rectangle_h

#include <stdio.h>
#include <string>
#include "Shape.h"
#include "Canvas.h"

using std::string;

class Rectangle: public Shape {
public:
  // Rectangle Constructor
  Rectangle(size_t, size_t, char = '*', string = "Rectangle");
  
  // Rectangle Destructor
  virtual ~Rectangle();
  
  // ** Rectangle Mutators
  virtual void setHeight(const size_t&) override;
  virtual void setWidth(const size_t&) override;
  
  // ** Rectangle Area & Perimeter Functions
  // Computes and returns the Rectangle geometric area
  virtual double areaGeo() override;

  // Computes and returns the Rectangle geometric perimeter
  virtual double perimeterGeo() override; 

  // Computes and returns the Rectangle screen area, 
  // the number of characters forming the textual image of the Rectangle
  virtual double areaScr() override;

  // Computes and returns the Rectangle screen perimeter, 
  // the number of characters on the borders of the textual image of the Rectangle
  virtual double perimeterScr() override; 
  
  // ** Rectangle Draw Function
  // Draws a textual image of the Rectangle on a Canvas object using the shape's pen character
  virtual Canvas draw() const override; 
};

#endif // Rectangle_h
