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

using std::tolower;
using std::toupper;

#include <array>
using std::array;

/**
* Normal Constructor
* Creates the specified Dictionary object
*
* @param fiename - name of the file to be read
*/
Dictionary::Dictionary(const string& filename, const string& separators) : filename(filename), theSeparators(separators)
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

	// find the start index of first token, if any
	size_t sndx{ line.find_first_not_of(theSeparators) };

	while (sndx != string::npos) // while there are tokens
	{ // find the end of current token that starts at sndx
		size_t endIndex = line.find_first_of(theSeparators, sndx + 1);

		// did we find a separator or did we reach the of line?
		if (endIndex == string::npos)
		{ // we did reach the of line, so set sndx to end of line
			endIndex = line.length();
		}
		// extract the token
		string token{ line.substr(sndx, endIndex - sndx) };
		// again, find the start index of next token, if any
		sndx = line.find_first_not_of(theSeparators, endIndex + 1);

		lineVec.push_back(token); // push the token into lineVec
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

void Dictionary::print_input_lines(set<char>& char_set) const
{
	for (const char& s : char_set)
	{
		cout << s << " ";
	}
	cout << "\n";

	size_t lineNum = 1;
	for (const string& line : input_lines)
	{
		for (const char& c : char_set)
		{
			if (toupper(line[0]) == c || tolower(line[0]) == c)
			{
				cout << lineNum << " : " << line << "\n";
			}
		}
		++lineNum;
	}
}

void Dictionary::print_input_tokens() const
{
	for (int i = 0; i < 27; ++i)
	{
		if (i == 26) cout << "<>" << "\n";
		else cout << "<" << char(i + 'A') << ">" << "\n";

		for (const Token& token : token_list_buckets[i])
		{
			cout << setw(20) << token << "\n";
		}

		cout << "\n";
	}
}

void Dictionary::print_input_tokens(set<char>& char_set) const
{
	for (const char& s : char_set)
	{
		cout << s << " ";
	}
	cout << "\n";

	for (int i = 0; i < 27; ++i)
	{
		for (const char& c : char_set)
		{
			char headerChar = i + 'A';

			if (headerChar == toupper(c))
			{
				cout << "<" << headerChar << ">" << "\n";
				cout << "<" << i << " - " << c << ">" << "\n";
			}
			else if (i == 26 && !isalpha(c))
			{
				cout << "<>" << "\n";
				cout << "<" << i << " - " << c << ">" << "\n";
			}

			for (const Token& token : token_list_buckets[i])
			{
				string tokenChar = token.get_token_text();

				if (isalpha(tokenChar[0]) && (toupper(tokenChar[0]) == c || tolower(tokenChar[0]) == c))
				{
					cout << setw(20) << token << "\n";
				}
				else if (!isalpha(tokenChar[0]))
				{
					cout << setw(20) << token << "\n";
				}
			}
		}
		cout << "next " << "\n";
	}
}

void Dictionary::print_sorted_on_token_text()const
{
	for (int i = 0; i < 27; ++i)
	{
		forward_list<Token> flist{};

		if (i == 26) cout << "<>" << "\n";
		else cout << "<" << char(i + 'A') << ">" << "\n";

		for (const Token& token : token_list_buckets[i])
		{
			flist.push_front(token);
		}

		flist.sort(operator<);

		for (Token& t : flist)
		{
			cout << setw(20) << t << "\n";
		}
		cout << "\n";
	}
}

void Dictionary::print_sorted_on_token_text(set<char>& char_set)const
{
	for (const char& s : char_set)
	{
		cout << s << " ";
	}
	cout << "\n";
}

void Dictionary::print_sorted_on_token_frequecy()const
{
	for (int i = 0; i < 27; ++i)
	{
		forward_list<Token> flist{};

		if (i == 26) cout << "<>" << "\n";
		else cout << "<" << char(i + 'A') << ">" << "\n";

		for (const Token& token : token_list_buckets[i])
		{
			flist.push_front(token);
		}

		flist.sort(isLessFrequent);

		for (Token& t : flist)
		{
			cout << setw(20) << t << "\n";
		}
		cout << "\n";
	}
}

void Dictionary::print_sorted_on_token_frequecy(set<char>& char_set)const
{
	for (const char& s : char_set)
	{
		cout << s << " ";
	}
	cout << "\n";
}

void Dictionary::print_sorted_on_token_length()const
{
	for (int i = 0; i < 27; ++i)
	{
		forward_list<Token> flist{};

		if (i == 26) cout << "<>" << "\n";
		else cout << "<" << char(i + 'A') << ">" << "\n";

		for (const Token& token : token_list_buckets[i])
		{
			flist.push_front(token);
		}

		flist.sort(isShorter);

		for (Token& t : flist)
		{
			cout << setw(20) << t << "\n";
		}
		cout << "\n";
	}
}

void Dictionary::print_sorted_on_token_length(set<char>& char_set)const
{
	for (const char& s : char_set)
	{
		cout << s << " ";
	}
	cout << "\n";
}

string Dictionary::escape_tab_newline_chars(const string& separators)
{
	string result{};

	for (auto c : separators)
	{
		switch (c)
		{
		case '\n':
			result += "\\n";
			break;

		case '\t':
			result += "\\t";
			break;

		case '\0':
			result += "\\0";
			break;

		default:
			result += c;
			break;
		}
	}

	return result;
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