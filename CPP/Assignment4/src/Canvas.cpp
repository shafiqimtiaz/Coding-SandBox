#include "Canvas.h"

/**
Creates this canvas's (rows x columns) grid filled with blank characters
*/
Canvas::Canvas(int rows, int columns, char fillChar) {
	for (int i = 0; i < rows; ++i) {
		vector<char> gridCol;
		for (int j = 0; j < columns; j++) {
			gridCol.push_back(fillChar);
		}
		grid.push_back(gridCol);
	}
}

/**
Validates row r and column c, 0-based
* @return true or false absed on r and c
*/
bool Canvas::check(int r, int c) const {
	return (0 <= r && r < getRows() && 0 <= c && c < getColumns());
}

/**
Resizes this Canvas's dimensions
*/
void Canvas::resize(size_t rows, size_t cols) {
	grid.resize(rows);
	for (auto& vec : grid) {
		vec.resize(cols);
	}
}

/**
* @return height of Canvas object
*/
int Canvas::getRows() const {
	return grid.size();
}

/**
* @return width of Canvas object
*/
int Canvas::getColumns() const {
	int col = 0;
	for (auto& vec : grid) {
		col = vec.size() > col ? vec.size() : col;
	}
	return col;
}

/**
* @return char at row r and column c, 0-based index
*/
char Canvas::get(int r, int c) const {
	if (!check(r, c)) {
		throw std::out_of_range{ "Canvas index out of range" };
	}
	else return grid[r][c];
}

/**
Puts ch at row r and column c, , 0-based index
*/
void Canvas::put(int row, int col, char ch) {
	if (!check(row, col)) {
		throw std::out_of_range{ "Canvas index out of range" };
	}
	else grid[row][col] = ch;
}

/**
Draws text starting at row rand col c on this canvas
*/
void Canvas::drawString(int r, int c, const std::string text) {
	for (char ch : text) {
		put(r, c, ch);
		++c; // move to next char in string
	}
}

/**
* @return horizontally flipped canvas
*/
Canvas Canvas::flip_horizontal() const {
	Canvas newCan{ getRows(), getColumns() };

	for (int row = 0; row < getRows(); ++row) {
		int last = getColumns() - 1; // fetch last column
		for (int col = 0; col < getColumns(); ++col) {
			newCan.put(row, last, grid[row][col]);
			--last; // decrement last column element
		}
	}
	return newCan;
}

/**
* @return vertically flipped canvas
*/
Canvas Canvas::flip_vertical() const {
	Canvas newCan{ getRows(), getColumns() };

	int last = getRows() - 1; // fetch last row
	for (int row = 0; row < getRows(); ++row) {
		for (int col = 0; col < getColumns(); ++col) {
			newCan.put(last, col, grid[row][col]);
		}
		--last; // decrement last row element
	}
	return newCan;
}

/**
Copies the non-blank characters of "can" onto the invoking Canvas object;
maps can's origin to row r and column c on the invoking Canvas object
*/
void Canvas::overlap(const Canvas& can, size_t r, size_t c) {

	// checks if the total size of canvas after overlap exceeds current canvas size
	if (can.getRows() + r > getRows() || can.getColumns() + c > getColumns()) {
		// if true, resize the current canvas to new size
		this->resize(getRows() + can.getRows(), getColumns() + can.getColumns());
	}

	// overlapping loop
	for (int row = 0; row < can.getRows(); ++row) {
		for (int col = 0; col < can.getColumns(); ++col) {
			if (can.get(row, col) != ' ') {
				put(r + row, c + col, can.get(row, col));
			}
		}
	}
}

/**
Prints this Canvas to ostream
*/
void Canvas::print(ostream& sout) const {
	for (auto& row : grid) {
		for (char ch : row) {
			sout << ch;
		}
		sout << endl;
	}
}

/**
Overloaded output operator << to print canvas obhject
* @param canvas object to print
* @return output stream with canvas object info
*/
ostream& operator<< (ostream& sout, const Canvas& can) {
	can.print(sout);
	return sout;
}