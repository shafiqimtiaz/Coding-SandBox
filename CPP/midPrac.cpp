#include <iostream>
#include <string>
#include <vector>
#include <array>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::array;

string toLower(string str) {
	string newStr{};
	for (char c : str) {
		if (std::isalpha(c))
			newStr += static_cast<char>(std::tolower(c)); // static cast since tolower(char) returns int
		else newStr += c;
	}
	return newStr;
}

string toLowerCase(const string& str) {
	string phrase{ str };
	for (size_t i{}; i < phrase.length(); ++i) {
		phrase[i] = static_cast<char>(std::tolower(phrase[i]));
	}
	return phrase;
}

// Inefficient bubblesort
// bubble sort to demonstrate string compare post c++20
std::vector<string> bubble_sort(const std::vector<string>& strVec) {
	std::vector<string> tempStrVec{ strVec };
	bool sorted{ false };
	// repeat until tempStrVec is sorted
	while (!sorted) {
		// assume no swap will take plaec; that is, assume tempStrVec is sorted
		sorted = true;  // will remain true when tempStrVec is sorted
		for (size_t i{ 1 }; i < tempStrVec.size(); ++i) {
			if (tempStrVec[i - 1] > tempStrVec[i]) {    // can also be: if(tempStrVec[i-1].compare(tempStrVec[i])>0)
				tempStrVec[i].swap(tempStrVec[i - 1]);    // container class swap function:
				//std::swap(tempStrVec[i],tempStrVec[i-1]) can be used instead
				sorted = false;  // assumption failed, tempStrVec was not sorted
			}
		}
	}
	return tempStrVec;
}


int countOccurrences(const string& sentence, const string& word) {
	int count{};
	size_t startIndex{};
	while ((startIndex = sentence.find(word, startIndex)) != string::npos) {
		count++;
		startIndex++;  // if you are not interested in overlapping occurences, startIndex+=word.length();
	}
	return count;
}

// Using find_first_of member function, write a function to count the number of vowels in a given sentence.
int countVowelsFF(const string& sentence) {
	int count{};
	size_t startIndex{};
	string vowels{ "aeiouAEIOU" };
	while ((startIndex = sentence.find_first_of(vowels, startIndex)) != string::npos) {
		count++;
		startIndex++;
	}
	return count;
}

// Searching for any of the Characters in a Given string object
// Write a function to count number of vowels
int countVowels(string& sentence) {
	int count{};
	string vowels{ "aeiouAEIOU" };

	for (char c : sentence) {
		if (vowels.find(c) != string::npos) count++;
	}

	return count;
}

void printTokens(const string& line, const string& separators) {

	size_t startIndex{};

	while ((startIndex = line.find_first_not_of(separators, startIndex)) != string::npos) {
		// find the end of current token that starts at startIndex
		size_t endIndex = line.find_first_of(separators, startIndex + 1);

		// did we find a separator or did we reach the end of line
		if (endIndex == string::npos) {
			endIndex = line.length();   // we reached the end of line, so set sndx to end of line
		}
		// extract and print the tokens
		cout << line.substr(startIndex, endIndex - startIndex) << endl;
		startIndex = endIndex + 1;
	}
}

void printToken(const string& line, const string& separators) {

	size_t startIndex{ line.find_first_not_of(separators) };
	size_t endIndex{};

	// substring exists
	while (startIndex != string::npos) {
		// determine end of substring
		endIndex = line.find_first_of(separators, startIndex + 1);
		// reached end of valid substring, or reached end of line
		if (endIndex == string::npos) {
			endIndex = line.length();
		}
		string subStr = line.substr(startIndex, endIndex - startIndex);
		cout << subStr << endl;
		startIndex = line.find_first_not_of(separators, endIndex + 1);
	}
}

