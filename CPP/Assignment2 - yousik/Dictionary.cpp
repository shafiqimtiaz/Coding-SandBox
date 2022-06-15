#include "Dictionary.h"
#include "Token.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <forward_list>
using std::string;
using std::vector;
using std::array;
using std::ostream;
using std::cout;
using std::endl;
using std::ifstream;
using std::forward_list;

Dictionary::Dictionary(const string& filename, const string& theSeparators): filename(filename), theSeparators(theSeparators){
    cout << "theSeparators:" << theSeparators << endl;
    
    vector<string> v1{};
    array<list<Token>, 27> t1{};
    this -> input_lines = v1;
    this -> token_list_buckets = t1;
//    this -> theSeparators = theSeparatorEscaped;

    
    // create an input file stream
    ifstream fin(filename);
    
    if (!fin){
        cout << "could not open input file: " << filename << endl;
        exit(1);
    }
    int linenum = 0;
    string line;
    getline(fin, line);

    while (fin){
        ++linenum; // count the line
        std::istringstream sin(line); // turn the line into an input string stream
        extract_and_push(line, linenum);
        getline(fin, line); // attempt to read the next line, if any
    }
    fin.close();
};

//returns the index of the bucket corresponding to tokenText[0]
size_t Dictionary::bucket_index(const string &tokenText) const {
    size_t index = 26;
    if (isalpha(tokenText[0])) {
        if (isupper(tokenText[0])) {
            index = tokenText[0] - 'A';
        }
        else {
            index = tokenText[0] - 'a';
        }
    }
    return index;
}



void printTokens(const string& line,
    const string& separators) {
    size_t sndx{ line.find_first_not_of(separators) };     // find the start index of first token, if any
    while (sndx != string::npos){    // while there are tokens
         size_t endIndex = line.find_first_of(separators, sndx + 1);      // find the end of current token that starts at sndx
        
         if (endIndex == string::npos){ // we did reach the of line, so set sndx to end of line
             endIndex = line.length();
         }
        
         string token{line.substr(sndx, endIndex - sndx) };  // extract the token
         sndx = line.find_first_not_of(separators, endIndex + 1);  // again, find the start index of next token, if any
         cout << token << endl;
     }
}


//extracts and returns the tokens separated by theSeparators in the specified line
vector<string> Dictionary::extract_tokens_from_line(const string &line) const{
    // find the start index of first token, if any
    size_t sndx{ line.find_first_not_of(theSeparators) };
    
    //a vector to hold list of tokens, separated by theSeparators
    vector<string> tokens{};

    while (sndx != string::npos){    // while there are tokens
         size_t endIndex = line.find_first_of(theSeparators, sndx + 1);      // find the end of current token that starts at sndx
        
         if (endIndex == string::npos){ // we did reach the of line, so set sndx to end of line
             endIndex = line.length();
         }
        
         string token{line.substr(sndx, endIndex - sndx) };  // extract the token
         sndx = line.find_first_not_of(theSeparators, endIndex + 1);  // again, find the start index of next token, if any
        tokens.push_back(token);
     }
    return tokens;
}

//creates a token with the specified tokenText and line_number and then pushes (inserts)
//the token at the end of the bucket list corresponding to tokenText[0]
void Dictionary::push_back_into_bucket(const string &tokenText, size_t line_number){
    size_t bucketPosition = bucket_index(tokenText);
    Token newToken{tokenText, line_number};
 
    if(token_list_buckets[bucketPosition].size() > 0){
        for(Token &currentToken: token_list_buckets[bucketPosition]){
            if(currentToken.compare(newToken) == 0){
                cout << "=======" << endl;
                cout << "c:" << currentToken << endl;
                cout << "n:" << newToken << endl;
                cout << "=======" << endl;

                currentToken.push_back_line_number(line_number);
            } else {
                token_list_buckets[bucketPosition].push_back(newToken);
            }
            return;
        }
    } else {
        token_list_buckets[bucketPosition].push_back(newToken);
        return;
    }
    return;
}

//using extract_tokens_from_line and push_back_into_bucket, inserts the tokens
//extracted from the specified line and line_number into appropriate buckets
void Dictionary::extract_and_push(const string &line, size_t line_number){
    vector<string> tokens = extract_tokens_from_line(line);
    
    for (string tokenText : tokens) {
        push_back_into_bucket(tokenText, line_number);
    }
}



//prints all input lines, each preceded by line number
//prints the input lines beginning with the characters stored in char_set
//each line is preceded by its line numbers in the input file
//if char_set is empty, then it prints all input lines
void Dictionary::print_input_lines(set<char>& char_set) const {
    cout << "Input Lines" << endl;
    cout << "===========" << endl;
    
    ifstream fin(filename);
    int linenum = 1;
    string line;
    getline(fin, line);

    while (fin){
        if(char_set.size() > 0){
            //get first character of each line, in lower case
            char firstCharacter = tolower(line[0]);
            
            //if first char of each line is included in given char_set, display line
            if(char_set.find(firstCharacter) != char_set.end()){
                cout << linenum << ". " <<  line << endl;
            }
            
        } else {
            cout << linenum << ". " <<  line << endl;
        }
        ++linenum; // count the line
        std::istringstream sin(line); // turn the line into an input string stream
        getline(fin, line); // attempt to read the next line, if any
  
    }
    fin.close();
}



