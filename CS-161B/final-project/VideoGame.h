#ifndef VIDEOGAME_H_
#define VIDEOGAME_H

using namespace std;

// Define struct
struct Video_Game{
    char gameName[120];
    char publisher[120];
    int year;
    double globalSales;
};

// Define function prototypes
void removeGame(Video_Game data[], int count);
void searchGame(Video_Game data[], int count);
void printGame(Video_Game game);

#endif
