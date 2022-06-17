#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <array>
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
using std::array;
using std::tolower;
using std::toupper;

/**
* Normal Constructor
* Creates the specified Dictionary object
*
* @param filename - name of the file to be read
*/
Dictionary::Dictionary(const string& filename, const string& separators)
	: filename(filename), theSeparators(separators)
{
	ifstream fin(filename); // create an input file stream

	// if input file stream false, show error
	if (!fin)
	{
		cout << "could not open input file: " << filename << endl;
		exit(1);
	}
	size_t lineNumber{ 1 };
	string line;

	// first attempt to read, this first attempt will get the i/o flags initialized
	getline(fin, line);

	// while input file stream is true, keep on looping
	while (fin)
	{
		input_lines.push_back(line); // push line in lineVec
		extract_and_push(line, lineNumber); // extract the tokens from line and push them
		++lineNumber; // count the line

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
	size_t index{ 26 }; // bucket index for tokens not beginning with a letter
	if (isalpha(tokenText[0]))
	{
		if (isupper(tokenText[0])) index = size_t(tokenText[0]) - 'A';
		else index = size_t(tokenText[0]) - 'a';
	}
	return index;
}

/**
* @param line - string line from input file
* @return string vector of all tokens from string line
*/
vector<string> Dictionary::extract_tokens_from_line(const string& line) const
{
	vector<string> lineVec;

	// find the index of first character not in theSeparators
	size_t startIndex{ line.find_first_not_of(theSeparators) };

	// iterate over line while there are tokens
	while (startIndex != string::npos)
	{
		// find the end of current token that starts at startIndex
		size_t endIndex = line.find_first_of(theSeparators, startIndex + 1);

		// no other separator character found, endIndex is line length
		if (endIndex == string::npos) endIndex = line.length();

		// extract the token using startIndex and endIndex
		string token{ line.substr(startIndex, endIndex - startIndex) };

		// push the extracted token into lineVec
		lineVec.push_back(token);

		// find the start index of next token if any is present
		startIndex = line.find_first_not_of(theSeparators, endIndex + 1);
	}

	return lineVec;
}

/**
* @param token - the token string to be inserted
* @param lineNumber - the line number of the Token
*/
void Dictionary::push_back_into_bucket(const string& tokenText, size_t line_number)
{
	size_t i = bucketIndex(tokenText);
	Token checkToken{ tokenText, line_number };
	list<Token>& tokenList{ token_list_buckets[i] };

	// check if tokenList has checkToken - to prevent repeated line_number insertion
	if (hasToken(tokenList, checkToken))
	{
		// if true, getToken and push_back_line_number
		getToken(tokenList, checkToken).push_back_line_number(line_number);
	}
	// else push_back checkToken in tokenList
	else tokenList.push_back(checkToken);
}

/**
* @param line - string line from input file
* @param line_number - line number to be pushed into
*/
void Dictionary::extract_and_push(const string& line, size_t line_number)
{
	// get the token vector from the line
	vector<string> tokenVec = extract_tokens_from_line(line);

	// iterate over token vector and push the extracted
	// tokenStr and line_number into bucket
	for (const string& tokenStr : tokenVec)
	{
		// push back the tokenStr and line_number in token_bucket_list
		push_back_into_bucket(tokenStr, line_number);
	}

}

/**
* Helper function - checks if tokenList has passed Token
*
* @param tokenList - list of Tokens
* @param check - Token to check
* @return bool whether the tokenList contains the passed Token
*/
bool Dictionary::hasToken(list<Token>& tokenList, Token& check) const
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

/**
* Helper function - gets the Token& if tokenList has passed Token
*
* @param tokenList - list of Tokens
* @param check - Token to check
* @return Token& for the corresponding Token in tokenList
*/
Token& Dictionary::getToken(list<Token>& tokenList, Token& check) const
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

/**
* Helper function - check if character set has any non alphabetic character
*
* @param ch_set - character set to check inside
* @return bool if character set contains foreign bucket
*/
bool Dictionary::hasNonAlpha(const set<char>& ch_set) const
{
	for (char ch : ch_set) {
		if (!isalpha(ch)) {
			return true;
		}
	}
	return false;
}

/**
* @param separators - the string of separator characters
* @return string of user readable separator characters
*/
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

		default:
			result += c;
			break;
		}
	}

	return result;
}

/**
* Print all input lines
*/
void Dictionary::print_input_lines() const
{
	cout << "\nInput Lines\n==========\n";

	size_t lineNum = 1;
	for (const string& line : input_lines)
	{
		cout << lineNum << " : " << line << "\n";
		++lineNum;
	}
}

/**
* Print input lines based on char_set input defined by user
*
* @param char_set - set of characters input by user during runtime
*/
void Dictionary::print_input_lines(set<char>& char_set) const
{
	cout << "\nInput Lines\n==========\n";

	size_t lineNum = 1;
	for (const string& line : input_lines)
	{
		// get first character
		char first_char = tolower(line[0]);

		// if first_char is found in line till set end, display line_num and line
		if (char_set.count(first_char))
		{
			cout << lineNum << " : " << line << "\n";
		}
		++lineNum; // increment line
	}
}

/**
* Print all tokens parsed from input lines
*/
void Dictionary::print_input_tokens() const
{
	cout << "\nDictionary Unsorted\n===================\n";

	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'
		cout << "<" << headerChar << ">" << "\n"; // print headerChar

		// iterate and print Tokens
		for (const Token& token : token_list_buckets[i])
		{
			cout << setw(20) << token << "\n";
		}
		cout << "\n";
	}
}

