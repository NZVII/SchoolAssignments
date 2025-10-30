/******************************************************************************
# Author:           Alan Diaz
# Lab:              Discussion #5
# Date:             October 20, 2025
# Description:
# Input:
# Output:
# Sources:          None
#******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

// function prototypes
bool openFile(ifstream &inFile, string fileName);
bool openFile(ofstream &outFile, string fileName);
void ratioCalc(ifstream& inFile, ofstream& outFile);
void highestSalaries(ifstream& inFile, ofstream& outFile);
// declare max array size
const int MAX_SIZE = 120;

// main
int main() {
  ifstream inFile;
  ofstream outFile;

  char fileName[120];

  cout << "Enter name of input file: ";
  cin.getline(fileName, MAX_SIZE);

  // Attempt to open the input file
  if (!openFile(inFile, fileName)) {
    cout << "file did not open. Program terminating!!!";
    return 0;
  }

  // Attempt to open the output file
  if (!openFile(outFile, "stemout.txt")) {
    cout << "file did not open. Program terminating!!!";
    return 0;
  }

  ratioCalc(inFile, outFile);

  highestSalaries(inFile, outFile);


  outFile.close();
  inFile.close();
}

// function to open file
// returns true if file opens
// returns false if file does not open for any reason
// parameters: file stream variable by reference and fileName
bool openFile(ifstream &inFile, string fileName) {
  inFile.open(fileName);
  if (!inFile) {
    return false;
  }
  return true;
}

// function to open file. Overloaded for output file
// returns true if file opens
// returns false if file does not open for any reason
// parameters: file stream variable by reference and fileName
bool openFile(ofstream &inFile, string fileName) {
  inFile.open(fileName);
  if (!inFile) {
    return false;
  }
  return true;
}

// Function to calculate the percentage of women and men in each major
// parameters: file stream variables by reference
void ratioCalc(ifstream& inFile, ofstream& outFile){
  // Declare variables
  char majorName[MAX_SIZE];
  int total, numWomen, numMen;
  double percentWomen, percentMen;
  char ignoreData[10000];

  // Ignore the first line in the file till the newline character (the header)
  inFile.getline(ignoreData, 1000);

  while(!inFile.eof())
  {
    inFile >> ignoreData >> majorName >> ignoreData
           >> total >> numMen >> numWomen >> ignoreData;
    // Calculate percentages
    percentWomen = static_cast<double>(numWomen)/total * 100;
    percentMen = static_cast<double>(numMen)/total * 100;
    // write to the output file
    outFile << fixed << setprecision(2)
            << majorName << ", " << percentWomen << "% Women and "
            << percentMen << "% Men" << endl;

  }
}

// Function to find the highest salaries
// parameters: file stream variables by reference
void highestSalaries(ifstream& inFile, ofstream& outFile){
  int highestSalary;
  int tempSalary;
  char tempMajor[MAX_SIZE];
  char major[MAX_SIZE];
  char ignoreData[MAX_SIZE];
  int count = 0; // tracks the current line

  // Ignore the first line in the file till the newline character (the header)
  inFile.getline(ignoreData, 1000);

  cout << "running highestSalaries" << endl;
  while(!inFile.eof()){
    // Assume that the first line consists of the highest salary
    if (count == 0){
      inFile >> ignoreData >> major >> ignoreData >> ignoreData
             >> ignoreData >> ignoreData >> highestSalary;
    }
    else {
      // Assign temp variables
      inFile >> ignoreData >> tempMajor >> ignoreData >> ignoreData
             >> ignoreData >> ignoreData >> tempSalary;

      cout << "running.." << endl;

      cout << tempMajor << " " << tempSalary << endl;

      // Assign new highest variables
      if (tempSalary > highestSalary){
        highestSalary = tempSalary;
        strcpy(major, tempMajor);
      }
    }
    //increment count
    count++;
  }

  outFile << "The major with the highest salary is "
          << major << " with a salary of $" << highestSalary << endl;

}
