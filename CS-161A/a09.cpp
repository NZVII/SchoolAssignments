/******************************************************************************
# Author:           Alan Diaz
# Assignment:       A9 (CS161A)
# Date:             June 2, 2025
# Description:      This program gets an x amount of assignments from the user
                    then asks the user to input x amount of positive numbers.
                    The program returns the maximum and minimum values with
                    the position they were found in.
# Input:  int numIntegers
# Output: int minNum, minPos, maxNum, maxPos
# Sources:
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <climits>
#include <string>
#include <iomanip>
using namespace std;

int maxNum = INT_MAX * -1;
int minNum = INT_MAX;
int maxPos, minPos;

void getInput(int& num);
void doStates(int num);

int main(){
  int numIntegers;
  cout << "Welcome to my Final Exam Practice\n" << endl;

  getInput(numIntegers);

  if (cin.fail()){
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Invalid input" << endl;
  }
  else if (numIntegers <= 0){
    cout << "Only enter positive integers" << endl;
  }
  else if (numIntegers > 0){
    doStates(numIntegers);
    cout << "\nThe minimum number entered was "
         << minNum << " entered in position " << minPos << endl; 
    cout << "The maximum number entered was "
         << maxNum << " entered in position " << maxPos << endl; 
  }
 
  cout << "\nThank you for using my program" << endl;
  return 0;
}

void getInput(int& num){
  cout << "How many positive integers do you want to enter? ";
  cin >> num;
}

void doStates(int num){
  for(int i = 1; i < num+1; ++i){
    while(true){
      int input;
      cout << "Enter integer #" << i << ": ";
      cin >> input;
      if (input > 0){
        // assign maximum
        if (input > maxNum){
          maxNum = input;
          maxPos = i;
        }
        // assign minimum
        if (input < minNum){
          minNum = input;
          minPos = i;
        }
        break;
      }
      else
      {
        cout << "Enter a valid positive integer!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        continue;
      }
    }
  }
}