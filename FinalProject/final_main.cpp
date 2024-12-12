#include <iostream>
#include <ctime>
#include "Classes\Game.h"
using namespace std;

int main()
{
    //will act as main menu. new game, load game (from saved text files), help
    //actual game will be run in a game class

    //take input function that will return the input and make sure its a valid selection
    //by checking an array of inputs

    Game game;
    game.runGame();

    return 0;
}