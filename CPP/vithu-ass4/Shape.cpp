//
// Created by Vithu Maheswaran on 2022-07-11.
//

#include "Shape.h"

int Shape::shape_count = 0;

// Common operations
Shape::Shape(char pen, string name): pen{pen}, name{name} {
    identity = ++shape_count;
}

int Shape::getIdentity() const { return identity; }

char Shape::getPen() const { return pen; }

string Shape::getName() const { return name; }

// Mutator (setter) member-function for setting pen data member
void Shape::setPen(char pen) { this->pen = pen; }

// Mutator (setter) member-function for setting name data member
void Shape::setName(string name) { this->name = name; }

string Shape::toString() const{
    ostringstream out;
    out << "Shape Information\n";
    out << "-----------------\n";
    out << "id:             " << getIdentity() << endl;
    out << "Shape name:     " << getName() << endl;
    out << "Pen character:  " << getPen() << endl;
    out << "Height:         " << getHeight() << endl;
    out << "Width:          " << getWidth() << endl;
    out << "Textual area:   " << areaScr() << endl;
    out << "Geometric area: " << std::fixed << std::setprecision(2) << areaGeo() << endl;
    out << "Scr perimeter:  " << perimeterScr() << endl;
    out << "Geo perimeter:  " << std::fixed << std::setprecision(2) << perimeterGeo() << endl;
    out << "Static type:    " << typeid(this).name() << endl;
    out << "Dynamic type:   " << typeid(*this).name() << endl;
    return out.str();
}

// Overloaded output operator <<,
// Invokes the toString() function above polymorphically
ostream& operator<<(ostream& cout, const Shape& shp){
    return cout<<shp.toString();
}
