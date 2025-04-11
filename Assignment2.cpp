/******************************************************************************
# Author:           Alan Diaz
# Assignment:       A2  (CS161A)
# Date:             April 9, 2025
# Description:
# Input:
# Output:
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
    // START declaring variables used for user input
    int cookiesEaten;
    // Declare variables used for calculations
    double userServings;
    double userTotalCalories;
    // Declare constants
    int packageServings = 5;
    int caloriesPerServing = 160;
    // END variable declarations
    //
    cout << "Welcome to the Oreo Calorie Counter Program \nHow many cookies have you've eaten today? ";
    cin >> cookiesEaten;

    // START calculations
    userServings = cookiesEaten / static_cast<double>(packageServings);
    userTotalCalories = userServings * caloriesPerServing;
    // END calculations

    cout << "Here is a summary of your caloric intake:\nTotal Servings: " << userServings << "\nTotal Calories: " << userTotalCalories << endl;

  return 0;
}
