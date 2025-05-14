// note: this template is to be used for discussion only! you must
// use the required algorithmic design document for all assignments.
/******************************************************************************
# author:           Alan Diaz
# lab:              Discussion #5
# date:             May 12, 2025
# description:      Program that determines if you are drinking enough water.
                    outputs the average number of glasses, the max, the min,
                    the total duration, and the total number of glasses drank.
# input: numGlasses
# output: maxNumberGlasses, minNumberGlasses, avgNumberGlasses,
          totalNumberGlases,duration
# sources:
#******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
int main (){
    // declare variables
    int numGlasses;
    int maxNumberGlasses = 0;
    int minNumberGlasses;
    double avgNumberGlasses = 0;
    int totalNumberGlasses = 0;
    int duration = 1;

    cout << "Welcome to the Water Consumption Calculator" << endl
         << "It is recommended that the average person consumes 6-8 "
         << "glasses of water per day.\n" << endl;

    char input;
    do{
      numGlasses = 0;
      cout << "Enter the number of 8oz glasses of water you've drank on day "
           << duration << ": ";
      cin >> numGlasses;
      cout << endl;
      totalNumberGlasses = totalNumberGlasses + numGlasses;
      if (maxNumberGlasses < numGlasses){
          maxNumberGlasses = numGlasses;
      }
      if (minNumberGlasses > numGlasses){
          minNumberGlasses = numGlasses;
      }
      ++duration;
      cout << "Add another day (y/n): ";
      cin >> input;
      input = tolower(input);
      while (input != 'y' && input != 'n'){
        cout << "Invalid input, please try again: ";
        cin >> input;
        input = tolower(input);
      }
      cout << endl;
    }
    while(input != 'n');

    avgNumberGlasses = static_cast<double>(totalNumberGlasses) / duration;

    // Results

    cout << "Your result: ";
    if (avgNumberGlasses >= 6){
        cout << "You are a hydrated human!" << endl;
    }
    else {
        cout << "Drink more water!" << endl;
    }
    cout << endl;

    cout << "Total number of glasses drank in " << duration << " days: "
         << totalNumberGlasses << endl
         << "Average number of glasses: " << avgNumberGlasses << endl
         << "Most amount of glasses drank: " << maxNumberGlasses << endl
         << "Least amount of glasses drank: " << minNumberGlasses << endl;

    return 0;
}
