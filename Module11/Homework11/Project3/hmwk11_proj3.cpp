/* hmwk11_proj2.cpp - Recursively determines if a string is a palindrome
 * Author:     Jared Ziv
 * Module:     11
 * Project:    Homework, Part 3
 * Problem statement: Write a recursive function that returns true if and
 *      only if the part of the string str in positions lower through upper
 *      (inclusive at both ends) is a palindrome.
 *
 * Algorithm:
 *  1. Check if lower is >= string.length() or if upper < 0.
 *     If so, return true (upper and lower made it to respective
 *     ends without returning false)
 *  2. If !isalnum the character at the lower index, call the
 *     function recursively again, but iterate lower up one.
 *  3. If !isalnum the character at the upper index, call
 *     again passing upper - 1
 *  4. Check if (tolower for capitalization ignoring) characters
 *     at upper and lower indices are different. If they are, return
 *     false (not a palindrome)
 *  5. If past all cases, recursively call function with lower + 1
 *     and upper - 1
 */
#include <iostream>

using namespace std;

bool isPalindrome(string str, int lower, int upper);

int main()
{
    //input loop
    while (true)
    {
        cout << "Please enter a string: " << endl;
        string input, output;
        getline(cin, input);

        //check if blank enter
        if (input == "")
        {
            cout << "Exiting program." << endl;
            return 0;
        }
        
        output = (isPalindrome(input, 0, input.length() - 1))
        ? '\"' + input + "\" is a palindrome." : input + " is not a palindrome.";

        cout << output << endl;
    }
    return 0;
}

bool isPalindrome(string str, int lower, int upper)
{
    //base case: lower or upper run off the string
    if (lower >= (int) str.length() || upper < 0) { return true; }
    //ensure lower and upper do not sit on whitespace or punctuation
    else if (!isalnum(str.at(lower))) {
        return isPalindrome(str, lower + 1, upper);
    }
    else if (!isalnum(str.at(upper))) {
        return isPalindrome(str, lower, upper - 1);
    }
    //base case 2: char at lower and upper are different
    else if (tolower(str.at(lower)) != tolower(str.at(upper))) { return false; }
    //recursive case: lower moves down and upper moves up
    else { return isPalindrome(str, lower + 1, upper - 1); }
}