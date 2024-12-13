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

        //returns t/f if player is alive
        bool combat(Monster &enemy);

        //main game loop
        void runGame();
};

//TODO: enemy scaling to make it a game and save state with binary file
//initializing player to default values
Game::Game() : num_monsters(4), num_items(3),
player(Player(100, 10, 100, 0, 1)), map(Map(num_monsters, num_items, player))
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
    //map = Map(num_monsters, num_items, player);
    map.populate(monsters, items);
}

bool Game::combat(Monster &enemy)
{
    while(enemy.isAlive() && player.isAlive())
    {
        //monster will attack first
        int damage = enemy.attack();
        cout << "Monster attacks for " << damage << " damage!" << endl;
        player.takeDamage(damage);
        cout << "You have " << player.getHealth() << " health remaining." << endl;
        if (!player.isAlive())
        {
            //player died
            return false;
        }

        cout << endl << "Your turn!" << endl;
        int selection = 0;
        while (selection != 1 && selection != 2)
        {
            cout << "1. Attack" << endl;
            cout << "2. Use potion" << endl;
            cin >> selection;
            switch (selection)
            {
                case 1:
                    damage = player.attack();
                    cout << "You attack for " << damage << " damage!" << endl;
                    enemy.takeDamage(damage);
                    cout << "The monster has " << enemy.getHealth() << " health remaining." << endl;
                    if (!enemy.isAlive())
                    {
                        return true;
                    }
                    break;
                case 2:
                    if (!player.usePotion())
                    {
                        //so that loop begins again
                        selection = 0;
                    }
                    break;
                default:
                    cout << "Invalid selection" << endl;
            }
        }
    }
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
            //find monster at coordinate
            for (int i = 0; i < num_monsters; i++)
            {
                if (monsters[i].getCoord() == player.getCoord())
                {
                    bool success = combat(monsters[i]);
                    if (!success)
                    {
                        cout << "You lose!" << endl;
                        return;
                    }
                }
            }
        }
        else if (containsCoord(player, items, num_items))
        {
            //pick up item
            //find item at coordinate
            for (int i = 0; i < num_items; i++)
            {
                if (items[i].getCoord() == player.getCoord())
                {
                    player.addItem(items[i]);
                }
            }
        }
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