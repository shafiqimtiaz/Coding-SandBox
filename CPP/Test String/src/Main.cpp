#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;

void string_to_int_and_print(string& str)
{
	vector<int> vec{};

	for (size_t i{}; i < str.length(); ++i)
	{
		vec.push_back(str[i] - '0'); // converts string to int
	}

	for (int& v : vec)
	{
		cout << v << " ";
	}
	cout << "\n";
}

void bubbleSort_and_print(string& str)
{
	string temp{ str };

	bool sorted{ false };

	while (!sorted)
	{
		sorted = true;
		for (size_t i{ 1 }; i < temp.length(); ++i)
		{
			if (temp[i - 1] > temp[i])
			{
				std::swap(temp[i], temp[i - 1]);
				sorted = false;
			}
		}
	}

	cout << temp;
}

bool check_if_starts_with(string& str, string& check)
{
	if (str.starts_with(check))
	{
		return true;
	}
	return false;
}

void compareOperation(string& str, string& check)
{
	// compare(offset, length, string obj)

	int result{ str.compare(10, check.length(), check) };

	if (result == 0)
		cout << "\"" << str << "\" contains \"" << check << "\" starting at index 10\n";
	else
		cout << "Strings didn't match ";
}

void removeWhiteSpaces(const string& str)
{
	size_t len = str.length();
	char* chStr = new char[len];
	for (size_t k{}; k < len; ++k)
	{
		if (str[k] != ' ')	chStr[k] = str[k];

	}
	for (size_t k{}; k < len; ++k)	cout << chStr[k];

	delete[] chStr;
}

int main()
{
	string str = "hello hoobla nigga";
	removeWhiteSpaces(str);

	/*string phrase;
	cin >> phrase;
	string_to_int_and_print(phrase);/*

	/*string phrase{ "Hoobla is magical in his own ways!!" };

	cout << phrase.substr(4, 10) << "\n";
	cout << phrase.substr(4) << "\n";

	bubbleSort_and_print(phrase);

	string check{ "magical" };
	cout << check_if_starts_with(phrase, check);

	compareOperation(phrase, check);*/
}