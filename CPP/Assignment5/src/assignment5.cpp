#include "assignment5.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::reverse;
using std::runtime_error;

WordsVector read_words_into_vector(const std::string& inFileName){
    std::ifstream ifs(inFileName); // Create an input file stream
    if (!ifs.is_open()) { // Check that the file is open
        cout << "Could not open file " + inFileName << endl;
        throw runtime_error("Could not open file " + inFileName);
    }
    
    WordsVector words_vector; // an empty vector
//    std::copy(ifs.seekg(0), ifs.seekg(), words_vector.begin());
    return words_vector;
}
//WordsMap map_and_count_words_using_lambda(const WordsVector& wvec){
//
//}
//
//WordsMap map_and_count_words_using_functor(const WordsVector& wvec){
//
//}
//
//WordsVector remove_duplicates(const WordsVector& words_vector){
//
//}

bool is_palindrome(const std::string& phrase){
    string reversed{phrase};
    reverse(reversed.begin(), reversed.end());
    return phrase.compare(reversed) == 0;
}

//size_t count_using_lambda(const std::vector<std::string>& vec, int n){
//
//}
//
//size_t count_using_Free_Func(const std::vector<std::string>& vec, int n){
//
//}
//
//size_t count_using_Functor(const std::vector<std::string>& vec, int n){
//
//}

void multisetUsingMyComparator(const std::vector<std::string>& vec){

}

void multisetUsingDefaultComparator(const std::vector<std::string>& vec){

}

//std::vector<int> getnerate_Fibonacci(int n){
//
//}


