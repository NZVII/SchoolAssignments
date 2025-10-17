/******************************************************************************
# Author:           Alan Diaz
# Assignment:       a04  (CS161B)
# Date:             October 16, 2025
# Description: Using arrays to represent courses and students enrolled in them,
               get the number of students in each course. For any courses that
               have an enrollment number of less than 10 students, the course
               will be removed from the lists.
# Input:       courseNums[] (course numbers), studentNums (number of students
               per course)
# Output: courseNums[] and studentNums before and after course cancellations
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

// Set the max amount of courses and max amount of characters
int const MAX_COURSES = 20, MAX_CHAR = 51;

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome();

//Name:   readInput()
//Desc:   This function reads course numbers and student counts from user
//input:  courseNums array, students array, count by reference
//output: prompts for course numbers and student counts
//return: void
void readInput(char courseNums[][MAX_CHAR], int students[], int& count);

//Name:   readInt()
//Desc:   This function reads and validates integer input from user
//input:  prompt string, num by reference
//output: prompt message and error messages if needed
//return: void
void readInt(string prompt, int& num);

//Name:   printList()
//Desc:   This function all the course numbers and its corresponding student count
//input:  courseNums array, students array, count
//output: formatted list of courses and enrollment numbers
//return: void
void printList(char const courseNums[][MAX_CHAR], int const students[], int count);

//Name:   cancelCourses()
//Desc:   This function removes courses with less than 10 students
//input:  courseNums array, students array, count by reference
//output: none
//return: void
void cancelCourses(char courseNums[][MAX_CHAR], int students[], int& count);


int main(){
  // Declare parallel arrays
  char courseNums[MAX_COURSES][MAX_CHAR];
  int studentNums[MAX_COURSES];
  // Count keeps track of the number of courses
  int count = 0;

  welcome();

  readInput(courseNums, studentNums, count);

  cout << "\nList of courses and students: " << endl;
  printList(courseNums, studentNums, count);

  cancelCourses(courseNums, studentNums, count);

  cout << "\nList after cancellations:" << endl;
  printList(courseNums, studentNums, count);

  cout << "\nThank you for checking out my Course Rosters program!!" << endl;

  return 0;
}

void welcome(){
  cout << "Welcome to my Course Rosters program!!\n" << endl;
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
