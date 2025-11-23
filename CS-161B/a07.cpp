/******************************************************************************
# Author:           Alan Diaz
# Assignment:       a07  (CS161B)
# Date:             November 19, 2025
# Description: Reads 2 integers from input and performs 3 different types of
               of operations using pointer values.
# Input: 2 integer values, firstInput and secondInput
# Output: outputs the 2 integer values after going through multiple
          transformations
# Sources:
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <cstring>
using namespace std;

// Declare function prototypes
void welcome();
void readInt(int& num);
void swapArgs(int *, int *);
void divideArgs(int *, int *);
void powerArgs(int *, int *);

int main(){
  // Declare variables for user inputs
  int firstInput, secondInput;

  // Gather user inputs
  cout << "Enter integer 1: ";
  readInt(firstInput);
  cout << "Enter integer 2: ";
  readInt(secondInput);

  // Do not allow both inputs to be 0
  if(secondInput == 0 && firstInput == 0){
      cout << "No operations performed!" << endl;
      return 0;
  }

  // Message 1
  cout << "\nBefore call to swapArgs "
       << "a: " << firstInput
       << " b: " << secondInput << endl;

  // Swap and show results
  swapArgs(&firstInput,&secondInput);
  cout << "After call to swapArgs "
       << "a: " << firstInput
       << " b: " << secondInput << endl;

  // Call division and show results
  divideArgs(&firstInput, &secondInput);
  cout << "After call to divideArgs "
       << "a: " << firstInput
       << " b: " << secondInput << endl;

  // Call power function and show results
  powerArgs(&firstInput, &secondInput);
  cout << "After call to powerArgs "
       << "a: " << firstInput
       << " b: " << secondInput << endl;

  // output goodbye message
  cout << "\nGoodbye!" << endl;

  return 0;
}

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome(){
  cout << "Welcome to my Assignment 7 program!!\n" << endl;
}

//Name:   readInt()
//Desc:   Reads user input and performs integer data validation
//input:  integer num as reference
//output: updates num reference integer with a validated integer
//return: void
void readInt(int& num){
  int tempVar = 0;
  cin >> tempVar;
  cin.ignore(100,'\n');
  // Error handle invalid inputs
  while (cin.fail()){
    cin.clear();
    cin.ignore(100,'\n');
    cout << "invalid input, please try again." << endl;
    cin >> tempVar;
    cin.ignore(100,'\n');
  }
  num = tempVar;
}

//Name:   swapArgs()
//Desc: swaps the value pointer integers a and b
//input: pointer integer variables a and b
//output: none
//return: void
void swapArgs(int *a, int *b){
  int tempNum = *(a);
  // dereference and swap values
  *(a) = *(b);
  *(b) = tempNum;
}

//Name:   divideArgs()
//Desc: Performs division of a and b. Quotient stores in a and remainder in b
//input: pointer integer variables a and b
//output: none
//return: void
void divideArgs(int *a, int *b){
  int remainder, quotient;

  // prevent division by 0
  if(*(b) != 0){
    quotient = *(a) / *(b);
    remainder = *(a) % *(b);
    *(a) = quotient;
    *(b) = remainder;
  }

}

//Name:   powerArgs()
//Desc: increases value of a to the power of b
//input: pointer integer variables a and b
//output: none
//return: void
void powerArgs(int *a, int *b){
  // store the original value of a for arithmetic purposes
  int const powerMultiplier = *(a);

  // Conditional to handle power of 0 edge case
  if(*(b) > 0){
    for (int i = 0 ; i < *(b)-1; ++i){
      *(a) = *(a)*powerMultiplier;
    }
  }
  else if (*(b) == 0){
    *(a) = 1;
  }
}
