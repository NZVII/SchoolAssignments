/******************************************************************************
# Author:           Alan Diaz
# Assignment:       A7 (CS161A)
# Date:             May 21, 2025
# Description:    This program reads x amount of assignments from the user
                  then calculates the final grade for the class. The final grade
                  is then used to calculate the letter grade.  

# Input:  int numAssignments;
          double averageAssignmentScore;
          double midtermExamScore;
          double finalExamScore;  
# Output: double finalNumericScore, calcFinalGrade(double finalScore)  
# Sources:
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char calcLetterGrade(double finalScore);
double calcFinalScore(double assignAvg, double midterm, double final);
double assignAverage(int numAssigns);
double readScore(string prompt);
void welcomeMessage();

int readInt(string prompt);

int main(){
  
  int numAssignments;
  double averageAssignmentScore;
  double midtermExamScore;
  double finalExamScore;
  double finalNumericScore;

  welcomeMessage();
  
  do {
    numAssignments = readInt("Enter the number of assignments (0 to 10): ");
    if (!(numAssignments >=0 && numAssignments <= 10)){
      cout << "Invalid entry, please try again" << endl;
    }
  }
  while (!(numAssignments >=0 && numAssignments <= 10));

  averageAssignmentScore = assignAverage(numAssignments);
  midtermExamScore = readScore("Enter your midterm exam score: ");
  finalExamScore = readScore("Enter your final exam score: ");
  finalNumericScore = calcFinalScore(averageAssignmentScore, midtermExamScore, finalExamScore);

  cout << setprecision(1) << fixed 
       << "\nYour Final Numeric Score is " << finalNumericScore << endl;
  cout << "Your Final Grade is " << calcLetterGrade(finalNumericScore) << endl;

  cout << "\nThank you for using my Grade Calculator!" << endl;

  return 0;
}

void welcomeMessage(){
  cout << "Welcome to my Final Grade Calculator!\n"
       << "Please enter the following information "
       << "and I will calculate your Final Numerical Grade "
       << "and Letter Grade for you!\n"
       << "The number of assignments must be between 0 and 10\n"
       << "All scores entered must be between 0 and 4\n"
       << endl;
}

int readInt(string prompt = ""){
  int userInput;
  if (prompt.length() > 0){
    cout << prompt;
  }
  cin >> userInput;
  while (cin.fail() || userInput < 0){
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Invalid input, please try again" << endl;
    if (prompt.length()){
      cout << prompt;
    }
    cin >> userInput;
  }
  return userInput;
}

/*
Description: 
Reads and validates score from the user.
Score must be between 0 and 4.
*/
double readScore(string prompt = ""){
  double scoreInput;
  bool rangeValid = false;

  if (prompt.length() > 0){
    cout << prompt;
  }

  cin >> scoreInput;

  while(!rangeValid){
    if (scoreInput >= 0 && scoreInput <=4 && !cin.fail()){
      rangeValid = true;
    }
    else {
      cout << "Invalid range. Please enter a number from 0-4" << endl;
      if (prompt.length() > 0){
        cout << prompt;
      }
      cin >> scoreInput;
    }
  }
  return scoreInput;
}

/*
Description: 
Returns the average score over numAssigns amount of assignments
*/
double assignAverage(int numAssigns){
  double totalScore = 0.0;
  int i = 0;
  for (; i < numAssigns; ++i){
    auto numToString = to_string(i + 1);
    string prompt = "Enter score " + numToString + ": ";
    // cout << "Enter score " << i + 1 << ": ";
    totalScore = totalScore + readScore(prompt);
  }
  return totalScore / i;
}

double calcFinalScore(double assignAvg, double midterm, double final){
  const double ASSIGNMENT_WEIGHT = 0.6;
  const double MIDTERM_FINAL_EXAM_WEIGHT = 0.2;
  return (assignAvg * ASSIGNMENT_WEIGHT) 
         + (midterm * MIDTERM_FINAL_EXAM_WEIGHT)
         + (final * MIDTERM_FINAL_EXAM_WEIGHT);
}

char calcLetterGrade(double finalScore){
  char letterGrade;
  if (finalScore >= 3.3 && finalScore <= 4.0){
    letterGrade = 'A';
  }
  else if (finalScore >= 2.8 && finalScore < 3.3){
    letterGrade = 'B';
  } 
  else if (finalScore >= 2.0 && finalScore < 2.8){
    letterGrade = 'C';
  }
  else if (finalScore >= 1.2 && finalScore < 2.0){
    letterGrade = 'D';
  }
  else {
    letterGrade = 'F';
  }
  return letterGrade;
}