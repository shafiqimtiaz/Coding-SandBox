#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
public:
	/**
	* Default Constructor
	*/
	RightTriangle(int base, char pen = '*', string name = "Ladder");

	/**
	* Default Destructor
	*/
	virtual ~RightTriangle();

	/**
	* @return height of RightTriangle
	*/
	virtual int getHeight() const override;

	/**
	* @return base width of RightTriangle
	*/
	virtual int getWidth() const override;

	/**
	* @return RightTriangle geometric perimeter
	*/
	virtual double perimeterGeo() const override;

	/**
	* @return RightTriangle screen area
	*/
	virtual double areaScr() const override;

	/**
	* @return RightTriangle screen perimeter
	*/
	virtual double perimeterScr() const override;

	/**
	* @return Canvas object with textual image of RightTriangle
	*/
	virtual Canvas draw() const override;
};

#endif