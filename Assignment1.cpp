/******************************************************************************
# Author:           Alan Diaz
# Assignment:       A2  (CS161A) 
# Date:             April 9, 2025
# Description: Program to calculate payroll for employees.
# Input: Program asks for the employee ID, hours worked, hourly rate, 
and federal withholding rate
# Output: Program outputs the total gross pay, the federal withholding tax, 
and the netpay
# Sources:
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
