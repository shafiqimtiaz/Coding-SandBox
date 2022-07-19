//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_SHAPE_H
#define ASSIGNMENT04_SHAPE_H

#include <iomanip>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include "Canvas.h"

using std::endl;
using std::ostringstream;
using std::string;
using std::ostream;
using std::vector;



class Shape {

protected:
    static int shape_count;
    // Common attributes
    int identity;
    char pen;
    string name;

public:

    // CTOR
    Shape(char pen, string name);

    // Common operations
    // Three (getter) member-functions, one for each attribute
    int getIdentity() const;
    char getPen() const;
    string getName() const;

    // Mutator (setter) member-function for setting pen data member
    void setPen(char pen);

    // Mutator (setter) member-function for setting name data member
    void setName(string name);

    // Member-function
    // returns a string representation of the Shape object invoking it
    string toString() const;

    // Overloaded output operator <<,
    // Invokes the toString() function above polymorphically
    friend ostream& operator<<(ostream& cout, const Shape& shp);

    // Accessor Member-function
    // returning a non- negative integer, measuring the height of the shape’s bounding box
    virtual int getHeight() const = 0;

    // Accessor Member-function
    // returning a non-negative integer, measuring the width of the shape’s bounding box
    virtual int getWidth() const = 0;

    // Member-function
    // Computes and returns the shape’s geometric area
    virtual double areaGeo() const = 0;

    // Member-function
    // Computes and returns the shape’s geometric perimeter
    virtual double perimeterGeo() const = 0;

    // Member-function
    // Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
    virtual int areaScr() const = 0;

    // Member-function
    // Computes and returns the shape’s screen perimeter, the number of characters on the borders of the textual image of the shape
    virtual int perimeterScr() const = 0;

    virtual Canvas draw() const = 0;

};


#endif //ASSIGNMENT04_SHAPE_H
