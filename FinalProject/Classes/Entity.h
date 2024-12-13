/* Entity.h - Abstract class representing an entity
 * Author:  Jared Ziv
 * Module:  Final Project
 * 
 * Description: This file contains the prototypes for the abstract
 *      class "Entity". An Entity will be anything present in the
 *      game which has features similar to a living creature (meaning
 *      health, attack, inventory, etc.)
 * 
 *      Other classes, such as Player or Enemy will inherit from
 *      Entity.
 */
#pragma once
#include "Coordinate.h"
using namespace std;

class Entity
{
    private:
        int health;
        bool is_alive;  //will handle is_alive logic in takeDamage()
        //inventory implemented after items'
    
    protected:
        int atk;
        Coordinate position;
        int MAX_HEALTH;
    
    public:
        //default constructor
        Entity() : health(0), atk(0), is_alive(true), MAX_HEALTH(0),
        position(Coordinate(-1,-1)) {}
        //parameterized constructor
        Entity(int health, int atk, int max) : health(health), atk(atk),
        is_alive(true), MAX_HEALTH(max), position(Coordinate(-1,-1)) {}

        bool takeDamage(int dmg);
        bool healDamage(int healing);
        bool isAlive();
        void setCoord(Coordinate coord);
        Coordinate getCoord();

        //accesor
        int getHealth() { return health; }

        //pure virtual. children must implement attack
        virtual int attack() = 0;
};

bool Entity::takeDamage(int dmg)
{
    //if already dead, cant deal damage to it
    if (!is_alive) { return false; }

    //entity dies if health drops to or below 0
    health -= dmg;
    if (health <= 0) { is_alive = false; }
    return true;
}

bool Entity::healDamage(int healing)
{
    //cant heal entity that isnt alive
    if (!is_alive) { return false; }

    //cap health at max health
    health += healing;
    if (health > MAX_HEALTH) { health = MAX_HEALTH; }
    return true;
}

bool Entity::isAlive()
{
    return is_alive;
}

void Entity::setCoord(Coordinate coord)
{
    position = coord;
}

Coordinate Entity::getCoord()
{
    return position;
}