// COMP5421 - Asg3 - Summer 2022
// Mike Poullas - 21917739
// Shape.cpp

#include <typeinfo>
#include "Shape.h"

using std::to_string;

int Shape::counter_id = 1;

// ** Shape Constructor
Shape::Shape(size_t height, size_t width, char pen, string name): 
  height{ height }, 
  width{ width }, 
  pen{ pen }, 
  name{ name }, 
  identity_number{ counter_id } {
  ++counter_id;
}

// ** Shape Destructor
Shape::~Shape() {};

// Returns a string representation of the this shape
string Shape::toString() { 
  return "Shape Information"
    "\n-----------------"
    "\nid:                  " + to_string(identity_number) +
    "\nShape name:          " + name +
    "\nPen character:       " + pen +
    "\nHeight:              " + to_string(height) +
    "\nWidth:               " + to_string(width) +
    "\nTextual area:        " + to_string(areaScr()) +
    "\nGeometric area:      " + to_string(areaGeo()) +
    "\nTextual perimeter:   " + to_string(perimeterScr()) +
    "\nGeometric perimeter: " + to_string(perimeterGeo()) +
    "\nStatic type:         " + typeid(this).name() +
    "\nDynamic type:        " + typeid(*this).name();
}

// Insert Operator Overloading
ostream& operator<<(ostream& sout, Shape& shp) {
   return sout << shp.toString();
}

// Shape Accessors
string Shape::getName() const {
  return name;
}

int Shape::getIdentityNumber() const {
  return identity_number;
}

char Shape::getPen() const {
  return pen;
}

size_t Shape::getHeight() const {
  return height;
}

size_t Shape::getWidth() const {
  return width;
}

// Shape Mutators
void Shape::setName(const string& name) {
  this->name = name;
}

void Shape::setPen(const char& pc) {
  this->pen = pc;
}
