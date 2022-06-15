#ifndef Dictionary_h
#define Dictionary_h

#include <iostream>
#include <fstream>
#include<string>
#include<list>
#include<array>
#include<vector>
#include<set>
#include "Token.h"

using std::set;
using std::vector;
using std::string;
using std::ostream;
using std::array;
using std::list;

class Dictionary{
    private:
        string filename; //input file name
        const string theSeparators; //the separator characters in a std::string
        vector<string> input_lines; //the lines in the input file
        array<list<Token>, 27> token_list_buckets; //array of 27 token list buckets
    
        //returns the index of the bucket corresponding to tokenText[0]
        size_t bucket_index(const string& tokenText) const;
    
        //extracts and returns the tokens separated by theSeparators in the specified line
        vector<string> extract_tokens_from_line(const string& line) const;
        
        //creates a token with the specified tokenText and line_number and then pushes (inserts)
        //the token at the end of the bucket list corresponding to tokenText[0]
        void push_back_into_bucket(const string& tokenText, size_t line_number);
        
        //using extract_tokens_from_line and push_back_into_bucket, inserts the tokens
        //extracted from the specified line and line_number into appropriate buckets
        void extract_and_push(const string& line, size_t line_number);
   
        //extract and print tokens from given line and separators
        void printTokens(const string& line, const string& separators);
    public:
        //normal constructor
        Dictionary(const string& filename, const string& theSeparators = " \t\n");
    
        //special member functions
        Dictionary() = delete; // default ctor
        ~Dictionary() = default; //default ctor
        Dictionary(const Dictionary& ) = default; //copy ctor
        Dictionary(Dictionary&&) = default; // move ctor
        Dictionary& operator=(const Dictionary&) = default;
        Dictionary& operator=(Dictionary&&) = default;

        
        void print(ostream& cout) const; //default print of dictionary (wip)


        void print_input_lines(set<char>& char_set) const; //prints all input lines, each preceded by line number
        void print_input_tokens(set<char>& char_set) const; //prints original unsoorted tokens
        void print_sorted_on_token_text(set<char>& char_set) const; //prints all buckets sorted on token text
        void print_sorted_on_token_frequency(set<char>& char_set) const; //prints all buckets sorted on token frequency
        void print_sorted_on_token_length(set<char>& char_set) const; //prints all buckets sorted on token length
    

    
        //An example of a static member function, which could otherwise be a free function.
        //replace \t and \n with \\t and \\n in separators and returns the resulting string
        static string escape_tab_newline_chars(const string& separators);
    
};


#endif /* Dictionary_h */
