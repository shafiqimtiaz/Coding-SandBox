#ifndef ACUTE_TRIANGLE_H
#define ACUTE_TRIANGLE_H

#include "Triangle.h"

class AcuteTriangle : public Triangle {
public:
	/**
	* Default Constructor
	*/
	AcuteTriangle(size_t base, char pen = '*', string name = "Wedge");

	/**
	* Default Destructor
	*/
	virtual ~AcuteTriangle();

	/**
	* @return AcuteTriangle geometric perimeter
	*/
	virtual double perimeterGeo() const override;

	/**
	* @return AcuteTriangle screen area
	*/
	virtual double areaScr() const override;

	/**
	* @return AcuteTriangle screen perimeter
	*/
	virtual double perimeterScr() const override;

	/**
	* @return Canvas object with textual image of AcuteTriangle
	*/
	virtual Canvas draw() const override;
};

#endif