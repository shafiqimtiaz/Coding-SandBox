#include "Token.h"

/**
* Normal Constructor
* Creates the specified Token object
*
* @param str - string text for Token
* @param line_num - the integer value to be inserted in the list
*/
Token::Token(string str, size_t line_num)
	: text{ str }, frequency{ 1 }
{
	// inserts the line_num in the line_number_list
	line_number_list.push_back(line_num);
}

/**
* @param the invoking Token object
* @return the integer value returned by compare: >0 / 0 / <0
*/
int Token::compare(const Token& other) const
{
	return text.compare(other.text); // using the string compare
}

/**
* @param out - the Token ostream to be printed
*/
void Token::print(ostream& out) const
{
	// print Token string and frequency
	out << text << " (" << frequency << ") ";

	// print line_number_list vector
	vector<size_t> vec = line_number_list;
	for (size_t i : vec)
	{
		out << i << " ";
	}
}

/**
* @return the token string from Token object
*/
string Token::get_token_text() const
{
	return text;
}

/**
* @return the frequency of number_list from Token object
*/
size_t Token::get_frequency() const
{
	return frequency;
}

/**
* @return the number_list vector of the Token object
*/
vector<size_t> Token::get_number_list() const
{
	return line_number_list;
}

/**
* @return the length of the string from Token object
*/
size_t Token::length() const
{
	return text.length();
}

/**
* increment the number of occurences of the Token
*/
void Token::increment_freqency()
{
	frequency++;
}

/**
* @param line_num - to be added to the Token object number_list
*/
void Token::push_back_line_number(size_t line_num)
{
	vector<size_t> numList = get_number_list();
	if (!contains(numList, line_num))
	{
		// push_back the line_num in line_number_list
		line_number_list.push_back(line_num);

		// increment the number of occurences of the Token
		increment_freqency();
	}
}

/**
* Helper Function - checks whether Token number_list contains passed Token
*
* @param numList - number_list vector to iterate over
* @param check - passed Token ref to check if contained
* @return bool if number_list contains passed Token or not
*/
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


/**
* @param out - the Token ostream to be printed
* @param token - the Token object ref
* @return Token ostream object ref
*/
ostream& operator<<(ostream& out, const Token& token)
{
	token.print(out);
	return out;
}

/**
* Predicate to sort based on Token string
*
* @param first - first token
* @param second - second token
* @return bool based on the Token compare function
*/
bool operator<(const Token& first, const Token& second)
{
	if (first.compare(second) < 0)	return true;
	else return false;
}

/**
* Predicate to sort based on Token length
*
* @param t1 - first token
* @param t2 - second token
* @return bool based on the Token.length() function
*/
bool isShorter(const Token& first, const Token& second)
{
	if (first.length() < second.length()) return true;
	if (first.length() > second.length()) return false;
	if (first.compare(second) < 0) return true;

	return false;
}

/**
* Predicate to sort based on Token frequency
*
* @param t1 - first token
* @param t2 - second token
* @return bool based on the Token.get_frequency() function
*/
bool isLessFrequent(const Token& first, const Token& second)
{
	if (first.get_frequency() < second.get_frequency()) return true;
	if (first.get_frequency() > second.get_frequency()) return false;

	return false;
}