int main() {

	// Defining and initializing string objects

	string s1;  // default ctor; s1 is an empty string
	cout << "s1: " << s1 << endl;
	string s2{ s1 };  // copy ctor; s2 is a copy of s1
	cout << "s2: " << s2 << endl;
	string s3{ "Hello" }; // s3 is a copy of string literal
	cout << "s3 length: " << s3.length() << endl;    //output: 5
	string s3mod{ s3 };
	s3mod[2] = 'A';
	cout << "s3mod: " << s3mod << endl;  // string is mutable in c++
	string s4(7, 'z'); // s4 is 7 z's: zzzzzzz
	cout << "s4: " << s4 << endl;

	string s5{ 68, 'R' }; // "DR"
	cout << "s5: " << s5 << endl;

	string s6{ "programming is fun", 7 };  //output:  "program"
	cout << "s6: " << s6 << endl;

	string s7{ "programming is fun" };
	string s8{ s7, 3, 8 };  // 8 characters starting at index 3
	cout << "s8: " << s8 << endl;

	//string name;
	//cout << "enter your name: ";
	//cin >> name;  //must press enter to end input
	//cout << name << endl;

	//  Operations on std::string Objects

	string sub{ "programming" };
	string obj{ "fun" };

	// Concatenating string Objects using operator+

	// programming is fun:
	string phrase = sub + " is " + obj;

	// One of the operands of the binary operator + must always be a string object:
	// string s9 = "programming" + " is " + obj; Error one of the operands of + must be string

	string s10 = string{ "programming" } + " is " + obj; // ok

	string s11 = "programming" + (" is " + obj);  // ok

	// Concatenating std::string Objects using operator +=
	string first{ "Homer" };
	string middle{ "Jay" };
	string last{ "Simpson" };

	string full_name{};  // an empty string
	full_name += first + " ";   // stores "Homer "
	full_name += middle + " ";  // store "Homer Jay"
	full_name += last;  // store "Homer Jay Simpson"
	cout << full_name << endl; //outputs: "Homer Jay Simpson"

	// Using std::string's append() Instead of operator+=
	string fullname{};  // an empty string
	fullname.append(first).append(" ").append(middle).append(" ").append(last).append(3, '!');
	cout << fullname << endl; //Output: Homer Jay Simpson!!!

	// Concatenating std::string Objects and Characters
	string fname{}; // an empty string
	fname = first + ' ' + middle + ' ' + last + '!' + '!' + '!';
	cout << fname << endl;   // Output: Homer Jay Simpson!!!

	// Concatenating std::string Objects and Numbers
	cout << "Summer of " + std::to_string(2022) << endl;    // Output: Summer of 2022

	cout << "pi is " + std::to_string(3.141592653589793) << endl;    // Output: pi is 3.141593

	// Accessing Individual Characters in a std::string Object

	// write a function to convert all the characters in a specified std::string object to lowercase:
	// see above
	string upperCaseStr{ "APPLE" };
	upperCaseStr[2] = 'Z';
	cout << "Lower Case Str: " << toLower(upperCaseStr) << endl;
	cout << "Lower Case Str: " << toLowerCase(upperCaseStr) << endl;

	// Extracting substrings
	// std::string's substr(size_t position, size_t length) member
	string phrase2{ "Raining cats and dogs" };

	string substr1{ phrase2.substr(8, 4) };    // cats
	cout << "substring1(8,4): " << substr1 << endl;

	string substr2{ phrase2.substr(8) };  // Output: cats and doges
	cout << "Substr2(8): " << substr2 << endl;

	string substr3{ phrase2.substr(8, 1000) }; // cats and dogs
	cout << "Substr3(8,1000): " << substr3 << endl;

	// Comparing string Objects
	string a{ "hello" };
	string b{ "bye" };

	// Using std::string's compare() Member function
	// Compare a substring of a string object with another string object
	string phraseCD{ "Raining cats and dogs" }, cat{ "cat" };
	const int result{ phraseCD.compare(8, cat.length(), cat) };
	if (result == 0)
	{
		cout << phraseCD << " contains " << cat << " starting at index 8" << endl;
	}

	// Compare two string objects at once
	string phrase3{ "do not let the cat out of the bag" };
	int result2{ phraseCD.compare(8, 3, phrase3, 15, 3) };

	if (result2 == 0) {
		cout << phraseCD << " contains " << phrase3.substr(15, 3) << " starting at index 15" << endl;
	}

	// checking the start of a std:string Object
	// The hard way before c++20
	if (phraseCD.compare(0, 4, "Rain") == 0) {
		cout << "The phrase \"" << phraseCD << "\" starts with \"Rain\"" << endl;
	}

	// The easy way after c++20
	if (phraseCD.starts_with("Rain")) {
		cout << "The phrase \"" << phraseCD << "\" starts with \"Rain\"" << endl;
	}

	// Checking the end of a std::string object
	// The Hard way until C++20:
	string word{ "dogs" };

	//subtr(startIndex,lengthOfSubstr)
	if (phraseCD.substr(phraseCD.length() - word.length(), word.length()) == word) {
		cout << "The phrase \"" << phraseCD << "\" ends with " << "\"word\"" << endl;
	}
	if (phraseCD.ends_with(word)) {
		cout << "The phrase \"" << phraseCD << "\" ends with " << "\"word\"" << endl;
	}

	// Searching string object

	char ch{ 'c' };
	string::size_type index{ phraseCD.find(ch) };
	if (index == string::npos) {
		cout << "there are no '" << ch << "' in the phrase \"" << phraseCD << "\"\n";
	}
	else {
		cout << "there is a '" << ch << "' in the phrase \"" << phraseCD << "\" at index " << index << '\n';
	}

	cout << phraseCD.find('i') << endl;
	cout << phraseCD.find('g') << endl;
	cout << phraseCD.find("in") << endl;
	cout << phraseCD.find("an") << endl;
	cout << phraseCD.find('z')
		<< endl; // On 64-bit platforms, the value std::string::npos is (2^64)-1 which evaluated to 18446744073709551615


	string sentence{ "Now, See's saw sawed Soar's seesaw" };
	string word1{ "saw" };
	cout << "Testing countOccurrences: \n";
	int count{ countOccurrences(sentence, word1) };
	cout << "the word \"" << word << "\" occurs " << count << " times in the sentence\n\"" << sentence << "\"\n";

	int vCount{ countVowels(sentence) };
	cout << "there are " << vCount << " vowels in the sentence\n\"" << sentence << "\"\n";
	int vFFCount{ countVowelsFF(sentence) };
	cout << "there are " << vFFCount << " vowels in the sentence\n\"" << sentence << "\"\n";

	string sentence2{ "Now; ]See's) saw( sawed !Soar's===seesaw" };
	string separators{ " .',;[]()!\t=" };
	printToken(sentence2, separators);


	/* Use std::string's rfind() member function to*/ /***Search a string in reverse:***/
	cout << sentence.rfind("saw") << endl;
	cout << sentence.find("saw") << endl;

	/*** INSERT a string into another string ***/
	// Use the string's insert() member function to insert a string object into another string object:
	string sentenceInsertEx{ "He ate the canary" };
	string phraseInsertEx{ "looks like the cat that " };
	sentenceInsertEx.insert(0, phraseInsertEx);
	cout << sentenceInsertEx << endl;

	/** Replacing a substring of a string object **/
	// Use string's replace() member function to replace a substring of string object

	string sentenceReplaceEx{ "He looks like the cat that ate the canary" };
	sentenceReplaceEx.replace(27, 3, "swallowed");
	sentenceReplaceEx.replace(18, 3, "snake");
	cout << sentenceReplaceEx << endl;

	/** Replacing a substring of a string object with a substring of another string **/
	// Use string's replace() member function to replace a substring (snake that swallowed)
	// of string object with another substring (cat that ate) of another object
	string str1{ "He looks like the snake that swallowed the canary" };
	string snake{ "snake" };
	string swallowed{ "swallowed" };
	size_t start1{ str1.find(snake) };
	size_t end1{ str1.rfind(swallowed) + swallowed.length() + 1 };    // empty space after swallowed' '

	string str2{ "the cat that ate the" };
	string cat2{ "cat" };
	string ate{ "ate" };
	size_t start2{ str2.find(cat2) };
	size_t end2{ str2.rfind(ate) + ate.length() + 1 };    //+1 to move carrot one position after end of word to make replace function easy to understand.

	str1.replace(start1, end1 - start1, str2, start2, end2 - start2);
	cout << str1 << endl;

	return 0;
}