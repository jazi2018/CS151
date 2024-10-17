 /* hmwkN_projN.cpp - <simple description>
 * Author:     Jared Ziv
 * Module:     n
 * Project:    Homework, Part n
 * Problem statement:  <problem statement>
 *
 * Algorithm:
 *   1.  <detailed algorithm>
 */
#include <iostream>
#include <string>

using namespace std;

bool checkPass(string str);

int main()
{
    /*
     * I am confused about the order of operations for the main function
     * In the problem statement, it says it should "return" a list of the
     * errors and also return true or false. I assumed that meant print
     * the list of errors. But after, it says that upon return from the
     * function, it should say if it was accepted or rejected, and if
     * it was rejected, a list of reasons why. I interpreted that as an
     * ordered sequence, where it would print "Password rejected" and
     * THEN the list. I could think of a few ways to implement it (like
     * maybe using a class?) but the specifications were pretty clear about
     * passing strings and returning true or false so I went the path of
     * least resistance :) If there's any issues with my implementation
     * just let me know and I will fix it.
     */

    bool valid_pass = false;
    while (!valid_pass)
    {
        cout << "Enter a password:" << endl;
        string password;
        cin >> password; //cin is space delimited so there shouldnt be spaces anyways

        valid_pass = checkPass(password);

        if (valid_pass)
        {
            cout << "The password entered is valid." << endl;
        }
        else
        {
            cout << "The password entered is invalid." << endl;
        }
    }

    return 0;
}

bool checkPass(string str)
{
    bool valid_pass = true;

    //check characters
    if (str.length() < 6)
    {
        cout << "Password must be at least 6 characters." << endl;
        valid_pass = false;
    }

    //check for upper, lower, digit and blank characters
    bool has_upper = false, has_lower = false, has_blanks = false, has_digit = false;
    for (char c : str)
    {
        if (isupper(c))
        {
            has_upper = true;
        }
        else if (islower(c))
        {
            has_lower = true;
        }
        else if (isdigit(c))
        {
            has_digit = true;
        }
        else if (isspace(c))
        {
            has_blanks = true;
        }
    }

    //report appropriate errors
    if (!has_upper)
    {
        cout << "Password must contain at least one uppercase letter." << endl;
        valid_pass = false;
    }

    if (!has_lower)
    {
        cout << "Password must contain at least one lowercase letter." << endl;
    }

    if(!has_digit)
    {
        cout << "Password must contain at least one digit" << endl;
        valid_pass = false;
    }

    if(has_blanks)
    {
        cout << "Password cannot contain spaces." << endl;
        valid_pass = false;
    }

    return valid_pass;
}