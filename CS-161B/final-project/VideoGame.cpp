#include <iostream>
#include <fstream>
#include <cstring>

#include "VideoGame.h"
using namespace std;


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


void printGameData(Video_Game data[], int dataSize){
  for (int i = 0; i < dataSize; ++i){
    cout << data[i].gameName << ","
         << data[i].year << ","
         << data[i].publisher << ","
         << data[i].globalSales
         << endl;
  }
}

void searchGame(Video_Game data[], int dataSize){
  // declare variables
  char gameName[120]; // game name to search for
  Video_Game searchMatch;
  bool foundMatch = false;

  // get user input
  cout << "Enter the name of the game you'd like to search for: ";
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


void printGame(Video_Game game){
  cout << "Game name: " << game.gameName << "\n"
       << "Published Date: " << game.year << "\n"
       << "Publisher: " << game.publisher << "\n"
       << "Global Sales: " << game.publisher << endl;
}
