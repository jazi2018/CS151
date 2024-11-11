#pragma once
#include <iostream>
using namespace std;

class AbstractSort
{
    private:
        int comparisons;
    public:
        //default constructor
        AbstractSort() : comparisons(0) {}

        int getComparisons() { return comparisons; }
        void resetComparisons() { comparisons = 0; }

        int compare(int arr[], int k, int m)
        {
            //returns -1 if k < m, 0 if k = m, 1 if k > m
            comparisons++;
            if ( arr[k] < arr[m] ) { return -1; }
            else { return arr[k] > arr[m]; } // 0 if false, 1 if true
        }

        virtual void sort(int arr[], int size) = 0;
};

//descendant class
class SelectionSort : private AbstractSort
{
    public:
        virtual void sort(int arr[], int size)
        {
            for (int i = 0; i < size; i++)
            {
                //assume min index is current idx
                int min = i;

                //check for actual min index
                for (int j = i + 1; j < size; j++)
                {
                    if (compare(arr, j, min) == -1)
                    {
                        min = j;
                    }
                }

                //swap key and min idx
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }

            cout << "Sort completed with " << getComparisons() << " comparisons." << endl;
            //reset counter
            resetComparisons();
        }
};