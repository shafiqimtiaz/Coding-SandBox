#include "Shape.h"

/**
* Static id initializer out of class scope
*/
int Shape::id{ 0 };

/**
* Default Constructor
*/
Shape::Shape(char p, string n)
	:pen{ p }, name{ n } { Shape::id++; }

/**
* Default Destructor
*/
Shape::~Shape() {};

/**
* @return shape object name
*/
string Shape::getName() const {
	return this->name;
}

/**
* @return shape object pen character
*/
char Shape::getPen() const {
	return this->pen;
}

/**
* @return shape object unique id
*/
int Shape::getId() const {
	return this->id;
}

/**
* @param string name to set in shape object
*/
void Shape::setName(string name) {
	this->name = name;
}

/**
* @param char pen to set in shape object
*/
void Shape::setPen(char pen) {
	this->pen = pen;
}

/**
* @return a string representation of the Shape
*/
string Shape::toString() const {
	ostringstream buffer;

	buffer << "Shape Information\n"
		<< "-----------------\n"
		<< "id:             " << getId() << "\n"
		<< "Shape name:     " << getName() << "\n"
		<< "Pen character:  " << getPen() << "\n"
		<< "Height:         " << getHeight() << "\n"
		<< "Width:          " << getWidth() << "\n"
		<< "Textual area:   " << areaScr() << "\n"
		<< "Geometric area: " << fixed << setprecision(2) << areaGeo() << "\n"
		<< "Scr perimeter:  " << perimeterScr() << "\n"
		<< "Geo perimeter:  " << fixed << setprecision(2) << perimeterGeo() << "\n"
		<< "Static type:    " << typeid(this).name() << "\n"
		<< "Dynamic type:   " << typeid(*this).name() << endl;

	return buffer.str();
};

/**
Overloaded output operator << to print shape obhject info by polymorphic call
* @param shape object to invoke to_string()
* @return output stream with shape object info
*/
ostream& operator<<(ostream& cout, const Shape& shp) {
	return cout << shp.toString();
}
