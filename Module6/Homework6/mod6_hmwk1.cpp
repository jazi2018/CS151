/* mod6_hmwk1.cpp - demonstrates functionality of DayOfYear class
 * Author: Jared Ziv
 * Module: 6
 * Project: 1
 * Description:
 *      Demonstrates the use of two separate constructors, as well as the overloaded
 *      increment operators as prefixes and postfixes, and the stream insertion operator.
 *      Also demonstrates error checking in the second constructor by terminating the program.
 *  Algorithm:
 *      1. Define a class DayOfYear with necessary functionality.
 *          a. Stream insertion operator
 *              - Parse input by using predefined ELAPSED_DAYS and MONTHS
 *              - Iterate through ELAPSED_DAYS backwards. If object.day > ELAPSED_DAYS
 *                at the given index, print the month at the corresponding index of
 *                MONTHS, as well as object.day - ELAPSED_DAYS (giving the day of the month)
 *          b. String constructor
 *              - Define a function stringToLower() which takes a string and converts it to
 *                lowercase by iterating through it and converting each individual letter to
 *                lowercase.
 *              - First check validity of month (case-insensitive by passing thru stringToLower())
 *              - If valid, store index of month and check validity of day by checking number of
 *                days at DAYS_IN_MONTH[idx]
 *              - If both are valid, store ELAPSED_DAYS[idx] + days in the object
 *              - If either is invalid, print which is invalid and exit(1)
 *          c. Prefix / postfix --/++
 *              - For prefix, increment or decrement value. If it goes below 1 (decrement) or
 *                above 365 (increment), loop it back to the end or start of the year,
 *                respectively. Return *this
 *              - For postfix, logic is the same. However, at the start of the function create
 *                a local object clone = *this. Then, continue to perform operations on this->day.
 *                When the logic is complete, return clone (NOT *this).
 */
#include "DayOfYear.cpp"
#include <iomanip>

int main()
{
    DayOfYear day1(15), day2(31), day3(59), day4(180), day5(360);

    //demonstrating first constructor and stream insertion operator
    cout << "First constructor demonstration" << endl;
    cout << day1 << endl << day2 << endl << day3 << endl
        << day4 << endl << day5 << endl << endl;
    
    //demonstrating second constructor
    DayOfYear day6("January", 1), day7("March", 4), day8("July", 25), day9("December", 31);
    cout << "Second constructor demonstration" << endl;
    cout << setw(15) << left << "January 1" << ": " << day6.getDay() << endl;
    cout << setw(15) << left << "March 4" << ": " << day7.getDay() << endl;
    cout << setw(15) << left << "July 25" << ": " << day8.getDay() << endl;
    cout << setw(15) << left << "December 31" << ": " << day9.getDay() << endl << endl;

    //demonstrating increment operators
    cout << "Increment operator overload demonstration" << endl;

    //Jan 1 prefix --
    cout << "Using January 1 (day 1):" << endl;
    cout << setw(20) << left << "Original value" << ": " <<  day6 << endl;
    cout << setw(20) << left << "Using prefix--" << ": " << --day6 << endl;
    cout << setw(20) << left << "After prefix--" << ": " << day6 << endl << endl;

    //Mar 4 prefix ++
    cout << "Using March 4 (day 63):" << endl;
    cout << setw(20) << left << "Original value" << ": " <<  day7 << endl;
    cout << setw(20) << left << "Using prefix++" << ": " << ++day7 << endl;
    cout << setw(20) << left << "After prefix++" << ": " << day7 << endl << endl;

    //Jul 25 postfix --
    cout << "Using July 25 (day 206):" << endl;
    cout << setw(20) << left << "Original value" << ": " <<  day8 << endl;
    cout << setw(20) << left << "Using postfix--" << ": " << day8-- << endl;
    cout << setw(20) << left << "After postfix--" << ": " << day8 << endl << endl;

    //December 31 postfix ++
    cout << "Using December 31 (day 365):" << endl;
    cout << setw(20) << left << "Original value" << ": " <<  day9 << endl;
    cout << setw(20) << left << "Using postfix++" << ": " << day9++ << endl;
    cout << setw(20) << left << "After postfix++" << ": " << day9 << endl << endl;

    //demonstrating invalid constructor
    cout << "Invalid constructor demonstration" << endl;
    DayOfYear day10("February", 30);
    cout << "The program has not exited!" << endl; // this line should not be printed
    return 0;
}