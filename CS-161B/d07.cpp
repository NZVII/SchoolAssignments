/******************************************************************************
# Author:           Alan Diaz
# Assignment:       d07  (CS161B)
# Date:             November 21, 2025
# Description:
# Input: Program asks for the user inputs
# Output: Program outputs the discount, totalCost, finalCost, and tip
# Sources:
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// declare function prototypes
void welcome();
void multiplication();
void pointDecl();
void dereference();
void readInt(int& num);

int main(){
    // declare variables
    char menuInput;

    // output welcome message
    welcome();

    do{

      // Display menu
      cout << "\nSelect one of the following options:\n"
           << "(M)ultiplication Operator\n"
           << "(P)ointer Declaration\n"
           << "(D)ereference Operator\n"
           << "(Q)uit" << endl;

      cin >> menuInput;

      // Find selected user option
      switch(tolower(menuInput)){
        case 'm':
          multiplication();
          break;
        case 'p':
          pointDecl();
          break;
        case 'd':
          dereference();
          break;
        case 'q':
          cout << "Goodbye!" << endl;
          break;
        default:
          cout << "Invalid input. Please try again!" << endl;
      }

    } while(menuInput != 'q' && menuInput != 'Q');


    return 0;
}


//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome(){
    cout << "Welcome to my Discussion 7 Program" << endl
        << "This program will describe the ways the * operation is used."
        << endl;
}

//Name: multiplication()
//Desc:
//input:
//output:
//return: void
void multiplication(){
  // declare variables
  int a, b, product;

  // message output
  cout << "\nThe * symbol is used in\n"
       << "multiplication operations\n"
       << "to multiply 2 or more values.\n"
       << "Syntax: a*b\n"
       << "\nLet's try an example." << endl;

  // collect user inputs
  cout << "Enter the first number for a: ";
  readInt(a);
  cout << "Enter the second number for b: ";
  readInt(b);

  // calculate the result
  product = a*b;

  // output the result
  cout << "Result: " << a << "*" << b << " = " << product << "." << endl;
}

//Name:   pointDecl()
//Desc:
//input:  none
//output:
//return: void
void pointDecl(){
  int num;
  int* ptrNum;

  // message output
  cout << "\nThe * symbol is used for\n"
       << "declaring pointers. Pointers\n"
       << "contain the address to the memory\n"
       << "location of that variable\n"
       << "Syntax: dataType* ptrNum = &num\n"
       << "\nLet's try an example." << endl;

  // collect user input
  cout << "Enter an integer value to store to num: ";
  readInt(num);

  // set the pointer variable
  ptrNum = &num;

  cout << "Result: the address location, ptrNum, to the value\n"
       << "of " << num << " is " << ptrNum << "." << endl;
}

//Name:   dereference()
//Desc:
//input:  none
//output:
//return: void
void dereference(){
  int num;
  int* ptrNum;

  // message output
  cout << "\nThe * symbol is used for\n"
       << "dereferencing pointer variables.\n"
       << "Dereferencing retrieves the value\n"
       << "stored in the address location\n"
       << "Syntax: *(ptrNum)\n"
       << "\nLet's try an example." << endl;

  // collect user input
  cout << "Enter an integer value to store to num: ";
  readInt(num);

  // set the pointer variable
  ptrNum = &num;

  cout << "Result: the value of the pointer is " << ptrNum << "\n"
       << "and the dereferenced value of the pointer is " << *(ptrNum) << endl;

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
