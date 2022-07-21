// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// Canvas.h


#ifndef Canvas_h
#define Canvas_h

#include <stdio.h>
#include <vector>
#include <ostream>

using std::vector;
using std::ostream;

class Canvas {
public:
  // All special members are defaulted because ’grid’,
  // the only data member, is self-sufficient and efficient; that is,
  // it is equipped to handle the corresponding operations efficiently
  Canvas()                         = default;
  virtual ~Canvas()                = default;
  Canvas(const Canvas&)            = default;
  Canvas(Canvas&&)                 = default;
  Canvas& operator=(const Canvas&) = default;
  Canvas& operator=(Canvas&&)      = default;

protected:
  vector<vector<char>> grid{};            // the only data member
  bool check(int r, int c) const;         // validates row r and column c
  void resize(size_t rows, size_t cols);  // resizes this Canvas’s dimensions

public:
  // Creates this canvas’s (rows x columns) grid filled with blank characters
  Canvas(int rows, int columns, char fillChar = ' '); 
  
  int getRows() const;                    // returns height of this Canvas object
  int getColumns() const;                 // returns width of this Canvas object
  Canvas flip_horizontal() const;         // flips this canvas horizontally
  Canvas flip_vertical() const;           // flips this canvas vertically
  void print(ostream&) const;             // prints this Canvas to ostream
  char get(int r, int c) const;           // returns char at row r and column c, 0-based;
                                          // throws std::out_of_range{ "Canvas index out of range" }
                                          // if r or c is invalid.
  void put(int r, int c, char ch);        // puts ch at row r and column c, 0-based;
                                          // the only function used by a shape’s draw functon;
                                          // throws std::out_of_range{ "Canvas index out of range" }
                                          // if r or c is invalid.
    
  // Draws text starting at row r and col c on the canvas
  void drawString(int r, int c, const std::string text);  
  
  // Copies the non-blank characters of "can" onto the invoking Canvas object;
  // Maps can’s origin to row r and column c on the invoking canvas
  void overlap(const Canvas& can, size_t r, size_t c); 
};

ostream& operator<< (ostream& sout, const Canvas& can);

#endif // Canvas_h
