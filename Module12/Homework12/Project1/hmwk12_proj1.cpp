/* hmwk12_proj1.cpp - Utilizes abstract sort class to sort random arrays.
 * Author:     Jared Ziv
 * Module:     12
 * Project:    Homework, Part 1
 * Problem statement: Design a class named AbstractSort that can be used
 *      to analyze the number of comparisons performed by a sorting algorithm.
 *      Create a subclass of AbstractSort that uses a simple sorting
 *      algorithm to implement the sort function.
 *
 * Algorithm:
 *  Selection sort:
 *      1. For each index in an array:
 *          a. Assign current index to min variable
 *          b. Check every index after current index. If a new minimum is found
 *             assign that index to the min variable
 *          c. Swap the current index and the min index
 *      2. Print comparisons and reset them to zero for the next sort
 */
#include <iostream>
#include <random>   //to populate the arrays
#include <ctime>    //to srand
#include "AbstractSort.h"

using namespace std;

string displayArray(int arr[], int size);

int main()
{
    srand(time(NULL));

    //define const size arr1
    const int ARR_SIZE = 20;
    int arr1[ARR_SIZE];
    //populate arr1
    for(int i = 0; i < ARR_SIZE; i++)
    {
        //filled with numbers 1-100
        arr1[i] = rand() % 100 + 1;
    }

    //define random size arr2 21 - 100
    int arr2_size = rand() % 80 + 21;
    int * arr2 = new int[arr2_size];
    //populate arr2
    for(int i = 0; i < arr2_size; i++)
    {
        //filled with numbers 1-100
        arr2[i] = rand() % 100 + 1;
    }

    //make sort object
    SelectionSort sorter;
    //display array 1
    cout << "Array 1 (fixed size of 20):\n" << displayArray(arr1, ARR_SIZE) << endl;
    //sort and display again
    cout << "Sorting array 1..." << endl;
    sorter.sort(arr1, ARR_SIZE);
    cout << "Array 1 post sort:\n" << displayArray(arr1, ARR_SIZE) << endl << endl;

    //display array 2
    cout << "Array 2 (random size of " << arr2_size << "):\n" << displayArray(arr2, arr2_size) << endl;
    //sort and display again
    cout << "Sorting array 2..." << endl;
    sorter.sort(arr2, arr2_size);
    cout << "Array 2 post sort:\n" << displayArray(arr2, arr2_size) << endl << endl;
    return 0;
}

string displayArray(int arr[], int size)
{
    string out = "[ ";
    for(int i = 0; i < size; i++)
    {
        out += (i != size - 1) ? to_string(arr[i]) + ", " : to_string(arr[i]) + " ";
    }
    out += "]";
    return out;
}