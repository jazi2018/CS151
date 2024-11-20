/* lab13_proj1.cpp - Reports perfect squares from 0 to 25
 * Author:     Jared Ziv
 * Module:     13
 * Project:    Lab, Part 1
 * Problem statement: Write a function which accepts an integer parameter and
 *      returns its integer square root (if one exists). The function should
 *      throw an exception if it is passed an number that is not a perfect square.
 *
 * Algorithm:
 *   1. Create a new exception type called ImperfectSquareException, which inherits
 *      from exception. what() should be overwritten to output a string explaining
 *      the exception.
 *   2. In the perfectRoot function, take the root of the number using sqrt() and
 *      cast to an int.
 *   3. Check if the calculated root times itself is equal to the passed number.
 *      If it isnt, throw ImperfectSquareException()
 *      If it is, return the calculated root
 *   4. Include an error handler in main and report which values between 0 and 25
 *      are perfect squares.
 */
#include <iostream>
#include <iomanip>
#include <cmath> //for sqrt
#include <exception>
using namespace std;

struct ImperfectSquareException : public exception
{
    virtual const char * what() const noexcept
    {
        return "Not a perfect square.";
    }
};

int perfectRoot(int num);

int main()
{
    //test numbers 0 through 25
    for (int i = 0; i <= 25; i++)
    {
        try
        {
            int root = perfectRoot(i);
            //if no exception is thrown, this line of code will execute
            cout << left << setw(3) << i << ": Perfect square with a root of " << root << '.' << endl;
        }
        catch (ImperfectSquareException &e)
        {
            //otherwise the exception is printed
            cout << left << setw(3) << i << ": " << e.what() << endl;
        }
    }
    return 0;
}

int perfectRoot(int num)
{
    //calculate the root
    int root = (int)sqrt(num);

    //check if root squared is equal to num after truncation from int cast
    if (root * root != num)
    {
        throw ImperfectSquareException();
    }

    //if no exception, return root
    return root;
}