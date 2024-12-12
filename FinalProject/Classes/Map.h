
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
        char grid[width][height];
    
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
        Map(int num_monsters, int num_items) :
        num_monsters(num_monsters), num_items(num_items), player(Coordinate(0,0))
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

        //member functions
        Coordinate genCoord()
        {
            //generates and returns a random coordinate
            int x = rand() % width;
            int y = rand() % height;
            return Coordinate(x, y);
        }

        void populate()
        {
            cout << "num_monsters: " << num_monsters << endl;
            cout << "num_items: " << num_items << endl;
            //generate monster positions
            for (int i = 0; i < num_monsters; i++)
            {
                //generate positions until a position is found
                //that does not already exist in the set (i.e. count == 0)
                Coordinate position;
                do
                {
                    position = genCoord();
                } while (used_pos.count(position) != 0);

                monsters[i] = position;
                used_pos.insert(position);

                //populate monster position with 'M'
                grid[position.y][position.x] = 'M';
            }

            //generate item positions
            for (int i = 0; i < num_items; i++)
            {
                Coordinate position;
                do
                {
                    position = genCoord();
                } while (used_pos.count(position) != 0);

                items[i] = position;
                used_pos.insert(position);

                //populate item position with 'I'
                grid[position.y][position.x] = 'I';
            }

            //place @ at player position
            grid[player.y][player.x] = '@';
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
        bool movePlayer(int direction)
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
            if (next_position < Coordinate(0,0) ||
                next_position >= Coordinate(width, height))
            {
                //out of bounds
                return false;
            }

            //check if anything is on tile
            if (used_pos.count(next_position) > 0)
            {
                //check if monster
                if (grid[next_position.y][next_position.x] == 'M')
                {
                    //find which monster corresponds to the tile
                    for (int i = 0; i < num_monsters; i++)
                    {
                        if (next_position == monsters[i])
                        {
                            //remove monster from coordinate list
                            monsters[i] = Coordinate(-1,-1);
                        }
                    }
                }
                //check if item
                else if (grid[next_position.y][next_position.x] == 'I')
                {
                    //find which item corresponds to the tile
                    for (int i = 0; i < num_items; i++)
                    {
                        if (next_position == items[i])
                        {
                            //remove item from coordinate list
                            items[i] = Coordinate(-1,-1);
                        }
                    }
                }
            }
            //update player position
            used_pos.erase(player);
            used_pos.insert(next_position);
            grid[player.y][player.x] = '.';
            player = next_position;
            grid[player.y][player.x] = '@';
            return true;
        }
};