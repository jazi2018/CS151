#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Fox : public Animal
{
    public:
        Fox(string name) : Animal(name)
        {
            cout << "A Fox " << getName() << " has been created." << endl;
        }

        void makeNoise()
        {
            cout << "The Fox " << getName() << " is yelping." << endl;
        }

        void showInfo()
        {
            cout << "The Fox " << getName() << endl;
        }
};