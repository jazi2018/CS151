/*
project3.cpp : accepts user input and presents the most common inputted number
Name: Jared Ziv
Module: 3
Project: 3
Problem statement: Create a program using a dynamically-allocated integer array
    that accepts user input regarding number of pies eaten and find the mode in
    the distribution.
Algorithm:
    1. Allocate an int array of size 15 from the heap
    2. Iterate through the array indeces, storing user input at each index. If
       the number inputted is less than 0, don't store it and prompt for input
       again
    3. After the loop (when the array is full), sort the array using insertion
       sort
       Insertion Sort:
            a. Starting at index 1, iterate through array, checking if previous
               index contains a lower value. If it does, swap the two indeces.
            b. Now the two indeces are "sorted". Move to the next index and
               check a again. If it is lower, decrement the index being checked
               and check a again.
            c. Repeat until the array is sorted.
    4. Iterate through the array with a counter. If the current index and the
       next index are the same value, increment the counter. If the counter
       is higher than a max_count variable, store the current counter value
       into it and store the current index into a variable representing the
       mode.
    5. Repeat 4 until the entire array has been checked.
*/

#include <iostream>

using namespace std;

void insertionSort(int arr[], int size);
int findMode(int arr[], int size);

int main()
{
    //dynamically allocate array of arr_size
    int arr_size = 15;
    int *pie_array = new int[arr_size];

    //accept user input
    for (int i = 0; i < arr_size; i++)
    {
        int input = 0;
        cout << "Please enter the number of pies you eat in a year:" << endl;
        cin >> input;
        //input validation
        if (input < 0)
        {
            cout << "Please enter a non-negative number." << endl;
            i--;
            continue;
        }

        pie_array[i] = input;
    }

    //sort array
    insertionSort(pie_array, arr_size);

    //find mode
    int mode = findMode(pie_array, arr_size);
    if (mode == -1)
    {
        //print that all values appear once
    }

    return 0;
}

void insertionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = i;
        while (j > 0 && arr[j] > arr[j-1])
        {
            //swap values
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            //check "a" again
            j--;
        }
    }
}

int findMode(int arr[], int size)
{
    int mode = -1, count = 1, max_count = 1;

    for (int i = 0; i < size; i++)
    {
        //check if count will be iterated, otherwise set to 1
        if (arr[i] == arr[i + 1])
        {
            count++;
            if (count > max_count)
            {
                max_count = count;
                mode = arr[i];
            }
        }
        else
        {
            count = 1;
        }
    }

    return mode;
}