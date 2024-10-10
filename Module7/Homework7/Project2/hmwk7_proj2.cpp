/* hmwk7_proj2.cpp - demonstrates functionality of EncryptableString class
 * Author: Jared Ziv
 * Module: 7
 * Project: 2
 * Description:
 *      Utilizes the EncryptableString class (inherits from string) by
 *      creating various objects using different strings and running their
 *      encrypt function twice, printing the result both times.
 *  Algorithm:
 *      1. The main file uses the string object constructor to create objects
 *         of varying EncryptableStrings.
 *      2. After printing the EncryptableString, encrypt() is called.
 *          a. When encrypt() is called, iterate through the string using
 *             a for loop until string size - 1.
 *          b. At each iteration, check if the character at the index is between
 *             ASCII values for 'a' and 'z', 'A' and 'Z', or '0' and '9' (second
 *             values not inclusive)
 *              - If true, iterate the character by 1 (char++)
 *          c. At each iteration, also check if the character IS 'z', 'Z', or '9'
 *              - If true, instead of iterating the character, loop the character
 *                back to its respective starting value (i.e. 'a', 'A', or '0')        
 */
#include <iostream>
#include <iomanip>
#include "EncryptableString.h"

using namespace std;

int main()
{
    string test_string = "Holy Moly!";
    EncryptableString *holy = new EncryptableString(test_string);
    cout << setw(20) << left << "Test string"<< ": " << *holy << endl;
    holy->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *holy << endl;
    holy->encrypt();
    cout << setw(20) << left << "encrypt() twice"<< ": " << *holy << endl << endl;

    test_string = "San Diego Zoo.";
    EncryptableString *zoo = new EncryptableString(test_string);
    cout << setw(20) << left << "Test string"<< ": " << *zoo << endl;
    zoo->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *zoo << endl;
    zoo->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *zoo << endl << endl;

    test_string = "The cost is $25.89.";
    EncryptableString *cost = new EncryptableString(test_string);
    cout << setw(20) << left << "Test string"<< ": " << *cost << endl;
    cost->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *cost << endl;
    cost->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *cost << endl << endl;

    test_string = "Go away – unless you have tacos.";
    EncryptableString *tacos = new EncryptableString(test_string);
    cout << setw(20) << left << "Test string"<< ": " << *tacos << endl;
    tacos->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *tacos << endl;
    tacos->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *tacos << endl << endl;

    test_string = "No one can make you feel inferior without your consent.";
    EncryptableString *consent = new EncryptableString(test_string);
    cout << setw(20) << left << "Test string"<< ": " << *consent << endl;
    consent->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *consent << endl;
    consent->encrypt();
    cout << setw(20) << left << "encrypt() once"<< ": " << *consent << endl << endl;
    return 0;
}