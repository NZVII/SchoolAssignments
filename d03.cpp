// note: this template is to be used for discussion only! you must
// use the required algorithmic design document for all assignments.
/******************************************************************************
# author:           Alan Diaz
# lab:              Discussion #3
# date:             April 12, 2025
# description:      This program prompts for a vehicle's mpg and the price per
                    gallon then calculates the total cost per gallon for
                    20, 75, and 500 miles.

# input:            double carmpg, double costpergallon
# output:           double totalgascost
# sources:          none
#******************************************************************************/

#include <iomanip>
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

    // if there is no remaining change, set all to 0

    // process remaining change
    // evaluate quarters
    if (totalCents % 25 == 0){
        changeQuarters = totalCents / 25;
    } else{
        int remainder = totalCents % 25;
        changeQuarters = (totalCents - remainder) / 25;
        totalCents = remainder;
    }

    // evaluate dimes
    if (totalCents % 10 == 0){
        changeDimes = totalCents / 10;
    } else {
        int remainder = totalCents % 10;
        changeDimes = (totalCents - remainder) / 10;
        totalCents = remainder;
    }


    // outputs
    // dollar output
    cout << changeDollars << " ";
    if (changeDollars == 1){
        cout << "Dollar" << endl;
    }
    else {
        cout << "Dollars" << endl;
    }
    //quarter output
    cout << changeQuarters << " ";
    if (changeQuarters == 1){
        cout << "Quarter" << endl;
    }
    else {
        cout << "Quarters" << endl;
    }
    //dime output
    cout << changeDimes << " ";
    if (changeQuarters == 1){
        cout << "Dime" << endl;
    }
    else {
        cout << "Dimes" << endl;
    }



    return 0;
}