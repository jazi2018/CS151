/* hmwkN_projN.cpp - Demonstration of oddseq and factorialseq classes
 * Author:     Jared Ziv
 * Module:     12
 * Project:    Homework, Part 12
 * Problem statement: Write an abstract class AbstractSeq that has a
 *      pure virtual member function virtual int fun(int value) = 0 ;
 *      as a stand-in for an actual sequence. Demonstrate your AbstractSeq
 *      class by creating two child classes that you use to define two fun
 *      functions of two different sequences
 *
 * Algorithm:
 *  Algorithm for AbstractSeq class:
 *      1. Define a pure virtual function fun that takes an int parameter and returns an int.
 *      2. Define a public function printSeq that takes two int parameters (low and high):
 *           a. Print header for the sequence.
 *           b. For each value i from low to high:
 *              - Print i and the result of fun(i) with appropriate formatting.
 *      3. Define a public function sumSeq that takes two int parameters (low and high):
 *           a. Initialize sum to 0.
 *           b. For each value i from low to high:
 *              - Add the result of fun(i) to sum.
 *           c. Return the final sum.
 *   Algorithm for OddSeq class (derived from AbstractSeq):
 *      1. Implement the fun function:
 *          a. Return 2 * value + 1.
 *   Algorithm for FactorialSeq class (derived from AbstractSeq):
 *      2. Implement the fun function:
 *           a. Initialize num to 1.
 *           b. For each i from 2 to value:
 *              - Multiply num by i.
 *           c. Return the final value of num.
 */
#include "AbstractSeq.h"

using namespace std;

int main()
{
    //srand
    srand(time(NULL));

    //create objects
    OddSeq odd;
    FactorialSeq fac;

    //odd output
    odd.printSeq(3, 12);
    cout << "Total sum for odds: " << odd.sumSeq(3, 12) << endl;

    //fac output
    fac.printSeq(1, 10);
    cout << "Total sum for factorial: " << fac.sumSeq(1, 10) << endl;
}