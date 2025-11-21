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
#include "VideoGame.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;



// Function prototypes
void welcome();
void printMenu();
void readOption(char& input);
int loadData(ifstream& inFile, Video_Game data[]);


int main(){
  int dataSize = 0; // size of the gameData array
  Video_Game gameData[20]; // stores video game data
  char menuInput;

  welcome();

  // Reads inputs until user quits
  do{
    readOption(menuInput);

    switch(menuInput){
      case 'm':
        printMenu();
        break;
    }
  }
  while(menuInput != 'q');

  cout << "Goodbye!" << endl;
  return 0;
}

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome(){
  cout << "Welcome to my Final Project!\n"
       << "This program will give statistical information about\n"
       << "global video game sales from a variety of publishers\n"
       << "over the course of a few decades. You can remove an\n"
       << "item from the dataset, find the average global sales of a\n"
       << "specific publisher, print the dataset, or quit the program.\n"
       << endl;
}

//Name: printMenu()
//Desc:
//input:
//output:
//return:
void printMenu(){
    cout << "(M) Prints the menu.\n"
         << "(P) Prints the dataset.\n"
         << "(A) Finds the average global sales of a publisher.\n"
         << "(R) Remove a game from the dataset.\n"
         << "(S) Search for data about a specific video game\n"
         << "(Q) Quit the program.\n" << endl;
}

//Name: readOption()
//Desc:
//input:
//output:
//return:
void readOption(char& input){
  char tempVar;
  cin >> tempVar;
  tempVar = tolower(tempVar);

  while (cin.fail() || tempVar != 'm' && tempVar != 'p' &&
         tempVar != 'a' && tempVar !='r' && tempVar !='s' &&
         tempVar != 'q'
        ){
    cout << "Invalid option! Press m to view the menu." << endl;

    cin.clear();
    cin.ignore(1000, '\n');

    cin >> tempVar;
    tempVar = tolower(tempVar);
  }

  input = tempVar;
}
