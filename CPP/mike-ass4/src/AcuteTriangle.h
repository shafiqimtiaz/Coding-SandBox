// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// AcuteTriangle.h

#ifndef AcuteTriangle_h
#define AcuteTriangle_h

#include <stdio.h>
#include "Shape.h"
#include "Triangle.h"

using std::string;

class AcuteTriangle: public Triangle {
public:
  // AcuteTriangle Constructor
  AcuteTriangle(size_t, char = '*', string = "Wedge");
    
  // AcuteTriangle Destrcutor
  virtual ~AcuteTriangle();
    
  // AcuteTriangle Mutators
  virtual void setHeight(const size_t&) override;
  virtual void setWidth(const size_t&) override;

  // ** AcuteTriangle Area & Perimeter Functions
  // Computes and returns the AcuteTriangle geometric perimeter
  virtual double perimeterGeo() override;

  // Computes and returns the AcuteTriangle screen area, 
  // the number of characters that form the textual image of the AcuteTriangle
  virtual double areaScr() override;

  // Computes and returns the AcuteTriangle screen perimeter, 
  // the number of characters on the borders of the textual image of AcuteTriangle
  virtual double perimeterScr() override; 

  // ** AcuteTriangle Draw Function
  // Draws a textual image of the AcuteTriangle on a Canvas object using the shape's pen character
  virtual Canvas draw() const override; 
};

#endif // AcuteTriangle_h
