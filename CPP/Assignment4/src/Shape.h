#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include "Canvas.h"

using std::endl;
using std::ostringstream;
using std::string;
using std::ostream;
using std::vector;
using std::fixed;
using std::setprecision;

class Shape
{
protected:
	/**
	* Common data memeber
	*/
	string name;
	char pen;
	static int id;

public:
	Shape(char pen, string name);

	/**
	* Accessor
	*/
	string getName() const;
	char getPen() const;
	int getId() const;

	/**
	* Mutator
	*/
	void setName(string name);
	void setPen(char pen);

	/**
	* @return a string representation of the Shape
	*/
	string toString() const;

	virtual int getHeight() const = 0;

	virtual int getWidth() const = 0;

	virtual double areaGeo() const = 0;

	virtual double perimeterGeo() const = 0;

	virtual double areaScr() const = 0;

	virtual double perimeterScr() const = 0;

	virtual Canvas draw() const = 0;
};

ostream& operator<<(ostream& cout, const Shape& shp);

#endif