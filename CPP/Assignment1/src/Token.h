#ifndef TOKEN_H
#define TOKEN_H

#include "ArrayList.h"
using std::ostream;

class Token
{
public:
	Token(const char* cstr, int line_num); // normal ctor
	Token() = delete;
	Token(const Token& token); // copy ctor
	Token(Token&& token) noexcept; // move ctor
	Token& operator=(const Token& rhs); // copy assignment
	Token& operator=(Token&& rhs) noexcept; // move assignment
	virtual ~Token(); // virtual dtor

	const char* c_str() const;
	void addLineNumber(int line_num);
	size_t size() const;
	void print(ostream& sout) const;
	const ArrayList& getNumberList() const;
	int compare(const Token& aToken) const;

private:
	char* cstr;
	int frequency;
	ArrayList number_list;
};

ostream& operator<<(ostream& sout, const Token& token);

#endif