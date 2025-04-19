// NOTE: This template is to be used for discussion ONLY! You must
// use the required Algorithmic Design Document for all Assignments.
/******************************************************************************
# Author:           Alan Diaz & Andrew Van Horn 
# Lab:              Discussion #2
# Date:             April 12, 2025
# Description:      This program prompts for a vehicle's mpg and the price per
                    gallon then calculates the total cost per gallon for
                    20, 75, and 500 miles.

# Input:            double carMpg, double costPerGallon
# Output:           double totalGasCost
# Sources:          None
#******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main (){
    // START declare variables
    double carMpg; 
    double costPerGallon;
    double totalGasCost;
    double gallonsUsed;
    int milesRan;
    // END declare variables
    // START recieve user input
    cout <<"---"<<"Welcome to the driving costs calculator"<<"---"<<endl;
    cout << "Enter your vehicle's mpg: ";
    cin >> carMpg;
    cout << "Enter the price per gallon: ";
    cin >> costPerGallon;
    cout << endl;
    // END receive user input
    // START calculations

    cout << "----Summary----" << endl;
    /* Get the amount of gas used by the vehicle for 20 miles & output*/ 
    milesRan = 20;
    gallonsUsed = milesRan / carMpg;
    totalGasCost = gallonsUsed * costPerGallon;
    cout << setprecision(2) << fixed << "Gas cost for "<< milesRan 
    << " miles: " << totalGasCost << endl;

    /* Get the amount of gas used by the vehicle for 75 miles & output*/ 
    milesRan = 75;
    gallonsUsed = milesRan / carMpg;
    totalGasCost = gallonsUsed * costPerGallon;

    cout << "Gas cost for "<< milesRan << " miles: " << totalGasCost << endl;

    /* Get the amount of gas used by the vehicle for 75 miles & output*/ 
    milesRan = 500;
    gallonsUsed = milesRan / carMpg;
    totalGasCost = gallonsUsed * costPerGallon;

    cout << "Gas cost for "<< milesRan << " miles: " << totalGasCost << endl;

    // END calculation & outputs
    cout << "\nThank you for using our calculator" << endl;

    return 0;
}
