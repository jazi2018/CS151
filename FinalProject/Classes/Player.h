/* Player.h - Class containing all relevant player information
 * Author:  Jared Ziv
 * Module:  Final Project
 * 
 * Description: Player class, which will represent the player
 *      values throughout the game. Inherits from Entity.
 */
#pragma once
#include "Entity.h"
#include "Item.h"
#include <random>
#include <vector>
//#include <iterator>
using namespace std;

class Player : public Entity
{
    private:
        int level;  //implementing this later
        int xp;     //need 100 xp to level up
        vector<Item> inventory;
    public:
        //default constructor
        Player() : xp(0), level(0) {}
        //parameterized constructor
        Player(int health, int atk, int max, int xp, int level) :
        xp(xp), level(level), Entity(health, atk, max) { position = Coordinate(0,0); }
        virtual int attack() override;

        //inventory management
        void addItem(Item item);
        bool usePotion();
};

int Player::attack()
{
    //add up damage from all weapons
    int weapon_dam = 0;
    for (Item i : inventory)
    {
        if (!i.isPotion())
        {
            weapon_dam += i.use();
        }
    }

    //if attack is 10, can deal anywhere from 5 - 14 dmg
    return rand() % atk + atk / 2 + weapon_dam;
}

void Player::addItem(Item item)
{
    //adds item to player inventory
    inventory.push_back(item);
    cout << "Added " << (item.isPotion() ? "potion" : "weapon") <<
    " to inventory." << endl;
}

bool Player::usePotion()
{
    for (int i = 0; i < inventory.size(); i++)
    {
        //only does anything if we find a potion while iterating.
        if (inventory.at(i).isPotion())
        {
            int amt = inventory.at(i).use();
            this->healDamage(amt);
            cout << "Healed " << amt << " damage." << endl;
            inventory.erase(inventory.begin() + i);
            return true;
        }
    }
    //reports that there are no potions if none found
    cout << "No potions available for use." << endl;
    return false;
}