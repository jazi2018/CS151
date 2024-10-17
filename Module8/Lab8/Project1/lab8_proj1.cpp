/* lab8_proj1.cpp - uses various lambda functions to "encrypt" a string
 * Author:     Jared Ziv
 * Module:     8
 * Project:    Lab, Part 1
 * Problem statement:  Define a function "encrypt()" which takes the reference
 *      to a character and increases its value by one. Implement it using the
 *      for_each() function from the algorithm header and pass a lambda function
 *      to it.
 *
 * Algorithm:
 *   1.  Followed lab instructions
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


void encrypt(char &character);

int main()
{
    while (true)
    {
        cout << "Enter a string to encode: " << endl;
        //define string to store input
        string input;
        getline(cin, input);

        //create string copy to check if user inputted quit
        string quit_test = input;
        //convert to lowercase using lambda function
        for_each(quit_test.begin(), quit_test.end(),
                    [](char &c) { c = tolower(c); });
        if (quit_test == "quit")
        {
            break;
        }

        string encrypted = input;
        //encrypt provided string
        for_each(encrypted.begin(), encrypted.end(),
                 [](char & c) { encrypt(c); });
        
        cout << setw(15) << left << "Original string: " << input << endl;
        cout << setw(15) << left << "Once encrypted: " << encrypted << endl;
        //encrypt once more
        for_each(encrypted.begin(), encrypted.end(),
                 [](char & c) { encrypt(c); });
        cout << setw(15) << left << "Twice encrypted: " << encrypted << endl;

        //for readability
        cout << endl;
    }
    
    return 0;
}

void encrypt(char &character)
{
    //The following code is reused from my own EncryptableString.h

    //checks if character is between 'a' and 'z' (z not inclusive)
    if (character < 122 && character >= 97)
    {
        //increment character
        character++;
    }
    //checks if character is 'z'
    else if (character == 122)
    {
        //wraps around to 'a'
        character = 97;
    }
    //checks if character is between 'A' and 'Z' (Z not inclusive)
    else if (character < 90 && character >= 65)
    {
        character++;
    }
    //checks if character is 'Z'
    else if (character == 90)
    {
        //wraps around to 'A'
        character = 65;
    }
    //checks if character is between '0' and '9' (9 not inclusive)
    else if (character < 57 && character >= 48)
    {
        character++;
    }
    //checks if character is '9'
    else if (character == 57)
    {
        //wraps around to '0'
        character = 48;
    }
}