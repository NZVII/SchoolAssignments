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
using namespace std;

int main(){
    // input variables
    string phraseOne;
    string phraseTwo;
    string resultMessage;

    cout << "Welcome to the Phrase and Subphrases program" << endl;

    // user inputs
    cout << "Enter phrase one: ";
    cin >> phraseOne;

    cout << "Enter phrase two: ";
    cin >> phraseTwo;

    const int PHRASE_ONE_LENGTH = phraseOne.length();
    const int PHRASE_TWO_LENGTH = phraseTwo.length();


    return 0;
}
