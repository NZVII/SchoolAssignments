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
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;



// Function prototypes
void welcome();
void printMenu();

int main(){
  // variables
  ifstream inFile;
  int dataSize = 0; // size of the gameData array
  Video_Game gameData[20]; // stores video game data
  char menuInput; // reads user inputs

  welcome();

  // Attempt to open the file and handle errors
  inFile.open("vgsales_small.csv");
  if (!inFile){
    cout << "Failed to open data file! Quiting Program..." << endl;
    return 0;
  }

  // Load the data and get the size of the data array
  dataSize = loadGameData(inFile, gameData);

  // Print the menu
  printMenu();

  // Reads inputs until user quits
  do{

    // Read the menu selection from the user
    cin >> menuInput;
    cin.ignore(1000,'\n');
    menuInput = tolower(menuInput); // ensure input is lowercase

    // Menu options
    switch(menuInput){
      case 'm':
        printMenu();
        break;
      case 'p':
        printGameData(gameData, dataSize);
        cout << endl;
        break;
      case 's':
        searchGame(gameData, dataSize);
        cout << endl;
        break;
      case 'r':
        removeGame(gameData,dataSize);
        cout << endl;
        break;
      case 'q':
        cout << "Quitting program. Goodbye!" << endl;
        break;
      case 'a':
        calcPublisherAvg(gameData, dataSize);
        break;
      default:
        cout << "Invalid selection! Press M a list of commands." << endl;
        break;
    }
  }
  while(menuInput != 'q');

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
//Desc: This function displays the command menu to the user
//input: none
//output: the program's menu
//return: void
void printMenu(){
    cout << "(M) Prints the menu.\n"
         << "(P) Prints the dataset.\n"
         << "(A) Finds the average global sales of a publisher.\n"
         << "(R) Remove a game from the dataset.\n"
         << "(S) Search for data about a specific video game\n"
         << "(Q) Quit the program.\n" << endl;
}
