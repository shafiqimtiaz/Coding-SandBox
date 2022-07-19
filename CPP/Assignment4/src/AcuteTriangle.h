#ifndef ACUTE_TRIANGLE_H
#define ACUTE_TRIANGLE_H

#include "Triangle.h"

class AcuteTriangle : public Triangle
{
public:

	AcuteTriangle(int base, char pen = '*', string name = "Wedge");

	int getHeight() const override;

	int getWidth() const override;

	double perimeterGeo() const override;

	double areaScr() const override;

	double perimeterScr() const override;

	Canvas draw() const override;
};

#endif