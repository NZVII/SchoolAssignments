/******************************************************************************
# Author:           Gayathri Iyer
# Assignment:       A1 Sample (CS161A)
# Date:             March 29, 2022
# Description:      This program will read the principal amount, rate, and period #
in years and calculate Simple Interest for the user.
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Assignment 1 specifications
#                   and any other substantial aids, like web pages or students
#                   who helped you.
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
using namespace std;
//main function
int main() {
  // declaring variables used for user input
  int employeeID;
  int hoursWorked;
  int hourlyRate;
  double fedWithholdingRate;
  // declaring variables used for calculations
  int grossPay;
  int fedTaxWithholding;
  int netPay;
  // END variable declarations

  // USER INPUTS
  cout << "*** Welcome to the National Payroll Program *** \n";
  cout << "Enter the employee ID: ";
  cin >> employeeID;
  cout << "Enter the number of hours worked: ";
  cin >> hoursWorked;
  cout << "Enter the hourly rate: ";
  cin >> hourlyRate;
  cout << "Enter the federal withholding rate: ";
  cin >> fedWithholdingRate;
  // END user inputs

  // doing calculations
  grossPay = hoursWorked * hourlyRate;
  fedTaxWithholding = grossPay * ( fedWithholdingRate / 100);
  netPay = grossPay - fedTaxWithholding;
  // display results
  cout << "--Payroll Summary-- \n";
  cout << "Total gross pay: $" << grossPay << endl;
  cout << "Federal tax withholding: $" << fedTaxWithholding << endl;
  cout << "Net pay: $" << netPay << endl;


  //end program
  cout << "Thank you for using the program. Goodbye!" << endl;
  return 0;
}
