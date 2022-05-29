#ifndef TOKEN_H
#define TOKEN_H

#include "ArrayList.h"
using std::ostream;

class Token
{
public:

	/**
	* Normal Constructor
	*/
	Token(const char* cstr, int line_num);

	/**
	* default constructor = delete
	*/
	Token() = delete;

	/**
	* Copy Constructor
	*/
	Token(const Token& token);

	/**
	* Move Constructor
	*/
	Token(Token&& token) noexcept;

	/**
	* Copy Assignment Operator
	*/
	Token& operator=(const Token& rhs);

	/**
	* Move Assignment Operator
	*/
	Token& operator=(Token&& rhs) noexcept;

	/**
	* Token Destructor
	*/
	virtual ~Token();

	/**
	* @return the char pointer of the Token object
	*/
	const char* c_str() const;

	/**
	* @param the line_num integer to be added to the Token object number_list
	*/
	void addLineNumber(int line_num);

	/**
	* @return the length of the Token char array
	*/
	size_t size() const;

	/**
	* @param sout - the Token ostream to be printed
	*/
	void print(ostream& sout) const;

	/**
	* @return the number_list of the Token object
	*/
	const ArrayList& getNumberList() const;

	/**
	* @param the invoking Token object
	* @return the integer value returned by strcmp - 0 / 1 / -1
	*/
	int compare(const Token& aToken) const;


private:
	char* cstr;
	int frequency;
	ArrayList number_list;
};

/**
* @param sout - the Token ostream to be printed
* @param token - the Token object ref
* @return Token ostream object ref
*/
ostream& operator<<(ostream& sout, const Token& token);

#endif