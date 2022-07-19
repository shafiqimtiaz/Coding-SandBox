#include "Triangle.h"

Triangle::Triangle(int b, char p, string n)
	: Shape{ p,n }, base{ b } {}

double Triangle::areaGeo() const
{
	return getHeight() * base / 2.0;
}