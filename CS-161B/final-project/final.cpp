/******************************************************************************
# Author:           Alan Diaz
# Assignment:
# Date:             October 16, 2025
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
#include <cstring>
#include <iomanip>
using namespace std;



// Function prototypes
void welcome();
void printMenu();


int main(){

  return 0;
}

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome(){
  cout << "Welcome to my Final Project!\n"
       << "This program will give statistical information about "
       << "global video game sales from a variety of publishers "
       << "over the course of a view decades. You can remove an "
       << "item from the dataset, find the average global sales of a "
       << "specific publisher, print the dataset, or quit the program."
       << endl;
}
