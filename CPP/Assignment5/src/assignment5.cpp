#include "assignment5.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::reverse;
using std::runtime_error;

/*********************************************************************/

class WordCountFunctor {
public:
	void operator()(const std::string& word) { wmap[word]++; }
	bool operator()(const std::string& word, int n) { return (n == word.length()); }
	WordsMap getmap() { return wmap; }
private:
	WordsMap wmap;
};

bool is_alphabetic(char input) {
	bool checkSpace = !std::isalpha(input);
	return checkSpace;
}

bool freeFunc(std::string word, int n) {
	return (word.length() == n);
}

class compareBylength {
public:
	bool operator()(const std::string& lhs, const std::string& rhs) const {
		if (lhs.length() == rhs.length()) {
			return lhs < rhs;
		}
		return lhs.length() < rhs.length();
	}
};

/*********************************************************************/

WordsVector read_words_into_vector(const std::string& inFileName) {
	std::ifstream ifs(inFileName); // Create an input file stream
	if (!ifs.is_open()) { // Check that the file is open
		cout << "Could not open file " + inFileName << endl;
		throw runtime_error("Could not open file " + inFileName);
	}
	WordsVector words_vector; // an empty vector
	std::istream_iterator<std::string> ibegin(ifs), iend;
	std::copy(ibegin, iend, std::back_inserter(words_vector));

	return words_vector;
}

WordsMap map_and_count_words_using_lambda(const WordsVector& wvec) {
	WordsMap wmap;
	std::for_each(wvec.begin(), wvec.end(), [&wmap](const std::string& word) { wmap[word]++; });
	return wmap;
}

WordsMap map_and_count_words_using_functor(const WordsVector& wvec) {
	WordCountFunctor wcf{};
	wcf = std::for_each(wvec.begin(), wvec.end(), wcf);
	return wcf.getmap();
}

WordsVector remove_duplicates(const WordsVector& words_vector) {
	WordsVector words_vec{ words_vector }; // make a copy of the supplied words_vector

	// 1- use std::sort to sort words_vec alphabetically
	// so that we can locate the duplicate words in it.
	std::sort(words_vec.begin(), words_vec.end(), [](const std::string& a, const std::string& b) -> bool {	return a < b; });

	// 2- use std::unique to rearrange the words in the sorted words_vec
	// so that each word appears once in the front portion of words_vec.
	auto returnedIterator = std::unique(words_vec.begin(), words_vec.end());
	// store the returned iterator, which points to the element
	// immediately after all the unique elements in the front of words_vec.

	// 3- use std::vector’s erase member function to erase the range of non-unique
	// words in words_vec, starting at the iterator stored in step 2 above
	// to the end of words_vec.
	words_vec.erase(returnedIterator, words_vec.end());
	return words_vec;
}

bool is_palindrome(const std::string& phrase) {
	std::string buffer;

	// Copy alphabets and exclude spaces
	std::remove_copy_if(phrase.begin(), phrase.end(), back_inserter(buffer), is_alphabetic);

	// Convert everything to lowercase
	std::transform(buffer.begin(), buffer.end(), buffer.begin(), [](unsigned char c) { return std::tolower(c); });

	// Compare first half of string with the last half
	bool isPalindrome = std::equal(buffer.begin(), buffer.begin() + buffer.size() / 2, buffer.rbegin());

	return isPalindrome;
}

size_t count_using_lambda(const std::vector<std::string>& vec, int n)
{
	size_t count = std::count_if(vec.begin(), vec.end(), [n](const std::string& word) { return (n == word.length()); });
	return count;
}

size_t count_using_Functor(const std::vector<std::string>& vec, int n) {
	WordCountFunctor wcf{};
	size_t count = std::count_if(vec.begin(), vec.end(), std::bind(wcf, std::placeholders::_1, n));
	return count;
}

size_t count_using_Free_Func(const std::vector<std::string>& vec, int n) {
	size_t count = std::count_if(vec.begin(), vec.end(), std::bind(freeFunc, std::placeholders::_1, n));
	return count;
}


void multisetUsingDefaultComparator(const std::vector<std::string>& vec) {
	// an empty set
	std::multiset<std::string> strSet;

	// to print a sorted verstion of the supplied vector vec,
	// we first copy vec to our strSet and then print the strSet.
	// note: since std::multiset does not provide push_front or push_back members,
	// we can’t use a front or back inserter when we copy vec to our empty strSet,
	// meaning that we must use a general inserter:

	std::copy(vec.begin(), vec.end(), // source start and finish
		std::inserter(strSet, strSet.begin())); // destination start using
		// a general inserter

		// create an ostream_iterator attached to cout, using a space " " as a separator
	std::ostream_iterator<std::string> out(cout, " ");

	// output the set elements to the cout
	std::copy(strSet.begin(), strSet.end(), out);
}

void multisetUsingMyComparator(const std::vector<std::string>& vec) {

	// an empty set
	std::multiset<std::string, compareBylength> strSet;

	// to print a sorted verstion of the supplied vector vec,
	// we first copy vec to our strSet and then print the strSet.
	// note: since std::multiset does not provide push_front or push_back members,
	// we can’t use a front or back inserter when we copy vec to our empty strSet,
	// meaning that we must use a general inserter:

	std::copy(vec.begin(), vec.end(), std::inserter(strSet, strSet.begin())); // destination start using
	// a general inserter

	// create an ostream_iterator attached to cout, using a space " " as a separator
	std::ostream_iterator<std::string> out(cout, " ");

	// output the set elements to the cout
	std::copy(strSet.begin(), strSet.end(), out);
}



int recursiveFibo(int n) {
	if (n <= 1) return n;
	return recursiveFibo(n - 1) + recursiveFibo(n - 2);
}


class Fibonacci {
private:
	int num{ 0 };
public:
	int operator()() { return recursiveFibo(num++); }
};

std::vector<int> getnerate_Fibonacci(int n) {
	std::vector<int>fiboVec(n);
	Fibonacci fibo{};
	std::generate_n(fiboVec.begin(), n, fibo);
	return fiboVec;
}