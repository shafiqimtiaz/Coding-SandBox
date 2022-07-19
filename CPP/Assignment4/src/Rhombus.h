#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape
{
protected:
	int d;
public:
	Rhombus(int d, char p = '*', string n = "Rhombus");

	int getHeight() const override;

	int getWidth() const override;

	double areaGeo() const override;

	double perimeterGeo() const override;

	double areaScr() const override;

	double perimeterScr() const override;

	Canvas draw() const override;
};

#endif