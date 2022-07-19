#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle
{
public:

	RightTriangle(int base, char pen = '*', string name = "Ladder");

	int getHeight() const override;

	int getWidth() const override;

	double perimeterGeo() const override;

	double areaScr() const override;

	double perimeterScr() const override;

	Canvas draw() const override;
};

#endif