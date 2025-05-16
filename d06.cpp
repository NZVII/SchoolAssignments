// note: this template is to be used for discussion only! you must
// use the required algorithmic design document for all assignments.
/******************************************************************************
# author:           Alan Diaz
# lab:              Discussion #6
# date:             May 15, 2025
# description:      This is a program that determines if a word is a palindrome.
                    It receives a word input which gets compared with its 
                    inverse.
# input: wordInput
# output: 
# sources:
#******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main (){
    // declare input variable
    string wordInput;
    // list of special characters that should be ignored
    vector<char> specialCharBlacklist = {'.', ' ', ';', '!', '?'};

    bool isPalindrome = true;


    cout << "Welcome to the Palindrome Checker program\n" << endl 
         << "Enter a word or phrase you would like to check: ";


    getline(cin, wordInput);
    cout << endl;

    vector<char> filteredWordInput(wordInput.size());
    vector<char> wordInputInverse(wordInput.size());

    unsigned int i = 1;

    // Filter out all special characters from input
    for (unsigned int i = 0; i < wordInput.size(); ++i ){
        bool addToArray = true;
        for (char blacklistedChar : specialCharBlacklist){
            if (wordInput.at(i) == blacklistedChar){
                cout << "black listed character found" << endl;
                addToArray = false;
                break;
            }
        }
        if (addToArray){
            filteredWordInput.push_back(tolower(wordInput.at(i)));
            wordInputInverse.push_back(tolower(wordInput.at((wordInput.size()-1)-i)));
        }
    }
    // for (int i = 0; i < filteredWordInput.size(); ++i)[
    //     char characterInverse = filteredWordInput.at((wordInput.size()-i));
    //     char characterNormal = filteredWordInput[i];
    // ]
    for (int i = 0; i < filteredWordInput.size(); ++i){
        if(filteredWordInput[i] != wordInputInverse[(wordInputInverse.size()-1)-i]){
            isPalindrome = false;
            break;
        }
    }


    if (isPalindrome){
        cout << wordInput << " is a palindrome!" << endl;
    }
    else {
        cout << wordInput << " is not a palindrome!" << endl;
    }
    return 0;
}
