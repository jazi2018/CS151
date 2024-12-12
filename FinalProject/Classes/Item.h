/* Item.h - Class that represents an Item that a player could obtain.
 * Author:  Jared Ziv
 * Module:  Final Project
 * 
 * Description: Simple class containing logic for items. Can be either
 *      a weapon or a potion. Potions will heal, weapons will deal
 *      damage. Healing / damaging logic will be present when item
 *      is used.
 */
#pragma once
#include <string>
#include "Coordinate.h"
using namespace std;

class Item
{
    private:
        bool is_potion;
        int magnitude;  //magnitude of effect (healing or damage)
        Coordinate position;
    public:
        //defualt constructor
        Item() : is_potion(false), magnitude(0), position(Coordinate(-1,-1)) {}
        //parameterized constructor
        Item(bool is_potion, int magnitude, int max_width, int max_height) : is_potion(is_potion),
        magnitude(magnitude) { position.genCoord(max_width, max_height); }

        //healing vs damage logic will be in class above
        int use() { return magnitude; }

        //coord accessor / mutator
        void setCoord(Coordinate coord)
        {
            position = coord;
        }

        Coordinate getCoord()
        {
            return position;
        }
};