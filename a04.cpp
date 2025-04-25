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
#include <string>
using namespace std;

int main(){
    // input variables
    string phraseOne;
    string phraseTwo;
    // used 
    string resultMessage = "";

    cout << "Welcome to the Phrases and Subphrases program\n" << endl;

    // user inputs
    cout << "Enter phrase one: ";
    getline(cin, phraseOne);
    cout << "You entered: " 
         << phraseOne << endl;

    cout << "Enter phrase two: ";
    getline(cin, phraseTwo);
    cout << "You entered: " 
         << phraseTwo << endl << endl;

    const int PHRASE_ONE_LENGTH = phraseOne.length();
    const int PHRASE_TWO_LENGTH = phraseTwo.length();

    // evaluate phrases
    // find phraseOne in phraseTwo
    if (phraseOne == phraseTwo) {
        resultMessage = "Both phrases match";
    }
    else if (phraseTwo.find(phraseOne) != string::npos){
        // assign the position number to a variable for calculations
        int phraseOnePosition = phraseTwo.find(phraseOne);
        // gets the length of phrase two from the beginning of phrase one.
        int phraseTwoRemainder = PHRASE_TWO_LENGTH - phraseOnePosition;

        resultMessage = phraseTwo.substr(phraseOnePosition, phraseTwoRemainder);

        cout << "\"" << phraseOne << "\""
            << " was found in "
            << "\"" << phraseTwo << "\""
            << endl;
    }
    else if (phraseOne.find(phraseTwo) != string::npos){
        // assign the position number to a variable for calculations
        int phraseTwoPosition = phraseOne.find(phraseTwo);
        // gets the length of phrase two from the beginning of phrase one.
        int phraseOneRemainder = PHRASE_ONE_LENGTH - phraseTwoPosition;

        resultMessage = phraseOne.substr(phraseTwoPosition, phraseOneRemainder);

        cout << "\"" << phraseTwo << "\""
            << " was found in "
            << "\"" << phraseOne << "\""
            << endl;
    }
    else {
        resultMessage = "No matches";
    }
    
    // output the result
    cout << resultMessage << "\nThank you for using the program" << endl;
    return 0;
}
