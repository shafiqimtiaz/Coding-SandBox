#ifndef ASSIGNMENT5_H_
#define ASSIGNMENT5_H_

#include <map>
#include <string>
#include <vector>
// Type aliases
using WordsVector = std::vector<std::string>;
using WordsMap = std::map<std::string, size_t>;

WordsVector read_words_into_vector(const std::string& inFileName);
WordsMap map_and_count_words_using_lambda(const WordsVector& wvec);
WordsMap map_and_count_words_using_functor(const WordsVector& wvec);
WordsVector remove_duplicates(const WordsVector& words_vector);
bool is_palindrome(const std::string& phrase);
size_t count_using_lambda(const std::vector<std::string>& vec, int n);
size_t count_using_Free_Func(const std::vector<std::string>& vec, int n);
size_t count_using_Functor(const std::vector<std::string>& vec, int n);
void multisetUsingMyComparator(const std::vector<std::string>& vec);
void multisetUsingDefaultComparator(const std::vector<std::string>& vec);
std::vector<int> getnerate_Fibonacci(int n);
#endif