/******************************************************************************
# Author:           Alan Diaz
# Lab:              Discussion #9
# Date:             June 4, 2025
# Description:
#
# Input:
# Output:
# Sources:          None
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Function Prototypes
int reverseDigit(int num);

int main()
{
   int numReverse;
   int input;
   // input prompt
   cout << "Enter an integer: ";
   cin >> input;

   numReverse = reverseDigit(input);

   // output
   cout << "\n\nThe value of reverseDigit(" << input << ") is: "
        << numReverse << endl;

   return 0;
}

int reverseDigit(int num){

    // string numString = to_string(num);
    // vector<char> numVectorReverse(numString.size());
    // for (unsigned int i = 0; i < numString.size(); ++i){
    //     numVectorReverse.push_back(numString.at((numString.length()-1)-i));
    // }
    // string reverseNumString(numVectorReverse.begin(), numVectorReverse.end());
    // cout << reverseNumString;
    // string temp = "404";
    // int reverseNumInt = stoi(temp);
    // return reverseNumInt;
}
