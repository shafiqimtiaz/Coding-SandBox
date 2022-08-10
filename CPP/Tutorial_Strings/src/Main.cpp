#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;

std::string toLowerCase(const std::string& str)
{
	std::string phrase{ str };
	for (size_t i{}; i < phrase.length(); ++i)
	{
		phrase[i] = static_cast<char>(std::tolower(phrase[i]));
	}
	return phrase;
}

std::vector < std::string>
bubble_sort(const std::vector<std::string>& strVec)
{
	std::vector<std::string> tempStrVec{ strVec };
	bool sorted{ false };
	// repeat until tempStrVec is sorted
	while (!sorted)
	{ // assume no swaps will take place; that is, assume tempStrVec is sorted
		sorted = true; // will remain true when tempStrVec is sorted
		for (size_t i{ 1 }; i < tempStrVec.size(); ++i)
		{
			//if ((tempStrVec[i - 1] <=> tempStrVec[i]) > 0)
			//if (tempStrVec[i - 1].compare(tempStrVec[i]) > 0)
			if (tempStrVec[i - 1] > tempStrVec[i])
			{ // swap adjacent elements
				tempStrVec[i].swap(tempStrVec[i - 1]);
				//std::swap(names[i], names[i - 1]);
				sorted = false; // assumtion failed, tempStrVec was not sorted
			}
		}
	}
	return tempStrVec;
}

int CountOccurrences1(const std::string& sentence,
	const std::string& word)
{
	int count{}; // count of occurrences of word in sentence
	size_t startIndex{};
	while (startIndex <= sentence.length() - word.length())
	{ // search for word in sentence starting at position startIndex
		size_t position = sentence.find(word, startIndex);
		if (position == std::string::npos)
		{
			break; // no more word in sentence
		}
		++count;
		startIndex = position + 1; // update starting search position
	}
	return count;
}

int CountOccurrences2(const std::string& sentence,
	const std::string& word)
{
	int count{}; // count of occurrences of word in sentence
	size_t startIndex{};
	while ((startIndex = sentence.find(word, startIndex))
		!= std::string::npos)
	{
		++count;
		++startIndex; // update starting search position,
	}
	return count;
}

int countVowels1(const std::string& sentence)
{
	int count{}; // count of occurrences of vowels in sentence
	std::string vowels{ "AaEeIiOoUu" };
	for (char ch : sentence) // example of range-based loop
	{
		if (vowels.find(ch) != std::string::npos)
		{
			++count;
		}
	}
	return count;
}

int countVowels2(const std::string& sentence)
{
	int count{}; // count of occurrences of vowels in sentence
	std::string vowels{ "AaEeIiOoUu" };
	size_t startIndex{ sentence.find_first_of(vowels) };
	while (startIndex != std::string::npos)
	{
		++count;
		startIndex = sentence.find_first_of(vowels, startIndex + 1);
	}
	return count;
}

void printTokens(const std::string& line, const std::string& separators)
{
	// find the start index of first token, if any
	size_t sndx{ line.find_first_not_of(separators) };

	while (sndx != std::string::npos) // while there are tokens
	{ // find the end of current token that starts at sndx
		size_t endIndex = line.find_first_of(separators, sndx + 1);
		// did we find a separator or did we reach the of line?
		if (endIndex == std::string::npos)
		{ // we did reach the of line, so set sndx to end of line
			endIndex = line.length();
		}
		// extract the token
		std::string token{ line.substr(sndx, endIndex - sndx) };
		// again, find the start index of next token, if any
		sndx = line.find_first_not_of(separators, endIndex + 1);
		cout << token << endl; // process the token before losing it!
	}
}

