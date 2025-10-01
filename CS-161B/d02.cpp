/******************************************************************************
# Author:           Alan Diaz
# Lab:              Discussion #2
# Date:             October 1, 2025
# Description:      This program prompts for a word, a 4 digit number, and a
                    symbol to create a strong password. Uses C-strings.
# Input:            char word[MAX_ARRAY_LENGTH, number[MAX_ARRAY_LENGTH,
                    symbol[MAX_ARRAY_LENGTH;
# Output:           char password[MAX_ARRAY LENGTH]
# Sources:          None
#******************************************************************************/
#include <cstring>
#include <iostream>
using namespace std;
// Make the max length of the arrays 20 characters
const int MAX_ARRAY_LENGTH = 20;

void readNumber(char (&number)[MAX_ARRAY_LENGTH]);

void createPassword(char (&password)[MAX_ARRAY_LENGTH],char word[MAX_ARRAY_LENGTH],
    char number[MAX_ARRAY_LENGTH], char symbol[MAX_ARRAY_LENGTH]);

int main (){
    char word[MAX_ARRAY_LENGTH], number[MAX_ARRAY_LENGTH],
    symbol[MAX_ARRAY_LENGTH], password[MAX_ARRAY_LENGTH];

    cout << "Enter a word or phrase" << endl;
    cin >> word;

    // Clear the next 100 characters in case of a phrase
    cin.ignore(100,'\n');

    readNumber(number);

    cout << "Pick a symbol" << endl;
    cin >> symbol;

    createPassword(password, word, number, symbol);

    cout << "\nYour strong password is: " << password << endl;
    cout << "Thank you for using the program!" << endl;


    return 0;
}

void createPassword(char (&password)[MAX_ARRAY_LENGTH],char word[MAX_ARRAY_LENGTH],
    char number[MAX_ARRAY_LENGTH], char symbol[MAX_ARRAY_LENGTH]){
        // Copy the word into the string
        strcpy(password, word);
        // Concatenate the rest
        strcat(password, number);
        strcat(password, symbol);
    }

void readNumber(char (&number)[MAX_ARRAY_LENGTH]){
    char tempVar[MAX_ARRAY_LENGTH];
    bool isValid = true;
    do{
        cout << "Enter a number you can remember (max length of 4 numbers)"
        << endl;
        cin >> tempVar;

        // Validates that the length is 4 digits
        if(strlen(tempVar) > 4){
            cout << "\nPlease enter a max of 4 digits!" <<endl;
            isValid = false;
        }
        else {
            // Loops through the array and ensures that all the values are numbers
            for (int i=0; i < strlen(tempVar); ++i){
                if (!isdigit(tempVar[i])){
                    cout << "\nPlease enter numbers only!" << endl;
                    isValid = false;
                }

            }
            isValid = true;
        }

    }
    while(!isValid);
    strcpy(number, tempVar);
}
