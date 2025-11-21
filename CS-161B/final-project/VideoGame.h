#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
using namespace std;

// Define struct
struct Video_Game{
    char gameName[120];
    char publisher[120];
    int year;
    double globalSales;
};

// Define function prototypes
int loadGameData(ifstream& inFile, Video_Game data[]);
Video_Game createGame(char* gameName, char* publisher, int year, double sales);
void addGame(Video_Game game, Video_Game data[], int& dataSize);
void removeGame(Video_Game data[], int count);
void searchGame(Video_Game data[], int count);
void printGame(Video_Game game);

#endif
