/* Game.h - Class containing all game logic and main game loop
 * Author:  Jared Ziv
 * Module:  Final Project
 * 
 * Description: Game class to localize all necessary game logic.
 *      Interfaces with other present classes, such as map, to
 *      handle overarching logic and game states.
 */
#pragma once
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Map.h"
using namespace std;

class Game
{
    private:
        Player player;
        Map map;
    public:
        //default constructor
        Game();

        //main game loop
        void runGame();
};

Game::Game() : player(Player(50, 10, 50, 0, 1))
{
    //temporary code for testing
    map = Map(3, 2);
    map.populate();
}

void Game::runGame()
{
    // Monster mon(50, 10, 50);
    // while (player.isAlive())
    // {
    //     int dmg = player.attack();
    //     cout << "Player attacks for " << dmg << " dmg." << endl;
    //     mon.takeDamage(dmg);
    //     cout << "Monster now has " << mon.getHealth() << " health." << endl;

    //     dmg = mon.attack();
    //     cout << "Monster attacks for " << dmg << " dmg." << endl;
    //     player.takeDamage(dmg);
    //     cout << "Player now has " << player.getHealth() << " health." << endl;
    // }
    while(true)
    {
        map.print();
        int direction = 0;
        cin >> direction;
        map.movePlayer(direction);
    }
}