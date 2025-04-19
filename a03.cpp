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
     // input variables
     char inputVehicle;
     int inputNumAdults;
     int inputNumSeniors;
     int inputNumYouths;
     int inputNumBikes;
     // output variables
     double totalCharge = 0;
     double freeTicketCounter;

     const double TICKET_VEHICLE = 57.90;
     const double TICKET_ADULT = 14.95;
     const double TICKET_SENIOR = 7.40;
     const double TICKET_YOUTH = 5.55;
     const double BICYCLE_SURCHARGE = 4.00;
     const int FREE_TICKET_COST = 100;
     const int GROUP_LIMIT = 20;

     const int COLUMN_1_WIDTH = 50;
     const int COLUMN_2_WIDTH = 10;
     const int COLUMN_GAP = 5;

     // console output
     cout << fixed 
          << setprecision(2)
          << "Welcome to the Washington State Ferries Fare Calculator\n"
          << "Group size limit: " << GROUP_LIMIT << " or less.\n" << endl;
     
     /******2 COLUMN TABLE******/
     //header
     cout << left << setw(COLUMN_1_WIDTH) << "Fare Description"
          << setfill(' ') << setw(COLUMN_GAP) << ""
          << setw(COLUMN_2_WIDTH) << "Ticket $" << endl;
     //divider
     cout << setfill('-') << setw(COLUMN_1_WIDTH) << ""
          << setfill(' ') << setw(COLUMN_GAP) << ""
          << setfill('-') << setw(COLUMN_2_WIDTH)  <<  "" << endl;
          //row #1
     cout << setfill(' ')
          << left << setw(COLUMN_1_WIDTH) 
          << "Vehicle Under 14' (less than 168\") & Driver"
          << setfill(' ') << setw(COLUMN_GAP) << ""
          << setw(COLUMN_2_WIDTH) << "$57.90" << endl; //row #2
     cout 
          << left << setw(COLUMN_1_WIDTH) << "Adult (age 19 - 64)" 
          << setfill(' ') << setw(COLUMN_GAP) << ""
          << setw(COLUMN_2_WIDTH) << "$14.95" << endl;
     //row #3
     cout 
          << left << setw(COLUMN_1_WIDTH) 
          << "Senior (age 65 & over) / Disability" 
          << setfill(' ') << setw(COLUMN_GAP) << ""
          << setw(COLUMN_2_WIDTH) << "$7.40" << endl;

     //row #4
          cout 
          << left << setw(COLUMN_1_WIDTH) 
          << "Youth (age 65 & over) / Disability" 
          << setfill(' ') << setw(COLUMN_GAP) << ""
          << setw(COLUMN_2_WIDTH) << "$5.55" << endl;
     //row #5
      cout 
         << left << setw(COLUMN_1_WIDTH) 
         << "Bicycle surcharge (included with Vehicle)" 
         << setfill(' ') << setw(COLUMN_GAP) << ""
         << setw(COLUMN_2_WIDTH) << "$4.00\n" << endl;
   



     // question #1
     cout << "Are you riding a vehicle on the Ferry? (Y/N): ";
     cin >> inputVehicle;
     inputVehicle = tolower(inputVehicle);
     if (inputVehicle != 'y' && inputVehicle != 'n'){
          cout 
          << "Invalid input type. Please try again and input ('y' or 'n')" 
          << endl;
          cout 
          << "Thank you for using our calculator. Program will close now." 
          << endl;
          return 0;
     } 
     else {
          switch(inputVehicle){
               case 'y':
               totalCharge = totalCharge + TICKET_VEHICLE;
               break;
               case 'n':
               break;
          }
     }
     // question #2
     if (inputVehicle == 'n'){
          cout 
          << "How many bikes are you bringing? " 
          << "Please enter a positive whole number. ";
          cin >> inputNumBikes;

          if (cin.fail() || inputNumBikes < 0){
               cout 
               << "Invalid input type."
               << "Please try again and input a positive whole number." 
               << endl;
               cout 
               << "Thank you for using our calculator." 
               << "Program will close now." 
               << endl;
               return 0;
          }
          
          totalCharge = totalCharge + (BICYCLE_SURCHARGE * inputNumBikes);
          cout << endl;
     }

     // question #2
     cout << "How many adults? ";
     cin >> inputNumAdults;
     if (cin.fail() || inputNumAdults < 0){
          cout 
          << "Invalid input type. Please try again and input a whole number." 
          << endl;
          cout 
          << "Thank you for using our calculator." 
          << "Program will close now." 
               
          << endl;
          return 0;
     } else {
          totalCharge = totalCharge + (TICKET_ADULT * inputNumAdults);
     }
     // question #3
     cout << "How many seniors? ";
     cin >> inputNumSeniors;
     if (cin.fail() || inputNumSeniors < 0){
          cout 
          << "Invalid input type. Please try again and input a whole number." 
          << endl;
          cout 
          << "Thank you for using our calculator." 
          << "Program will close now." 
          << endl;
          return 0;
     } else {
          totalCharge = totalCharge + (TICKET_SENIOR * inputNumSeniors);
     }
     // question #4
     cout << "How many youths? ";
     cin >> inputNumYouths;
     if (cin.fail() || inputNumYouths < 0){
          cout << "Invalid input type. Please try again." 
          << endl;
          cout << "Thank you for using our calculator." 
          << "Program will close now." 
            

          << endl;
          return 0;
     } else {
          totalCharge = totalCharge + (TICKET_YOUTH * inputNumYouths);
     } 

     // stop program if user reaches the group limit
     if (
          (inputNumYouths + inputNumSeniors + inputNumAdults) 
          > 
          GROUP_LIMIT
        ){
          cout << "Too many people in your group. The group limit is "
               << GROUP_LIMIT << " or less. Please try again." << endl;
          cout 
          << "Thank you for using our calculator. Program will close now." 
          << endl;
          return 0; 
     }
     // total charge summary
     cout << "\nYour total charge is $" << totalCharge << endl;
     // free adult ticket
     if (totalCharge >= FREE_TICKET_COST){
          cout << "You are eligible for a free ticket on your next trip!" 
               << endl;
     } else {
          cout << "Spend $" 
               << (FREE_TICKET_COST - totalCharge) 
               << " more next time to be eligible for a free ticket!" 
               << endl;
     }
     
     cout << "Thank you for using our calculator. Program will close now." 
          << endl;
     return 0;
}
