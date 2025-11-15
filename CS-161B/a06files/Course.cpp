//The implementation file for Course.h
//It loads students from a text file.
#include <iostream>
#include <cstring>

#include "Course.h"
#include "Student.h"
using namespace std;

//initiaizes a course variable and returns it. The array is empty
//and the number of students is set to 0.
Course initCourse() {
	Course course;
	course.numStudents = 0;
	return course;
}

//reads a student from the file and calls AddStudent
void readStudent(ifstream& inFile, Course &course)
{
 /*Add code here to read from the file and call addStudent to add each student to the roster.*/

    // loop till the end of the file
    while(!inFile.eof()){
        // store the current student data
        Student student;

        // copy the first name
        inFile.getline(student.first, 200, ';');
        // copy the first name
        inFile.getline(student.last, 200, ';');
        // copy the gpa
        inFile >> student.gpa;
        inFile.ignore(5,'\n');

        // add the student to the roster
        addStudent(student, course);
    }
}

//adds a student to the roster, and increment coun  t
//modify this function to add the student sorted by name
//do not use any sorting functions.
//See this example in zyBooks Section 14.7 [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
void addStudent(Student student, Course &course) {

    // Dictates which indice to insert the student. Defaults to the end of the roster
    int insertIndex = course.numStudents;

    for (int i = 0; i < course.numStudents; i++){
        // checks to see if student.last shows up first alphabetically
        if (strcmp(student.last, course.roster[i].last) < 0){
            insertIndex = i;
            break;
        }
    }

    // shift right algorithm to add new student
    for(int j = course.numStudents; j > insertIndex; j--){
        course.roster[j] = course.roster[j-1];
    }

    // add the student
    course.roster[insertIndex] = student;
   	course.numStudents++;
}

//prints a whole Course roster calling student print.
//use a for loop and print all the students
//must call the printStd function in Student.h
void printRoster(Course course)
{
  // loop through all the students in the roster
  for(int i = 0; i < course.numStudents; i++){
     // prints the student
     printStd(course.roster[i]);
  }
}

/*
Based on the grade level you are doing: Please read the appropriate level assignment document.
add code and function comments for the below 2 functions.
void dropStudent(char *lastname, Course &course);
Student findStudentHighestGPA(Course course);
drops a student in the roster given the lastname
*/
void dropStudent(char *lastname, Course &course){
    for(int i = 0; i < course.numStudents; ++i){

        // validates that lastname matches
        if (strcmp(course.roster[i].last, lastname) == 0){
            // shift left algorithm to remove student
            for (int j = i; j < course.numStudents-1; ++j){
                course.roster[j] = course.roster[j+1];

            }

            // deincrement the num of students
            course.numStudents--;
        }

    }
}

// Finds the student with the highest GPA and returns that student
Student findStudentHighestGPA(Course course){
    int i = 0;
    // assumes highest gpa student is the first student
    Student highestGPAStudent = course.roster[i];

    // loop through the roster
    for (; i < course.numStudents; ++i){

       // change highestGPAStudent if the current student in the roster's gpa is higher
       if (course.roster[i].gpa > highestGPAStudent.gpa){
           highestGPAStudent = course.roster[i];
       }
    }
    return highestGPAStudent;
}
