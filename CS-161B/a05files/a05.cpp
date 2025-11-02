/******************************************************************************
# Author:           Alan Diaz
# Assignment:       a05  (CS161B)
# Date:             Novemeber 1, 2025
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
#include <fstream>
using namespace std;

// Set the max amount of courses and max amount of characters
int const MAX_CHAR = 120, CAP = 50;

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome();

//Name:   openFile()
//Desc:
//input:  none
//output: welcome message
//return: boolean
bool openFile(ifstream& inFile);

//Name:   loadData()
//Desc:
//input:  none
//output: welcome message
//return: boolean
int loadData(ifstream& inFile, char occupations[][MAX_CHAR], int sleepQuality[],
  int stressLevels[]);

//Name:   occupationsFlatten()
//Desc:
//input:  none
//output: welcome message
//return: boolean
void occupationsFlatten(char occupations[][MAX_CHAR], int occupationSize,
  char flattenedOccupations[][MAX_CHAR], int flattenedOccupationsSize);


//Name:   calculateQualitySleepAvg()
//Desc:
//input:  none
//output: welcome message
//return: boolean
void calculateAverages(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int flattenedOccupationsSize, int averages[]);

//Name:   calculateQualitySleepAvg()
//Desc:
//input:  none
//output: welcome message
//return: boolean
void calculateQualitySleepAvg(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int occupationsSize, int flattenedOccupationsSize, int columnToCalculate[], int averages[]);

int main(){
  // Declare variables
  char occupations[CAP][MAX_CHAR], flattenedOccupations[CAP][MAX_CHAR];
  int occupationsSize = 0 // the size of the occupations array
  , flattenedOccupationsSize = 0;
  int sleepQuality[CAP], stressLevels[CAP];
  int averages[CAP]; // calculates averages. Size must match the flattenedOccupation size

  ifstream inFile;

  welcome();

  if(!openFile(inFile)){
    cout << "File did not open. Terminating the program." << endl;
    exit(0);
  }

  occupationsSize = loadData(inFile, occupations, sleepQuality, stressLevels);

  occupationsFlatten(occupations, occupationsSize, flattenedOccupations, flattenedOccupationsSize);


  cout << "\nThank you for checking out my Course Rosters program!!" << endl;

  return 0;
}

void welcome(){
  cout << "Welcome to my File input/output program!\n"
       << "This program will read the occupation, sleep duration, "
       << "quality of sleep, and stress level values from a file and "
       << " display the occupations with the highest and lowest level of stress "
       << " and output the average quality of sleep for each occupation.\n"
       << endl;
}

bool openFile(ifstream& inFile){
  inFile.open("data-limited.txt");
  if (!inFile.is_open()){
    return false;
  }
  else{
    return true;
  }
}

int loadData(ifstream& inFile, char occupations[][MAX_CHAR], int sleepQuality[],
  int stressLevels[])
  {
  // declare variables
  int count = 0; // tracks the size of occupations
  char ignoreData[1000]; // used to store unneeded data

  // ignore the first line of data (data headings)
  inFile.getline(ignoreData, 1000);

  // read the occupation into occupations array
  inFile.getline(occupations[count], MAX_CHAR, ',');

  while(!inFile.eof()){

    // Read and store quality of sleep
    inFile >> sleepQuality[count];
    inFile.ignore(5,',');

    // Read and store quality of sleep & stress levels
    inFile >> stressLevels[count];
    inFile.ignore(5,'\n');

    // increment count for the next item
    count++;
    // Read the occupation of the next row down
    inFile.getline(occupations[count], MAX_CHAR, ',');
  }

  return count;

}

void occupationsFlatten(char occupations[][MAX_CHAR], int occupationSize,
  char flattenedOccupations[][MAX_CHAR], int flattenedOccupationsSize){

    // track the size of the occupation size
    // before assigning it to the flattenedOccupationsSize
    int totalOccupationCount = 0;

    strcpy(flattenedOccupations[totalOccupationCount], occupations[totalOccupationCount]);
    totalOccupationCount++; //increment count after adding

    for(int i = 0; i < occupationSize; ++i){
      int matches = 0; // keeps count of the amount of matches found

      for (int j = 0; j < totalOccupationCount; ++j){
        if(strcmp(occupations[i], flattenedOccupations[j]) != 0 ){
            cout << "match not found" << endl;
        }
        else if (strcmp(occupations[i], flattenedOccupations[j]) == 0){
          cout << "match found" << endl;
          matches++;
        }
      }

      if (matches == 0){
        // TESTING
        cout << "No matches found. Adding to the flattenedOccupationsArray: " << occupations[i] << endl;

        strcpy(flattenedOccupations[totalOccupationCount], occupations[i]);
        totalOccupationCount++;
      }

    }
}

void calculateAverages(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int occupationsSize, int flattenedOccupationsSize, int columnToCalculate[], int averages[]){

  // stores the count() and total for each occupation.
  // Row 1 is the count, row 2 is the total
  int occupationsData[2][CAP];

  // Initialize necessary vertices to 0
  for(int i = 0; i < flattenedOccupationsSize; ++i){
    occupationsData[0][i] = 0;
    occupationsData[1][i] = 0;
  }

  for(int i = 0; i < occupationsSize; ++i){

    for(int j = 0; j < flattenedOccupationsSize; j++){

    }

  }

}

void calculateQualitySleepAvg(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int flattenedOccupationsSize){

}
