#include<iostream>
#include<vector>

#include "Rhombus.h"
#include "Rectangle.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
#include "Canvas.h"

using std::cout;
using std::endl;

void shape_examples(); // the examples shown in the assignment description
void drawHouse();      // draw front view of a house 
void drawHouseElement(Canvas& house_canvas, const Shape& shp, int row, int col);

int main()
{
   // shape_examples();
   drawHouse();   
   return 0;
}



void drawHouseElement(Canvas& house_canvas, const Shape& shp, int row, int col)
{
   cout << shp << "\n=======================================\n";
   Canvas house_element_canvas = shp.draw();
   house_canvas.overlap(house_element_canvas, row, col);
}

// Using our four geometric shapes, 
// draws a pattern that looks like the front view of a house
void drawHouse()
{
   // create a 47-row by 72-column Canvas
   Canvas houseCanvas(47, 72);
   houseCanvas.drawString(1, 10, "a geometric house: front view");

   RightTriangle roof(20, '\\', "Right half of roof");
   Canvas roof_right_can = roof.draw();
   houseCanvas.overlap(roof_right_can, 4, 27);

   roof.setPen('/');
   Canvas roof_left_can = roof.draw().flip_horizontal();
   houseCanvas.overlap(roof_left_can, 4, 7);

   houseCanvas.drawString(23, 8, 
            "[][][][][][][][][][][][][][][][][][][]");

   Rectangle chimneyL(5, 1, '|', "left chimeny edge");
   drawHouseElement(houseCanvas, chimneyL, 14, 12);

   Rectangle chimneyR(4, 1, '|', "right chimeny edge");
   drawHouseElement(houseCanvas, chimneyR, 14, 13);

   Rectangle antenna_stem(11, 1, 'I', "antenna stem");
   drawHouseElement(houseCanvas, antenna_stem, 11, 45);

   RightTriangle antenna(5, '=', "Right antenna wing");
   Canvas antenna_Q1 = antenna.draw();
   Canvas antenna_Q2 = antenna_Q1.flip_horizontal();
   Canvas antenna_Q3 = antenna_Q2.flip_vertical();
   Canvas antenna_Q4 = antenna_Q1.flip_vertical();
   houseCanvas.overlap(antenna_Q3, 11, 40);
   houseCanvas.overlap(antenna_Q4, 11, 46);

   Rectangle wall(18, 1, '[', "vertical left and right brackets");
   drawHouseElement(houseCanvas, wall, 24, 8);
   drawHouseElement(houseCanvas, wall, 24, 44);

   wall.setPen(']'); // use the same wall shape
   drawHouseElement(houseCanvas, wall, 24, 9);
   drawHouseElement(houseCanvas, wall, 24, 45);

   Rectangle line(1, 66, '-', "horizontal lines depicting the ground");
   for (int c = 1; c <= 6; c++)
   {
      drawHouseElement(houseCanvas, line, 40 + c, 7 - c);
   }
   houseCanvas.drawString(40, 8,
            "[][][][][][][][][][][][][][][][][][][]");
   houseCanvas.drawString(41, 8, 
            "[][][][][][][][][][][][][][][][][][][]");

   Rectangle door_step(1, 12, '/', "door step");
   drawHouseElement(houseCanvas, door_step, 39, 21);

   Rectangle door(12, 12, '|', "door");
   drawHouseElement(houseCanvas, door, 27, 21);

   Rectangle door_edge(1, 10, '=', "door top/bottom edge");
   drawHouseElement(houseCanvas, door_edge, 27, 22);
   drawHouseElement(houseCanvas, door_edge, 38, 22);

   Rectangle door_knob(1, 1, 'O', "door knob");
   drawHouseElement(houseCanvas, door_knob, 33, 22);

   houseCanvas.drawString(26, 25, "5421");

   Rhombus window(5, '+', "left window");
   drawHouseElement(houseCanvas, window, 28, 14);
   drawHouseElement(houseCanvas, window, 28, 35);

   Rectangle tree_trunk(5, 3, 'H', "tree trunk");
   drawHouseElement(houseCanvas, tree_trunk, 36, 60);

   AcuteTriangle leaves(7, '*', "top level leaves");
   drawHouseElement(houseCanvas, leaves, 21, 58);
   
   AcuteTriangle middleLeaves(11, '*', "middle level leaves");
   drawHouseElement(houseCanvas, middleLeaves, 23, 56);
   
   AcuteTriangle bottomLeaves(19, '*', "bottom level leaves");
   drawHouseElement(houseCanvas, bottomLeaves, 26, 52);

   houseCanvas.drawString(13, 11, "\\||/");
   houseCanvas.drawString(12, 11, "_/\\_");

   // finally, reveal the house image
   cout << houseCanvas;
   return;
}

void shape_examples()
{
   Rectangle rect{ 5, 7 };
   cout << rect.toString() << endl;
   // or equivalently
   //cout << rect << endl;
   //------------------------------------------------------------
   Rhombus
      ace{ 16, 'v', "Ace of diamond" };
   // cout << ace.toString() << endl;
   // or, equivalently:
   cout << ace << endl;
   //------------------------------------------------------------
   AcuteTriangle at{ 17 };
   cout << at << endl;

   /*
     // equivalently:

     Shape *atPtr = &at;
     cout << *atPtr << endl;

     Shape &atRef = at;
     cout << atRef << endl;
  */
  //------------------------------------------------------------
   RightTriangle
      rt{ 10, 'L', "Carpenter's square" };
   cout << rt << endl;
   // or equivalently
   // cout << rt.toString() << endl;
   //------------------------------------------------------------
   Canvas aceCan{ ace.draw() }; // same as Canvas aceCan = ace.draw();
   cout << aceCan << endl;
   //------------------------------------------------------------
   Canvas rectCan{ rect.draw() };
   cout << rectCan << endl;
   //------------------------------------------------------------
   at.setPen('^');
   Canvas atCan{ at.draw() };
   cout << atCan << endl;
   //------------------------------------------------------------
   Canvas rtCan{ rt.draw() };
   cout << rtCan << endl;
   //------------------------------------------------------------
   rt.setPen('O');
   Canvas rtQuadrant_1{ rt.draw() };
   cout << rtQuadrant_1 << endl;
   //------------------------------------------------------------
   Canvas rtQuadrant_2{ rtQuadrant_1.flip_horizontal() };
   cout << rtQuadrant_2 << endl;
   //------------------------------------------------------------
   Canvas rtQuadrant_3{ rtQuadrant_2.flip_vertical() };
   cout << rtQuadrant_3 << endl;
   //------------------------------------------------------------
   Canvas rtQuadrant_4{ rtQuadrant_3.flip_horizontal() };
   cout << rtQuadrant_4 << endl;
   //------------------------------------------------------------
 // create a vector of smart pointers to Shape
   std::vector<std::unique_ptr<Shape>> shapeVec;

   // Next, add some shapes to shapeVec
   shapeVec.push_back
   (std::make_unique<Rectangle>(5, 7));
   shapeVec.push_back
   (std::make_unique<Rhombus>(16, 'v', "Ace"));
   shapeVec.push_back
   (std::make_unique<AcuteTriangle>(17));
   shapeVec.push_back
   (std::make_unique<RightTriangle>(10, 'L'));

   // now, draw the shapes
   for (const auto& shp : shapeVec)
   {
      cout << shp->draw() << endl;
   }
   // referncing a unique_ptr object that point to a
   // concrete shape object, shp behaves like a pointer, 
   // calling the virtual function draw() polymorphically
   //------------------------------------------------------------
}
