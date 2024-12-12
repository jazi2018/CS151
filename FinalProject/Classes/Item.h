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
using namespace std;

class Item
{
    private:
        bool is_potion;
        int magnitude;  //magnitude of effect (healing or damage)
    public:
        //defualt constructor
        Item() : is_potion(false), magnitude(0) {}
        //parameterized constructor
        Item(bool is_potion, int magnitude) : is_potion(is_potion),
        magnitude(magnitude) {}

        //healing vs damage logic will be in class above
        int use() { return magnitude; }
};