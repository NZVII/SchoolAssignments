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
int reverseDigit(int num1);
void reverseDigit(int& num2, int& num3);
int main()
{
   int numReverse, numOne, numTwo, numThree;
   // input prompt
   cout << "Enter an integer: ";
   cin >> numOne;
   numReverse = reverseDigit(numOne);
   cout << "Enter two integers: ";
   cin >> numTwo >> numThree; 
   // output
   cout << "\nThe value of reverseDigit(" << numOne << ") is: "
        << numReverse << endl;

    cout << "The value of reverseDigit(" 
         << numTwo << ", " << numThree << ") is: ";
    reverseDigit(numTwo, numThree);
    cout << numTwo << ", " << numThree << endl; 
   return 0;
}
/* * * * * * * * * 
ex: 532 -> 235
vars: revNum, digit
1. loop through num till num reaches 0
2. multiply revNum by 10; 0 when 0 but adds a place when > 0
3. get single place digit, assign to variable, digit
4. single place digit is added to another var, revNum
5. digit is subtracted from num and num is divided by 10 leaving 53
* * * * * * * * */
int reverseDigit(int num1){
    int revNum = 0;
    while(num1 != 0){
        revNum *= 10;
        int digit = num1 % 10;
        revNum += digit;
        num1 /= 10; // decimal disappears since num is an int
    }
    return revNum;
}

void reverseDigit(int& num2, int& num3){
    // reverse num2 & reassign
    num2 = reverseDigit(num2);
    // reverse num3 & reassign
    num3 = reverseDigit(num3);
}