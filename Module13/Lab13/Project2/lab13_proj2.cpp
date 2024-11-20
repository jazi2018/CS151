/* lab13_proj2.cpp - Demonstrates a template function called acuum
 * Author:     Jared Ziv
 * Module:     13
 * Project:    Lab, Part 2
 * Problem statement: In a separate program, write a template function with
 *      the heading T accum(vector <T> v) which forms and returns the "sum"
 *      of all items in the  vector v  passed to it.
 *
 * Algorithm:
 *   1.  Followed lab instructions
 */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

template<typename T>
    T accum(vector <T> v)
    {
        T accum = T();
        for (T item : v)
        {
            accum += item;
        }

        return accum;
    }

//to make printing vectors easier
template<typename T>
    void print(vector <T> v)
    {
        cout << "[";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i);
            if (i < v.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << ']';
    }

int main()
{
    //integers
    vector<int> iv = {1, 2, 3, 4, 5};
    cout << setw(15) << left << "Int vector " << ": ";
    print(iv);
    cout << endl << setw(15) << left << "Sum of iv " << ": " << accum(iv);
    cout << endl << endl;

    //doubles
    vector<double> dv = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << setw(15) << left << "Double vector " << ": ";
    print(dv);
    cout << endl << setw(15) << left << "Sum of dv " << ": " << accum(dv);
    cout << endl << endl;

    //strings
    vector<string> sv = {"These", " ", "strings", " ", "concatenate!"};
    cout << setw(15) << left << "String vector " << ": ";
    print(sv);
    cout << endl << setw(15) << left << "Sum of sv " << ": " << accum(sv);
    cout << endl << endl;
    return 0;
}