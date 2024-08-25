// Homework 1, Project 2: Create planet class, sort planets
// based on distance from sun. Report results in a formatted table.
// Tally the results of diameter and distance to sun at end
// of the table.
//
// Jared Ziv

#include <iostream>
#include <iomanip>
#include <vector>
#include "Planet.h"
#include "Planet.cpp"

using namespace std;

void insertPlanet(vector<Planet> &planets, Planet planet);


int main()
{
    const int NUM_PLANETS = 13;
    vector<Planet> planets;
    planets.reserve(NUM_PLANETS); //set capacity to number of planets

    //Ceres
    Planet ceres("Ceres", 952, 413700000);
    insertPlanet(planets, ceres);

    //Earth
    Planet earth("Earth", 12756, 149600000);
    insertPlanet(planets, earth);

    //Eris
    Planet eris("Eris", 2321, 10125000000);
    insertPlanet(planets, eris);

    //Haumea
    Planet haumea("Haumea", 1220, 6452000000);
    insertPlanet(planets, haumea);

    //Jupiter
    Planet jupiter("Jupiter", 142796, 778300000);
    insertPlanet(planets, jupiter);

    //Makemake
    Planet makemake("Makemake", 1475, 6850000000);
    insertPlanet(planets, makemake);

    //Mars
    Planet mars("Mars", 6787, 227900000);
    insertPlanet(planets, mars);

    //Mercury
    Planet mercury("Mercury", 4878, 57900000);
    insertPlanet(planets, mercury);

    //Neptune
    Planet neptune("Neptune", 48600, 4497000000);
    insertPlanet(planets, neptune);

    //Pluto
    Planet pluto("Pluto", 2302, 5891000000);
    insertPlanet(planets, pluto);

    //Saturn
    Planet saturn("Saturn", 120660, 1427000000);
    insertPlanet(planets, saturn);

    //Uranus
    Planet uranus("Uranus", 51118, 2831000000);
    insertPlanet(planets, uranus);

    //Venus
    Planet venus("Venus", 12104, 108200000);
    insertPlanet(planets, venus);

    int tsize_planet = 10, tsize_diameter = 9, tsize_dist = 16; //determine size for justifications
    long long total_diameter = 0, total_dist = 0;
    cout << " Solar System Planets by Distance" << endl; //format header
    cout << "Planet     Diameter    Dist. to Sun" << endl;
    cout << "-------    --------    ------------" << endl;
    for (int i = 0; i < planets.size(); i++)
    {
        cout << setw(tsize_planet) << left << planets.at(i).get_name();
        cout << setw(tsize_diameter) << right << planets.at(i).get_diameter();
        cout << setw(tsize_dist) << right << planets.at(i).get_dist() << endl;
        total_diameter += planets.at(i).get_diameter();
        total_dist += planets.at(i).get_dist();
    }
    cout << setw(tsize_planet) << left << "Totals:";
    cout << setw(tsize_diameter) << right << total_diameter;
    cout << setw(tsize_dist) << right << total_dist << endl;

    return 0;
}

void insertPlanet(vector<Planet> &planets, Planet planet)
{
    if (planets.size() == planets.capacity()) //if vector is full return
    {
        return;
    }
    else if (planets.size() == 0) //if vector is empty, add planet and return
    {
        planets.push_back(planet);
        return;
    }
    
    vector<Planet>::iterator it = planets.begin(); //create iterator
    Planet iter_planet; //object to hold dereferenced iterator
    while (it != planets.end())
    {
        iter_planet = *it; //dereference iterator into Planet object
        if (iter_planet.get_dist() > planet.get_dist())
        {
            planets.insert(it, planet); //insert planet if its dist is bigger (ascending order)
            break;
        }

        it++; //iterate
    }
    if (it == planets.end()) //if bigger than every other planet, put at end of vector
    {
        planets.push_back(planet);
    }
}