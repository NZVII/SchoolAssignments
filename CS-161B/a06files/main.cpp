//The client file or the driver file
//This file has the main() function
//Add header comments here.
#include <iostream>
#include <cstring>

#include "Student.h"
#include "Course.h"

using namespace std;

int main() {

  char lastName[200];

  Course course = initCourse();
  ifstream inFile;


  cout << "Welcome to my Course Roster Program\n" << endl;
  inFile.open("students.txt");
  if(!inFile)
  {
    cout << "File did not open! Program Exiting!!" << endl;
    return 0;
  }
  //calls readStudent to read from the file
  readStudent(inFile, course);
  //calls printRoster to print the roster
  cout << "Here is the course roster: " << endl;
  printRoster(course);

  //call the appropriate functions based on the grade level you are choosing.
  //calls dropStudent to drop a student from the roster.
  //read a last name into a char array and pass to function.
  //declare variables if needed

  /*Add code here to call function*/
  cout << "\nEnter the last name of the student to drop: ";
  cin.getline(lastName, 200);

  dropStudent(lastName, course);


  //calls printRoster to print the roster after the student drop.
  //Uncomment the next 2 lines once you have dropped a student
  cout << "\nHere is the course roster: " << endl;
  printRoster(course);

  //calls findStudentHighestGPA to get Student with highest GPA
  //declare variables if needed

  /*Add code here to call function*/
  Student highestGPAStudent = findStudentHighestGPA(course);
  //calls printStd to print the student with the highest GPA

  /*Add code here to call function*/
  cout << "The student with the highest GPA:" << endl;
  printStd(highestGPAStudent);

  cout << "\nThank you for using my Student Roster program!!" << endl;
	return 0;
}
