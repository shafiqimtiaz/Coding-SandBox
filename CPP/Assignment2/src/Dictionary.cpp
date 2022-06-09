#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Dictionary.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::string;
using std::ifstream;
using std::istringstream;
using std::setw;

/**
* Normal Constructor
* Creates the specified Dictionary object
*
* @param fiename - name of the file to be read
*/
Dictionary::Dictionary(const string& filename, const string& separators) : filename(filename)
{
	ifstream fin(filename); // create an input file stream

	if (!fin)
	{
		cout << "could not open input file: " << filename << endl;
		exit(1);
	}
	size_t lineNumber = 1;
	string line;
	getline(fin, line); // first attempt to read, this first attempt will get the i/o flags initialized

	while (fin)
	{
		input_lines.push_back(line); // push line in lineVec
		++lineNumber; // count the line

		extract_and_push(line, lineNumber);

		getline(fin, line); // attempt to read the next line, if any
	}
	fin.close();
}

/**
* @param token - the token string to be checked index for
* @return size_t index position of the token string in the Dictionary bucket
*/
size_t Dictionary::bucketIndex(const string& tokenText) const
{
	size_t index = 26; // bucket index for tokens not beginning with a letter
	if (isalpha(tokenText[0]))
	{
		if (isupper(tokenText[0])) index = (size_t)tokenText[0] - 'A';
		else index = (size_t)tokenText[0] - 'a';
	}
	return index;
}

/**
* @param token - the token string to be inserted
* @param lineNumber - the line number of the Token
*/
void Dictionary::push_back_into_bucket(const string& tokenText, size_t line_number)
{
	size_t i = bucketIndex(tokenText);
	token_list_buckets[i].push_back(Token{ tokenText, line_number });
}

vector<string> Dictionary::extract_tokens_from_line(const string& line) const
{
	vector<string> lineVec;
	istringstream sin(line); // turn the line into an input string stream
	string tokenStr;

	while (sin >> tokenStr) // extract token strings
	{
		lineVec.push_back(tokenStr);
	}

	return lineVec;
}

void Dictionary::extract_and_push(const string& line, size_t line_number)
{
	vector<string> tokenVec = extract_tokens_from_line(line);

	for (const string& tokenStr : tokenVec)
	{
		size_t i = bucketIndex(tokenStr);
		Token checkToken{ tokenStr, line_number };

		if (contains(token_list_buckets[i], checkToken))
		{
			getToken(token_list_buckets[i], checkToken).push_back_line_number(line_number);
		}
		else
		{
			push_back_into_bucket(tokenStr, line_number); // process the token
		}
	}
}

void Dictionary::print_input_lines() const
{
	size_t lineNum = 1;
	for (const string& line : input_lines)
	{
		cout << lineNum << " : " << line << "\n";
		++lineNum;
	}
}

void Dictionary::print_input_tokens() const
{
	for (const string& line : input_lines)
	{
		istringstream sin(line);
		vector<string> tokenVec = extract_tokens_from_line(line);

		for (const string& tokenStr : tokenVec)
		{
			cout << setw(20) << tokenStr << "\n";
		}
	}
}



/**
* @param sout - the Dictionary ostream to be printed
*/
void Dictionary::print(ostream& sout) const
{
	for (int i = 0; i < 27; ++i)
	{
		if (i == 26) cout << "<>" << "\n";
		else cout << "<" << char(i + 'A') << ">" << "\n";

		for (const Token& tlist : token_list_buckets[i])
		{
			cout << setw(20) << tlist << "\n";
		}

		cout << "\n";
	}
}

/**
* @param sout - the Dictionary ostream to be printed
* @param dictionary - the Dictionary object ref
* @return Dictionary ostream object ref
*/
ostream& operator<<(ostream& sout, const Dictionary& dictionary)
{
	dictionary.print(sout);
	return sout;
}

/**************************************************************/

bool Dictionary::contains(list<Token>& tokenList, Token& check)
{
	for (list<Token>::iterator it = tokenList.begin(); it != tokenList.end(); ++it)
	{
		if ((*it).compare(check) == 0)
		{
			return true;
			break;
		}
	}
	return false;
}

Token& Dictionary::getToken(list<Token>& tokenList, Token& check)
{
	for (list<Token>::iterator it = tokenList.begin(); it != tokenList.end(); ++it)
	{
		if ((*it).compare(check) == 0)
		{
			return (*it);
			break;
		}
	}
	return check;
}