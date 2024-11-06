/* lab11.cpp - Program to convert from decimal to binary
 * Author:     Jared Ziv
 * Module:     11
 * Project:    Lab, Part 1 & 2
 * Problem statement:  Create two functions (one recursive, one iterative) which take a
 *      non-negative whole number (in decimal as specified in your C++ source code) and
 *      convert it to a string of 0’s and 1’s representing the same number in binary (base 2).
 *
 * Algorithm:
 *  Iterative (to bin):
 *      1. Initialize an empty string
 *      2. If 0 is passed, return "0"
 *      3. While num > 0:
 *          a. Set the string variable to (num % 2) + the string variable (prepend)
 *          b. Divide num by 2
 *      4. Return the string variable
 * 
 *  Recursive (to bin):
 *      1. Define string variable binary_num
 *      2. Define base case (num / 2 == 0)
 *          a. Set binary num to to_string(num % 2) and return
 *      3. Otherwise
 *          a. Set binary num to a recursive call of the function passing (num / 2) + to_string(num % 2)
 *          b. Return binary num
 * 
 *  Iterative (to dec):
 *      1. Initialize a sum variable to 0
 *      2. For each character 'c' in the input string 'num':
 *          a. Multiply the current sum by 2 (left shift by 1 bit)
 *          b. Convert the character 'c' to its integer value (0 or 1) by subtracting '0'
 *          c. Add int to sum
 *      3. Return final sum
 * 
 *  Recursive (to dec):
 *      1. Define base case (string has 1 char left)
 *          a. Convert the single character to an integer and return it
 *      2. Otherwise
 *          a. Remove the least significant bit (last character) from the string
 *          b. Make a recursive call with the shortened string
 *          c. Multiply the result of the recursive call by 2
 *          d. Add the value of the least significant bit to the result and return
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string decToBinIter(int num);
string decToBinRecursive(int num);
int binToDecIter(string num);
int binToDecRecursive(string num);

int main()
{
    //decimal to binary
    vector<string> binary_output;
    cout << "       Decimal to Binary" << endl;
    cout << "Number     Iterative     Recursive" << endl;
    cout << "------     ---------     ---------" << endl;
    //test 0
    cout << left << setw(11) << '0' << left << setw(14) << decToBinIter(0) << decToBinRecursive(0) << endl;
    binary_output.push_back(decToBinIter(0));
    //test 5
    cout << left << setw(11) << '5' << left << setw(14) << decToBinIter(5) << decToBinRecursive(5) << endl;
    binary_output.push_back(decToBinIter(5));
    //test 32
    cout << left << setw(11) << "32" << left << setw(14) << decToBinIter(32) << decToBinRecursive(32) << endl;
    binary_output.push_back(decToBinIter(32));
    //test 240
    cout << left << setw(11) << "240" << left << setw(14) << decToBinIter(240) << decToBinRecursive(240) << endl;
    binary_output.push_back(decToBinIter(240));
    //test 682
    cout << left << setw(11) << "682" << left << setw(14) << decToBinIter(682) << decToBinRecursive(682) << endl << endl;
    binary_output.push_back(decToBinIter(682));

    //binary to decimal
    cout << "       Binary to Decimal" << endl;
    cout << "Binary     Iterative     Recursive" << endl;
    cout << "------     ---------     ---------" << endl;
    for (string num : binary_output)
    {
        cout << left << setw(11) << num << left << setw(14) << binToDecIter(num) << binToDecRecursive(num) << endl;
    }
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

int binToDecIter(string num)
{
    int sum = 0;
    for (char c : num)
    {
        sum *= 2;
        int i = c - '0';
        sum += i;
    }

    return sum;
}

int binToDecRecursive(string num)
{
    int sum;
    //base case: string has 1 character
    if (num.size() <= 1)
    {
        sum = num[0] - '0';
        return sum;
    }
    //recursive case
    else
    {
        //remove least significant bit
        string sub = num.substr(0, num.length() - 1);
        //pass substring
        sum = binToDecRecursive(sub);
        sum *= 2;
        //add least significant bit
        sum += num[num.length() - 1] - '0';
        return sum;
    }
}