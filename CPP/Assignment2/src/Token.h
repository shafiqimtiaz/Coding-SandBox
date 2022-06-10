#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;

class Token
{
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
	* @return the char pointer of the Token object
	*/
	string get_token_text() const;

	/**
	* @param the line_num integer to be added to the Token object number_list
	*/
	void push_back_line_number(size_t line_num);

	/**
	* @return the length of the Token char array
	*/
	size_t length() const;

	/**
	* @return the frequency of the Token
	*/
	size_t get_frequency() const;

	/**
	* @param sout - the Token ostream to be printed
	*/
	void print(ostream& out) const;

	/**
	* @return the number_list of the Token object
	*/
	vector<size_t> get_number_list() const;

	/**
	* increments this token's frequency
	*/
	void increment_freqency();

	/**
	* @param the invoking Token object
	* @return the integer value returned by strcmp - 0 / 1 / -1
	*/
	int compare(const Token& other) const;

	bool contains(vector<size_t>& numList, const size_t& check);

private:
	string text;
	size_t frequency;
	vector<size_t> line_number_list;
};

/**
* @param out - the Token ostream to be printed
* @param token - the Token object ref
* @return Token ostream object ref
*/
ostream& operator<<(ostream& out, const Token& token);

/**
* @param out - the Token ostream to be printed
* @param vec - the Token object ref
* @return Vector ostream object ref
*/
ostream& operator<<(ostream& out, const vector<size_t> vec);

bool operator<(const Token& t1, const Token& t2); // uses compare
bool isShorter(const Token& first, const Token& second); //uses length
bool isLessFrequent(const Token& first, const Token& second); // uses getFrequency

#endif