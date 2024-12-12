
#pragma once
#include <random>

struct Coordinate
{
    int x;
    int y;

    Coordinate() : x(0), y(0) {}
    Coordinate(int x, int y) : x(x), y(y) {}

    void genCoord(int width, int height)
    {
        //generates and returns a random coordinate
        x = rand() % width;
        y = rand() % height;
    }

    //overloaded operators to use in set, since sets must be sorted
    bool operator==(const Coordinate &other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator<(const Coordinate &other) const
    {
        //for comparisons, will check if x is lower first.
        //only if x is identical will y be a valid comparison
        return (x < other.x) || (x == other.x && y < other.y);
    }
    bool operator>(const Coordinate &other) const
    {
        //already implemented < operator so just using that
        //returns true if other < this (aka if this > other)
        return other < *this;
    }
    bool operator<=(const Coordinate & other) const
    {
        //returns true as long as this isnt greater than other
        return !(*this > other);
    }
    bool operator>=(const Coordinate & other) const
    {
        //returns true as long as this isnt less than other
        return !(*this < other);
    }
};