int main()
{
	std::string s1; // default ctor; s1 is the empty string
	std::string s2{ s1 }; // copy ctor; s2 is a copy of s1

	std::string s3{ "hello" }; // s3 is a copy of the string literal
	cout << s3.length() << endl; // Outputs 5

	std::string s4(7, 'z'); // s4 is zzzzzzz

	std::string s5{ 68, 'R' }; // "DR"
	cout << s5 << endl; // Outputs DR

	std::string s6{ "programming is fun", 7 }; // "program"
	cout << s6 << endl; // Outputs program

	std::string s7{ "programming is fun" };
	std::string s8{ s7, 3, 8 }; // 8 characters starting at index 3
	cout << s8 << endl; // Outputs gramming

	std::string name;
	std::cout << "enter your name: ";
	//std::cin >> name; // must Press Enter to end input
	cout << name << endl; // Outputs user's input

	std::string sub{ "programming" };
	std::string obj{ "fun" };

	std::string sentence = sub + " is " + obj; // "programming is fun"
	//std::string s9 = "programming" + " is " + obj; // error
	std::string s10 = std::string{ "programming" } + " is " + obj; // ok
	std::string s11 = "programming" + (" is " + obj); // ok

	std::string first1{ "Homer" };
	std::string middle1{ "Jay" };
	std::string last1{ "Simpson" };
	std::string full_name1{}; // an empty string
	full_name1 += first1 + " "; // stores "Homer "
	full_name1 += middle1 + " "; // stores "Homer Jay "
	full_name1 += last1 + " "; // stores "Homer Jay Simpson"
	cout << full_name1 << endl; // Outputs Homer Jay Simpson

	std::string first2{ "Homer" };
	std::string middle2{ "Jay" };
	std::string last2{ "Simpson" };
	std::string full_name2{}; // an empty string
	full_name2.append(first2).append(" ")
		.append(middle2).append(" ")
		.append(last2).append(3, '!');
	cout << full_name2 << endl; // Outputs: Homer Jay Simpson!!!

	std::string first3{ "Homer" };
	std::string middle3{ "Jay" };
	std::string last3{ "Simpson" };
	std::string full_name3{}; // an empty string
	full_name3 = first3 + ' ' + middle3 + ' ' + last3 + '!' + '!' + '!';
	cout << full_name3 << endl; // Outputs: Homer Jay Simpson!!!

	cout << "Summer of " + std::to_string(2022) << std::endl;
	// outputs: Summer of 2022

	cout << "pi is " + std::to_string(3.141592653589793) << endl;
	// Outputs: pi is 3.141593

	std::string phrase{ "Raining cats and dogs" };

	std::string substr1{ phrase.substr(8, 4) }; // cats
	cout << substr1 << endl; // Outputs: cats
	std::string substr2{ phrase.substr(8) };
	cout << substr2 << endl; // Outputs: cats and dogs
	std::string substr3{ phrase.substr(8, 1000) };
	cout << substr3 << endl; // Outputs: cats and dogs

	std::string cat{ "cat" };
	const int result1{ phrase.compare(8, cat.length(), cat) };
	if (result1 == 0)
	{
		cout << phrase << " contains "
			<< cat << " starting at index 8" << endl;
	}

	std::string phrase2{ "do not let the cat out of the bag" };
	const int result2{ phrase.compare(8, 3, phrase2, 15, 3) };
	if (result2 == 0)
	{
		cout << phrase << " contains "
			<< phrase2.substr(15, 3) << " starting at index 15" << endl;
	}

	if (phrase.compare(0, 4, "Rain") == 0)
	{
		std::cout << "The phrase \"" << phrase
			<< "\" starts with \"Rain\"" << std::endl;
	}

	if (phrase.starts_with("Rain"))
	{
		std::cout << "The phrase \"" << phrase
			<< "\" starts with \"Rain\"" << std::endl;
	}

	std::string word{ "dogs" };
	if (phrase.substr(phrase.length() - word.length(), word.length()) == word)
	{
		std::cout << "The phrase \"" << phrase
			<< "\" ends with \"" << word << "\"" << std::endl;
	}

	if (phrase.ends_with(word))
	{
		std::cout << "The phrase \"" << phrase
			<< "\" ends with \"" << word << "\"" << std::endl;
	}

	char ch{ 'c' };
	std::string::size_type index{ phrase.find(ch) };
	if (index == std::string::npos)
	{
		cout << "there are no '" << ch << "' in the phrase \""
			<< phrase << "\"\n";
	}
	else
	{
		cout << "there is a '" << ch << "' in the phrase \""
			<< phrase << "\" at index " << index << '\n';
	}

	cout << phrase.find('i') << endl;
	cout << phrase.find('g') << endl;
	cout << phrase.find("in") << endl;
	cout << phrase.find("an") << endl;
	cout << phrase.find('z') << endl;

	/**********************************************/

	std::string sentence1{ "Now, See's saw sawed Soar's seesaw" };
	std::string word1{ "saw" };
	int count1{ CountOccurrences1(sentence1, word1) };
	cout << "the word \"" << word1 << "\" occurs " << count1
		<< " times in the sentence\n\"" << sentence1 << "\"\n";

	std::string sentence2{ "ZZZZZ" };
	std::string word2{ "ZZ" };
	int count2{ CountOccurrences2(sentence2, word2) };
	cout << "the word \"" << word2 << "\" occurs " << count2
		<< " times in the sentence\n\"" << sentence2 << "\"\n";

	std::string sentence3{ "Now, See's saw sawed Soar's seesaw" };
	int count3 = countVowels1(sentence3);
	int count4 = countVowels2(sentence3);
	cout << "there are " << count3 << " OR " << count4 << " vowels in the sentence\n\""
		<< sentence3 << "\"\n";

	std::string sentence4{ "Now; ]See's) saw( sawed !Soar's===seesaw" };
	std::string separators{ " .',;[]()!\t=" };
	printTokens(sentence4, separators);

	std::string sentence5{ "Now, See's saw sawed Soar's seesaw" };
	cout << sentence5.rfind("saw") << endl; // outputs: 31
	cout << sentence5.find("saw") << endl; // outputs: 11

	std::string sentence6{ "He ate the canary" };
	std::string phrase3{ "looks like the cat that " };
	sentence6.insert(3, phrase3);
	cout << sentence6 << endl;

	std::string sentence7{ "He looks like the cat that ate the canary" };
	sentence7.replace(27, 3, "swallowed");
	sentence7.replace(18, 3, "snake");
	cout << sentence7 << endl;

	std::string str1{ "He looks like the snake that swallowed the canary" };
	std::string snake{ "snake" };
	std::string swallowed{ "swallowed" };
	size_t start1{ str1.find(snake) };
	size_t end1{ str1.rfind(swallowed) + swallowed.length() + 1 };

	std::string str2{ "the cat that ate the" };
	std::string cat2{ "cat" };
	std::string ate{ "ate" };
	size_t start2{ str2.find(cat2) };
	size_t end2{ str2.rfind(ate) + ate.length() + 1 };

	str1.replace(start1, end1 - start1, str2, start2, end2 - start2);
	cout << str1 << endl;
}