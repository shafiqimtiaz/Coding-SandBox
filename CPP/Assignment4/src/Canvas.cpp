#include "Canvas.h"
#include <iterator>

Canvas::Canvas(int rows, int columns, char fillChar)
{
	for (int i = 0; i < rows; ++i)
	{
		vector<char> gridCol;
		for (int j = 0; j < columns; j++)
		{
			gridCol.push_back(fillChar);
		}
		grid.push_back(gridCol);
	}
}

bool Canvas::check(int r, int c) const
{
	return (0 <= r && r < getRows() && 0 <= c && c < getColumns());
}

void Canvas::resize(size_t rows, size_t cols)
{
	grid.resize(rows);
	for (auto& vec : grid) {
		vec.resize(cols);
	}
}

int Canvas::getRows() const
{
	return grid.size();
}

int Canvas::getColumns() const
{
	int col = 0;
	for (auto& vec : grid)
	{
		col = vec.size() > col ? vec.size() : col;
	}
	return col;
}

char Canvas::get(int r, int c) const {
	if (!check(r, c))
	{
		throw std::out_of_range{ "Canvas index out of range" };
	}
	else return grid[r][c];
}

void Canvas::put(int row, int col, char ch) {
	if (!check(row, col))
	{
		throw std::out_of_range{ "Canvas index out of range" };
	}
	else grid[row][col] = ch;
}

void Canvas::drawString(int r, int c, const std::string text) {
	string str{ text };
	string::iterator itr;
	itr = str.begin();
	while (itr != str.end()) {
		put(r, c, *itr);
		c++;
		itr++;
	}
}

Canvas Canvas::flip_horizontal() const {
	Canvas newCan{ *this };
	for (auto& vec : newCan.grid) {
		vector<char>::iterator first = vec.begin();
		vector<char>::iterator last = vec.end();
		while ((first != last) && (first != --last)) {
			std::iter_swap(first, last);
			++first;
		}
	}
	return newCan;
}

Canvas Canvas::flip_vertical() const {
	Canvas newCan{ *this };

	vector<vector<char>>::iterator first = newCan.grid.begin();
	vector<vector<char>>::iterator last = newCan.grid.end();
	while ((first != last) && (first != --last)) {
		std::iter_swap(first, last);
		++first;
	}
	return newCan;
}

void Canvas::overlap(const Canvas& can, size_t r, size_t c) {

	resize(getRows() + can.getRows(), getColumns() + can.getColumns());

	size_t n = 0;  // starting row
	size_t m = 0;  // starting col

	for (size_t i = r; i < getRows(); i++) {
		if (n < can.getRows())
		{
			for (size_t j = c; j < getColumns(); j++) {
				if (m < can.getColumns())
				{
					put(i, j, can.get(n, m));
				}
				m++;
			}
		}
		n++;
		m = 0;
	}
}

void Canvas::print(ostream& sout) const
{
	for (auto& row : grid)
	{
		for (char ch : row)
		{
			sout << ch;
		}
		sout << endl;
	}
}

ostream& operator<< (ostream& sout, const Canvas& can)
{
	can.print(sout);
	return sout;
}