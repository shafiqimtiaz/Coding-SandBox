#include "DictionaryApp.h"

/**
* Driver function to test Token
*/

void DictionaryApp::Test_Token()
{
	cout << "Testing an Object of Class Token\n";

	Token t1{ "Hello", 1 };
	cout << "A) t1: " << t1 << "\n";
	t1.push_back_line_number(11);
	t1.push_back_line_number(13);
	t1.push_back_line_number(74);
	cout << "B) t1: " << t1 << "\n";

	Token t2{ t1 };
	t2.push_back_line_number(69);
	t2.push_back_line_number(101);
	cout << "C) t2: " << t2 << "\n";

	Token t3{ "A",1 };
	t3 = t2;
	t3.push_back_line_number(52);
	t3.push_back_line_number(71);
	cout << "D) t3: " << t3 << "\n";

	Token t4 = move(t3);
	t4.push_back_line_number(99);
	t4.push_back_line_number(65);
	cout << "E) t4: " << t4 << "\n";
	//cout << "post-t3: " << t3 << "\n";


	Token t5{ "A",1 };
	t5 = move(t4);
	t5.push_back_line_number(90);
	t5.push_back_line_number(36);
	cout << "F) t5: " << t5 << "\n";
	//cout << "post-t4: " << t4 << "\n";

	cout << t5.get_token_text() << "\n";
	cout << t5.length() << "\n";
	cout << "printing number_list of t5: " << t5.get_number_list() << "\n";

	Token t6{ "HellO", 10 };
	cout << "G) t6: " << t6 << "\n";

	cout << t5.compare(t6) << "\n";

	Token f1{ "sorting",1 };
	Token f2{ "is",1 };
	Token f3{ "a",1 };
	Token f4{ "piece",1 };
	f4.push_back_line_number(10);
	f4.push_back_line_number(111);
	Token f5{ "of",1 };
	Token f6{ "cake!",1 };
	f6.push_back_line_number(20);
	f6.push_back_line_number(21);
	f6.push_back_line_number(22);

	forward_list<Token> flist{ f1, f2, f3, f4, f5, f6 };

	flist.sort();
	cout << "\nDefault sort:\n";
	for (Token& t : flist)
	{
		cout << t << "\n";
	}

	flist.sort(isShorter);
	cout << "\nisShorter sort (asc):\n";
	for (Token& t : flist)
	{
		cout << t << "\n";
	}

	flist.sort(isLessFrequent);
	cout << "\nisLessFrequent sort (asc):\n";
	for (Token& t : flist)
	{
		cout << t << "\n";
	}

	Token f7{ "cake!",100 };

	set<Token> tokenSet{ f1, f2, f3, f4, f5, f6, f7 };
	cout << "\nset :\n";
	for (const Token& s : tokenSet)
	{
		cout << s << "\n";
	}

}

/**
* Driver function to test Dictionary
*/
void DictionaryApp::Test_Dictionary()
{
	//cout << "Enter the name of input text file : ";
	string filename = "Seuss.txt";
	//cin >> filename;
	//string separators = " \n\t\"\\;.,?!=':|{}[]()&+-*%$#!~>^</";
	string separators = ". ;?(),13579=-\"\t\n";
	//cin >> separators;

	string input = Print_Menu();

	int option_int{};
	string display_string{};
	set<char> display_set{};

	Parse_User_Input(input, option_int, display_string, display_set);

	cout << "Dictionary Source File: " << filename << "\n"
		"Separator Characters:" << Dictionary::escape_tab_newline_chars(separators) << "\n\n";

	while (option_int != 0)
	{
		Dictionary dictionary(filename, separators);

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

		case 0:
			break;

		default:
			cout << "Please choose an option mentioned\n";
			break;
		}

		cout << "\n";
		input = Print_Menu();

		Parse_User_Input(input, option_int, display_string, display_set);
	}

	cout << "Goodbye";
}

string DictionaryApp::Print_Menu()
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

void DictionaryApp::Parse_User_Input(const string& userInput, int& option_int, string& display_string, set<char>& display_set)
{
	char option_char = userInput[0];

	option_int = 0; // reset
	option_int = option_char - '0';

	display_string = ""; // reset
	display_string = userInput.substr(1, userInput.length());

	display_set.clear(); // reset
	display_set = set<char>(display_string.begin(), display_string.end());

}
