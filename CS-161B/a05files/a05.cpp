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


// function prototypes
void welcome();
bool openFile(ifstream& inFile);
int loadData(ifstream& inFile, char occupations[][MAX_CHAR], int sleepQuality[],
  int stressLevels[]);
void occupationsFlatten(char occupations[][MAX_CHAR], int occupationSize,
  char flattenedOccupations[][MAX_CHAR], int& flattenedOccupationsSize);
void calculateAverages(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int occupationsSize, int flattenedOccupationsSize, int columnToCalculate[], double averages[]);
void calculateQualitySleepAvg(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int flattenedOccupationsSize, int occupationsSize, int sleepQuality[]);
void calculateStressHighLow(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int flattenedOccupationsSize, int stressLevels[], int occupationsSize);

int main(){
  // Declare variables
  char occupations[CAP][MAX_CHAR], flattenedOccupations[CAP][MAX_CHAR];
  int occupationsSize = 0 // the size of the occupations array
  , flattenedOccupationsSize = 0;
  int sleepQuality[CAP], stressLevels[CAP];

  ifstream inFile;

  welcome();

  if(!openFile(inFile)){
    cout << "File did not open. Terminating the program." << endl;
    exit(0);
  }

  // Load the data
  occupationsSize = loadData(inFile, occupations, sleepQuality, stressLevels);

  occupationsFlatten(occupations, occupationsSize, flattenedOccupations, flattenedOccupationsSize);

  calculateQualitySleepAvg(occupations, flattenedOccupations, flattenedOccupationsSize,
    occupationsSize, sleepQuality);

  cout << endl;

  calculateStressHighLow(occupations, flattenedOccupations, flattenedOccupationsSize,
    stressLevels, occupationsSize);



  cout << "\nThank you for checking out my  program! Goodbye!" << endl;

  return 0;
}

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome(){
  cout << "Welcome to my File input/output program!\n"
       << "This program will read the occupation, sleep duration, "
       << "quality of sleep, and stress level values from a file."
       << "The program will then output the average quality of sleep for each occupation "
       << "sorted from highest quality to lowest. Finally, the program will "
       << "then output the occupations with the highest and lowest stress average.\n"
       << endl;
}

//Name:   openFile()
//Desc :  Opens the txt file and returns a true/false depending if it opened successfully.
//input:  inFile as ifstream reference
//output: true if the program opened successfully. False if it didn't.
//return: boolean
bool openFile(ifstream& inFile){
  inFile.open("data-limited.txt");
  if (!inFile.is_open()){
    return false;
  }
  else{
    return true;
  }
}

