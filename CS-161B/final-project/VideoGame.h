#ifndef VIDEOGAME_H
#define VIDEOGAME_H

// Define struct
struct Video_Game{
    char gameName[120];
    char publisher[120];
    int year;
    double globalSales;
};

// Define function prototypes
Video_Game initGame(char* gameName, char* publisher, int year, double sales);
void removeGame(Video_Game data[], int count);
void searchGame(Video_Game data[], int count);
void printGame(Video_Game game);

#endif
