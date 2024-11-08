/* hmwk11_proj1.cpp - Program that iteratively calculates a factorial
 * Author:     Jared Ziv
 * Module:     11
 * Project:    Homework, Part 1
 * Problem statement:  Write a function which is the iterative version of the
 *      factorial function demonstrated in this chapter (using a loop instead of
 *      recursion).
 *
 * Algorithm:
 *  1. Initialize an unsigned long long variable 'total' to the input 'num'
 *  2. Initialize another unsigned long long 'prev' to 'num' (for overflow checking)
 *  3. Check if num is 0. If true, return 1
 *  4. While num > 2
 *      a. Decrement num by 1
 *      b. Multiply total by new value of num
 *      c. Check if total is less than prev. If true, print an overflow error message
 *         and return 0. Otherwise update prev to total
 *  5. After loop ends, return final value of total
 */
#include <iostream>

using namespace std;

unsigned long long factorialI(int num);

int main()
{
    while (true)
    {
        int num;
        cout << "Please enter a number: ";
        cin >> num;
        //bounds checking
        if (num < 0)
        {
            cout << "Exiting program..." << endl;
            break;
        }
        cout << num << "! = " << factorialI(num) << endl;
    }
    return 0;
}

unsigned long long factorialI(int num)
{
    //initialize total var to num
    unsigned long long total = num;
    //initialize prev var to check for overflowing
    unsigned long long prev = num;
    // 0! is 1
    if (num == 0)
    {
        return 1;
    }

    //terminate repition when num is at 2 (dont want to multiply by 0 & dont need to multiply by 1)
    while (num > 2)
    {
        //subtract 1 from num, multiply total by new value
        num -= 1;
        total *= num;
        if (total < prev)
        {
            //overflow has occured
            cout << "Variable overflow in factorialI function. Returning 0..." << endl;
            return 0;
        }
        else { prev = total; }
    }

    return total;
}