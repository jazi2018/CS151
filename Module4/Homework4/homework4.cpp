/*
homework4.cpp - Utilize an array of unique pointers
Author:     Jared Ziv
Module:     4
Project:    1
Problem Statement: Using an array of unique pointers, sort a Stone struct
        into "slots" of a gem box, recording number of attempts to be
        sorted correctly. Report results based on slot and letter.

Algorithm:
    1. Seed random number generator using system time.
    2. Create array of 10 unique pointers.
    3. Iterate through the array using a character as the iterator (a-j).
        a. Initialize an attempt counter to 1
        b. Using a while loop, continuously generate a random number.
           If the index at the random number is not occupied, create
           a stone struct with the current letter iterator and the
           attempt counter and break. Otherwise, increase the attempt
           counter and repeat.
    4. Report results by iterating through the slots and printing using
       printf(). Include a running total for attempts.
    5. To sort by letter, iterate through all the letters and find the index
       that has that letter, then use a similar printf(). Include a running
       total for attemps.
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <memory>

using namespace std;

struct Stone
{
    char letter;
    int attempts;
    Stone(char l, int a)
    {
        letter = l;
        attempts = a;
    }
};

int main()
{
    srand(time(NULL));

    //create array of 10 unique pointers to stone structs
    unique_ptr<Stone> slots[10];

    //iterate through characters a-j
    for (char letter = 'A'; letter <= 'J'; letter++)
    {
        //at stone letter
        int attempt_ctr = 1;
        while(true)
        {
            int index = rand() % 10;
            if (! slots[index])
            {
                unique_ptr<Stone> new_stone(new Stone(letter, attempt_ctr));
                slots[index] = move(new_stone);
                break;
            }
            else
            {
                attempt_ctr++;
            }
        }
    }

    //report results
    cout << " ** Sorted by slot **" << endl;
    cout << "Slot  Letter  Attempts" << endl;
    cout << "----  ------  --------" << endl;
    int total_attempts = 0;
    for (int i = 0; i < 10; i++)
    {
        total_attempts += slots[i]->attempts;
        printf("%4d %7c %9d\n", i, slots[i]->letter, slots[i]->attempts);
    }
    cout << "Total attempts: " << total_attempts << endl;

    cout << "** Sorted by letter **" << endl;
    cout << "Letter  Slot  Attempts" << endl;
    cout << "------  ----  --------" << endl;
    total_attempts = 0;
    for (char letter = 'A'; letter <= 'J'; letter++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (slots[i]->letter == letter)
            {
                total_attempts += slots[i]->attempts;
                printf("%6c %5d %9d\n", slots[i]->letter, i, slots[i]->attempts);
            }
        }
    }
    cout << "Total attempts: " << total_attempts << endl;

    return 0;
}