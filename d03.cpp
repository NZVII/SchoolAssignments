// note: this template is to be used for discussion only! you must
// use the required algorithmic design document for all assignments.
/******************************************************************************
# author:           Alan Diaz
# lab:              Discussion #3
# date:             April 12, 2025
# description:      This program prompts the user for a total change amount
                    and then outputs the change using the fewest coins

# input:            double carmpg, double costpergallon
# output:           double totalgascost
# sources:          none
#******************************************************************************/
#include <iostream>
using namespace std;
int main (){
    // declare variables
    int promptTotalChange;
    int changeDollars;
    int changeQuarters;
    int changeDimes;
    int changeNickels;
    int changePennies;
    //tracks the running total of cents
    int totalCents;
    // inputs
    cin >> promptTotalChange;

    // data transformations
    // evaluate dollars & store cents
    if (promptTotalChange >= 100){
        totalCents = promptTotalChange % 100;
        changeDollars = (promptTotalChange - totalCents)/100;
    }
    else {
        changeDollars = 0;
        totalCents = promptTotalChange;
    }

    // process remaining change
    // evaluate quarters
    if (totalCents % 25 == 0){
        changeQuarters = totalCents / 25;
        totalCents = 0;
    }
    else{
        int remainder = totalCents % 25;
        changeQuarters = (totalCents - remainder) / 25;
        totalCents = remainder;
    }

    // evaluate dimes
    if (totalCents % 10 == 0){
        changeDimes = totalCents / 10;
        totalCents = 0;

    } else {
        int remainder = totalCents % 10;
        changeDimes = (totalCents - remainder) / 10;
        totalCents = remainder;
    }
    //evaluate nickels
    if (totalCents % 5 == 0){
        changeNickels = totalCents / 5;
        totalCents = 0;
    } else {
        int remainder = totalCents % 5;
        changeNickels = (totalCents - remainder) / 5;
        totalCents = remainder;
    }
    // evaluate pennies
    if (totalCents % 1 == 0){
        changePennies = totalCents;
    }
    // outputs
    // dollar output
    if (changeDollars == 1 && changeDollars != 0){
        cout << changeDollars << " ";
        cout << "Dollar" << endl;
    }
    else {
        cout << changeDollars << " ";
        cout << "Dollars" << endl;
    }
    //quarter output
    if (changeQuarters == 1 && changeQuarters != 0){
        cout << changeQuarters << " ";
        cout << "Quarter" << endl;
    }
    //dime output
    if (changeDimes == 1 && changeDimes !=0){
        cout << changeDimes << " ";
        cout << "Dime" << endl;
    }
    //nickel output
    if (changeNickels == 1 && changeNickels != 0 ){
        cout << changeNickels << " ";
        cout << "Nickel" << endl;
    }
    //pennies output
    if (changePennies == 1 && changePennies !=0){
        cout << changePennies << " ";
        cout << "Penny" << endl;
    }
    return 0;
}
