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
      if (game.globalSales < data[i].globalSales){
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
