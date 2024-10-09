#pragma once
#include <iostream>
#include "Animal.h"

using namespace std;

class Owl : public Animal
{
    private:
        string breed;

    public:
        Owl(string name, string breed) : Animal(name), breed(breed)
        {
            cout << "A Owl " << getName() << " of breed " << this->breed << " has been created." << endl;
        }

        //getter
        string getBreed() const { return this->breed; }

        //setter
        void setBreed(const string breed) { this->breed = breed; }

        void makeNoise()
        {
            cout << "The Owl " << getName() << " is hooting." << endl;
        }
        void showInfo()
        {
            cout << "The Owl " << getName() << " of breed " << this->breed << "." << endl;
        }
};