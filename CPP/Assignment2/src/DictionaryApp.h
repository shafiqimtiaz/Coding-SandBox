#ifndef DRIVER_H
#define DRIVER_H

#include "Token.h"
#include "Dictionary.h"

#include <iostream>
#include<string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::ostream;
using std::string;
using std::getline;

// Driver class to test individual components of the program
class DictionaryApp
{
public:

	/**
	* Print Menu
	*/
	string Print_Menu();
	void Parse_User_Input(const string& userInput, int& option_int, string& display_string, set<char>& display_set);

	/**
	* Test Token Class
	*/
	void Test_Token();

	/**
	* Test Dictionary Class
	*/
	void Test_Dictionary();
};

#endif