/**
* Print tokens based on char_set input defined by user
*
* @param char_set - set of characters input by user during runtime
*/
void Dictionary::print_input_tokens(set<char>& char_set) const
{
	cout << "\nDictionary Unsorted\n===================\n";

	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'

		// if headerChar is found in char_set
		// OR if last iteration and char_set has foreign character
		if (char_set.count(tolower(headerChar)) || (i == 26 && hasNonAlpha(char_set)))
		{
			cout << "<" << headerChar << ">" << "\n"; // print headerChar
			// iterate and print Tokens
			for (const Token& token : token_list_buckets[i])
			{
				cout << setw(20) << token << "\n";
			}
		}
	}
}

/**
* Print all tokens sorted by token text
*/
void Dictionary::print_sorted_on_token_text()const
{
	cout << "\nDictionary sorted by token text\n===============================\n";

	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'
		cout << "<" << headerChar << ">" << "\n"; // print headerChar

		// initilaize forward_list with all tokens from token_list_buckets
		forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

		// sort the forward list
		flist.sort(operator<);

		// iterate and print Tokens
		for (Token& token : flist)
		{
			cout << setw(20) << token << "\n";
		}
		cout << "\n";
	}
}

/**
* Print tokens sorted by token text based on char_set input defined by user
*
* @param char_set - set of characters input by user during runtime
*/
void Dictionary::print_sorted_on_token_text(set<char>& char_set)const
{
	cout << "Dictionary sorted by token text\n===============================\n";

	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'

		// if headerChar is found in char_set
		// OR if last iteration and char_set has foreign character
		if (char_set.count(tolower(headerChar)) || (i == 26 && hasNonAlpha(char_set)))
		{
			cout << "<" << headerChar << ">" << "\n"; // print headerChar

			// initilaize forward_list with all tokens from token_list_buckets
			forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

			// sort the forward list
			flist.sort(operator<);

			// iterate and print Tokens
			for (Token& token : flist)
			{
				cout << setw(20) << token << "\n";
			}
			cout << "\n";
		}

	}
}

/**
* Print all tokens sorted by token frequecy
*/
void Dictionary::print_sorted_on_token_frequecy()const
{
	cout << "\nDictionary sorted by token frequecy\n===================================\n";

	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'
		cout << "<" << headerChar << ">" << "\n"; // print headerChar

		// initilaize forward_list with all tokens from token_list_buckets
		forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

		// sort the forward list
		flist.sort(isLessFrequent);

		// iterate and print Tokens
		for (Token& token : flist)
		{
			cout << setw(20) << token << "\n";
		}
		cout << "\n";
	}
}

/**
* Print tokens sorted by token frequecy based on char_set input defined by user
*
* @param char_set - set of characters input by user during runtime
*/
void Dictionary::print_sorted_on_token_frequecy(set<char>& char_set)const
{
	cout << "\nDictionary sorted by token frequecy\n===================================\n";

	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'

		// if headerChar is found in char_set
		// OR if last iteration and char_set has foreign character
		if (char_set.count(tolower(headerChar)) || (i == 26 && hasNonAlpha(char_set)))
		{
			cout << "<" << headerChar << ">" << "\n"; // print headerChar

			// initilaize forward_list with all tokens from token_list_buckets
			forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

			// sort the forward list
			flist.sort(isLessFrequent);

			// iterate and print Tokens
			for (Token& token : flist)
			{
				cout << setw(20) << token << "\n";
			}
			cout << "\n";
		}
	}
}

/**
* Print all tokens sorted by token length
*/
void Dictionary::print_sorted_on_token_length()const
{
	cout << "\nDictionary sorted by token length\n=================================\n";

	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'
		cout << "<" << headerChar << ">" << "\n"; // print headerChar

		// initilaize forward_list with all tokens from token_list_buckets
		forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

		// sort the forward list
		flist.sort(isShorter);

		// iterate and print Tokens
		for (Token& token : flist)
		{
			cout << setw(20) << token << "\n";
		}
		cout << "\n";
	}
}

/**
* Print tokens sorted by token length based on char_set input defined by user
*
* @param char_set - set of characters input by user during runtime
*/
void Dictionary::print_sorted_on_token_length(set<char>& char_set)const
{
	cout << "\nDictionary sorted by token length\n=================================\n";

	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'

		// if headerChar is found in char_set
		// OR if last iteration and char_set has foreign character
		if (char_set.count(tolower(headerChar)) || (i == 26 && hasNonAlpha(char_set)))
		{
			cout << "<" << headerChar << ">" << "\n"; // print headerChar

			// initilaize forward_list with all tokens from token_list_buckets
			forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

			// sort the forward list
			flist.sort(isShorter);

			// iterate and print Tokens
			for (Token& token : flist)
			{
				cout << setw(20) << token << "\n";
			}
			cout << "\n";
		}
	}
}

/**
* @param sout - the Dictionary ostream to be printed
*/
void Dictionary::print(ostream& sout) const
{
	// loop for all 27 token_list_buckets
	for (int i = 0; i < 27; ++i)
	{
		char headerChar = i + 'A'; // convert iteration i to char ASCII starting from A
		if (i == 26) headerChar = '\0'; // if last iteration, make headerChar to '\0'
		cout << "<" << headerChar << ">" << "\n"; // print headerChar

		for (const Token& token : token_list_buckets[i])
		{
			cout << setw(20) << token << "\n";
		}
		cout << "\n";
	}
}

/**
* @param out - the Dictionary ostream to be printed
* @param dictionary - the Dictionary object ref
* @return Dictionary ostream object ref
*/
ostream& operator<<(ostream& out, const Dictionary& dictionary)
{
	dictionary.print(out);
	return out;
}