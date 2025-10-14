/******************************************************************************
# Author:           Alan Diaz
# Assignment:       a03  (CS161B)
# Date:             October 11, 2025
# Description:  The program will store a list of scores and its corresponding
                letter grade in two parallel arrays. The program calculates
                the letter grade from the user inputted numerical score.
                Both arrays will be sorted in ascending order and the median
                score will be calculated.
# Input:  double scores[] - a list of scores collected from the user
# Output: double median - median score, char scores[] - in ascending order
          char letterGrades[] in ascending order.
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

const int MAX = 20;

//Name:   welcome()
//Desc:   This function displays a welcome message to the user
//input:  none
//output: welcome message
//return: void
void welcome();

//Name:   readScores()
//Desc:   Reads the scores from the user
//input:  count as reference and scores[]
//output: none
//return: void
void readScores(double scores[], int& count);

//Name:   readDouble()
//Desc:   validates user inputted numbers
//input:  prompt and num as reference
//output: none
//return: void
void readDouble(string prompt, double & num);

//Name:   calcGrade()
//Desc:   Calculates letter grades from numerical scores
//input:  scores[] as constant, grade[] array, and count
//output: none
//return: void
void calcGrade(const double scores[], char grade[], int count);

//Name:   printList()
//Desc:   Prints the list of scores and their corresponding letter grades
//input:  scores[] and grades[] as constants, and count
//output: scores and grades printed to console
//return: void
void printList(const double scores[], const char grades[], int count);

//Name:   sort()
//Desc:   Sorts both scores and grades arrays in ascending order
//input:  scores[] array, grades[] array, and count
//output: none
//return: void
void sort(double scores[], char grades[], int count);

//Name: median()
//Desc: Calculates the median of the scores
//input:  scores[] and count as constants
//output:
//return: The calculated median
double median(double const scores[], int const count);

int main(){
  // Declare variables
  double scores[MAX]; // array of user inputted scores
  char grades[MAX]; // array of letter grades parallel to scores
  int count = 0; // array length
  double gradeMedian; // median for scores



  welcome();

  cout << fixed << setprecision(2);

  // Begin reading the scores
  readScores(scores, count);

  // Calculate the letter grades from scores
  calcGrade(scores, grades, count);

  // Print the scores prior to sorting
  cout << "Your stats are as below:\n"
       << "The list of scores and their grades are: " << endl;
  printList(scores, grades, count);

  // Print the scores after sorting
  cout << "The list sorted by scores in ascending order:" << endl;
  sort(scores, grades, count);
  printList(scores, grades, count);

  gradeMedian = median(scores, count);
  cout << "The median score is " << gradeMedian << endl;

  cout << "\nThank you for using my Parallel Arrays program!" << endl;


  return 0;
}

void welcome(){
  cout << "Welcome to my Parallel Arrays program!" << endl;
}

void readScores(double scores[], int& count){
  double userInput;

  cout << "Please enter the list of scores (-1 to end input).\nValid scores "
       << "are between 0 and 4 inclusive" << endl;


  // Exit loop if input is = -1 or count reaches  the array max length
  do{
    readDouble("Enter score", userInput);

    // Validate that the input is between 0 and 4 and not equal to -1
    if(userInput >= 0 && userInput <= 4 && userInput != -1){
      scores[count] = userInput;
      count++;
    }
    else{
      cout <<"Invalid score! Try again!" << endl;
    }

  }
  while(count <= 20 && userInput != -1);

}

void readDouble(string prompt, double & num){

  // Holds the user input for validations
  double tempVar = 0;

  // prints the prompt if it is not empty
  if (prompt != ""){
      cout << prompt << ": ";
  }
  cin >> tempVar;

  // Error handling for invalid inputs
  while (cin.fail()){
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "invalid score! Please try again!!" << endl;
      cin >> tempVar;
  }

  num = tempVar;
}

void calcGrade(const double scores[], char grade[], int count){

  // loop through each score and evaluate the grade
  for (int i = 0; i < count; ++i){

   if(scores[i] > 3.3 && scores[i] <= 4.0){
     grade[i] = 'A';
   }

   else if(scores[i] > 2.7 && scores[i] <= 3.3){
     grade[i] = 'B';
   }

   else if(scores[i] > 1.9 && scores[i] <= 2.7){
     grade[i] = 'C';
   }

   else if(scores[i] > 1.1 && scores[i] <= 1.9){
     grade[i] = 'D';
   }

   else if(scores[i] >= 0.0 && scores[i] <= 1.1){
     grade[i] = 'F';
   }

  }
}

void printList(const double scores[], const char grades[], int count){

  for (int i = 0; i < count; ++i){
   cout << scores[i] << " " << grades[i] << endl;
  }
  cout << endl;

}

void sort(double scores[], char grades[], int count){

  for(int i = 0; i < count; ++i){
    // assume that i is the minimum value
    int minPos = i;

    // loop for all elements after minPos
    for (int j = i+1; j < count; j++){
      if (scores[j] < scores[minPos]){

        // Define temp variables to hold values
        double tempScore = scores[minPos];
        char tempGrade = grades[minPos];

        // Swap the scores
        scores[minPos] = scores[j];
        scores[j] = tempScore;

        // Swap the grades
        grades[minPos] = grades[j];
        grades[j] = tempGrade;

      }
    }
  }

}


double median(double const scores[], int const count){

  // Calculates the median if count is odd
  if (count % 2 != 0){
    return scores[(count-1)/2];
  }

  // Calculates the median if count is even
  else{
    return (scores[count/2] + scores[(count/2)-1])/2;
  }
}
