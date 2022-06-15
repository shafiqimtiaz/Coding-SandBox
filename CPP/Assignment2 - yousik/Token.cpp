#include "Token.h"

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::endl;

//constructor
Token::Token(string text, size_t line_number): frequency{1}, line_number_list{}, text{text}{
    line_number_list.push_back(line_number);
};

//compare the text of current Token and other given token
int Token::compare(const Token& other) const{
    return text.compare(other.text);
}

//print out the Token
void Token::print(ostream &sout) const{
    sout << this -> text;
    sout << " (" << this -> frequency << ") ";

    for (size_t i: get_number_list()){
        sout << i << " ";
    }
}

//get token text
string Token::get_token_text(){
    cout << text << endl;
    return text;
}

//get frequency
int Token::get_frequency() const{
    return (int) frequency;
}

//get number list
vector<size_t> Token::get_number_list() const{
    return this -> line_number_list;
}

//increase frequency
void Token::increment_frequency(){
    frequency++;
}

//if this vector doesn't have lineNum, push_back
void Token::push_back_line_number(size_t lineNum){
    
    bool foundLineNum = false;
    for(size_t currentLineNumber: line_number_list){
        if(currentLineNumber == lineNum){
            foundLineNum = true;
        }
    }
    
    if(foundLineNum == false){
        line_number_list.push_back(lineNum);
        increment_frequency();
    }
}

//operator overloading to use compare t1 and t2
bool operator<(const Token& t1, const Token& t2){
    int compared = t1.compare(t2);
    if(compared < 0){
        return true;
    } else {
        return false;
    }
}

//compare if first token has shorter length than the second
bool isShorter(const Token& first, const Token& second){
    if(first.length() < second.length()) return true;
    if(first.length() > second.length()) return false;
    if(first.compare(second) < 0) return true;
    return false;
}
//
//compare if the first has less frequency than the second
bool isLessFrequent(const Token& first, const Token& second){
    if(first.get_frequency() < second.get_frequency()) return true;
    if(first.get_frequency() > second.get_frequency()) return false;
    if(first.compare(second) < 0) return true;
    return false;
}


ostream& operator<<(ostream& sout, const Token& t){
    t.print(sout);
    return sout;
}
