/******************************************************************************
# Author:           Alan Diaz
# Lab:              Discussion #5
# Date:             October 20, 2025
# Description:      The program reads data from a stem.txt file and outputs
                    the percentage of men and women in each major alongside
                    the major with the highest salary
# Input:            fileName as the name of the file to read from.
# Output:
# Sources:          None
#******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// function prototypes
bool openFile(ifstream &inFile, string fileName);
bool openFile(ofstream &outFile, string fileName);
void ratioCalc(ifstream& inFile, ofstream& outFile);
int highestSalaries(int salaries[], int count);

// declare global constants
const int MAX_CHAR = 120;
const int CAP = 200;

// main
int main() {
  ifstream inFile;
  ofstream outFile;

  char fileName[120];

  cout << "Enter name of input file: ";
  cin.getline(fileName, MAX_CHAR);

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
  char majorNames[MAX_CHAR][CAP]; // Stores the names of the major
  int total, numWomen, numMen, salaries[CAP], count = 0;
  double percentWomen, percentMen;
  char ignoreData[10000];
  int highestSalaryIndex; // Stores the index of the highest salaries

  // Ignore the first line in the file till the newline character (the header)
  inFile.getline(ignoreData, 1000);

  while(!inFile.eof())
  {
    inFile >> ignoreData >> majorNames[count] >> ignoreData
           >> total >> numMen >> numWomen >> salaries[count];
    // Calculate percentages
    percentWomen = static_cast<double>(numWomen)/total * 100;
    percentMen = static_cast<double>(numMen)/total * 100;
    // write to the output file
    outFile << fixed << setprecision(2)
            << majorNames[count] << ", " << percentWomen << "% Women and "
            << percentMen << "% Men" << endl;
    count++;
  }

  // Find the major with the highest salary
  highestSalaryIndex = highestSalaries(salaries, count);

  outFile << "\nThe major with the highest annual salary is "
          << majorNames[highestSalaryIndex]
          << " with a salary of $"
          << salaries[highestSalaryIndex] << endl;


}

// Function to find the highest salaries
// parameters: file stream variables by reference
// returns the index that has the highest salary
int highestSalaries(int salaries[], int count){
  int highestSalary;
  int highestSalaryIndex = 0;

  // assume the highest is the first value
  highestSalary = salaries[0];

  for(int i = 0; i < count; i++){
    if (salaries[i] > highestSalary){
      highestSalary = salaries[i];
      highestSalaryIndex = i;
    }
  }
  return highestSalaryIndex;
}