//prints original unsorted tokens
//for each character ch in char-set:
//if ch is a letter, it prints original unsorted bucket corresponding to ch;
//if ch is not a letter, it prints the original unsorted foreign bucket.
void Dictionary::print_input_tokens(set<char>& char_set) const {
    cout << "Dictionary Unsorted" << endl;
    cout << "===================" << endl;
    
    //prepare a list of alphabets + '\0' for non-alphabet letters
    char alphabet[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};

    
    for (int i = 0; i < 27; i++) {
        //if first char of each line is included in given char_set, display line
        if(char_set.size() > 0){
            if(char_set.find(tolower(alphabet[i])) != char_set.end() || i == 26){
                cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
                for (Token tkn : token_list_buckets[i]){
                   cout << tkn << "\n";
                }
                cout << "" << endl;
            }
        } else {
            cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
            for (Token tkn : token_list_buckets[i]){
               cout << tkn << "\n";
            }
        }
       
    }
}

//compare function to give as a parameter to forward_list.sort()
bool tokenTextCompare(Token token1, Token token2){
    return token1 < token2;
}
//compare function to give as a parameter to forward_list.sort()
bool tokenFrequencyCompare(Token token1, Token token2){
    return isLessFrequent(token1, token2);
}

//compare function to give as a parameter to forward_list.sort()
bool tokenLengthCompare(Token token1, Token token2){
    return isShorter(token1, token2);
}


//1.copy the bucket list corresponding to ch into a std::forward_list
//2.sort the forward list by a specific attribute, and
//3.print the sorted forward list

//prints all buckets sorted on token text
void Dictionary::print_sorted_on_token_text(set<char>& char_set) const {
    cout << "Dictionary sorted by token text" << endl;
    cout << "===================" << endl;
    
    //prepare a list of alphabets + '\0' for non-alphabet letters
    char alphabet[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};

    for (int i = 0; i < 27; i++) {
        if(char_set.size() > 0){
            //if char_set contains current alphabet[i], or i is at the end(for non-alphabets)
            if(char_set.find(tolower(alphabet[i])) != char_set.end() || i == 26){
                cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
                forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

                flist.sort(tokenTextCompare); //sort by token_text(wip)
                
                for (Token tkn : flist){
                   cout << tkn << "\n";
                }
                cout << "" << endl;
            }
        } else {
            cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
            forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

            flist.sort(tokenTextCompare); //sort by token text
            
            for (Token tkn : flist){
               cout << tkn << "\n";
            }
            cout << "" << endl;
        }
      
    }
}


//prints all buckets sorted on token frequency
void Dictionary::print_sorted_on_token_frequency(set<char>& char_set) const {
    cout << "Dictionary sorted by token frequency" << endl;
    cout << "===================" << endl;
    
    //prepare a list of alphabets + '\0' for non-alphabet letters
    char alphabet[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};

    for (int i = 0; i < 27; i++) {
        if(char_set.size() > 0){
            //if char_set contains current alphabet[i], or i is at the end(for non-alphabets)
            if(char_set.find(tolower(alphabet[i])) != char_set.end() || i == 26){
                cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
                forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

                flist.sort(tokenFrequencyCompare); //sort by token_frequency
                
                for (Token tkn : flist){
                   cout << tkn << "\n";
                }
                cout << "" << endl;
            }
        } else {
            cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
            forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

            flist.sort(tokenFrequencyCompare); //sort by token text
            
            for (Token tkn : flist){
               cout << tkn << "\n";
            }
            cout << "" << endl;
        }
      
    }
}


//prints all buckets sorted on token length
void Dictionary::print_sorted_on_token_length(set<char>& char_set) const {
    cout << "Dictionary sorted by token length" << endl;
    cout << "===================" << endl;
    
    //prepare a list of alphabets + '\0' for non-alphabet letters
    char alphabet[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};

    for (int i = 0; i < 27; i++) {
        if(char_set.size() > 0){
            //if char_set contains current alphabet[i], or i is at the end(for non-alphabets)
            if(char_set.find(tolower(alphabet[i])) != char_set.end() || i == 26){
                cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
                forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

                flist.sort(tokenLengthCompare); //sort by token_length
                
                for (Token tkn : flist){
                   cout << tkn << "\n";
                }
                cout << "" << endl;
            }
        } else {
            cout << "<" << alphabet[i] << ">" << endl;   //prints the sub-title of current index
            forward_list<Token> flist(token_list_buckets[i].begin(), token_list_buckets[i].end());

            flist.sort(tokenLengthCompare); //sort by token text
            
            for (Token tkn : flist){
               cout << tkn << "\n";
            }
            cout << "" << endl;
        }

    }
}


//An example of a static member function, which could otherwise be a free function.
//replace \t and \n with \\t and \\n in separators and returns the resulting string
static string escape_tab_newline_chars(const string& separators){



    string original = separators;
    cout << original << endl;
    return original;
}

