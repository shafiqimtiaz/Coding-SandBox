#include "Triangle.h"

/**
* Default Constructor
*/
Triangle::Triangle(int b, char p, string n)
	: Shape{ p,n }, base{ b } {}

/**
* Default Destructor
*/
Triangle::~Triangle() {};

/**
* @return Triangle object geometric area
*/
double Triangle::areaGeo() const {
	return getHeight() * base / 2;
}