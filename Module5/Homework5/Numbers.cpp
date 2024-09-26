#pragma once
#include "Numbers.h"
#include <iostream>
#include <string>

using namespace std;

const string Numbers::less_than_20[] = {
    "zero", "one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "ten", "eleven", "twelve",
    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
    "eighteen", "nineteen"
};

const string Numbers::tens[] = {
    "ten", "twenty", "thirty", "fourty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
};

const string Numbers::hundred = "hundred";

const string Numbers::thousand = "thousand";

Numbers::Numbers(int number)
{
    this->number = number;
}

void Numbers::print() const
{
    string num_english = "";
    bool complete = false;

    //checking the thousands place
    int temp = number / 1000, num_copy = number;
    if (temp > 0)
    {
        num_english += less_than_20[temp] + " ";
        num_english += thousand + " ";
    }
    //set temp equal to thousands value and subtract from num_copy
    temp *= 1000;
    num_copy -= temp;

    //checking the hundreds place
    temp = num_copy / 100;
    if (temp > 0)
    {
        num_english += less_than_20[temp] + " ";
        num_english += hundred + " ";
    }
    temp *= 100;
    num_copy -= temp;

    //checking the tens place
    temp = num_copy / 10;
    if(temp >= 2)
    {
        num_english += tens[temp - 1] + " ";
    }
    else if (temp > 0)
    {
        num_english += less_than_20[num_copy];
        complete = true;
    }
    temp *= 10;
    num_copy -= temp;
    //if num_copy is zero, you dont add zero to the end of the number
    if (!complete && num_copy != 0)
    {
        num_english += less_than_20[num_copy];
    }

    cout << num_english << endl;
}