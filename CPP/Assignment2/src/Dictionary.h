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
	string filename;
	const string theSeparators;
	vector<string> input_lines;
	array<list<Token>, 27> token_list_buckets;

	/**
	* @param token - the token string to be checked index for
	* @return size_t index position of the token string in the Dictionary bucket
	*/
	size_t bucketIndex(const string& tokenText) const;

public:
	/**
	* Normal Constructor
	* Creates the specified Dictionary object
	*
	* @param fiename - name of the file to be read
	*/
	Dictionary(const string& filename, const string& separators = " \t\n");

	/**
	* @param tokenText - the token string to be inserted
	* @param line_number - the line number of the Token
	*/
	void push_back_into_bucket(const string& tokenText, size_t line_number);

	/**
	* @param sout - the Dictionary ostream to be printed
	*/
	void print(ostream& sout) const;

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
};

/**
* @param sout - the Dictionary ostream to be printed
* @param dictionary - the Dictionary object ref
* @return Dictionary ostream object ref
*/
ostream& operator<<(ostream& sout, const Dictionary& dictionary);

#endif