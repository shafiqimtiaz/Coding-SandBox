#pragma warning(disable : 4996) // to use strcpy

#include <iostream>
#include <cctype>
#include <cstring>
#include "Token.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;

/*
* Normal Constructor
*/
Token::Token(const char* cstr, int line_num)
	: cstr {new char[strlen(cstr)+1]}, frequency{1}, number_list{}
{
	strcpy(this->cstr, cstr);
	number_list.pushBack(line_num);
}

/*
* Copy Constructor
*/
Token::Token(const Token& token)
{
	//cout << "Token Copy Ctor" << endl;

	delete[] cstr;
	cstr = new char[strlen(token.cstr) + 1];

	strcpy(cstr, token.cstr);
	frequency = token.frequency;
	number_list = token.number_list;
}

/*
* Move Constructor
*/
Token::Token(Token&& token) noexcept
	: cstr{token.cstr}, frequency{token.frequency}, number_list{move(token.number_list)}
{
	//cout << "Token Move Ctor" << endl;

	token.cstr = new char[1];
	token.cstr[0] = NULL;
	token.frequency = 0;
}

/*
* Copy Assignment Operator
*/
Token& Token::operator=(const Token& rhs)
{
	//cout << "Token Copy Ass Op" << endl;
	if (&rhs != this)
	{
		delete[] cstr;
		cstr = new char[strlen(rhs.cstr) + 1];

		strcpy(cstr, rhs.cstr);
		frequency = rhs.frequency;
		number_list = rhs.number_list;
	}
	return *this;
}

/*
* Move Assignment Operator
*/
Token& Token::operator=(Token&& rhs) noexcept
{
	//cout << "Token Move Ass Op" << endl;
	if (&rhs != this)
	{
		delete[] cstr;

		cstr = rhs.cstr;
		frequency = rhs.frequency;
		number_list = move(rhs.number_list);

		rhs.cstr = new char[1];
		rhs.cstr[0] = NULL;
		rhs.frequency = 0;
	}
	return *this;
}

/*
* Destructor
*/
Token::~Token()
{
	delete[] cstr;
}

const char* Token::c_str() const
{
	return cstr;
}

size_t Token::size() const
{
	return strlen(cstr);
}

const ArrayList& Token::getNumberList() const
{
	return number_list;
}


void Token::addLineNumber(int line_num)
{
	number_list.pushBack(line_num);
	frequency++;
}

int Token::compare(const Token& aToken) const
{
	if (strcmp(cstr, aToken.cstr) > 0) return 1;
	else if (strcmp(cstr, aToken.cstr) < 0) return -1;
	else return 0;
}

void Token::print(ostream& sout) const
{
	if (strlen(cstr) > 0 && number_list.size() > 0)
	{
		sout << cstr << "\t(" << frequency << ") ";
		number_list.print(sout);
	}
	else
	{
		sout << "";
	}
}

ostream& operator<<(ostream& sout, const Token& token)
{
	token.print(sout);
	return sout;
}