/*
hmwk5_proj1.cpp - Accepts input of a number and prints an english representation of it
Author:     Jared Ziv
Module:     5
Project:    1
Problem Statement: Write a program that accepts a user-inputted number (1-9999) and prints
        the number using typical english structuring.

Algorithm:
    1. Define an int variable to accept user input
    2. Start a while loop
        a. Prompt for and accept user input
        b. If the input is the sentinel (0), break from the loop
        c. If the input is negative, restart the loop
        d. If the input is valid and not zero, create a new Number named num
           using the input, and use num.print()

    num.print():
    1. Divide number by 1000 and store in temp to check the thousands place. If it is greater than
       0, take the resultant value and concatenate the value in an array of strings
       contaning numbers to an existing string. If it is not, there is no relevant value
       in the array (the number is less than a thousand) so it continues.
    2. Multiply temp by 1000 and subtract from number to get rid of the thousands place.
    3. Apply the same logic to check the 100s place (divide by 100, check, and then subtract
       the hundreds value from the number)
    4. Repeat this logic until in the 10s place.
        a. In the 10s place, if the number is less than 20, take the exact number and append the
           string with the relevant value from the less_than_20 array. Set a flag to note that
           the process is complete so the ones place isnt checked.
        b. Otherwise continue the logic and check the ones place

*/
#include "Numbers.cpp"

int main()
{
    int input;

    while (true)
    {
        cout << "Enter a number or \"0\" to exit" << endl;
        cin >> input;
        if (input == 0)
        {
            cout << "Exiting" << endl;
            break;
        }
        else if (input < 0)
        {
            cout << "Invalid input" << endl;
            continue;
        }
        else
        {
            Numbers num(input);
            num.print();
        }
    }

    return 0;
}