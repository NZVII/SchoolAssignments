// note: this template is to be used for discussion only! you must
// use the required algorithmic design document for all assignments.
/******************************************************************************
# author:           Alan Diaz & Andrew Van Horn
# lab:              Discussion #4
# date:             April 28, 2025
# description:      The program creates a user name based on inputs from
                    user. It asks for the first and last name, and a four
                    digit integer. The program then returns a login name.

# input:            string firstName, string lastName, int loginNameIntegers
# output:           string loginName 
# sources:          none
#******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
int main (){
    // declare variables
    string firstName;
    string lastName;
    string nameIntegers;
    string loginName;

    cout << "Welcome to the Login Name Creation program\n" << endl;
    cout << 
    "Please enter your first & last name, followed a couple of numbers: ";

    cin >> firstName;
    cin >> lastName;
    cin >> nameIntegers; 

    cout << endl;

    // START perform data manipulation
    
    // reassign firstName to the first letter of the first name;
    firstName = firstName.substr(0,1);

    // reassigns lastName to the first 5 letters of lastName
    if(lastName.length() > 5){
        lastName = lastName.substr(0,5);
    }

    if(nameIntegers.length() > 2){
        int getLastTwoIndex = nameIntegers.length() - 2;
        nameIntegers = nameIntegers.substr(getLastTwoIndex,2);
    }

    // END data manipulation
    // result
    cout << "Your Login Name is: "
         << lastName << firstName << nameIntegers << endl;

    return 0;
}
