/* Monster.h - Class representing monster entities in the game
 * Author:  Jared Ziv
 * Module:  Final Project
 * 
 * Description: This file contains the prototypes for the Monster
 *      class, which inherits from Entity and represents enemy
 *      characters in the game. It includes functionality for monster
 *      creation, attack calculation, and health management.
 */
#pragma once
#include "Entity.h"
#include "Coordinate.h"
#include <random>
using namespace std;

class Monster : public Entity
{
    //could add private member for amount of xp given
    public:
        //default constructor
        Monster() : Entity() {}
        //parameterized constructor
        Monster(int health, int atk, int max, int max_width, int max_height) :
        Entity(health, atk, max) { position.genCoord(max_width, max_height); }
        virtual int attack() override;

        int getMax();
};

int Monster::attack()
{
    //just relates to attack of monster
    return rand() % atk + atk / 2;
}

int Monster::getMax() { return MAX_HEALTH; }