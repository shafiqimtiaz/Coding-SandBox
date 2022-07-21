// COMP5421 - Asg3 - Summer 2022
// Mike Poullas - 21917739
// Triangle.c

#include "Triangle.h"

// Triangle Constructor
Triangle::Triangle(size_t height, size_t base, char pen, string name) : Shape{ height, base, pen, name } {};

// Triangle Destrcutor
Triangle::~Triangle() {};

// ** Triangle Area Function
// Computes and returns the Triangle geometric area
double Triangle::areaGeo() {
  return ( getHeight() * getWidth() ) / 2;
}

