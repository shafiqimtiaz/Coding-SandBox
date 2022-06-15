#include <iostream>
#include <vector>
#include <string>
#include "Dictionary.h"

using std::string;
using std::vector;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

string mainInterface(){
    cout << "Choose one of the options listed below and, optionally," << endl;
    cout << "enter the initial character of the tokens to print:" << endl;
    cout << "1 - Print input lines" << endl;
    cout << "2 - Print original unsorted tokens" << endl;
    cout << "3 - Print tokens sorted by text" << endl;
    cout << "4 - Print tokens sorted by frequency" << endl;
    cout << "5 - Print tokens sorted by length" << endl;
    cout << "0 - Exit" << endl;
    cout << "Enter your input:" << endl;
    string userInput;
    cin >> userInput;
    return userInput;
}

int main(int argc, const char * argv[]) {
    
    //[current issues]:
    
    //add line number failing (need help)
    //escape failing (need help) how to access public static
    
    //need to create main interface (wip)
    //refactor and create final ver. (wip)
    

    string userInput = mainInterface();

//    string userInput = "12f3iab4wc890\"\\";
//    string userInput = "2def";
//    string userInput = "2";
//    string userInput = "3defxyzdddddddeeeeeeeeeeee?-)(*!fffffff...zzzzzzz,,,yyyyyyy///xxxxxxxxx+++";
//    string userInput = "4defxyz><";
//    string userInput = "5def.>,<zyz";
    
    cout << userInput << endl;
    char menuOption = userInput[0];
    string displayInputString = userInput.substr(1, userInput.length());
    set<char> displayInputSet (displayInputString.begin(), displayInputString.end());
    int menuOptionInt = menuOption - '0';
    cout << "menu:" << menuOptionInt << endl;


    cout << "Separator characters: " << endl;
    string theSeparators = ". ;?(),13579=-\"\t\n";
    //    string escapedSeparators = Dictionary::escape_tab_newline_chars(theSeparators);
    //    cout << "escapedSeparators:" << escapedSeparators << endl;

    
    cout << "Dictionary Source File: ";
    string filename = "/Users/andrewskej/Documents/dev/concordia/COMP5421/Assignment2/Assignment2/Seuss.txt";
    cout << filename << endl;
    //    cin >> filename;
    


    if(filename.length() && menuOptionInt){
        Dictionary dictionary(filename, theSeparators);
            switch(menuOptionInt){
                case 1: dictionary.print_input_lines(displayInputSet);
                    break;
                case 2:  dictionary.print_input_tokens(displayInputSet);
                    break;
                case 3: dictionary.print_sorted_on_token_text(displayInputSet);
                    break;
                case 4: dictionary.print_sorted_on_token_frequency(displayInputSet);
                    break;
                case 5: dictionary.print_sorted_on_token_length(displayInputSet);
                    break;
                case 0: return 0;
                    break;
                default:
                    break;
            }
    }
    
    return 0;
}

