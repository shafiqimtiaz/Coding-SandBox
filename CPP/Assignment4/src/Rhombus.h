#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape {
public:
	/**
	* Default Constructor
	*/
	Rhombus(size_t diagonal, char pen = '*', string name = "Rhombus");

	/**
	* Default Destructor
	*/
	virtual ~Rhombus();

	/**
	* @return Rhombus geometric area
	*/
	virtual double areaGeo() const override;

	/**
	* @return Rhombus geometric perimeter
	*/
	virtual double perimeterGeo() const override;

	/**
	* @return Rhombus screen area
	*/
	virtual double areaScr() const override;

	/**
	* @return Rhombus screen perimeter
	*/
	virtual double perimeterScr() const override;

	/**
	* @return Canvas object with textual image of Rhombus
	*/
	virtual Canvas draw() const override;
};

#endif