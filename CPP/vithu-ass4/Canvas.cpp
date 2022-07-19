//
// Created by Vithu Maheswaran on 2022-07-11.
//
#include <iterator>
#include "Canvas.h"

// validates row r and column c, 0-based
bool Canvas::check(int r, int c) const {
    return (0 <= r && r < getRows() && 0 <= c && c < getColumns());
}

// resizes this Canvas’s dimensions
void Canvas::resize(size_t rows, size_t cols) {
    grid.resize(rows);
    for (auto &vec: grid) {
        vec.resize(cols, ' ');
    }
}

// creates this canvas’s (rows x columns) grid filled with blank characters
Canvas::Canvas(int rows, int columns, char fillChar) {

    for (int i = 0; i < rows; i++) {
        vector<char> r;
        for (int j = 0; j < columns; j++) {
            r.push_back(fillChar);
        }
        grid.push_back(r);
    }
}

int Canvas::getRows() const { return grid.size(); }             // returns height of this Canvas object

// returns width of this Canvas object
int Canvas::getColumns() const {
    size_t cols{};
    for (auto vec: grid) {
        cols = vec.size() > cols ? vec.size() : cols;
    }
    return cols;
}

// Private Helper Function
// Reverse vector<char>'s in vector<vector<char>> object
void Canvas::reverseV(vector<vector<char>>::iterator first, vector<vector<char>>::iterator last) {
    while ((first != last) && (first != --last)) {
        std::iter_swap(first, last);
        ++first;
    }
}

// Private Helper Function
// Reverse char's in vector<char> object
void Canvas::reverseH(vector<char>::iterator first, vector<char>::iterator last) {
    while ((first != last) && (first != --last)) {
        std::iter_swap(first, last);
        ++first;
    }
}


// flips this canvas horizontally
Canvas Canvas::flip_horizontal() const {
    Canvas newCan{*this};
    for (auto &vec: newCan.grid) {
        vector<char>::iterator first = vec.begin();
        vector<char>::iterator last = vec.end();
        while ((first != last) && (first != --last)) {
            std::iter_swap(first, last);
            ++first;
        }
    }
    return newCan;
}

// flips this canvas vertically
Canvas Canvas::flip_vertical() const {
    Canvas newCan{*this};

    vector<vector<char>>::iterator first = newCan.grid.begin();
    vector<vector<char>>::iterator last = newCan.grid.end();
    while ((first != last) && (first != --last)) {
        std::iter_swap(first, last);
        ++first;
    }
    return newCan;
}

// prints this Canvas to ostream
void Canvas::print(ostream &sout) const {
    for (auto r: grid) {
        for (char ch: r) {
            sout << ch;
        }
        sout << endl;
    }
}

// throws std::out_of_range{ "Canvas index out of range" }
//if r or c is invalid.
// returns char at row r and column c, 0-based;
char Canvas::get(int r, int c) const {
    if (!check(r, c)) {
        throw std::out_of_range{"Canvas index out of range"};
    }
    return grid[r][c];
}

// puts ch at row r and column c, 0-based;
// the only function used by a shape’s draw functon;
// throws std::out_of_range{ "Canvas index out of range" }
//if r or c is invalid.
void Canvas::put(int row, int col, char ch) {
    if (!check(row, col)) {
        throw std::out_of_range{"Canvas index out of range"};
    }
    grid[row][col] = ch;
}

// draws text starting at row r and col c on this canvas
void Canvas::drawString(int r, int c, const std::string text) {
    string str{text};
    string::iterator itr;
    itr = str.begin();
    while (itr != str.end()) {
        put(r, c, *itr);
        c++;
        itr++;
    }
}

// copies the non-blank characters of "can" onto the invoking Canvas object;
// maps can’s origin to row r and column c on the invoking Canvas object
void Canvas::overlap(const Canvas &can, size_t r, size_t c) {

    resize(getRows() + can.getRows(), getColumns() + can.getColumns());

    int n = 0;  // starting row
    int m = 0;  // starting col

    for (int i = r; i < getRows(); i++) {   // this row
        if (n < can.getRows()) {
            for (int j = c; j < getColumns(); j++) {    // this col
                if (m < can.getColumns() && can.get(n, m) != ' ') {
                    put(i, j, can.get(n, m));
                }
                m++;
            }
        }
        n++;
        m=0;
    }
}

ostream &operator<<(ostream &sout, const Canvas &can) {
    can.print(sout);
    return sout;
}