// note: this template is to be used for discussion only! you must
// use the required algorithmic design document for all assignments.
/******************************************************************************
# author:           Alan Diaz & Andrew Van Horn
# lab:              Discussion #3
# date:             April 21, 2025
# description:      This program prompts the user for a total change amount
                    and then outputs the change using the fewest 
                    amount of coins.

# input:            promptTotalChange as int 
# output:           int: dollars, quarters, dimes, nickels, pennies
# sources:          none
#******************************************************************************/
#include <iostream>
using namespace std;
int main (){
    // declare variables
    int promptTotalChange;
    int dollars;
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    //tracks the running total of cents
    int remainingCents;
    // inputs
    cout << "Welcome to our Discussion 3 Program\n"
         << "Please input your total change (without decimal points): ";
    cin >> promptTotalChange;

    // data transformations
    // evaluate dollars & store cents
    if (promptTotalChange >= 100){
        remainingCents = promptTotalChange % 100;
        dollars = (promptTotalChange - remainingCents)/100;
    }
    else {
        dollars = 0;
        remainingCents = promptTotalChange;
    }

    // process remaining change
    // evaluate quarters
    if (remainingCents % 25 == 0){
        quarters = remainingCents / 25;
        remainingCents = 0;
    }
    else{
        int remainder = remainingCents % 25;
        quarters = (remainingCents - remainder) / 25;
        remainingCents = remainder;
    }

    // evaluate dimes
    if (remainingCents % 10 == 0){
        dimes = remainingCents / 10;
        remainingCents = 0;

    } else {
        int remainder = remainingCents % 10;
        dimes = (remainingCents - remainder) / 10;
        remainingCents = remainder;
    }
    //evaluate nickels
    if (remainingCents % 5 == 0){
        nickels = remainingCents / 5;
        remainingCents = 0;
    } else {
        int remainder = remainingCents % 5;
        nickels = (remainingCents - remainder) / 5;
        remainingCents = remainder;
    }
    // evaluate pennies
    if (remainingCents % 1 == 0){
        pennies = remainingCents;
    }
    // outputs

    // output of 0
    if (promptTotalChange == 0){
        cout << "No Change." << endl;
    } 
    else{
        // dollar output
        if (dollars == 1 && dollars != 0){
            cout << dollars << " ";
            cout << "Dollar" << endl;
        }
        else {
            cout << dollars << " ";
            cout << "Dollars" << endl;
        }
        //quarter output
        if (quarters == 1 && quarters != 0){
            cout << quarters << " ";
            cout << "Quarter" << endl;
        }
        else {
            cout << quarters << " ";
            cout << "Quarters" << endl;
        }
        //dime output
        if (dimes == 1 && dimes !=0){
            cout << dimes << " ";
            cout << "Dime" << endl;
        }
        else {
            cout << dimes << " ";
            cout << "Dimes" << endl;
        }
        //nickel output
        if (nickels == 1 && nickels != 0 ){
            cout << nickels << " ";
            cout << "Nickel" << endl;
        }
        else {
            cout << nickels << " ";
            cout << "Nickels" << endl;
        } 
        //pennies output
        if (pennies == 1 && changePennies !=0){
            cout << pennies << " ";
            cout << "Penny" << endl;
        } 
        else {
            cout << pennies << " ";
            cout << "Pennies" << endl;
        } 

    }

    cout << "Thank you for using the program!" << endl;

    return 0;
}
