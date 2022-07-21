#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
protected:
	int base;
public:
	/**
	* Default Constructor
	*/
	Triangle(int base, char pen = '*', string name = "Triangle");

	/**
	* Default Destructor
	*/
	virtual ~Triangle();

	/**
	* @return Triangle object geometric area
	*/
	virtual double areaGeo() const;
};

#endif