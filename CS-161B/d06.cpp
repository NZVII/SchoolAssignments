/******************************************************************************
# Author:           Alan Diaz
# Assignment:       d06  (CS161B)
# Date:             November 11, 2025
# Description:
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

// declare constants
const int MAX_CHAR = 150;
const int CAP = 50;

// declare struct
struct Vehicle{
 char make[MAX_CHAR];
 char model[MAX_CHAR];
 int year;
};

// declare function prototypes
void welcome();
void readInt(int& num);
void inputVehicles(Vehicle vehicleList[], int count);
void printVehicles(const Vehicle vehicleList[], int count);

int main(){
    // declare variables
    int count = 0;
    Vehicle vehicleList[CAP];

    welcome();

    cout << "How many vehicles would you like to add?" << endl;
    readInt(count);

    // prompt user for input
    inputVehicles(vehicleList, count);

    printVehicles(vehicleList, count);


    cout << "\nThank you for using my program!" << endl;
    return 0;
}


//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome(){
    cout << "Welcome to my Discussion 6 Program!" << endl
        << "This program stores user information about vehicles"
        << " they own or like by prompting for the # of vehicles "
        << "they would like to add and prompting for its year,make,model."
        << endl;
}

//Name:   readInt()
//Desc:   This function validates and reads integer input
//input:  num (int reference)
//output: error messages for invalid input
//return: void
void readInt(int& num){
   int tempVar = 0;
   cin >> tempVar;
   cin.ignore(5, '\n');

   // Error handle invalid inputs
   while (cin.fail()){
       cin.clear();
       cin.ignore(100,'\n');
       cout << "invalid input, please try again." << endl;
       cin >> tempVar;
   }
   num = tempVar;
}


//Name:   inputVehicles()
//Desc:   Prompts user to input each vehicle's make,model,year
//input:  vehicleList as Vehicle array, count as int
//output: none
//return: void
void inputVehicles(Vehicle vehicleList[], int count){
    for (int i = 0; i < count; ++i){

        // Get the make
        cout << "\nVehicle " << i+1<< "'s make: ";
        cin.getline(vehicleList[i].make, MAX_CHAR);

        // Get the model
        cout << "Vehicle " << i+1 << "'s model: ";
        cin.getline(vehicleList[i].model, MAX_CHAR);

        // Get the year
        cout << "Vehicle " << i+1<< "'s year: ";
        int tempYear;
        readInt(tempYear);
        vehicleList[i].year = tempYear;
    }
}

//Name:   printVehicles()
//Desc:   Prints each array of vehicle
//input:  vehicleList as Vehicle array, count as int
//output: Information for each vehicle in vehicleList
//return: void
void printVehicles(const Vehicle vehicleList[], int count){
    for(int i = 0; i < count; ++i){
        cout << "\nInformation for vehicle #" << i+1 << endl;
        cout << "Make: " << vehicleList[i].make << endl;
        cout << "Model: " << vehicleList[i].model << endl;
        cout << "Year: " << vehicleList[i].year << endl;
    }
}
