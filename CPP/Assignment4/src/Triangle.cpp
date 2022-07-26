#include "Triangle.h"

/**
* Default Constructor
*/
Triangle::Triangle(size_t h, size_t w, char p, string n)
	: Shape{ h, w, p, n } {}

/**
* Default Destructor
*/
Triangle::~Triangle() {};

/**
* @return Triangle object geometric area
*/
double Triangle::areaGeo() const {
	return (getHeight() * getWidth()) / 2;
}