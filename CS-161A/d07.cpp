/******************************************************************************
# Author:           Alan Diaz
# Lab:              Discussion #7
# Date:             May 24, 2025
# Description:      This program displays a menu and asks the user to make a
#                   selection. A do-while loop repeats the program until the
#                   user selects item 4 from the menu.
# Input:            integer membership category, integer months
# Output:           float membership costs
# Sources:          None
#******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Constants for menu choices
const int ADULT_CHOICE = 1,
            CHILD_CHOICE = 2,
            SENIOR_CHOICE = 3,
            QUIT_CHOICE = 4;

// Constants for membership rates
const double ADULT = 40.0,
            CHILD = 20.0,
            SENIOR = 30.0;

// Add function prototypes here

int ValidateInput(string inputType);
void DisplayMenu();

int main()
{  
   // Variables
   int choice = 0;         // Menu choice
   int months = 0;         // Number of months
   double charges = 0.0;   // Monthly charges

   cout << fixed << showpoint << setprecision(2);

   do
   {
      // Display the menu.
      DisplayMenu();
      choice = ValidateInput("menu");
      // Validate and process the user's choice.
      if (choice != QUIT_CHOICE)
      {
         // Get the number of months.
         cout << "For how many months? ";
         // cin >> months;
         months = ValidateInput("months");

         // Respond to the user's menu selection.
         switch (choice)
         {
            case ADULT_CHOICE:
                charges = months * ADULT;
                break;
            case CHILD_CHOICE:
                charges = months * CHILD;
                break;
            case SENIOR_CHOICE:
                charges = months * SENIOR;
         }

         // Display the monthly charges.
         cout << "The total charges are $"
              << charges << endl;
      }
   } while (choice != QUIT_CHOICE);

   return 0;
}

int ValidateInput(string inputType){
   int input;
   cin >> input;
   while (cin.fail()){
      cin.clear();
      cin.ignore(10000,'\n');
      cout << "Please enter a number: ";
      cin >> input;
   }
   if (inputType == "menu"){
      while (input < ADULT_CHOICE || input > QUIT_CHOICE){
         cout << "Please enter a valid menu choice: ";
         cin >> input;
      }
   }
   else if (inputType == "months"){
      while (input < 0 || input > 60)
         {
             cout << "Please enter months between 0 and 60: ";
             cin >> input;
         }
   }
   return input;
}

void DisplayMenu(){
      cout << "\n\t\tHealth Club Membership Menu\n\n"
           << "1. Standard Adult Membership\n"
           << "2. Child Membership\n"
           << "3. Senior Citizen Membership\n"
           << "4. Quit the Program\n\n"
           << "Enter your choice: ";
}