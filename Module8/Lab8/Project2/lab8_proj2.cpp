/* lab8_proj2.cpp - demonstrates string conversions with <sstream> header and c-strings
 * Author:     Jared Ziv
 * Module:     8
 * Project:    Lab, Part 2
 * Problem statement:  Use C-String and C++ string cuntions to follow a number through
 *      several conversions from/to strings, binary strings, hex strings and back to
 *      numbers, many using the frunctionality of stringstreams.
 *
 * Algorithm:
 *   1.  Followed lab instructions
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    //loop for output
    while(true)
    {
        cout << setw(50) << left << "Please enter a positive integer: ";
        int original = 0;
        cin >> original;
        //exits while loop
        if (original < 0)
        {
            break;
        }

        //convert to a string
        string original_as_string = to_string(original) + " rah!";
        cout << setw(50) << left << "Original as string: " << original_as_string << endl;

        //convert back to int using istringstream
        istringstream inpstr(original_as_string);
        int original_copy;
        inpstr >> original_copy;
        cout << setw(50) << left << "Converted back to a number: " << original_copy << endl;

        //convert to binary in c-string
        char *binary = new char[33];
        *(binary + 32) = '\0'; //null terminator at end
        int index = 32; //starting at last index
        do
        {
            //move back one index, set equal to val of original string %2 (converting to binary)
            *(binary + (--index)) = (char) (original_copy % 2 + '0');
            //update original copy to check next binary character
            original_copy /= 2;
        } while (original_copy > 0); //once original copy is 0 its fully converted
        //report number starting at last filled index
        cout << setw(50) << left << "That number in binary is: " << (binary + index) << endl;

        //convert binary string to original number
        original_copy = stoi((binary + index), nullptr, 2);
        cout << setw(50) << left << "Binary converted back to int: " << original_copy << endl;

        //convert number to hexadecimal
        stringstream iostr;
        iostr << hex << original;
        cout << setw(50) << left << "Inputted number converted to hexadecimal: " << iostr.str() << endl;

        //convert hexidecimal back to decimal
        iostr >> hex >> original_copy;
        cout << setw(50) << left << "Back to decimal: " << original_copy << endl;

        cout << endl;
    }
    
    return 0;
}