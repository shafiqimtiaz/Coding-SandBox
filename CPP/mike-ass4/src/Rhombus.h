// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// Rhombus.h

#ifndef Rhombus_h
#define Rhombus_h

#include <stdio.h>
#include <string>
#include "Shape.h"
#include "Canvas.h"

using std::string;

class Rhombus: public Shape {
public:
  // Rhombus Constructor
  Rhombus(size_t, char = '*', string = "Diamond");
    
  // Rhombus Destructor
  virtual ~Rhombus();
  
  // Rhombus Accessors
  virtual void setHeight(const size_t&) override;
  virtual void setWidth(const size_t&) override;

  // ** Rhombus Area & Perimeter Functions
  // Returns the Rhombus geometric area
  virtual double areaGeo() override;

  // Computes and returns the Rhombus geometric perimeter
  virtual double perimeterGeo() override;  

  // Computes and returns the Rhombus screen area,
  // The number of characters forming the textual image of the Rhombus
  virtual double areaScr() override;       

  // Computes and returns the Rhombus screen perimeter, 
  // the number of characters on the borders of the textual image of the Rhombus
  virtual double perimeterScr() override;  

  // ** Rhombus Draw Function
  // Draws a textual image of the Rhombus on a Canvas object using the Rhombus pen character
  virtual Canvas draw() const override;    
};

#endif // Rhombus_h
