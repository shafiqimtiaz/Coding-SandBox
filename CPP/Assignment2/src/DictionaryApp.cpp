#include "Token.h"
#include "Dictionary.h"

#include <iostream>
#include<string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ostream;
using std::ifstream;
using std::istringstream;

/**
* Print the menu of options to assist the user to prompt for option
*/
string Print_Menu();

/**
* Parse the user input in option_int, display_string and display_set
*/
void Parse_User_Input(string& userInput, int& option_int, string& display_string, set<char>& display_set);

int main()
{
	/*cout << "Enter the name of input text file : ";
	string filename;
	cin >> filename;

	cout << "Enter the separator characters : ";
	string separators;
	cin.ignore();
	getline(cin, separators);
	separators += '\n';*/

	string filename = "Seuss.txt";
	//string separators = " \n\t\"\0\\;.,?!=':|{}[]()&+-*%$#!~>^</";
	string separators = ". ;?(),13579=-\"\t\n";

	cout << "Dictionary Source File: " << filename << "\n"
		"Separator Characters:" << Dictionary::escape_tab_newline_chars(separators) << "\n\n";

	// take the user input from Print_Menu
	string input = Print_Menu();

	// initiallize all the variables for option_int, display_string, display_set
	int option_int{};
	string display_string{};
	set<char> display_set{};

	// parse and update all the variables from user input
	Parse_User_Input(input, option_int, display_string, display_set);

	// loop the program until the user enters 0
	while (option_int != 0)
	{
		// creates the dictionary object 
		Dictionary dictionary(filename, separators);

		// executes the associated printer functions based on option_int
		// either for set of display characters or for only option
		switch (option_int)
		{
		case 1:
			if (display_set.size() == 0) dictionary.print_input_lines();
			else dictionary.print_input_lines(display_set);
			break;
		case 2:
			if (display_set.size() == 0) dictionary.print_input_tokens();
			else dictionary.print_input_tokens(display_set);
			break;

		case 3:
			if (display_set.size() == 0) dictionary.print_sorted_on_token_text();
			else dictionary.print_sorted_on_token_text(display_set);
			break;

		case 4:
			if (display_set.size() == 0) dictionary.print_sorted_on_token_frequecy();
			else dictionary.print_sorted_on_token_frequecy(display_set);
			break;

		case 5:
			if (display_set.size() == 0) dictionary.print_sorted_on_token_length();
			else dictionary.print_sorted_on_token_length(display_set);
			break;

			// when user inputs 0, the program will break, the loop will exit,
			// since option_int is set to 0
		case 0:
			break;

			// the default case, in case of invalid options being passed as option_int
		default:
			cout << "\nPlease choose an option mentioned!!\n";
			break;
		}

		cout << "\n";

		// take the looping input from user
		input = Print_Menu();

		// parse the new set of varibles on a loop
		Parse_User_Input(input, option_int, display_string, display_set);
	}

	cout << "\nGoodbye\n";
	return 0;
}


/**
* Helper Function - Print the menu of options to assist the user to prompt for option
* @return the userInput as string
*/
string Print_Menu()
{
	cout << "Choose one of the options listed below and, optionally,\n"
		"enter the initial character of the tokens to print :\n"
		"\t1 - Print input lines\n"
		"\t2 - Print original unsorted tokens\n"
		"\t3 - Print tokens sorted by text\n"
		"\t4 - Print tokens sorted by frequency\n"
		"\t5 - Print tokens sorted by length\n"
		"\t0 - Exit\n"
		"Enter your input : ";

	string userInput;
	cin >> userInput;

	return userInput;
}

/**
* Helper Function - parse the user input in option_int, display_string and display_set
* @param userInput - string input by user
* @param option_int - option integer to choose operation
* @param display_string - string for setting the char to display
* @param display_set - set of character parsed from display_string to show matching results
*/
void Parse_User_Input(string& userInput, int& option_int, string& display_string, set<char>& display_set)
{
	// the first character from the user input to be parsed as integer
	char option_char = userInput[0];

	// parse the first character of input string to option_int
	option_int = 0; // reset option_int
	option_int = option_char - '0';

	// parse the rest of the input string to display_string
	display_string = ""; // reset display_string
	display_string = userInput.substr(1, userInput.length());

	display_set.clear(); // reset display_set
	 // take all the display_string and insert it to display_set using begin-end iterator
	display_set = set<char>(display_string.begin(), display_string.end());
}
