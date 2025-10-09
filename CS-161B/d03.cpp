/******************************************************************************
# Author:           Alan Diaz
# Lab:              Discussion #3
# Date:             October 9, 2025
# Description:      Program to check if an area in an array is in ascending order
# Input:            Number of integers, the array values, start and end indices
# Output:           "yes" if it is in ascending order; otherwise, "no".
# Sources:          None
#******************************************************************************/
#include <iostream>
using namespace std;

//Name:   validateStartEnd()
//Desc:   Function to validate user input for start and end indices
//input: start and end indexes as int. length of inputs as int
//output: sets start  and end indices.
//return: void
void validateStartEnd(int& start, int& end, int maxLength){
  bool isValid;
  do {
    isValid = true; // Assume input is valid until validation fails
    cout << "Start index: ";
    cin >> start;
    cout << "End index: ";
    cin >> end;

    // Check if start index is out of bounds.
    // Can't be negative or over the array length
    if (start > 0 || start > maxLength){
      isValid = false;
      cout << "\nThe starting index can not be greater than "
           << "the number of integers or less than 0." << endl;
    }

    // Check if end index is out of bounds.
    // Can't be negative or over the array length
    if (end < 0 || end > maxLength){
      isValid = false;
      cout << "\n\nThe ending index can not be greater than "
           << "the number of integers or less than 0." << endl;
    }

    // Check if the start index is greater than the end index
    if (start > end){
      isValid = false;
      cout << "\nThe starting index must be less than the ending index"
      << endl;
    }

  }
  while(!isValid);
}

//Name:   results()
//Desc:  Print the final results.
//input: Boolean isAscending to check if the numbers are ascending
//output: prints "yes" if numbers are ascending; Otherwise, "no".
//return: void
void results(bool isAscending){
  cout << "\nResults" << endl;
  if (isAscending == true){
    cout << "yes";
  }
  else
  {
    cout << "no";
  }
  cout << endl;
}

// Define maximum array size to avoid memory issues
const int MAX_ARRAY_LENGTH = 20;

int main(){
  int numIntegers; // Number of integers user can input
  int userNumbers[MAX_ARRAY_LENGTH]; // Array to store user input
  int startIndex, endIndex; // Range in the array to check
  bool isAscending = true; //Boolean to track if the numbers are ascending


  // Get the number of integers from user
  cout << "Number of integers: ";
  cin >> numIntegers;


  // Input loop to populate the array
  for (int i = 0; i < numIntegers; ++i){
    int userValue;
    cout << "Enter the value #" << i+1 << ": ";

    cin >> userValue;
    userNumbers[i] = userValue; // Store value in array
  }
  cout << endl;

  // Validate and store the start and end indices for evaluation
  validateStartEnd(startIndex, endIndex, numIntegers);

  // Check if the numbers from startIndex to endIndex is in ascending order
  int prevNum = userNumbers[startIndex];//Initialize with first element for comparing
  for (int i = startIndex + 1; i <= endIndex; ++i){
    // If previous number is greater than current, not ascending
    if(prevNum > userNumbers[i]){
      isAscending = false;
    }
    prevNum = userNumbers[i]; // Update previous number for next comparison
  }
  // Display results
  results(isAscending);


  return 0;
}
