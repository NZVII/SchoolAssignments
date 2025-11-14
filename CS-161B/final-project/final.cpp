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
void readInput(char courseNums[][MAX_CHAR], int students[], int& count);
void readInt(string prompt, int& num);
void printList(char const courseNums[][MAX_CHAR], int const students[], int count);
void cancelCourses(char courseNums[][MAX_CHAR], int students[], int& count);


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

void readInput(char courseNums[][MAX_CHAR], int students[], int& count){
  //Get a singular course number
  char tempCourseNums[MAX_CHAR];
  //Get a singular student number
  int tempStudentNumber;


  cout << "Enter course number: ";
  cin.getline(tempCourseNums, MAX_CHAR);


  while((strcmp(tempCourseNums, "quit") != 0 &&
            strcmp(tempCourseNums, "Quit") != 0) &&
          count < MAX_COURSES){

    strcpy(courseNums[count], tempCourseNums);

    // Get the student amount in the course
    readInt("Number of students enrolled", tempStudentNumber);

    while (tempStudentNumber < 0 || tempStudentNumber > 25){
      cout << "Invalid number!! Please enter a number between 0 and 25" << endl;
      readInt("Number of students enrolled", tempStudentNumber);
    }

    students[count] = tempStudentNumber;
    count++;

    cout << "Enter course number: ";
    cin.getline(tempCourseNums, MAX_CHAR);
  }

}

void readInt(string prompt, int& num){
  int tempVar = 0;
  // prints the prompt if it is not empty
  if (prompt != ""){
      cout << prompt << ": ";
  }
  cin >> tempVar;
  cin.ignore(100,'\n');
  // Error handle invalid inputs
  while (cin.fail()){
      cin.clear();
      cin.ignore(100,'\n');
      cout << "invalid input, please try again." << endl;
      cin >> tempVar;
      cin.ignore(100,'\n');
  }
  num = tempVar;
}

void printList(char const courseNums[][MAX_CHAR], int const students[], int count){

  // Table header
  cout << left << setw(25) << "Course Number"
       << left << setw(12) << "Students" << endl;

  for(int i = 0; i < count; ++i){


    // Table Data
    cout << left << setw(25) << courseNums[i]
         << left << setw(12) << students[i] << endl;

  }

}

void cancelCourses(char courseNums[][MAX_CHAR], int students[], int& count){
  for(int i = 0; i < count; ++i){

      if(students[i] < 10){

        // implement shuffle left algorithm
        for(int j = i; j < count-1; j++){
          students[j] = students[j+1];
          strcpy(courseNums[j], courseNums[j+1]);
        }

        count--;

        // Since the array values are being moved around, deincrement i to recheck
        // the current position as the value has changed.
        i--;

        students[count] = 0;
        strcpy(courseNums[count], "\0");

      }
  }

}
