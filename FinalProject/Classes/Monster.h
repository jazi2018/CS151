
#pragma once
#include "Entity.h"
#include "Coordinate.h"
#include <random>
using namespace std;

class Monster : public Entity
{
    public:
        //default constructor
        Monster() : Entity() {}
        //parameterized constructor
        Monster(int health, int atk, int max, Coordinate pos) :
        Entity(health, atk, max, pos) {}
        virtual int attack() override;
};

int Monster::attack()
{
    //just relates to attack of monster
    return rand() % atk + atk / 2;
}