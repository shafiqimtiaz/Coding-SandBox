#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<string>
#include "TokenList.h"

using std::string;

class Dictionary
{
private:
	string filename;
	TokenList tokenListBuckets[27]; // 26 alpha buckets + 1 none-alpha bucket

	/**
	* @param token - the token string to be checked index for
	* @return size_t index position of the token string in the Dictionary bucket
	*/
	size_t bucketIndex(const string& token) const;
public:
	/**
	* Normal Constructor
	* Creates the specified Dictionary object
	*
	* @param fiename - name of the file to be read
	*/
	Dictionary(const string& filename);

	/**
	* @param token - the token string to be inserted
	* @param lineNumber - the line number of the Token
	*/
	void processToken(const string& token, int lineNumber);

	/**
	* @param sout - the Dictionary ostream to be printed
	*/
	void print(ostream& sout) const;


	Dictionary() = delete; // no default constructor

	/**
	* Virtual Default Destructor
	*/
	virtual ~Dictionary() = default;

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
};

/**
* @param sout - the Dictionary ostream to be printed
* @param dictionary - the Dictionary object ref
* @return Dictionary ostream object ref
*/
ostream& operator<<(ostream& sout, const Dictionary& dictionary);

#endif