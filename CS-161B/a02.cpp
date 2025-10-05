/******************************************************************************
# Author:           Alan Diaz
# Assignment:       a01  (CS161B)
# Date:             September 25, 2025
# Description: Food cart simulation program.
# Input: Program asks for the user inputs
# Output: Program outputs the discount, totalCost, finalCost, and tip
# Sources:
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

const int MAX_ARRAY_LENGTH = 60;

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome();

//Name:   displayMenu()
//Desc:   This function displays the menu options to the user
//input:  none
//output: menu options
//return: void
void displayMenu();

//Name:   readOption()
//Desc:   This function reads and validates user menu option
//input:  reference to char for option
//output: prompts and error messages
//return: void
void readOption(char &option);

//Name:   encode()
//Desc:   This function creates an encoded filename from user inputs
//input:  char array for encoded filename
//output: none
//return: void
void encode(char encodedFilename[]);

//Name:   readInput()
//Desc:   This function reads first name, last name, and late flag
//input:  char arrays for first/last name, reference to bool for late flag
//output: prompts for user input
//return: void
void readInput(char fName[], char lName[], bool& lateFlag);

//Name:   readInput()
//Desc:   This function reads and validates student ID and filename
//input:  char arrays for parsed ID and filename
//output: prompts and validation messages
//return: void
void readInput(char parsedId[], char fileName[]);

//Name:   readTime()
//Desc:   This function reads and validates military time input
//input:  char array for time string
//output: prompts and validation messages
//return: void
void readTime(char strTime[]);

//Name:   lowercaseString()
//Desc:   This function converts a string to lowercase
//input:  char array to convert
//output: none
//return: void
void lowercaseString(char inputString[]);


int main(){
  char encodedFilename[MAX_ARRAY_LENGTH], option;

  welcome();

  do{
    displayMenu();
    readOption(option);
    if (option == 'e'){
      encode(encodedFilename);
      cout << "\nYour encoded file name is: " << encodedFilename << endl << endl;
    }
  }
  while(option != 'q');

  cout << "\nThank you for using my fileName program." << endl;

  return 0;
}

void welcome(){
  cout << "Welcome to my filename encoding program.\n" << endl;
}

void displayMenu(){
  cout << "Please pick an option below:\n"
       << "(e)Encode a file name\n"
       << "(q)Quit" << endl;
}

void readOption(char &option){
  char tempVar;
  cin >> tempVar;
  tempVar = tolower(tempVar);

  while (cin.fail() || tempVar != 'e' && tempVar != 'q'){
    cout << "Invalid option! Please select e or q" << endl;

    cin.clear();
    cin.ignore(1000, '\n');

    cin >> tempVar;
    tempVar = tolower(tempVar);
  }

  option = tempVar;
}

void encode(char encodedFileName[]){
  char firstName[MAX_ARRAY_LENGTH], lastName[MAX_ARRAY_LENGTH],
  submissionTime[MAX_ARRAY_LENGTH], studentId[MAX_ARRAY_LENGTH],
  fileName[MAX_ARRAY_LENGTH];
  bool isLate;

  readInput(firstName, lastName, isLate);
  readInput(studentId, fileName);

  readTime(submissionTime);

  // Copy first name first
  strcpy(encodedFileName, firstName);
  strcat(encodedFileName,"_");

  // Concatenate the last name
  strcat(encodedFileName,lastName);
  strcat(encodedFileName,"_");


  // Optionally concatenate the LATE tag
  switch(isLate){
    case true:
      strcat(encodedFileName,"LATE");
      strcat(encodedFileName,"_");
      break;
    case false:
      break;
  }


  // Concatenate the student ID
  strcat(encodedFileName,studentId);
  strcat(encodedFileName,"_");

  // Concatenate the submission time
  strcat(encodedFileName,submissionTime);
  strcat(encodedFileName,"_");

  // Concatenate the file name
  strcat(encodedFileName,fileName);

}

void readInput(char fName[], char lName[], bool& lateFlag){
  char input;

  cout << "Enter your first name: ";
  cin >> fName;
  lowercaseString(fName);

  cout << "Enter your last name: ";
  cin >> lName;
  lowercaseString(lName);

  cout << "Was your assignment late (y/n): ";
  cin >> input;
  input = tolower(input);

  while (cin.fail() || input != 'y' && input != 'n'){
    cout << "\nInvalid option! Please select y or n." << endl;

    cin.clear();
    cin.ignore(1000, '\n');

    cin >> input;
    input = tolower(input);
  }

  switch(input){
    case 'y':
      lateFlag = true;
      break;
    case 'n':
      lateFlag = false;
      break;
  }

}


void readInput(char parsedId[], char fileName[]){
  char tempStudentId[MAX_ARRAY_LENGTH];
  bool validInput;

  do{
    validInput = true;

    cout << "Input your Student-ID (format: 222-22-2222): ";
    cin >> tempStudentId;

    // Validate the length of the input
    if (strlen(tempStudentId) != 11){
      cout << "\nInvalid input length." << endl;
      validInput = false;
    }

    // Validate that dashes are used
    if (validInput && (tempStudentId[3] != '-' || tempStudentId[6] != '-')){
      cout << "\nPlease ensure student id is in the correct format" << endl;
      validInput = false;
    }

    // Validate that numbers are numbers
    if (validInput){
      for (int i = 0; i < strlen(tempStudentId); ++i){
        if (!(isdigit(tempStudentId[i])) && i != 3 && i != 6){
            cout << "\nInvalid input. Expected number, got: "
                 << tempStudentId[i] << endl;

            validInput = false;
        }
      }
    }
  }
  while(!(validInput));

  strncpy(parsedId, tempStudentId + 7, 4);
  parsedId[4] = '\0';

  cout << "\nEnter the file name: ";
  cin >> fileName;
  lowercaseString(fileName);
}


void readTime(char strTime[]){
  int hours, minutes;
  char separator;
  bool isValid;

  do {
    isValid = true;
    cout << "Enter the time submitted in military time (e.g., 18:24 for 6:24pm): ";
    cin >> hours >> separator >> minutes;

    if (cin.fail() || separator != ':' || hours > 24 || minutes > 60){
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "\nInvalid format or values, please try again" << endl;
      isValid = false;
    }

  }
  while (!isValid);

  // Convert hours to string then c string and copy into strTime
  strncpy(strTime, to_string(hours).c_str(),10);
  //Convert minutes to string then c string and concatenate to strTime
  strcat(strTime, to_string(minutes).c_str());
}

void lowercaseString(char inputString[]){
  for(int i = 0; i < strlen(inputString); ++i){
    if (!(islower(inputString[i]))){
      inputString[i] = tolower(inputString[i]);
    }
  }
}
