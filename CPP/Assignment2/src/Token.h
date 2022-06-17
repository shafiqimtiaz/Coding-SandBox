#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class Token
{
private:
	/**
	* Token text
	*/
	string text;

	/**
	* Frequency of number of lines for object Token
	*/
	size_t frequency;

	/**
	* vector of number lines for object Token
	*/
	vector<size_t> line_number_list;

public:
	/**
	* Normal Constructor
	*/
	Token(string str, size_t line_num);

	/**
	* disables default construction
	*/
	Token() = delete;

	/**
	* Copy Constructor
	*/
	Token(const Token& source) = default;

	/**
	* Move Constructor
	*/
	Token(Token&& source) noexcept = default;

	/**
	* Copy Assignment Operator
	*/
	Token& operator=(const Token& rhs) = default;

	/**
	* Move Assignment Operator
	*/
	Token& operator=(Token&& rhs) noexcept = default;

	/**
	* Token Destructor
	*/
	virtual ~Token() = default;

	/**
	* @param the invoking Token object
	* @return the integer value returned by compare: >0 / 0 / <0
	*/
	int compare(const Token& other) const;

	/**
	* @param out - the Token ostream to be printed
	*/
	void print(ostream& out) const;

	/**
	* @return the token string from Token object
	*/
	string get_token_text() const;

	/**
	* @return the frequency of number_list from Token object
	*/
	size_t get_frequency() const;

	/**
	* @return the number_list vector of the Token object
	*/
	vector<size_t> get_number_list() const;

	/**
	* @return the length of the string from Token object
	*/
	size_t length() const;

	/**
	* increment the number of occurences of the Token
	*/
	void increment_freqency();

	/**
	* @param line_num - to be added to the Token object number_list
	*/
	void push_back_line_number(size_t line_num);

	/**
	* Helper Function - checks whether Token number_list contains passed Token
	*
	* @param numList - number_list vector to iterate over
	* @param check - passed Token ref to check if contained
	* @return bool if number_list contains passed Token or not
	*/
	bool contains(vector<size_t>& numList, const size_t& check);
};

/**
* @param out - the Token ostream to be printed
* @param token - the Token object ref
* @return Token ostream object ref
*/
ostream& operator<<(ostream& out, const Token& token);

/**
* Predicate to sort based on Token string
*
* @param first - first token
* @param second - second token
* @return bool based on the Token compare function
*/
bool operator<(const Token& first, const Token& second); // uses compare

/**
* Predicate to sort based on Token length
*
* @param t1 - first token
* @param t2 - second token
* @return bool based on the Token.length() function
*/
bool isShorter(const Token& first, const Token& second); //uses length

/**
* Predicate to sort based on Token frequency
*
* @param t1 - first token
* @param t2 - second token
* @return bool based on the Token.get_frequency() function
*/
bool isLessFrequent(const Token& first, const Token& second); // uses getFrequency

#endif