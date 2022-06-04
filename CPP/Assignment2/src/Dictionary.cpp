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
	int lineNumber = 0;
	string line;
	getline(fin, line); // first attempt to read, this first attempt will get the i/o flags initialized
	while (fin)
	{
		++lineNumber; // count the line
		istringstream sin(line); // turn the line into an input string stream
		string tokenStr;
		while (sin >> tokenStr) // extract token strings
		{
			push_back_into_bucket(tokenStr, lineNumber); // process the token
		}
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