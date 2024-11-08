/* hmwk11_proj2.cpp - Searches for values in user defined array
 * Author:     Jared Ziv
 * Module:     11
 * Project:    Homework, Part 2
 * Problem statement:  Write a recursive Boolean function named isMember.
 *      The function should accept three parameters: an array of integers,
 *      the size of the array, and an value to be searched for in the array.
 *      The function should return true if the value is found in the array
 *      or false if the value is not found.
 *
 * Algorithm:
 *  1. Check if arr_size is 0, return false if true
 *  2. Check if value at current index is val, return true if true
 *  3. Otherwise return isMember with:
 *      a. arr + 1 (move to next element in array)
 *      b. arr_size - 1 (decrease array size by 1, ensuring proper bounds)
 *      c. val
 */
#include <iostream>

using namespace std;

bool isMember(int arr[], const int arr_size, int val);

int main()
{
    int ARR_SIZE;
    string arr_str = "[ ";
    //allocate array
    cout << "Enter size of array: ";
    cin >> ARR_SIZE;
    int * arr = new int[ARR_SIZE];
    //populate array
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << "Enter an int: ";
        cin >> arr[i];

        //dumb formatting stuff for my brain to be calm
        string comma;
        comma = (i == ARR_SIZE - 1) ? " " : ", ";
        arr_str += to_string(arr[i]) + comma;
    }
    arr_str += "]";
    cout << "The inputted array is " << arr_str << endl;
    int search_count;
    cout << "How many searches would you like to make?" << endl;
    cin >> search_count;
    while (search_count > 0)
    {
        int val;
        cout << "Enter an int to search for: ";
        cin >> val;
        //search for value
        if (isMember(arr, ARR_SIZE, val))
        {
            cout << val << " is in the array." << endl;
        }
        else
        {
            cout << val << " is not in the array." << endl;
        }
        search_count--;
    }
    
    return 0;
}

bool isMember(int arr[], int arr_size, int val)
{
    //base case 1: ran off end of array
    if (arr_size == 0)
    {
        return false;
    }
    //base case 2: value at current index is equivalent to val
    else if (* arr == val)
    {
        return true;
    }
    //recursive step: move up one index in array
    else
    {
        return isMember(arr + 1, arr_size - 1, val);
    }
}