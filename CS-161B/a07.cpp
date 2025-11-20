/******************************************************************************
# Author:           Alan Diaz
# Assignment:       a07  (CS161B)
# Date:             November 19, 2025
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
#include <cstring>
#include <iomanip>
using namespace std;

// Declare function prototypes
void welcome();
void readInt(int& num);
void swapArgs(int *, int *);
void divideArgs(int *, int *);
void powerArgs(int *, int *);

int main(){
  int firstInput, secondInput;

  // Gather user inputs
  cout << "Enter integer 1: ";
  readInt(firstInput);
  cout << "Enter integer 2: ";
  readInt(secondInput);

  if(secondInput == 0 && firstInput == 0){
      cout << "No operations performed!" << endl;
      return 0;
  }

  cout << "\nBefore call to swapArgs "
       << "a: " << firstInput
       << " b: " << secondInput << endl;

  swapArgs(&firstInput,&secondInput);
  cout << "After call to swapArgs "
       << "a: " << firstInput
       << " b: " << secondInput << endl;


  divideArgs(&firstInput, &secondInput);
  cout << "After call to divideArgs "
       << "a: " << firstInput
       << " b: " << secondInput << endl;


   powerArgs(&firstInput, &secondInput);
   cout << "After call to powerArgs "
        << "a: " << firstInput
        << " b: " << secondInput << endl;

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

//Name:   readInput()
//Desc:   This function reads course numbers and student counts from user
//input:  courseNums array, students array, count by reference
//output: prompts for course numbers and student counts
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
//Desc:
//input:
//output:
//return: void
void swapArgs(int *a, int *b){
    int tempNum = *(a);
    *(a) = *(b);
    *(b) = tempNum;
}

//Name:   divideArgs()
//Desc:
//input:
//output:
//return: void
void divideArgs(int *a, int *b){
    int remainder, quotient;

    quotient = *(a) / *(b);
    remainder = *(a) % *(b);

    *(a) = quotient;
    *(b) = remainder;
}

//Name:   powerArgs()
//Desc:
//input:
//output:
//return: void
void powerArgs(int *a, int *b){
    int const powerMultiplier = *(a);
    if(*(b) > 0){
        for (int i = 0 ; i < *(b)-1; ++i){
            *(a) = *(a)*powerMultiplier;
        }
    }
    else if (*(b) == 0){
        *(a) = 1;
    }
}
