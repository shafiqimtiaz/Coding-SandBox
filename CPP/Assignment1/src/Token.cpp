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

/**
* Normal Constructor
* Creates the specified Token object
*
* @param cstr - char pointer for Token string
* @param line_num - the integer value to be inserted in the list
*/
Token::Token(const char* cstr, int line_num)
	: cstr{ new char[strlen(cstr) + 1] }, frequency{ 1 }, number_list{}
{
	// copies the passed cstr to object cstr
	strcpy(this->cstr, cstr);

	// inserts the line_number in the number_list
	number_list.pushBack(line_num);
}

/**
* Copy Constructor
* Creates the specified Token object by copying the invoking Token object
*
* @param token - The specified Token object
*/
Token::Token(const Token& token)
	: cstr{ new char[strlen(token.cstr) + 1] }, frequency{ token.frequency }, number_list{ token.number_list }
{
	// copies the passed token.cstr to object cstr
	strcpy(cstr, token.cstr);
}

/**
* Move Constructor
* Creates the specified Token object by moving the invoking Token object
*
* @param token - The specified Token object
*/
Token::Token(Token&& token) noexcept
	: cstr{ token.cstr }, frequency{ token.frequency }, number_list{ move(token.number_list) }
{
	// resetting the already moved token object to a safe state
	token.cstr = new char[1];
	token.cstr[0] = NULL;
	token.frequency = 0;
}

/**
* Copy Assignment Operator
* Copies a specified Token object to the invoking Token object
*
* @param rhs - The specified Token object
* @return The invoking Token object
*/
Token& Token::operator=(const Token& rhs)
{
	// checking for self assignment
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

/**
* Move Assignment Operator
* Moves a specified Token object to the invoking Token object
*
* @param rhs - The specified Token object
* @return The invoking Token object
*/
Token& Token::operator=(Token&& rhs) noexcept
{
	// checking for self assignment
	if (&rhs != this)
	{
		delete[] cstr;

		cstr = rhs.cstr;
		frequency = rhs.frequency;
		number_list = move(rhs.number_list);

		// resetting the already moved token object to a safe state
		rhs.cstr = new char[1];
		rhs.cstr[0] = NULL;
		rhs.frequency = 0;
	}
	return *this;
}

/**
* Token Destructor
*
* Destroys the Token object by clearing cstr memory from heap
* at the end of execution scope
*/
Token::~Token()
{
	delete[] cstr;
}

/**
* @return the char pointer of the Token object
*/
const char* Token::c_str() const
{
	return cstr;
}

/**
* @return the length of the Token char array
*/
size_t Token::size() const
{
	return strlen(cstr);
}

/**
* @return the number_list of the Token object
*/
const ArrayList& Token::getNumberList() const
{
	return number_list;
}

/**
* @param the line_num integer to be added to the Token object number_list
*/
void Token::addLineNumber(int line_num)
{
	number_list.pushBack(line_num);

	// increment the number of occurences of the Token
	frequency++;
}

/**
* @param the invoking Token object
* @return the integer value returned by strcmp - 0 / 1 / -1
*/
int Token::compare(const Token& aToken) const
{
	if (cstr != NULL)
	{
		return strcmp(cstr, aToken.cstr);
	}
	else
	{
		return NULL;
	}
}

/**
* @param sout - the Token ostream to be printed
*/
void Token::print(ostream& sout) const
{
	sout << cstr << " (" << frequency << ") ";
	number_list.print(sout);
}

/**
* @param sout - the Token ostream to be printed
* @param token - the Token object ref
* @return Token ostream object ref
*/
ostream& operator<<(ostream& sout, const Token& token)
{
	token.print(sout);
	return sout;
}