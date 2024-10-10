/* hmwk7_proj1.cpp - demonstrates functionality of PString class
 * Author: Jared Ziv
 * Module: 7
 * Project: 2
 * Description:
 *      Utilizes the PString class (inherits from string) to create a few
 *      objects and check if they are palendromes.
 *  Algorithm:
 *      1. The main file uses the string object constructor to create objects
 *         of varying PStrings.
 *      2. When isPalendrome() is called:
 *          a. Create two iterators: One forward, one reverse.
 *          b. Place iterators at begin and rbegin, respectively.
 *          c. Loop while both iterators are NOT at end or rend, respectively:
 *          d. Using a nested while loop (while *iterator is equal to a character
 *             not included in the palendrome i.e. ' ' ',' '.' etc.), iterate
 *             the iterator forward until it is no longer equal to a non-included
 *             character. Do this for both iterators.
 *          e. After the nested loops, check if the dereferenced iterators are
 *             equal to eachother.
 *              - If they are, iterate both iterators forward one
 *              - Otherwise, its not a palendrome (return false)
 *          f. Loop back to c
 */
#include <iostream>
#include <iomanip>
#include "PString.h"

using namespace std;

int main()
{
    //using a string object to pass into PString here just to suppress compiler warning
    //"warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]"
    //program still compiled and ran, just outputted warning for every PString object
    string test_string = "Chic";
    PString *chic = new PString(test_string);
    cout << setw(20) << left << "Test string"<< ": " << *chic << endl;
    cout << setw(20) << "isPalendrome()"<< ": " << (chic->isPalindrome() ? "True" : "False") << endl << endl;

    test_string = "Book";
    PString *book = new PString(test_string);
    cout << setw(20) << "Test string"<< ": " << *book << endl;
    cout << setw(20) << "isPalendrome()"<< ": " << (book->isPalindrome() ? "True" : "False") << endl << endl;

    test_string = "Kayak";
    PString *kayak = new PString(test_string);
    cout << setw(20) << "Test string"<< ": " << *kayak << endl;
    cout << setw(20) << "isPalendrome()"<< ": " << (kayak->isPalindrome() ? "True" : "False") << endl << endl;

    test_string = "1x2x3x4x5";
    PString *numbers = new PString(test_string);
    cout << setw(20) << "Test string"<< ": " << *numbers << endl;
    cout << setw(20) << "isPalendrome()"<< ": " << (numbers->isPalindrome() ? "True" : "False") << endl << endl;

    test_string = "25  ABC 9cba52";
    PString *gibberish = new PString(test_string);
    cout << setw(20) << "Test string"<< ": " << *gibberish << endl;
    cout << setw(20) << "isPalendrome()"<< ": " << (gibberish->isPalindrome() ? "True" : "False") << endl << endl;

    test_string = "No lemons, no melon";
    PString *lemons = new PString(test_string);
    cout << setw(20) << "Test string"<< ": " << *lemons << endl;
    cout << setw(20) << "isPalendrome()"<< ": " << (lemons->isPalindrome() ? "True" : "False") << endl << endl;

    test_string = "Not even close!";
    PString *close = new PString(test_string);
    cout << setw(20) << "Test string"<< ": " << *close << endl;
    cout << setw(20) << "isPalendrome()"<< ": " << (close->isPalindrome() ? "True" : "False") << endl << endl;

    test_string = "A man, a plan, a canal -- Panama";
    PString *panama = new PString(test_string);
    cout << setw(20) << "Test string"<< ": " << *panama << endl;
    cout << setw(20) << "isPalendrome()"<< ": " << (panama->isPalindrome() ? "True" : "False") << endl << endl;
    return 0;
}