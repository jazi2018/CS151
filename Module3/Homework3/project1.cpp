/*project1.cpp contains code for project 1 of homework 3, involves dynamic heap
    memory allocation with arrays
Author: Jared Ziv
Module 3, Homework 3

Problem Statement: Dynamically allocate an array of user defined size, storing
    name and score of students. Sort array in ascending order, calculate and 
    report average score.

Algorithm:
    1. Prompt for user input and store in size variable
    2. Allocate an array from the heap based on user input
    3. Loop through the indeces of the array (starting at 0), prompting the
       user for name and score input at each index. Verify that the input
       is valid. Store the input.
    4. After storing the input, add the value of the input to a total_score
       variable.
    5. After filling the array, sort the array using insertion sort
    6. Calculate average score by dividing total_score by size
    7. Report array with names and scores, as well as average score
*/
#include <iostream>
#include <iomanip>

using namespace std;

void insertionSort(int arr[], int size);

int main()
{
    //prompt for user input and store in size variable
    int size = 0, total_score = 0;
    cout << "Please enter number of test scores." << endl;
    cin >> size;

    //allocate an array from the heap based on user input
    int *score_array = new int[size];

    //loop through the indeces of the array
    for (int i = 0; i < size; i++)
    {
        //prompt user for score and name input
        int input = 0;
        cout << "Please enter score " << i + 1 << ":" << endl;
        cin >> input;
        //validate user input
        if (input < 0)
        {
            cout << "Test score cannot be negative." << endl;
            //restart current iteration
            i--;
            continue;
        }
        //store input in score_array
        *(score_array + i) = input;
        total_score += input;
    }

    //sort array
    insertionSort(score_array, size);

    //calculate average score
    float avg_score = (float)total_score / size;

    //report array
    for(int i = 0; i < size; i++)
    {
        cout << *(score_array + i) << endl;
    }
    cout << "avg: " << avg_score << endl;

    delete [] score_array;

    return 0;
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && *(arr + j) < *(arr + j - 1))
        {
            int temp = *(arr + j);
            *(arr + j) = *(arr + j - 1);
            *(arr + j - 1) = temp;
            j--;
        }
    }
}