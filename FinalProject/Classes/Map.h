/* Map.h - Class representing the game map and its elements
 * Author:  Jared Ziv
 * Module:  Final Project
 * 
 * Description: Map class that manages the game's 2D grid, including
 *      player, monster, and item positions. It handles map generation,
 *      population, movement, and tile checking. In an attempt to provide
 *      good encapsulation (as in the Map class ONLY manages map related
 *      events) I WAY overcomplicated it. It only considers coordinates
 *      of the player, monsters, and items, and uses dynamic memory
 *      allocation to do so.
 *      I used the STL Set data structure to store used coordinates,
 *      since it can only contain unique items. This also contributed
 *      to its overcomplication, but I thought it made sense logically.
 */
#pragma once
#include <iostream>
#include <set> // data structure from C++ STL
#include "Player.h"
#include "Entity.h"
#include "Coordinate.h"
using namespace std;

class Map
{
    private:
        Coordinate player;

        int num_monsters;
        Coordinate * monsters;

        int num_items;
        Coordinate * items;

        //all coordinates regardless of type
        set<Coordinate> used_pos;

        //dimensions of map grid (always 15x10)
        static const int width = 15;
        static const int height = 10;
        char grid[height][width];
    
    public:
        //default constructor
        Map()
        {
            num_items = 0;
            num_monsters = 0;

            monsters = nullptr;
            items = nullptr;
            player = Coordinate(0, 0);
            used_pos.insert(player);

            //fill map with '.'
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    grid[i][j] = '.';
                }
            }
        }

        //parameterized constructor
        Map(int num_monsters, int num_items, Player player) :
        num_monsters(num_monsters), num_items(num_items)//, player(player.getCoord())
        {
            //allocate array for monsters and items
            monsters = (num_monsters > 0) ? new Coordinate[num_monsters] : nullptr;

            items = (num_items > 0) ? new Coordinate[num_items] : nullptr;

            //fill map with '.'
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    grid[i][j] = '.';
                }
            }
            this->player = player.getCoord();
        }

        //destructor
        ~Map()
        {
            if (monsters != nullptr)
            {
                delete [] monsters;
                monsters = nullptr;
            }
            if (items != nullptr)
            {
                delete [] items;
                items = nullptr;
            }
        }

        //overloaded operator= to copy another map
        Map& operator=(const Map &other)
        {
            //deallocate any pre-existing memory
            delete [] monsters;
            delete [] items;

            //update member values
            num_monsters = other.num_monsters;
            num_items = other.num_items;
            player = other.player;
            used_pos = other.used_pos;

            //allocate new memory to use for deep copy
            monsters = (num_monsters > 0) ? new Coordinate[num_monsters] : nullptr;
            items = (num_items > 0) ? new Coordinate[num_items] : nullptr;

            //copy
            for (int i = 0; i < num_monsters; i++)
            {
                monsters[i] = other.monsters[i];
            }
            for (int i = 0; i < num_items; i++)
            {
                items[i] = other.items[i];
            }

            //copy grid
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    grid[i][j] = other.grid[i][j];
                }
            }

            return *this;
        }

        //accessors
        int getWidth() { return width; }
        int getHeight() { return height; }

        void populate(Monster *monster_list, Item *item_list)
        {
            //populate monsters
            for (int i = 0; i < num_monsters; i++)
            {
                //generate positions until a position is found
                //that does not already exist in the set (i.e. count == 0)
                Coordinate position = monster_list[i].getCoord();
                if (used_pos.count(position) != 0) //if in list
                {
                    do
                    {
                        //generate new positions until not in list
                        position.genCoord(width, height);
                    } while (used_pos.count(position) != 0);
                    //update monster position if changed
                    monster_list[i].setCoord(position);
                }

                monsters[i] = position;
                used_pos.insert(position);

                //populate monster position with 'M'
                grid[position.y][position.x] = 'M';
            }

            //populate items
            for (int i = 0; i < num_items; i++)
            {
                //generate positions until a position is found
                //that does not already exist in the set (i.e. count == 0)
                Coordinate position = item_list[i].getCoord();
                if (used_pos.count(position) != 0) //if in list
                {
                    do
                    {
                        //generate new positions until not in list
                        position.genCoord(width, height);
                    } while (used_pos.count(position) != 0);
                    //update item position if changed
                    item_list[i].setCoord(position);
                }

                items[i] = position;
                used_pos.insert(position);

                //populate item position with 'I'
                grid[position.y][position.x] = 'I';
            }

            //place indicator on player position
            grid[player.y][player.x] = '@';
            used_pos.insert(player);
        }

        void print()
        {
            for(int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    cout << grid[i][j] << ' ';
                }
                cout << endl;
            }
        }

        //player functions
        bool movePlayer(Player &player_obj, int direction)
        {
            //direction represents a cardinal direction, starting from
            //north = 0, and moving clockwise (i.e east = 1, south = 2 ...)
            Coordinate next_position = player;
            switch (direction)
            {
                case 0:
                    next_position.y -= 1;
                    break;
                case 1:
                    next_position.x += 1;
                    break;
                case 2:
                    next_position.y += 1;
                    break;
                case 3:
                    next_position.x -= 1;
                    break;
                default:
                    cout << "ERROR: Invalid direction" << endl;
                    return false;
            }

            //check bounds of movement
            if (next_position.x < 0 || next_position.y < 0 ||
                next_position.x >= width || next_position.y >= height)
            {
                //out of bounds
                return false;
            }

            //update player position
            used_pos.erase(player);
            used_pos.insert(next_position);
            grid[player.y][player.x] = '.';
            player = next_position;
            grid[player.y][player.x] = '@';
            //update player object
            player_obj.setCoord(player);
            return true;
        }

        bool playerOnMonster()
        {
            if (used_pos.count(player) > 0)
            {
                //check if monster
                if (grid[player.y][player.x] == 'M')
                {
                    //find which monster corresponds to the tile
                    for (int i = 0; i < num_monsters; i++)
                    {
                        if (player == monsters[i])
                        {
                            //remove monster from coordinate list
                            monsters[i] = Coordinate(-1,-1);
                            return true;
                        }
                    }
                }
            }

            return false;
        }

        bool playerOnItem()
        {
            if (used_pos.count(player) > 0)
            {
                //check if Item
                if (grid[player.y][player.x] == 'I')
                {
                    //find which Item corresponds to the tile
                    for (int i = 0; i < num_items; i++)
                    {
                        if (player == items[i])
                        {
                            //remove Item from coordinate list
                            items[i] = Coordinate(-1,-1);
                            return true;
                        }
                    }
                }
            }

            return false;
        }
};