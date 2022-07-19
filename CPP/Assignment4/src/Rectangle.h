#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
protected:
	int height;
	int width;

public:
	Rectangle(int height, int width, char pen = '*', string name = "Rectangle");

	int getHeight() const override;

	int getWidth() const override;

	double areaGeo() const override;

	double perimeterGeo() const override;

	double areaScr() const override;

	double perimeterScr() const override;

	Canvas draw() const override;
};

#endif