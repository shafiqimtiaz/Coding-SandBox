// COMP5421 - Asg3 - Summer 2022
// Mike Poullas - 21917739
// Triangle.h

#ifndef Triangle_h
#define Triangle_h

#include <stdio.h>
#include "Shape.h"

class Triangle: public Shape {
  protected:
    // Triangle Constructor
    Triangle(size_t, size_t, char, string);

  public:
    // Triangle Destructor
    virtual ~Triangle();

    // ** Triangle Area Function
    // Computes and returns the Triangle geometric area
    virtual double areaGeo() override; 
};

#endif // Triangle_h
