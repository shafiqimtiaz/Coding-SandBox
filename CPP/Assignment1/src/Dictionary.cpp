//#include <iostream>
//#include <fstream>
//#include <string>
//#include "Dictionary.h"
//
//using std::ostream;
//using std::cin;
//using std::cout;
//using std::endl;
//using std::move;
//using std::string;
//
//using std::ifstream;
//using std::istringstream;
//
//Dictionary::Dictionary(const string& filename) : filename(filename)
//{
//	ifstream fin(filename); // create an input file stream
//	if (!fin)
//	{
//		cout << "could not open input file: " << filename << endl;
//		exit(1);
//	}
//	int linenum = 0;
//	string line;
//	getline(fin, line); // very important first attempt to read;
//	// this first attemot will get the i/o flags initialized
//	while (fin)
//	{
//		//cout << line << endl;
//		++linenum; // count the line
//		istringstream sin(line); // turn the line into an input string stream
//		string tokenStr;
//		while (sin >> tokenStr) // extract token strings
//		{
//			processToken(tokenStr, linenum);
//		}
//		getline(fin, line); // attempt to read the next line, if any
//	}
//	fin.close();
//}
//
//size_t Dictionary::bucketIndex(const string& token) const
//{
//	size_t index = 26; // bucket index for tokens not beginning with a letter
//	if (isalpha(token[0]))
//	{
//		if (isupper(token[0])) index = token[0] - 'A';
//		else index = token[0] - 'a';
//	}
//	return index;
//}