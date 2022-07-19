#include "Shape.h"

int Shape::id{ 0 };

Shape::Shape(char p, string n)
	:pen{ p }, name{ n } { Shape::id++; }

string Shape::getName() const { return this->name; }

char Shape::getPen() const { return this->pen; }

int Shape::getId() const { return this->id; }

void Shape::setName(string name) { this->name = name; }

void Shape::setPen(char pen) { this->pen = pen; }

string Shape::toString() const
{
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

ostream& operator<<(ostream& cout, const Shape& shp) {
	return cout << shp.toString();
}
