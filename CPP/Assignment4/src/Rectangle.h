#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
	/**
	* Default Constructor
	*/
	Rectangle(size_t height, size_t width, char pen = '*', string name = "Rectangle");

	/**
	* Default Destructor
	*/
	virtual ~Rectangle();

	/**
	* @return Rectangle geometric area
	*/
	virtual double areaGeo() const override;

	/**
	* @return Rectangle geometric perimeter
	*/
	virtual double perimeterGeo() const override;

	/**
	* @return Rectangle screen area
	*/
	virtual double areaScr() const override;

	/**
	* @return Rectangle screen perimeter
	*/
	virtual double perimeterScr() const override;

	/**
	* @return Canvas object with textual image of Rectangle
	*/
	virtual Canvas draw() const override;
};

#endif