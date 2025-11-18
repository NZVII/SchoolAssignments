#include "VideoGame.h"
#include <iostream>
#include <cstring>
using namespace std;

Video_Game initGame(char* gameName, char* publisher, int year, double sales){
    Video_Game game;
    strcpy(game.gameName, gameName);
    strcpy(game.publisher, publisher);
    game.year = year;
    game.globalSales = sales;

    return game;
}
