#include <iostream>
using namespace std;

// Function prototypes
void Welcome();
void Goodbye();
void GetInput(int &goal);
int CalcTotal();
string NumDayToName(int number);

// Main program start
int main(){
  int weeklyGoal = 0;
  int weeklyTotal;

  Welcome();


  // gather user input
  GetInput(weeklyGoal);


  if (weeklyGoal == 0 ){
    cout << "\nNo miles were tracked this week" << endl;
  }
  else{
    weeklyTotal = CalcTotal();
    cout << "\nYou rode " << weeklyTotal << " miles this week." << endl;

    if (weeklyTotal == weeklyGoal){
      cout << "Good job! You met your goal!" << endl;
    }
    else if (weeklyTotal > weeklyGoal){
      cout << "Good job! You exceeded your goal by " 
           << weeklyTotal-weeklyGoal 
           << " miles!" << endl;
    }
    else if (weeklyTotal < weeklyGoal){
      cout << "You missed your goal by " 
           << weeklyGoal-weeklyTotal 
           << " miles!" << endl;
    }

  }
  Goodbye();

  return 0;
}


void Welcome(){
  cout << "Welcome to the Final Fitness tracker program\n\n"
       << "How many miles would you like to run this week? ";
}

void Goodbye(){
  cout << "Thank you for using the program. Keep running!" << endl;
}

void GetInput(int &goal){
  int userInput = 0;
  cin >> userInput;
  while (cin.fail() || userInput < 0){
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Invalid input. Please try again..." << endl;
    cin >> userInput;
  }
  goal = userInput;
}

int CalcTotal(){
  int total = 0;
  for (int i=0;i<7;++i){
    int userInput = -1;
    while (userInput < 0){
      cout << "How many miles did you ride on "
          << NumDayToName(i) << "? ";
      cin >> userInput;
      if (cin.fail() || userInput < 0){
       cin.clear();
       cin.ignore(10000, '\n');
       cout << "\nMiles must be 0 or greater!" << endl;
      }
    }
    total = total + userInput;
  }
  return total;
}

string NumDayToName(int numDay){
  string stringDay;
  switch (numDay){
    case 0:
      stringDay =  "Monday";
      break;
    case 1:
      stringDay = "Tuesday";
      break;
    case 2:
      stringDay = "Wednesday";
      break;
    case 3:
      stringDay = "Thursday";
      break;
    case 4:
      stringDay = "Friday";
      break;
    case 5:
      stringDay = "Saturday";
      break;
    case 6:
      stringDay = "Sunday";
      break;
    };

  return stringDay;
}