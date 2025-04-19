/******************************************************************************
# Author:           Alan Diaz
# Assignment:       A2  (CS161A)
# Date:             April 18, 2025
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
#include <iomanip>
using namespace std;

int main(){
   //****************program variables
   // input variables
   char inputVehicle;
   int inputNumAdults;
   int inputNumSeniors;
   int inputNumYouths;
   // output variables
   double totalCharge;
   double freeTicketAmount;

   const double TICKET_VEHICLE = 57.90;
   const double TICKET_ADULT = 14.95;
   const double TICKET_SENIOR = 7.40;
   const double TICKET_YOUTH = 5.55;

   // console output
   cout << fixed << "Welcome to the Washington State Ferries Fare Calculator" << endl;
   // cout << "Fare Description" << right << setfill(' ') << "Ticket $";
   cout << left << setw(30) << "Fare Description"
        << setw(10) << "Ticket $" << endl;
   return 0;
}
