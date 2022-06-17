#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Token.h"

#include<iostream>
#include <fstream>
#include<string>
#include<list>
#include<array>
#include<vector>
#include<set>
#include <forward_list>

using std::ostream;
using std::string;
using std::forward_list;
using std::set;
using std::vector;
using std::array;
using std::list;

class Dictionary
{
private:
	/**
	* Input filename
	*/
	string filename;

	/**
	* Input separators
	*/
	const string theSeparators;

	/**
	* vector of strings parsed line by line from input file
	*/
	vector<string> input_lines;

	/**
	* array of 27 linked lists that contains 26 Alphabets and 1 foreign bucket
	*/
	array<list<Token>, 27> token_list_buckets;

public:
	/**
	* Normal Constructor
	* Creates the specified Dictionary object
	*
	* @param filename - name of the file to be read
	*/
	Dictionary(const string& filename, const string& separators = " \t\n");

	/**
	* Default Constructor disabled
	*/
	Dictionary() = delete;

	/**
	* Default Copy Constructor
	*/
	Dictionary(const Dictionary&) = default;

	/**
	* Default Move Constructor
	*/
	Dictionary(Dictionary&&) = default;

	/**
	* Default Copy Assignment Operator
	*/
	Dictionary& operator=(const Dictionary&) = default;

	/**
	* Default Copy Assignment Operator
	*/
	Dictionary& operator=(Dictionary&&) = default; // default move assignment

	/**
	* Virtual Default Destructor
	*/
	virtual ~Dictionary() = default;

private:
	/**
	* @param token - the token string to be checked index for
	* @return size_t index position of the token string in the Dictionary bucket
	*/
	size_t bucketIndex(const string& tokenText) const;

	/**
	* @param line - string line from input file
	* @return string vector of all tokens from string line
	*/
	vector<string> extract_tokens_from_line(const string& line) const;

	/**
	* @param tokenText - the token string to be inserted
	* @param line_number - the line number of the Token
	*/
	void push_back_into_bucket(const string& tokenText, size_t line_number);

	/**
	* @param line - string line from input file
	* @param line_number - line number to be pushed into
	*/
	void extract_and_push(const string& line, size_t line_number);

	/**
	* Helper function - checks if tokenList has passed Token
	*
	* @param tokenList - list of Tokens
	* @param check - Token to check
	* @return bool whether the tokenList contains the passed Token
	*/
	bool hasToken(list<Token>& tokenList, Token& check) const;

	/**
	* Helper function - gets the Token& if tokenList has passed Token
	*
	* @param tokenList - list of Tokens
	* @param check - Token to check
	* @return Token& for the corresponding Token in tokenList
	*/
	Token& getToken(list<Token>& tokenList, Token& check) const;

	/**
	* Helper function - check if character set has any non alphabetic character
	*
	* @param ch_set - character set to check inside
	* @return bool if character set contains foreign bucket
	*/
	bool hasNonAlpha(const set<char>& ch_set) const;

public:
	/**
	* @param separators - the string of separator characters
	* @return string of user readable separator characters
	*/
	static string escape_tab_newline_chars(const string& separators);

	/**
	* Print input lines based on char_set input defined by user
	* @param char_set - set of characters input by user during runtime
	*/
	void print_input_lines(set<char>& char_set) const;

	/**
	* Print tokens based on char_set input defined by user
	* @param char_set - set of characters input by user during runtime
	*/
	void print_input_tokens(set<char>& char_set) const;

	/**
	* Print tokens sorted by token text based on char_set input defined by user
	* @param char_set - set of characters input by user during runtime
	*/
	void print_sorted_on_token_text(set<char>& char_set)const;

	/**
	* Print tokens sorted by token frequecy based on char_set input defined by user
	* @param char_set - set of characters input by user during runtime
	*/
	void print_sorted_on_token_frequecy(set<char>& char_set)const;

	/**
	* Print tokens sorted by token length based on char_set input defined by user
	* @param char_set - set of characters input by user during runtime
	*/
	void print_sorted_on_token_length(set<char>& char_set)const;

	/**
	* Print all input lines
	*/
	void print_input_lines() const;

	/**
	* Print all tokens parsed from input lines
	*/
	void print_input_tokens() const;

	/**
	* Print all tokens sorted by token text
	*/
	void print_sorted_on_token_text()const;

	/**
	* Print all tokens sorted by token frequecy
	*/
	void print_sorted_on_token_frequecy()const;

	/**
	* Print all tokens sorted by token length
	*/
	void print_sorted_on_token_length()const;

	/**
	* @param out - the Dictionary ostream to be printed
	*/
	void print(ostream& out) const;
};

/**
* @param out - the Dictionary ostream to be printed
* @param dictionary - the Dictionary object ref
* @return Dictionary ostream object ref
*/
ostream& operator<<(ostream& out, const Dictionary& dictionary);

#endif