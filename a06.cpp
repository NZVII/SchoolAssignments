/******************************************************************************
# Author:           Alan Diaz
# Assignment:       A6 (CS161A)
# Date:             May 13, 2025
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
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  // accumulators that need to remain after the loop
  double balance = 0;
  double itemsTotal = 0;
  char menuSelection;
  cout << "Welcome to the Coffee & Tea Vending Machine!\n" << endl;
  do{
    int numCoins;
    while(true){
      cout << "Enter coins - 5, 10, or 25 only (0 to end): "
           << fixed << setprecision(2);
      cin >> numCoins;
      if(numCoins == 5 || numCoins == 10 || numCoins == 25){
        balance = balance + (static_cast<double>(numCoins)/100);
        continue;
      }
      else if (numCoins == 0){
        break;
      }
      else {
        cout << "Invalid input, please try again" << endl;
      }
    }
    
    cout << "\nYour balance is: $" << balance << endl
         << "\nPlease pick an option ($0.25 each): " << endl
         << "C/c: Coffee" << endl
         << "T/t: Tea" << endl
         << "Q/q: Quit" << endl;
    cin >> menuSelection;
    menuSelection = tolower(menuSelection);
    while(menuSelection != 'c' && menuSelection != 't' && menuSelection != 'q'){
      cout << "Invalid Option! Please choose a valid option." << endl;
      cin >> menuSelection;
      menuSelection = tolower(menuSelection);
    }
    if (menuSelection == 'c' || menuSelection == 't'){
      double tempBalance = balance;
      int drinkCount;
      cout << "How many would you like: ";
      cin >> drinkCount;
      //FIXME: handle validation
      while(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid option! Please choose a valid option: ";
        cin >> drinkCount;
      }

      itemsTotal = (0.25 * drinkCount);
      tempBalance = tempBalance - itemsTotal;
      if (tempBalance < 0){
        cout << "Your total is: $" << itemsTotal << endl
             << "Your balance is: $" << balance << endl
             << "Insufficient funds. Please add more coins..." << endl; 
             continue;
      }
      else if (tempBalance >=0){
        cout << "Your total is: $" << itemsTotal << endl
             << "Your remaining balance is: $" << balance - itemsTotal << endl;
             break;
      }
    }
  }
  while (menuSelection != 'q');
  cout << "\nThank you for using Vending Machine Program!" << endl;
  return 0;
}
