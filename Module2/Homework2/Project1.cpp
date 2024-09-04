// Decimal-to-Binary Converter: Converts decimal to binary
// Jared Ziv
// Module 2
// Project 1
// Create a program that will convert decimal numbers (int) to binary numbers
// and report the result as a string
// Algorithm: (NOTE: This is the algorithm provided on the assignment page with slight modifications)
// Ask the user to enter a decimal number and store in an  int  variable (sentinel is -1)
// Create an empty string to hold binary number.
// Using a loop:
// Determine the remainder (modulo) and convert to a string and add to front of exisiting string.
// Divide num by 2.
// Loop until num is 0.
// When the loop is finished, print the resulting string
// Go back to step 1 and prompt for the next number to convert

#include <iostream>
#include <string>

using namespace std;

string convertNumber(int num);

int main()
{
    int decimal_number = 0;
    string test = "";
    while (decimal_number != -1)
    {
        cout << "Please input a base 10 number to convert to binary, or -1 to stop:" << endl;
        cin >> decimal_number;
        if (decimal_number == -1)
        {
            break;
        }
        
        cout << decimal_number << " in binary is: " << convertNumber(decimal_number) << endl;
    }

    cout << "Exiting." << endl;

    return 0;
}

string convertNumber(int num)
{
    string binary_number = "";

    if (num == 0)
    {
        return "0";
    }
    
    while (num != 0)
    {
        binary_number = to_string(num % 2) + binary_number;
        num /= 2;
    }

    return binary_number;
}