#ifndef DRIVER_H
#define DRIVER_H

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
	void Print_Menu(int& option, string& input);

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