/* hmwk13_proj1.cpp - Demonstrates a bound checking string class
 * Author:     Jared Ziv
 * Module:     13
 * Project:    Homework, Part 1
 * Problem statement:  Write a class named  BCheckString  that is derived from
 *      the STL (Standard Template Library)  string  class. This new class should
 *      have two member functions: A  BCheckString (string s)  constructor that
 *      receives a string object passed by value and passes it on to the base class
 *      constructor and a char operator [ ] (int k)  function that throws a
 *      BoundsException  object if the index  k  is negative or is greater than or
 *      equal to the length of the string.  If  k  is within the bounds of the
 *      string, this function should return the character at position  k  in the
 *      string.
 *
 * Algorithm:
 *   1. Define BoundsException as a struct. Pass the index to the constructor and
 *      construct a message that will be returned when what() is called.
 *   2. Override the [] operator to first check if the passed index is less than
 *      0 or greater than or equal to the length of the string. If either case is
 *      true, throw a BoundsException and pass the index being checked. Otherwise
 *      return this->at(index)
 *   3. Test using various indices in main
 */

#include <iostream>
#include <iomanip>
#include "BCheckString.h"
using namespace std;

int main()
{
    BCheckString str("This string is a test.");
    cout << left << setw(15) << "String" << " : " << str << endl;

    //valid indices
    cout << left << setw(15) << "Index 0" << " : " << str[0] << endl;
    cout << left << setw(15) << "Index 21" << " : " << str[21] << endl;

    //invalid indices
    //-1
    try
    {
        cout << left << setw(15) << "Index -1" << " : ";
        cout << str[-1] << endl;
    }
    catch (BoundsException &e)
    {
        cout << e.what() << endl;
    }
    //22
    try
    {
        cout << left << setw(15) << "Index 22" << " : ";
        cout << str[22] << endl;
    }
    catch (BoundsException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}