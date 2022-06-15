#ifndef Token_h
#define Token_h

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::ostream;


class Token{
    private:
        string text;
        size_t frequency;
        vector<size_t> line_number_list;
        
    public:
        Token() = delete; //disable default constructor
        Token(string text, size_t line_number); //normal constructor
        
        Token(const Token& source) = default; //copy ctor
        Token(Token&& source) = default; //move ctor
        Token& operator=(const Token& rhs) = default;
        Token& operator=(Token&& rhs) = default;
        ~Token() = default;
        
        //compares this and other token texts using std::string's compare
        int compare(const Token & other)const;

        //prints this token's text, frequency, and list of line numbers
        void print (ostream &out) const;
        
        //returns a copy of this token's text
        string get_token_text();
        
        //returns this token's frequency
        int get_frequency()const;
        
        //returns a copy of this token's list of line numbers
        vector<size_t>
        get_number_list() const;
        
        //returns the length of this token's text
        size_t length() const { return text.length(); }
        
        //increment this token's frequency
        void increment_frequency();
        
        //add a specified line number to this token's list of line numbers
        //only if the specified line number is not in the list.
        void push_back_line_number(size_t lineNum);
};

    ostream & operator << (ostream &sout, const Token & t); //uses print

    bool operator<(const Token& t1, const Token& t2); //uses compare
    
    bool isShorter(const Token& first, const Token& second); //uses length

    bool isLessFrequent(const Token& first, const Token& second); //uses getFrequency

#endif /* Token_h */