//Name:   loadData()
//Desc:   Loads the data from the inFile into their respective arrays
//input:  inFile as ifstream refernce, occupations as a char array, sleepQuality as an int array
//        stressLevels as an int array.
//output: The program outputs the count as int which is the size of the data read
//return: int
int loadData(ifstream& inFile, char occupations[][MAX_CHAR], int sleepQuality[],
  int stressLevels[])
  {
  // declare variables
  int count = 0; // tracks the size of occupations

  // ignore the first line of data (data headings)
  inFile.ignore(500, '\n');

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

//Name:   occupationsFlatten()
//Desc:   Removes duplicate occupations and creates a new array without duplicates
//input:  occupations as char array, occupationSize as int, flattenedOccupations as char array
//        , and flattenedOccupationsSize as an int reference.
//output: none
//return: void
void occupationsFlatten(char occupations[][MAX_CHAR], int occupationSize,
  char flattenedOccupations[][MAX_CHAR], int& flattenedOccupationsSize){

    // track the size of the occupation size
    // before assigning it to the flattenedOccupationsSize
    int totalOccupationCount = 0;

    strcpy(flattenedOccupations[totalOccupationCount], occupations[totalOccupationCount]);
    totalOccupationCount++; //increment count after adding

    for(int i = 0; i < occupationSize; ++i){
      int matches = 0; // keeps count of the amount of matches found

      for (int j = 0; j < totalOccupationCount; ++j){
        if (strcmp(occupations[i], flattenedOccupations[j]) == 0){
          matches++;
        }
      }

      if (matches == 0){

        strcpy(flattenedOccupations[totalOccupationCount], occupations[i]);
        totalOccupationCount++;
      }

    }

    flattenedOccupationsSize = totalOccupationCount;
}

//Name:   calculateAverages()
//Desc:   Calculates the averages of a specific data set that correlates to its respective occupation
//input:  occupations as a char array, flattenedOccupations as a char array, occupationsSize as an int,
//        columnToCalculate as an int array, and averages as a double array
//output: welcome message
//return: boolean
void calculateAverages(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int occupationsSize, int flattenedOccupationsSize, int columnToCalculate[], double averages[]){

  // stores the total amount of values and sum of values for each occupation.
  // Row 1 (0)  stores the total amount of values
  // Row 2 (1) stores the sum of values
  // Each column corresponds to an occupation
  int occupationsData[2][CAP];

  // Initialize necessary vertices to 0
  for(int i = 0; i < flattenedOccupationsSize; ++i){
    occupationsData[0][i] = 0;
    occupationsData[1][i] = 0;
  }

  // iterate over the given raw data
  for(int i = 0; i < occupationsSize; ++i){

    // Find the index of the occupation
    for(int j = 0; j < flattenedOccupationsSize; j++){
      // handle matches and store results to column k
      if(strcmp(occupations[i], flattenedOccupations[j]) == 0 ){


        // add to the total amount of values
        occupationsData[0][j] = occupationsData[0][j] + 1;
        // add to the sum of values
        occupationsData[1][j] = occupationsData[1][j] + columnToCalculate[i];
      }

    }

  }

  // iterate over the occupationsData and calculate the averages for all occupations
  for(int i = 0; i < flattenedOccupationsSize; ++i){

    averages[i] = static_cast<double>(occupationsData[1][i])/ occupationsData[0][i];

  }

}

//Name:   calculateQualitySleepAvg()
//Desc:   Calculates the average sleep quality of each occupation and sorts it from high to low.
//input:  occupations as char array, flattenedOccupations as char array, flattenedOccupationsSize as an int,
//        occupationsSize as an int, sleepQuality as an int.
//output: Displays the sleep quality of each occupation in a table, sorted from high to low
//return: void
void calculateQualitySleepAvg(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int flattenedOccupationsSize, int occupationsSize, int sleepQuality[]){

  // stores the sleep quality average for each occupation
  double sleepQualityAvg[CAP];
  char sortedOccupations[CAP][MAX_CHAR];

  // Copy each of the occupations into a new array for sorting
  for(int i = 0; i < flattenedOccupationsSize; ++i){
    strcpy(sortedOccupations[i], flattenedOccupations[i]);
  }

  // Calculate the averages for sleep quality and update sleepQualityAvg array
  calculateAverages(occupations, flattenedOccupations,
    occupationsSize, flattenedOccupationsSize, sleepQuality , sleepQualityAvg);

  // Sort based off averages from high to low using this sorting algorithm
  for(int i = 0; i < flattenedOccupationsSize; ++i){
    int minPos = i;


    for(int j = i+1; j < flattenedOccupationsSize; ++j){

      if (sleepQualityAvg[j] > sleepQualityAvg[minPos]){

       // store into temporary variables
       double tempAvg = sleepQualityAvg[minPos];
       char tempOccupation[MAX_CHAR];
       strcpy(tempOccupation, sortedOccupations[minPos]);

       // swap sleepQuality values
       sleepQualityAvg[minPos] = sleepQualityAvg[j];
       sleepQualityAvg[j] = tempAvg;

       // swap occupation values
       strcpy(sortedOccupations[minPos], sortedOccupations[j]);
       strcpy(sortedOccupations[j], tempOccupation);

      }

    }

  }

  // table header
  cout << "Occupations sorted by highest sleep quality to lowest" << endl
    << "Occupation Name; Sleep Quality Avg" << endl;

  // table data
  for (int i = 0; i < flattenedOccupationsSize; ++i){
    cout << fixed << setprecision(2)
    << sortedOccupations[i] << "; " << sleepQualityAvg[i] << endl;
  }

}

//Name:   calculateStressHighLow()
//Desc:   Finds the occupations with the highest and lowest stress levels (based on their average)
//input:  occupations as a char array, flattenedOccupations as a char array, flattenedOccupations as
//        an int, stressLevels as an int array, and occupationsSize as an int
//output: Displays the occupations with the highest and lowest stress level
//return: void
void calculateStressHighLow(char occupations[][MAX_CHAR], char flattenedOccupations[][MAX_CHAR],
  int flattenedOccupationsSize, int stressLevels[], int occupationsSize){

  // declare variables
  double occupationStressAvg[CAP];
  int stressHighIndex = 0;
  int stressLowIndex = 0;
  int stressHigh = 0;
  int stressLow = 0;


  // Calculate the averages
  calculateAverages(occupations, flattenedOccupations, occupationsSize,
    flattenedOccupationsSize, stressLevels, occupationStressAvg);


  // Assume the highs and lows are the first values in the array
  stressHigh = occupationStressAvg[0];
  stressLow = occupationStressAvg[0];

  // Find the high and low value
  for (int i = 0; i < flattenedOccupationsSize; ++i){
    if (occupationStressAvg[i] > stressHigh){
     stressHigh = occupationStressAvg[i];
     stressHighIndex = i;
    }

    if(occupationStressAvg[i] < stressLow){
      stressLow = occupationStressAvg[i];
      stressLowIndex = i;
    }

  }

  cout << "The occupation with the highest stress average is: "
    << flattenedOccupations[stressHighIndex] << " with an average stress level of "
    << stressHigh << endl;

  cout << "The occupation with the lowest stress average is: "
    << flattenedOccupations[stressLowIndex] << " with an average stress level of "
    << stressLow << endl;
}
