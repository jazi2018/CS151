#pragma once
#include <iostream>

using namespace std;

class Animal
{
    private:
        string name = "";
    
    public:
        Animal(string name) //parameterized constructor
        {
            this->name = name;
            cout << "The Animal " << this->name << " has been created." << endl;
        }

        //getters
        string getName() const { return name; }

        //setters
        void setName(const string name) { this->name = name; }

        //member functions
        void sleep()
        {
            cout << "The Animal " << getName() << " is sleeping." << endl;
        }
        void makeNoise()
        {
            cout << "The Animal " << getName() << " is making a noise." << endl;
        }
        void showInfo()
        {
            cout << "The Animal " << getName() << endl;
        }
};