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

using namespace std;

bool checkPass(string str);

int main()
{

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
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            has_upper = true;
        }
        else if (str[i] >= 97 && str[i] <= 122)
        {
            has_lower = true;
        }
        else if (isdigit(str[0]))
        {
            has_digit = true;
        }
        else if (str[0] == ' ')
        {
            has_blanks = true;
        }
    }

    //report appropriate errors
    if (!has_upper || !has_lower)
    {
        cout << "Password must contain at least one uppercase and lowercase letter." << endl;
        valid_pass = false;
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