// COMP5421 - Asg3 - Summer 2022
// Mike Poullas - 21917739
// Shape.h

#ifndef Shape_h
#define Shape_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>
#include "Canvas.h"

using std::string;
using std::ostream;
using std::unique_ptr;

class Shape {
  protected:
    // Shape Attributes
    // Object shape name
    string name;

    // A unique positive integer, distinct from that of all the other shape objects
    int identity_number;

    // A character to draw the shape with
    char pen; 

    // Shape height, a non-negative integer
    size_t height;
    // Shape width, a non-negative integer
    size_t width;    
    
    static int counter_id;
    
    // Shape Constructor
    Shape(size_t, size_t, char, string);
    
public:
    // ** Shape Destructor
    virtual ~Shape();
    
    // Returns a string representation of the Shape object invoking it
    string toString(); 
    
    // An overloaded output operator <<, which invokes the toString() function above
    // polymorphically and then outputs the string object it returns to a supplied output stream
    friend ostream& operator<<(ostream&, Shape&);
    
    // ** Shape Accessors
    string getName() const;
    int getIdentityNumber() const;
    char getPen() const;

    // ** Shape Mutators
    void setName(const string&);
    void setPen(const char&);

    // Returns a non-negative height and width of the shape's bounding box
    size_t getHeight() const;
    size_t getWidth() const;

    virtual void setHeight(const size_t&) = 0;
    virtual void setWidth(const size_t&) = 0;
    
    // ** Area & Perimiter Functions
    // Returns the shape’s geometric area
    virtual double areaGeo() = 0;

    // Computes and returns the shape’s geometric perimeter
    virtual double perimeterGeo() = 0;

    // Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
    virtual double areaScr() = 0;

    // Computes and returns the shape’s screen perimeter, the number of characters 
    // on the borders of the textual image of the shape
    virtual double perimeterScr() = 0; 
    
    // ** Draw Function
    // Draws a textual image of the shape on a Canvas object using the shape’s pen character
    virtual Canvas draw() const = 0; 
};

#endif // Shape_h
