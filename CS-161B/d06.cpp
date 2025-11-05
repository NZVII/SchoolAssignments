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
void inputVehicles(Vehicle array[], int count);
void inputVehicles(const Vehicle array[], int count);

int main(){
    // declare variables
    int count = 0;
    Vehicle vehicleArray[CAP];



    cout << "\nThank you for using my program!" << endl;
    return 0;
}


//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome(){
    cout << "Welcome to my Food Cart Program!" << endl;
}

//Name:   readInt()
//Desc:   This function validates and reads integer input
//input:  num (int reference), prompt (string with default empty)
//output: error messages for invalid input
//return: void
void readInt(int& num){
   int tempVar = 0;
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


//Name:   readInt()
//Desc:   This function validates and reads integer input
//input:  num (int reference), prompt (string with default empty)
//output: error messages for invalid input
//return: void
void inputVehicles(Vehicle array[], int count){
    for (int i = 0; i < count; ++i){

        // Get the make
        cout << "Vehicle " << count << "'s make: ";
        cin.getline(array[count].make, MAX_CHAR);

        // Get the model
        cout << "\nVehicle " << count << "'s model: ";
        cin.getline(array[count].model, MAX_CHAR);

        // Get the year
        cout << "\nVehicle " << count << "'s year: ";
        cin >> array[count].year;
        cin.ignore(5, '\n');

    }
}

//Name:   readInt()
//Desc:   This function validates and reads integer input
//input:  num (int reference), prompt (string with default empty)
//output: error messages for invalid input
//return: void
void inputVehicles(const Vehicle& array, int count);
