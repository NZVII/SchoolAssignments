/******************************************************************************
# Author:           Alan Diaz
# Assignment:       A5 (CS161A)
# Date:             May 8, 2025
# Description:      The purpose of the program is to calculate and store 
                    the total cost of a pizza party in an accumulator variable. 
                    The program will ask for the average number of slices
                    per person, the total cost of one pizza, 
                    and the # of participants. The program then calculates 
                    and outputs the average number of pizzas for all the 
                    pizza parties.
# Input:  ints: numAttendees, numPizzas ; 
          doubles: singlePizzaCost, avgSlicesPerAttendees
# Output: doubles: tax, deliveryFee, totalPartyCost, partyPizzasCost
                   , maxPartyCost
          int: numPizzas, maxNumPeople, totalNumPizzas, maxNumParties,
               
# Sources:
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  // accumulators that need to remain after the loop
  int totalNumPizzas = 0; 
  int totalNumParties = 0;
  int maxNumPeople = 0;
  double maxPartyCost = 0;

  cout << "Welcome to my Pizza Party Statistics program!\n" << endl;
  char option;
  do{

    double tax = 0.07;
    double deliveryFee = 0.2;

    // party inputs
    int numAttendees;
    double singlePizzaCost, avgSlicesPerAttendees;

    int numPizzas;
    double totalPartyCost, partyPizzasCost;

    cout << "Enter the number of people, average number of slices per person,"
         << " and the cost of one pizza."
         << " all values must be separated by a space: "
         << fixed << setprecision(2);
    

    cin >> numAttendees >> avgSlicesPerAttendees >> singlePizzaCost;

    // error handle for invalid inputs
    while (cin.fail()){
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "invalid input, try again: ";
      cin >> numAttendees >> avgSlicesPerAttendees >> singlePizzaCost;
    }

    // calculate pizza party costs
    numPizzas = ceil(static_cast<double>(
      numAttendees*avgSlicesPerAttendees)/8);
    partyPizzasCost = numPizzas * singlePizzaCost;
    tax = partyPizzasCost * tax;
    deliveryFee = (partyPizzasCost + tax) * deliveryFee;
    totalPartyCost = partyPizzasCost + tax + deliveryFee;

    // update accumulator variables and max variables
    if (numAttendees > maxNumPeople){
      maxNumPeople = numAttendees;
    }
    if (totalPartyCost > maxPartyCost){
      maxPartyCost = totalPartyCost;
    }
    totalNumParties = totalNumParties + 1;
    totalNumPizzas = totalNumPizzas + numPizzas;

    cout << "\nNumber of pizzas (assuming 8 slices per pizza): "
         << numPizzas << endl
         << "Cost of Pizzas: $"
         << partyPizzasCost << endl
         << "Total Sales Tax: $"
         << tax << endl
         << "Delivery Fee: $"
         << deliveryFee << endl
         << "Total cost: $"
         << totalPartyCost << endl
         << "\nWould you like to add another party (y/n): ";

    cin >> option;
    option = tolower(option);
    while (option != 'y' && option != 'n'){
      cout << "Invalid input, please try again: ";
      cin >> option;
      option = tolower(option);
    }
  }
  while(option != 'n');

  cout << "\nThank you for using the program!\n"
       << "\nSummary of all Results" << endl
       << "Number of parties/entries: " << totalNumParties << endl
       << "Total number of Pizzas: " << totalNumPizzas << endl
       << "Average number of pizzas: " 
       << static_cast<double>(totalNumPizzas) / totalNumParties
       << endl
       << "Maximum number of people: " << maxNumPeople << endl
       << "Maximum cost of pizzas: $" << maxPartyCost << endl;


  

  return 0;
}
