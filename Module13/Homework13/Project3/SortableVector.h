#pragma once
#include <string>
#include "../Project2/SimpleVector.h"
using namespace std;

//taken from homework 13 project 1
struct BoundsException : public exception
{
    string message;
    BoundsException(int idx)
    {
        message = "Index " + to_string(idx) + " out of bounds";
    }
    virtual const char * what() const noexcept
    {
        return message.c_str();
    }
};

template <typename T>
class SortableVector : public SimpleVector<T>
{
    public:
        SortableVector(int capacity) : SimpleVector<T>(capacity) {}
        void insertion_sort()
        {
            for (int i = 1; i < this->size; i++)
            {
                T key = this->aptr[i];
                int j = i - 1;

                while (j >= 0 && this->aptr[j] > key)
                {
                    this->aptr[j + 1] = this->aptr[j];
                    j--;
                }
                this->aptr[j + 1] = key;
            }
        }
        T operator[](int k)
        {
            if (k < 0 || k >= this->size)
            {
                throw BoundsException(k);
            }
            
            return this->aptr[k];
        }
};