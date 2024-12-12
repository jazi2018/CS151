/* Player.h - Class containing all relevant player information
 * Author:  Jared Ziv
 * Module:  Final Project
 * 
 * Description: Player class, which will represent the player
 *      values throughout the game. Inherits from Entity.
 */
#pragma once
#include "Entity.h"
#include <random>
using namespace std;

class Player : public Entity
{
    private:
        int level;  //implementing this later
        int xp;     //need 100 xp to level up
    public:
        //default constructor
        Player() : xp(0), level(0) {}
        //parameterized constructor
        Player(int health, int atk, int max, int xp, int level, Coordinate pos) : xp(xp),
        level(level), Entity(health, atk, max, pos) {}
        virtual int attack() override;
};

int Player::attack()
{
    //if attack is 10, can deal anywhere from 5 - 14 dmg
    return rand() % atk + atk / 2;
}