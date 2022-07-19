//
// Created by Vithu Maheswaran on 2022-07-11.
//

#include "Rectangle.h"

Rectangle::Rectangle(int h, int w, char p, string n): Shape(p,n), height{h}, width{w} {}

// Accessor Member-function
// returning a non- negative integer, measuring the height of the shape’s bounding box
int Rectangle::getHeight() const { return height; }

// Accessor Member-function
// returning a non-negative integer, measuring the width of the shape’s bounding box
int Rectangle::getWidth() const { return width; }

// Member-function
// Computes and returns the shape’s geometric area
double Rectangle::areaGeo() const { return height * width; }

// Member-function
// Computes and returns the shape’s geometric perimeter
double Rectangle::perimeterGeo() const { return 2 * (height + width); }

// Member-function
// Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
int Rectangle::areaScr() const { return areaGeo(); }

// Member-function
// Computes and returns the shape’s screen perimeter, the number of characters on the borders of the textual image of the shape
int Rectangle::perimeterScr() const { return perimeterGeo()-4;}

Canvas Rectangle::draw() const {
    Canvas can{getHeight(),getWidth(),' '};
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            can.put(i ,k ,pen);
        }
    }
    return can;
}
