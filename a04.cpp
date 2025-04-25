/******************************************************************************
# Author:           Alan Diaz
# Assignment:       A4 (CS161A)
# Date:             April 24, 2025
# Description:
# Input:
# Output:
# Sources:
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <variant>
using namespace std;

int main(){
    // input variables
    string phraseOne;
    string phraseTwo;
    string resultMessage;

    cout << "Welcome to the Phrase and Subphrases program" << endl;

    // user inputs
    cout << "Enter phrase one: ";
    getline(cin, phraseOne);

    cout << "Enter phrase two: ";
    getline(cin, phraseTwo);


    // store the lengths of the phrases
    const int PHRASE_ONE_LENGTH = phraseOne.length();
    const int PHRASE_TWO_LENGTH = phraseTwo.length();

    // evaluate phrases
    // find phraseOne in phraseTwo

    size_t found = phraseTwo.find(phraseOne);
    size_t foundTest = phraseTwo.find("hello world");
    // issue wher
    cout << phraseOne << " " << foundTest << endl;
    if (found != string::npos){
        cout << "\"" << phraseOne << "\""
             << " was found in "
             << "\"" << phraseTwo << "\""
             << endl;
    }



    return 0;
}
