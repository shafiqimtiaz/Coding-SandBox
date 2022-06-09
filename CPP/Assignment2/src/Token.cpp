#include <iostream>
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
* @param str - string text for Token
* @param line_num - the integer value to be inserted in the list
*/
Token::Token(string str, size_t line_num)
	: text{}, frequency{ 1 }, line_number_list{}
{
	text = str; // copies the passed str to object text
	line_number_list.push_back(line_num); // inserts the line_num in the line_number_list
}

/**
* @return the char pointer of the Token object
*/
string Token::get_token_text() const
{
	return text;
}

/**
* @return the length of the Token char array
*/
size_t Token::length() const
{
	return text.length();
}

/**
* @return the frequency of the Token
*/
size_t Token::get_frequency() const
{
	return frequency;
}

/**
* @return the number_list of the Token object
*/
vector<size_t> Token::get_number_list() const
{
	return line_number_list;
}

/**
* @param the line_num integer to be added to the Token object number_list
*/
void Token::push_back_line_number(size_t line_num)
{
	vector<size_t> numList = get_number_list();
	if (!contains(numList, line_num))
	{
		line_number_list.push_back(line_num);
		increment_freqency(); // increment the number of occurences of the Token
	}
}

/**
* increments this token's frequency
*/
void Token::increment_freqency()
{
	frequency++; // increment the number of occurences of the Token
}

/**
* @param the invoking Token object
* @return the integer value returned by strcmp - 0 / 1 / -1
*/
int Token::compare(const Token& other) const
{
	return text.compare(other.text);
}

/**
* @param sout - the Token ostream to be printed
*/
void Token::print(ostream& out) const
{
	out << text << " (" << frequency << ") ";
	out << line_number_list;
}

/**
* @param sout - the Token ostream to be printed
* @param token - the Token object ref
* @return Token ostream object ref
*/
ostream& operator<<(ostream& out, const Token& token)
{
	token.print(out);
	return out;
}

/**
* @param out - the Token ostream to be printed
* @param vec - the Token object ref
* @return Vector ostream object ref
*/
ostream& operator<<(ostream& out, const vector<size_t> vec)
{
	for (size_t i : vec)
	{
		out << i << " ";
	}
	return out;
}

bool operator<(const Token& t1, const Token& t2)
{
	if (t1.compare(t2) < 0)	return true;
	else return false;
}

bool isShorter(const Token& first, const Token& second)
{
	if (first.length() < second.length()) return true;
	if (first.length() > second.length()) return false;
	// since the two suppplied tokens are of the same length
	// we order them lexicography.
	// return (first.compare(second) < 0);
	// or, equivalently
	if (first.compare(second) < 0) return true;

	return false;
}


bool isLessFrequent(const Token& first, const Token& second)
{
	if (first.get_frequency() < second.get_frequency()) return true;
	if (first.get_frequency() > second.get_frequency()) return false;

	return false;
}

bool Token::contains(vector<size_t>& numList, const size_t& check)
{
	for (auto& num : numList)
	{
		if (num == check)
		{
			return true;
			break;
		}
	}
	return false;
}