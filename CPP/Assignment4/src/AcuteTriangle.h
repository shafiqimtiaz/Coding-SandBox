#ifndef ACUTE_TRIANGLE_H
#define ACUTE_TRIANGLE_H

#include "Triangle.h"

class AcuteTriangle : public Triangle {
public:
	/**
	* Default Constructor
	*/
	AcuteTriangle(int base, char pen = '*', string name = "Wedge");

	/**
	* Default Destructor
	*/
	virtual ~AcuteTriangle();

	/**
	* @return height of AcuteTriangle
	*/
	virtual int getHeight() const override;

	/**
	* @return base width of AcuteTriangle
	*/
	virtual int getWidth() const override;

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