#include "Planet.h"

Planet::Planet() //default constructor
{
    name = "";
    diameter = 0;
    dist = 0;
}

Planet::Planet(std::string p_name, int p_diameter, long long p_dist) //parameterized constructor
{
    name = p_name;
    diameter = p_diameter;
    dist = p_dist;
}

//getters

std::string Planet::get_name()
{
    return name;
}

int Planet::get_diameter()
{
    return diameter;
}

long long Planet::get_dist()
{
    return dist;
}

//setters

void Planet::set_name(std::string p_name)
{
    name = p_name;
}

void Planet::set_diameter(int p_diameter)
{
    diameter = p_diameter;
}

void Planet::set_dist(long long p_dist)
{
    dist = p_dist;
}