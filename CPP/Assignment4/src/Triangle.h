#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
protected:
	int base;
public:
	Triangle(int base, char pen = '*', string name = "Triangle");

	double areaGeo() const;
};

#endif