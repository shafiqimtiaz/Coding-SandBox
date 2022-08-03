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

/**
* @return vector of words read from text file using input file stream
*/
WordsVector read_words_into_vector(const std::string& inFileName) {
	std::ifstream ifs(inFileName); // Create an input file stream
	if (!ifs.is_open()) { // Check that the file is open
		cout << "Could not open file " + inFileName << endl;
		throw runtime_error("Could not open file " + inFileName);
	}
	WordsVector words_vector; // an empty vector
	std::istream_iterator<std::string> it_start(ifs), it_end; // initialize input stream - start, end
	std::copy(it_start, it_end, std::back_inserter(words_vector)); // copy words from to words_vector

	return words_vector;
}

/**
* @return vector of words with duplicate words removed
*/
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

/*********************************************************************/

/**
* @return bool to take char input and return if it has space and if it isalpha
*/
bool is_alpha(char input) {
	bool notSpace = !std::isalpha(input);
	return notSpace;
}

/**
* @return bool to check whether phrase is palindrome or not
*/
bool is_palindrome(const std::string& phrase) {
	std::string buffer;

	// Copy alphabets and exclude spaces
	std::remove_copy_if(phrase.begin(), phrase.end(), back_inserter(buffer), is_alpha);

	// Convert everything to lowercase
	std::transform(buffer.begin(), buffer.end(), buffer.begin(), [](unsigned char c) { return std::tolower(c); });

	// Compare first half of string with the last half
	bool isPalindrome = std::equal(buffer.begin(), buffer.begin() + buffer.size() / 2, buffer.rbegin());

	return isPalindrome;
}

/*********************************************************************/

/**
* class of function overloads to map words, count words of length n and return the word map
*/
class WordCountFunctor {
public:
	void operator()(const std::string& word) { wmap[word]++; }
	bool operator()(const std::string& word, int n) { return (n == word.length()); }
	WordsMap getmap() { return wmap; }
private:
	WordsMap wmap;
};

/**
* @return map of words using labmda expression
*/
WordsMap map_and_count_words_using_lambda(const WordsVector& wvec) {
	WordsMap wmap;
	std::for_each(wvec.begin(), wvec.end(),
		[&wmap](const std::string& word) { wmap[word]++; }); // labmda expression with map key value and increment
	return wmap;
}

/**
* @return map of words using WordCountFunctor function object
*/
WordsMap map_and_count_words_using_functor(const WordsVector& wvec) {
	WordCountFunctor wcf{};
	wcf = std::for_each(wvec.begin(), wvec.end(), wcf); // wcf functor to map words
	return wcf.getmap();
}

/*********************************************************************/

/**
* @return word count of words with length n using labmda expression
*/
size_t count_using_lambda(const std::vector<std::string>& vec, int n)
{
	size_t count = std::count_if(vec.begin(), vec.end(),
		[n](const std::string& word) { return (n == word.length()); }); // labmda expression to count words of n specified word length
	return count;
}

/**
* @return word count of words with length n using WordCountFunctor function object
*/
size_t count_using_Functor(const std::vector<std::string>& vec, int n) {
	WordCountFunctor wcf{};
	size_t count = std::count_if(vec.begin(), vec.end(),
		std::bind(wcf, std::placeholders::_1, n)); // using std::bind wcf to count words of n specified word length
	return count;
}

/**
* @return bool word is of n specified length
*/
bool freeFunc(std::string word, int n) {
	return (word.length() == n);
}

/**
* @return word count of words with length n using freeFunc
*/
size_t count_using_Free_Func(const std::vector<std::string>& vec, int n) {
	size_t count = std::count_if(vec.begin(), vec.end(),
		std::bind(freeFunc, std::placeholders::_1, n)); // using std::bind freeFunc to count words of n specified word length
	return count;
}

/*********************************************************************/

/**
* creating a multiset using default comparator
*/
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

/**
* comparator class to compare word by length
*/
class customComparator {
public:
	bool operator()(const std::string& lhs, const std::string& rhs) const {
		if (lhs.length() == rhs.length()) { return lhs < rhs; }
		return lhs.length() < rhs.length();
	}
};

/**
* creating a multiset using customComparator
*/
void multisetUsingMyComparator(const std::vector<std::string>& vec) {

	// an empty set
	std::multiset<std::string, customComparator> strSet;

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

/*********************************************************************/

/**
* @return generate n'th fibonacci number using recursion
*/
int recursiveFunc(int n) {
	if (n <= 1) return n;
	return recursiveFunc(n - 1) + recursiveFunc(n - 2);
}

/**
* class to create a Fibonacci function object and call recursiveFunc
*/
class Fibonacci {
public:
	int operator()() { return recursiveFunc(num++); } // calling recursiveFunc
private:
	int num{ 0 };
};

/**
* @return vector of n Fibonacci numbers using generate_n and Fibonacci funtion object
*/
std::vector<int> generate_Fibonacci(int n) {
	std::vector<int>fiboVec(n);
	Fibonacci fibo{};
	std::generate_n(fiboVec.begin(), n, fibo);
	return fiboVec;
}