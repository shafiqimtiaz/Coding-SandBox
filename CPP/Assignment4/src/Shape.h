#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <typeinfo>

#include "Canvas.h"

using std::endl;
using std::ostringstream;
using std::string;
using std::ostream;
using std::vector;
using std::fixed;
using std::setprecision;

class Shape {
protected:
	/****************** Common data member ******************/

	/**
	Shape object name
	*/
	string name;

	/**
	Character to draw the shape object
	*/
	char pen;

	/**
	Unique positive integer id, distinct from that of all the other shape objects
	*/
	static int id;

public:
	/**
	* Default Constructor
	*/
	Shape(char pen, string name);

	/**
	* Default Destructor
	*/
	virtual ~Shape();

	/****************** Shape Accesors ******************/

	/**
	* @return shape object name
	*/
	string getName() const;

	/**
	* @return shape object pen character
	*/
	char getPen() const;

	/**
	* @return shape object unique id
	*/
	int getId() const;

	/****************** Shape Mutators ******************/

	/**
	* @param string name to set in shape object
	*/
	void setName(string name);

	/**
	* @param char pen to set in shape object
	*/
	void setPen(char pen);

	/**
	* @return a string representation of the Shape
	*/
	string toString() const;

	/****************** Pure Virtual Functions ******************/

	/**
	* @return height of Shape
	*/
	virtual int getHeight() const = 0;

	/**
	* @return width of Shape
	*/
	virtual int getWidth() const = 0;

	/**
	* @return Shape geometric area
	*/
	virtual double areaGeo() const = 0;

	/**
	* @return Shape geometric perimeter
	*/
	virtual double perimeterGeo() const = 0;

	/**
	* @return Shape screen area
	*/
	virtual double areaScr() const = 0;

	/**
	* @return Shape screen perimeter
	*/
	virtual double perimeterScr() const = 0;

	/**
	* @return Canvas object with textual image of Shape
	*/
	virtual Canvas draw() const = 0;
};

/**
Overloaded output operator << to print shape obhject info by polymorphic call
* @param shp - shape object to invoke to_string()
* @return cout - output stream with shape object info
*/
ostream& operator<<(ostream& cout, const Shape& shp);

#endif