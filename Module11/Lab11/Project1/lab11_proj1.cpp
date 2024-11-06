/* lab11_proj1.cpp - Program to convert from decimal to binary
 * Author:     Jared Ziv
 * Module:     11
 * Project:    Lab, Part 1
 * Problem statement:  Create two functions (one recursive, one iterative) which take a
 *      non-negative whole number (in decimal as specified in your C++ source code) and
 *      convert it to a string of 0’s and 1’s representing the same number in binary (base 2).
 *
 * Algorithm:
 *  Iterative:
 *      1. Initialize an empty string
 *      2. If 0 is passed, return "0"
 *      3. While num > 0:
 *          a. Set the string variable to (num % 2) + the string variable (prepend)
 *          b. Divide num by 2
 *      4. Return the string variable
 * 
 *  Recursive:
 *      1. Define string variable binary_num
 *      2. Define base case (num / 2 == 0)
 *          a. Set binary num to to_string(num % 2) and return
 *      3. Otherwise
 *          a. Set binary num to a recursive call of the function passing (num / 2) + to_string(num % 2)
 *          b. Return binary num
 */
#include <iostream>
#include <iomanip>

using namespace std;

string decToBinIter(int num);
string decToBinRecursive(int num);

int main()
{
    cout << "Number     Iterative     Recursive" << endl;
    cout << "------     ---------     ---------" << endl;
    //test 0
    cout << left << setw(11) << '0' << left << setw(14) << decToBinIter(0) << decToBinRecursive(0) << endl;
    //test 5
    cout << left << setw(11) << '5' << left << setw(14) << decToBinIter(5) << decToBinRecursive(5) << endl;
    //test 32
    cout << left << setw(11) << "32" << left << setw(14) << decToBinIter(32) << decToBinRecursive(32) << endl;
    //test 240
    cout << left << setw(11) << "240" << left << setw(14) << decToBinIter(240) << decToBinRecursive(240) << endl;
    //test 682
    cout << left << setw(11) << "682" << left << setw(14) << decToBinIter(682) << decToBinRecursive(682) << endl;
    return 0;
}

string decToBinIter(int num)
{
    string binary_num = "";
    //if zero is passed
    if (num == 0)
    {
        return to_string(num);
    }

    while (num > 0)
    {
        string temp = to_string(num % 2);
        binary_num = temp + binary_num;
        num /= 2;
    }
    return binary_num;
}

string decToBinRecursive(int num)
{
    string binary_num;
    //base case: num / 2 = 0
    if (num / 2 <= 0)
    {
        binary_num = to_string(num % 2);
        return binary_num;
    }
    //if not at base case
    else
    {
        binary_num = decToBinRecursive(num / 2) + to_string(num % 2);
        return binary_num;
    }
}
