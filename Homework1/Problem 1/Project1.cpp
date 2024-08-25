// Homework 1, Project 1: Generates list of 30 ints 1-10
// in descending order, then reports them in ascending order
//
// Jared Ziv
#include <iostream>
#include <vector> //for storing numbers
#include <ctime> //for srand()

using namespace std;

int main()
{
    srand(time(NULL)); //seeds random generator based on time for diff results

    const int NUMS_GENERATED = 30; //number of numbers to generate
    vector<int> numbers; //construct an empty vector of ints
    numbers.reserve(NUMS_GENERATED); //set capacity to NUMS_GENERATED
    vector<int>::iterator it = numbers.begin(); //construct an iterator and place at start of vector

    int num; //variable containing one number at a time
    while (numbers.size() != numbers.capacity()) //LOOP TO INSERT THE NUMBERS
    {
        num = rand() % 10 + 1; //generates number from 1-10
        if (numbers.size() == 0) //if there are no elements to compare values, insert num immediately
        {
            numbers.insert(it, num);
            continue; //dont want to insert twice, so skip the while loop with continue
        }

        while (it != numbers.end())
        {
            if (*it < num) //if value at iterator is lower than generated number
            {
                numbers.insert(it, num); //generated number is inserted at iterator
                break;
            }

            it++; //otherwise, iterator is iterated
        }

        if (it == numbers.end()) //if iterator made it to numbers.end (ending the while loop)
        {
            numbers.push_back(num); //just add the number to the end of the vector
        }

        it = numbers.begin(); //after number is inserted, iterator is returned to start
    } //loops

    while (!numbers.empty())
    {
        cout << numbers.back() << endl; //list number at back
        numbers.pop_back(); //delete number at back
    }

    return 0;
}