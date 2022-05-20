#ifndef TOKEN_H
#define TOKEN_H

#include "ArrayList.h"
using std::ostream;

class Token
{
public:
	Token(const char* cstr, int line_num);
	Token() = delete;
	Token(const Token& token);
	Token(Token&& token) noexcept;
	Token& operator=(const Token& rhs);
	Token& operator=(Token&& rhs) noexcept;
	virtual ~Token();

	const char* c_str() const;
	void addLineNumber(int line_num);
	void print(ostream& sout) const;

private:
	char* cstr;
	int frequency;
	ArrayList number_list;
};

ostream& operator<<(ostream& sout, const Token& token);

#endif