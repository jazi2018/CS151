/* hmwk13_proj2.cpp - Demonstrates SimpleVector class template
 * Author:     Jared Ziv
 * Module:     13
 * Project:    Homework, Part 2
 * Problem statement: Modify this SimpleVector class template to include
 *      the member functions  push_back  and  pop_back.
 *
 * Algorithm:
 *   1. Followed the instructions provided in the section describing
 *      the functions to be created.
 */
#include "SimpleVector.h"
#include <iomanip>
using namespace std;

int main()
{
    cout << "Populating vector:" << endl;
    SimpleVector<int> s_vec = SimpleVector<int>(5);
    for (int i = 0; i < 6; i++)
    {
        try 
        {
            cout << "Adding " << i << " to the vector" << endl;
            s_vec.push_back(i);
        }
        catch (MaxCapacityException &e)
        {
            cout << "Exception occured: " << e.what() << endl;
        }
    }

    cout << "Depopulating vector:" << endl;
    while (true)
    {
        try
        {
            int item = s_vec.pop_back();
            cout << "Removed " << item << " from the vector" << endl;
        }
        catch (EmptyVectorException &e)
        {
            cout << "Exception occured: " << e.what() << endl;
            break;
        }
    }

    return 0;
}