/******************************************************************************
# Author:           Alan Diaz
# Assignment:       a01  (CS161B)
# Date:             September 25, 2025
# Description: Food cart simulation program.
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
#include <cstring>
using namespace std;

const int MAX_ARRAY_LENGTH = 60;

void welcome();

void displayMenu();

void readOption(char &option);

void encode(char encodedFilename[MAX_ARRAY_LENGTH]);

int main(){
  char encodedFilename[MAX_ARRAY_LENGTH], option;

  welcome();

  do{
    displayMenu();
    readOption(option);

  }
  while(!(option == 'q'));

  return 0;
}

void welcome(){
  cout << "Welcome to my filename encoding program.\n" << endl;
}

void displayMenu(){
  cout << "Please pick an option below:\n"
       << "(e)Encode a file name\n"
       << "(q)Quit" << endl;
}

void readOption(char &option){
  char tempVar;
  cin >> tempVar;
  tempVar = tolower(tempVar);

  while (cin.fail() || tempVar != 'e' && tempVar != 'q'){
    cout << "Invalid option! Please select e or q" << endl;

    cin.clear();
    cin.ignore(1000, '\n');

    cin >> tempVar;
    tempVar = tolower(tempVar);
  }

  option = tempVar;
}

void encode(char encodedFileName[MAX_ARRAY_LENGTH]){
  char firstName[MAX_ARRAY_LENGTH], lastName[MAX_ARRAY_LENGTH],
  submissionTime[MAX_ARRAY_LENGTH], studentId[MAX_ARRAY_LENGTH];

  bool isLate;


}
