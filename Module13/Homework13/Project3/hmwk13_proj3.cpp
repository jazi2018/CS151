/* hmwk13_proj3.cpp - Demonstrates SimpleVector class template
 * Author:     Jared Ziv
 * Module:     13
 * Project:    Homework, Part 3
 * Problem statement: Write a class template named  SortableVector.
 *      The class should be a child of the modified class from Project 2 above.
 *      It should have a member function that sorts the array elements in
 *      ascending order, and  should overload the [ ] operator. If the calling
 *      program passes an argument which is less than 0 or greater than or
 *      equal to the size, then throw an exception.
 *
 * Algorithm:
 *   1. Implement insertion sort for the sorting algorithm, where the key is
 *      gradually shifted up an index at a time, and assuming every index
 *      before the key is sorted.
 *   2. Overload operator[]. Check that the index passed is within bounds of
 *      the vector. If it isn't, throw a BoundsException. Otherwise, return
 *      the object at this->aptr[index]
 */
#include <iostream>
#include <random>
#include <time.h>
#include "SortableVector.h"
using namespace std;

int main()
{
    srand(time(NULL));

    //iniotialize sortable vector of 10 doubles
    SortableVector<double> d_vec(10);

    cout << "Populating array..." << endl;
    //(lazily) populate array with doubles
    while (true)
    {
        try
        {
            //generate a random double up to 100
            double num = (double)rand() / 100;
            d_vec.push_back(num);
        }
        catch (MaxCapacityException &e)
        {
            cout << "Array populated:" << endl;
            //report all elements in vector using overloaded []
            for (int i = 0; i < d_vec.getSize(); i++)
            {
                cout << "Index " << i << ": " << d_vec[i] << endl;
            }
            break;
        }
    }

    cout << "Sorting array..." << endl;
    d_vec.insertion_sort();
    cout << "Array sorted:" << endl;
    for (int i = 0; i < d_vec.getSize(); i++)
    {
        cout << "Index " << i << ": " << d_vec[i] << endl;
    }

    cout << "Accessing index -1..." << endl;
    try
    {
        cout << d_vec[-1];
    }
    catch (BoundsException &e)
    {
        cout << e.what() << endl;
    }

    cout << "Accessing index 11..." << endl;
    try
    {
        cout << d_vec[11];
    }
    catch (BoundsException &e)
    {
        cout << e.what() << endl;
    }

    SortableVector<string> s_vec(10);
    //using the most common names in the US 1924 - 2023
    s_vec.push_back("James");
    s_vec.push_back("Mary");
    s_vec.push_back("Michael");
    s_vec.push_back("Patricia");
    s_vec.push_back("Robert");
    s_vec.push_back("Jennifer");
    s_vec.push_back("John");
    s_vec.push_back("Linda");
    s_vec.push_back("David");
    s_vec.push_back("Elizabeth");

    cout << "Sorting array of names..." << endl;
    s_vec.insertion_sort();
    cout << "Sorted array of names:" << endl;
    for (int i = 0; i < s_vec.getSize(); i++)
    {
        cout << "Index " << i << ": " << s_vec[i] << endl;
    }

}