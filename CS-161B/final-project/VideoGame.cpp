#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "VideoGame.h"
using namespace std;


//Name:   loadGameData()
//Desc:
//input:
//output:
//return: int
int loadGameData(ifstream& inFile, Video_Game data[]){
  int dataSize = 0;

  inFile.ignore(1000,'\n'); // ignore the data header

  while(!inFile.eof()){
    Video_Game game;

    // Store the game name
    inFile.getline(game.gameName, 120, ',');
    // Store the release year
    inFile >> game.year;
    inFile.ignore(100,',');
    // Store the publisher name
    inFile.getline(game.publisher, 120, ',');
    // Store the global sales
    inFile >> game.globalSales;
    inFile.ignore(100,'\n');

    // Add the game  to the data array
    addGame(game, data, dataSize);

  }
  return dataSize;
}

//Name: addGame()
//Desc:
//input:
//output:
//return: int
void addGame(Video_Game game, Video_Game data[], int& dataSize){
  // Dictates which indice to insert the game. Defaults to the end of the array
  int insertIndex = dataSize;

  for (int i = 0; i < dataSize; i++){
      // compares the global sales amount
      if (game.globalSales > data[i].globalSales){
          insertIndex = i;
          break;
      }
  }

  // shift right algorithm to add new game
  for(int j = dataSize; j > insertIndex; j--){
      data[j] = data[j-1];
  }

  // add the student
  data[insertIndex] = game;
 	dataSize++;
}


//Name: printGameData()
//Desc:
//input:
//output:
//return: int
void printGameData(Video_Game data[], int dataSize){
  for (int i = 0; i < dataSize; ++i){
    cout << data[i].gameName << ","
         << data[i].year << ","
         << data[i].publisher << ","
         << data[i].globalSales
         << endl;
  }
}


//Name: removeGame()
//Desc:
//input:
//output:
//return: int
void removeGame(Video_Game data[], int& dataSize){
    // declare variables
    char gameName[120]; // game name to delete
    bool foundMatch = false;
    int removeIndex;

    // get user input
    cout << "Enter the name of the game you'd like to remove (case sensitive): ";
    cin.getline(gameName, 120);

    cout << "Searching for " << gameName << endl;

    for(int i = 0; i < dataSize; ++i){
      if(strcmp(data[i].gameName, gameName) == 0){
        foundMatch = true;
        removeIndex = i;
        break; // quit the loop after finding a match
      }
    }


    // remove game if a match is found and print any results
    if(foundMatch){
        // Shift left algorithm
        for(int i = removeIndex; i < dataSize-1; i++){
            data[i] = data[i+1];
        }

        data[dataSize] = {};
        dataSize--; // deincrement # of elements in the array

        cout << "Game removed successfully!" << endl; // sucess message
    }
    else{
      cout << "No results found!" << endl;
    }
}

//Name: searchGame()
//Desc:
//input:
//output:
//return: int
void searchGame(Video_Game data[], int dataSize){
  // declare variables
  char gameName[120]; // game name to search for
  Video_Game searchMatch;
  bool foundMatch = false;

  // get user input
  cout << "Enter the name of the game you'd like to search for (case sensitive): ";
  cin.getline(gameName, 120);

  cout << "Searching for " << gameName << endl;

  for(int i = 0; i < dataSize; ++i){
    if(strcmp(data[i].gameName, gameName) == 0){
      searchMatch = data[i];
      foundMatch = true;
      break; // quit the loop after finding a match
    }
  }

  // Print the game info if there is a match otherwise output not found
  if(foundMatch){
    printGame(searchMatch);
  }
  else{
    cout << "No results found!" << endl;
  }

}


//Name:   printGame()
//Desc:
//input:
//output:
//return: int
void printGame(Video_Game game){
  cout << "Game name: " << game.gameName << "\n"
       << "Published Date: " << game.year << "\n"
       << "Publisher: " << game.publisher << "\n"
       << "Global Sales: " << game.publisher << endl;
}

//Name:   calcPublisherAvg()
//Desc:
//input:
//output:
//return: int
void calcPublisherAvg(Video_Game data[], int dataSize){
    // declare variables
    char publisherName[120]; // game name to search for
    Video_Game searchMatch;
    bool foundMatch = false;

    // Used for finding the average global sales of the publisher
    int globalSalesTotal = 0; // total global sales for the publisher
    int numGamesTotal = 0; // total number of games the publisher has

    // get user input
    cout << "Enter the name of the publisher you'd like \nto find the average global sales for (case sensitive): ";
    cin.getline(publisherName, 120);

    cout << "Searching for " << publisherName << endl;

    // loop through the data
    for(int i = 0; i < dataSize; ++i){
      if(strcmp(data[i].publisher, publisherName) == 0){
          // switch foundMatch to true once the publisher name is found
          if(!foundMatch){
              foundMatch = true;
          }
          // track data
          globalSalesTotal += data[i].globalSales; // add up the total
          numGamesTotal++; // increment the total # of games
      }
    }

    // Print the game info if there is a match otherwise output not found
    if(foundMatch){
        double publisherAvg = static_cast<double>(globalSalesTotal)/numGamesTotal;

        cout << fixed << setprecision(2)
             << "The average global sales for " << publisherName << "\n"
             << "is " << publisherAvg << endl;
    }
    else{
      cout << "Could not find the publisher!" << endl;
    }
}
