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
        int round;
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
Game::Game() : num_monsters(3), num_items(4), round(1),
player(Player(100, 15, 100)), map(Map(num_monsters, num_items, player)) //player starts with 100 hp, 15 atk
{
    //generate initial monster list
    monsters = new Monster[num_monsters];
    for (int i = 0; i < num_monsters; i++)
    {
        //generate a monster at a random position
        //start weak, will scale over time (exponentially)
        monsters[i] = Monster(25, 5, 25, map.getWidth(), map.getHeight());
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
        string selection;
        while (selection[0] != '1' && selection[0] != '2')
        {
            cout << "1. Attack" << endl;
            cout << "2. Use potion" << endl;
            cin >> selection;
            switch (selection[0])
            {
                case '1':
                    damage = player.attack();
                    cout << "You attack for " << damage << " damage!" << endl;
                    enemy.takeDamage(damage);
                    cout << "The monster has " << enemy.getHealth() << " health remaining." << endl;
                    if (!enemy.isAlive())
                    {
                        return true;
                    }
                    break;
                case '2':
                    if (!player.usePotion())
                    {
                        //so that loop begins again
                        selection = '0';
                    }
                    break;
                default:
                    cout << "Invalid selection" << endl;
            }
        }
    }

    //if somehow exiting the loop, an error has occured and false is returned
    return false;
}

void Game::runGame()
{
    cout << "Welcome! Defeat all enemies to progress to the next level." << endl;
    while(true)
    {
        //display map
        map.print();

        //take movement input
        cout << "'W' = up, 'S' = down, 'A' = left, 'D' = right" << endl;
        cout << "'P' to use a potion, 'X' to exit the game" << endl;
        string input;
        cin >> input;
        int direction;
        switch (tolower(input[0]))
        {
            case 'w' : direction = 0; break;
            case 'd' : direction = 1; break;
            case 's' : direction = 2; break;
            case 'a' : direction = 3; break;
            case 'p' : player.usePotion(); continue;
            case 'x' : cout << "Thanks for playing!" << endl; return;
            default : cout << "Invalid selection." << endl; continue;
        }
        map.movePlayer(player, direction);

        //check if on monster tile
        if (containsCoord(player, monsters, num_monsters))
        {
            //combat with monster
            //find monster at coordinate
            for (int i = 0; i < num_monsters; i++)
            {
                if (monsters[i].getCoord() == player.getCoord())
                {
                    //run combat
                    bool success = combat(monsters[i]);
                    //move monster to -1,-1 (off the map)
                    monsters[i].setCoord(Coordinate(-1,-1));
                    if (!success)
                    {
                        cout << "You lose!" << endl;
                        cout << "You made it to level " << round << "!" << endl;
                        cout << "Better luck next time!" << endl;
                        return;
                    }
                }
            }
        }

        //check if player is on item tile
        else if (containsCoord(player, items, num_items))
        {
            //pick up item
            //find item at coordinate
            for (int i = 0; i < num_items; i++)
            {
                if (items[i].getCoord() == player.getCoord())
                {
                    player.addItem(items[i]);
                    //move item so it cannot be picked up again
                    items[i].setCoord(Coordinate(-1,-1));
                }
            }
        }

        bool alive = false;
        //check if all monsters are dead. if so, progress to the next level
        for (int i = 0; i < num_monsters; i++)
        {
            if (monsters[i].isAlive())
            {
                alive = true;
                break;
            }
        }
        //if any monsters alive, move to next iteration
        if (alive) { continue; }

        cout << "You have defeated all monsters! Moving to next level." << endl;
        //if for loop was exited, all monsters are dead. progress to next level
        ++round;
        //move player back to 0,0
        player.setCoord(Coordinate(0,0));
        //store monster current attack and health (attack will generate a random value
        //within a range, scaling will vary slightly every game)
        int m_attack = monsters[0].attack();
        int m_health = monsters[0].getMax();
        //store item magnitude. gains 10 every round
        int i_magnitude = items[0].use();
        //clear monsters and items from memory
        delete [] monsters;
        delete [] items;
        //add one more monster and one more item
        ++num_monsters;
        ++num_items;
        //allocate memory for new monsters and items
        monsters = new Monster[num_monsters];
        items = new Item[num_items];
        //populate monsters with scaling
        for (int i = 0; i < num_monsters; i++)
        {
            monsters[i] = Monster(m_health * 2, m_attack * 2, m_health * 2, map.getWidth(), map.getHeight());
        }
        //populate items (25% chance for item to be a weapon)
        for (int i = 0; i < num_items; i++)
        {   
            //25% chance for rand() % 4 to be 3
            bool potion = (rand() % 4 < 3) ? true : false;
            items[i] = Item(potion, i_magnitude + 10, map.getWidth(), map.getHeight());
        }
        //allocate map
        map = Map(num_monsters, num_items, player);
        map.populate(monsters, items);
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