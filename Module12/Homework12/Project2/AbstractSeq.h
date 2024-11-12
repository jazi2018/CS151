#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class AbstractSeq
{
    public:
        virtual int fun(int value) = 0;
        void printSeq(int low, int high);
        int sumSeq(int low, int high);
};

void AbstractSeq::printSeq(int low, int high)
{
    cout << "  n       fun(n)" << endl;
    cout << "-----    --------" << endl;
    for (int i = low; i <= high; i++)
    {
        cout << setw(5) << i << setw(12) << fun(i) << endl;
    }
}

int AbstractSeq::sumSeq(int low, int high)
{
    int sum = 0;
    for (int i = low; i <= high; i++)
    {
        sum += fun(i);
    }
    return sum;
}

//odd sequence class
class OddSeq : public AbstractSeq
{
    public:
        //returns odd number in sequence corresponding to passed value
        virtual int fun(int value)
        {
            return 2 * value + 1;
        }
};

//factorial sequence class
class FactorialSeq : public AbstractSeq
{
    public:
        //calculates value in a sequence of factorials
        virtual int fun(int value)
        {
            //the only concern i'd have here is that an int will overflow very quickly
            //with factorials, but i dont think you can override the return type of
            //a virtual function
            int num = 1;
            for (int i = 2; i <= value; i++)
            {
                num *= i;
            }
            return num;
        }
};