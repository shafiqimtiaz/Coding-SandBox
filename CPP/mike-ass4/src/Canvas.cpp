// COMP5421 - Asg4 - Summer 2022
// Mike Poullas - 21917739
// Canvas.cpp


#include <iostream>
#include "Canvas.h"

using std::string;
using std::cout;

// Validates row r and column c, 0-based
bool Canvas::check(int r, int c) const {

  // Return true or false if row r and column c are within boundries
  return (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
} 

// Resizes this Canvas’s dimensions
void Canvas::resize(size_t rows, size_t cols) {
  
  for (auto& grid_row : grid) 
    grid_row.resize(cols, ' ');
  
  grid.resize(rows, std::vector<char>(cols, ' '));
  
}

// Canvas initilaizer. Creates this canvas’s (rows x columns) grid filled with blank characters
Canvas::Canvas(int rows, int columns, char fillChar) : 
  grid{ vector<vector<char>>(rows, vector<char>(columns, fillChar)) } {}; 

// Returns height of this Canvas object
int Canvas::getRows() const {

  return grid.size();
} 

// Returns width of this Canvas object
int Canvas::getColumns() const {
  
  return grid[0].size();
} 

// Flips this canvas horizontally
Canvas Canvas::flip_horizontal() const {
  
    Canvas flipped{ grid.size(), grid[0].size() };
  
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0, i = grid[0].size() - 1; c < grid[0].size(); ++c, --i) {
            flipped.put(r, i, grid[r][c]);
        }
    }
    return flipped;
}

// Flips this canvas vertically
Canvas Canvas::flip_vertical() const { 
  
    Canvas flipped{ grid.size(), grid[0].size() };
  
    for (int r = 0, i = grid.size() - 1; r < grid.size(); ++r, --i) {
        for (int c = 0; c < grid[0].size(); ++c) {
            flipped.put(i, c, grid[r][c]);
        }
    }
    return flipped;
}

// Prints to ostream
void Canvas::print(ostream& sout) const { 
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            sout << grid[r][c];
        }
        sout << std::endl;
    }
};

// returns char at row r and column c, 0-based;
// throws std::out_of_range{ "Canvas index out of range" }
// if r or c is invalid.
char Canvas::get(int r, int c) const {

  if (check(r, c))
    return grid[r][c];
  else
    throw std::out_of_range{ "Canvas index out of range" };
} 

// Puts ch at row r and column c, 0-based;
// the only function used by a shape’s draw functon;
// throws std::out_of_range{ "Canvas index out of range" }
// if r or c is invalid.
void Canvas::put(int r, int c, char ch) {
  
  if (check(r, c)) 
    grid[r][c] = ch;
  else 
    throw std::out_of_range{ "Canvas index out of range" };    
} 

// draws text starting at row r and col c on this canvas
void Canvas::drawString(int r, int c, const std::string text) {

  for (size_t i = 0; i < text.size(); ++i) {
    put(r, c, text[i]);
    ++c;
  }
}

// copies the non-blank characters of "can" onto the invoking Canvas object;
// maps can’s origin to row r and column c on the invoking Canvas object
void Canvas::overlap(const Canvas& can, size_t r, size_t c) {
  
    for (int r1 = 0; r1 < can.getRows(); ++r1)
        for (int c1 = 0; c1 < can.getColumns(); ++c1)
            if (can.get(r1, c1) != ' ') 
              put(r+r1, c+c1, can.get(r1, c1));
}

ostream& operator<< (ostream& sout, const Canvas& can) {
  
    for (int r = 0; r < can.getRows(); ++r) {
        for (int c = 0; c < can.getColumns(); ++c) {
            sout << can.get(r, c);
        }
        sout << std::endl;
    }
    return sout;
}
