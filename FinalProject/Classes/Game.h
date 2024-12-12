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
#include "Item.h"
#include "Map.h"
using namespace std;

bool containsCoord(Player player, Monster * monsters, int size);
bool containsCoord(Player player, Item * items, int size);

class Game
{
    private:
        Player player;
        Monster * monsters;
        Item * items;
        int num_monsters;
        int num_items;
        Map map;
    public:
        //default constructor
        Game();

        //main game loop
        void runGame();
};

Game::Game() : num_monsters(4), num_items(3)
{
    //generate initial monster list
    monsters = new Monster[num_monsters];
    for (int i = 0; i < num_monsters; i++)
    {
        //generate a monster at a random position
        monsters[i] = Monster(100, 15, 100, map.getWidth(), map.getHeight());
    }

    //generate initial item list
    items = new Item[num_items];
    for (int i = 0; i < num_items; i++)
    {
        //generate random items here later (25% chance to be weapon?)
        items[i] = Item(true, 25, map.getWidth(), map.getHeight());
    }
    //temporary code for testing
    map = Map(num_monsters, num_items);
    map.populate(monsters, items);
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
        map.movePlayer(player, direction);
        if (containsCoord(player, monsters, num_monsters))
        {
            //combat with monster
        }
        else if (containsCoord(player, items, num_items))
        {
            //pick up item
        }

        cout << "player x = " << player.getCoord().x << " player y = " << player.getCoord().y;
    }
}

bool containsCoord(Player player, Monster * monsters, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (player.getCoord() == monsters[i].getCoord())
        {
            return true;
        }
    }

    return false;
}

bool containsCoord(Player player, Item * items, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (player.getCoord() == items[i].getCoord())
        {
            return true;
        }
    }

    return false;
}