/******************************************************************************
# Author:           Alan Diaz
# Assignment:       a01  (CS161B)
# Date:             September 25, 2025
# Description: Food cart simulation program.
# Input: Program asks for the user inputs
# Output: Program outputs the discount, totalCost, finalCost, and tip
# Sources:
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// Discount amounts for small and large orders
const double LARGE_ORDER_DISCOUNT = 0.10;
const double SMALL_ORDER_DISCOUNT = 0.05;

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome();

//Name:   displayMenu()
//Desc:   This function displays the user menu options
//input:  none
//output: menu options to console
//return: void
void displayMenu();

//Name:   readOption()
//Desc:   This function handles user input for the menu options
//input:  option (int reference)
//output: error messages for invalid input
//return: void
void readOption(int& option);

//Name:   readInt()
//Desc:   This function validates and reads integer input
//input:  num (int reference), prompt (string with default empty)
//output: error messages for invalid input
//return: void
void readInt(int& num, string prompt="");

//Name:   readDouble()
//Desc:   This function validates and reads double input
//input:  num (double reference), prompt (string with default empty)
//output: error messages for invalid input
//return: void
void readDouble(double& num, string prompt="");

//Name:   placeOrder()
//Desc:   This function handles the order placement process
//input:  cost (double reference)
//output: prompts for item name and cost, confirmation messages
//return: void
void placeOrder(double& cost);

//Name:   tipDiscount()
//Desc:   This function handles tip and discount calculations
//input:  tip (double reference), discount (double reference), cost (double)
//output: prompt for tip amount
//return: double (final cost after tip and discount)
double tipDiscount(double& tip, double& discount, double cost);

int main(){
    int userInput;
    double orderTip, totalCost, finalCost, discount;

    welcome();

    do{

        displayMenu();

        readOption(userInput);

        if (userInput == 1){
            placeOrder(totalCost);
            cout << setprecision(2) << fixed << "\nYour total is $"
            << totalCost << endl;

            finalCost = tipDiscount(orderTip, discount, totalCost);

            if (totalCost > 50){
                cout << "You get a " << LARGE_ORDER_DISCOUNT * 100
                << "% discount!" << endl;
            }
            else if (totalCost > 35 && totalCost < 50){
                cout << "You get a " << SMALL_ORDER_DISCOUNT * 100 << "% discount!" << endl;
            }

            cout << "\nYour discount is $" << discount << endl;
            cout << "Your final total is: $" << finalCost << endl;
        }
    }

    while(userInput != 2);

    cout << "\nThank you for using my Food Cart Program!" << endl;
    return 0;
}



void welcome(){
    cout << "Welcome to my Food Cart Program!" << endl;
}

void displayMenu(){
    cout << "What would you like to do today?" << endl
    << "1. Place an order" << endl
    << "2. Quit" << "\n" << endl;
}

void readOption(int& option){
    int userChoice;

    readInt(userChoice);

    while(userChoice != 1 && userChoice != 2){
        cout << "Invalid option. Please choose 1 or 2!" << endl;
        cin.clear();
        cin.ignore(100,'\n');
        readInt(userChoice);
    }

    option = userChoice;

}

void readInt(int& num, string prompt){
   int tempVar = 0;
   // prints the prompt if it is not empty
   if (prompt != ""){
       cout << prompt << ": ";
   }
   cin >> tempVar;
   // Error handle invalid inputs
   while (cin.fail()){
       cin.clear();
       cin.ignore(100,'\n');
       cout << "invalid input, please try again." << endl;
       cin >> tempVar;
   }
   num = tempVar;
}

void readDouble(double& num, string prompt){
   double tempVar = 0;
   // prints the prompt if it is not empty
   if (prompt != ""){
       cout << prompt << ": ";
   }
   cin >> tempVar;
   // Error handling for invalid inputs
   while (cin.fail()){
       cin.clear();
       cin.ignore(100,'\n');
       cout << "invalid input, please try again." << endl;
       cin >> tempVar;
   }
   num = tempVar;
}

void placeOrder(double& cost){
   char userChoice;
   double tempVar = 0;
   string itemName;

   do{
       cout << "\nEnter the name of your item: ";
       cin >> itemName;

       readDouble(tempVar, "Enter the cost of your item");
       cost = cost + tempVar;

       cout << "Would you like to add another item? (y/n): ";
       cin >> userChoice;
       userChoice = tolower(userChoice);

       while(cin.fail() || userChoice != 'y' && userChoice != 'n'){
           cin.clear();
           cin.ignore(100,'\n');
           cout << "invalid option, please choose y/n." << endl;
           cin >> userChoice;
       }
   }
   while(userChoice != 'n');
}

double tipDiscount(double& tip, double& discount, double cost){
   double total;
   readDouble(tip, "\nEnter the amount of tip you want to add $");
   // total is the cost plus the tip
   total = cost + tip;

   // Calculate discounts based off the cost plus the tip
   if (total > 50){
       discount = LARGE_ORDER_DISCOUNT * cost;
   }
   else if (total > 35 && total < 50){
       discount = SMALL_ORDER_DISCOUNT * cost;
   }
   return total - discount;
}
