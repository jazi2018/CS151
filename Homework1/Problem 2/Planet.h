#ifndef PLANET_H
#define PLANET_H

#include <string>

class Planet //define planet class
{
    private: //member variables
        std::string name;
        int diameter;
        long long dist;
    public: //member functions
        Planet(); //default constructor
        Planet(std::string p_name, int p_diameter, long long p_dist); //parameterized constructor

        //getters
        std::string get_name();
        int get_diameter();
        long long get_dist();

        //setters
        void set_name(std::string p_name);
        void set_diameter(int p_diameter);
        void set_dist(long long p_dist);
};

#endif