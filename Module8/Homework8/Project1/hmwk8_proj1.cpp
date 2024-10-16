 /* hmwkN_projN.cpp - counts number of words in a space delimeted string
 * Author:     Jared Ziv
 * Module:     n
 * Project:    Homework, Part n
 * Problem statement:  Write a function that takes a C-string as an argument
 *      and returns the number of words contained in the C-string. For instance,
 *      if the argument is "Four score and seven years ago", the function should
 *      return the number 6. The program should skip over leading blanks and more
 *      than one adjacent blanks at a time.
 *
 * Algorithm:
 *  numWords():
 *      1. Calculate length of c-string using strlen() from the <cstring> header
 *      2. Define bool to track if there has been a space, and an int for the word
 *         count
 *      3. Iterate thru the string using a for loop starting from 0 going to the len
 *         of the c-string
 *          a. At each index, if the char at the index is a space, set the bool to
 *             true.
 *          b. Otherwise, if it is not a space AND the bool is true, increment the
 *             word counter and set the bool to false
 *      4. Return the word count variable
 *  main():
 *      1. Test the numWords() function using provided instructions.
 */
#include <iostream>
#include <cstring>

using namespace std;

int numWords(const char *str);

int main()
{
    //test c-string with several words
    char words[100] = "lorem ipsum dolor sit amet";
    cout << "The string \"" << words << "\" has:" << endl
         << numWords(words) << " words." << endl << endl;
    
    //test c-string with leading blanks
    char leading_blanks[100] = "          wow there's so many blanks there!";
    cout << "The string \"" << leading_blanks << "\" has:" << endl
         << numWords(leading_blanks) << " words." << endl << endl;

    //test c-string with several adjacent blanks between words
    char interspersed_blanks[100] = "blanks here    blanks    there!      here  too!";
    cout << "The string \"" << interspersed_blanks << "\" has:" << endl
         << numWords(interspersed_blanks) << " words." << endl << endl;

    //test empty c-string
    char empty[100] = "";
    cout << "The string \"" << empty << "\" has:" << endl
         << numWords(empty) << " words." << endl << endl;
    return 0;
}

int numWords(const char *str)
{
    //store a value for length of the string
    int len = strlen(str);
    int word_count = 0;
    //bool to check if previous character was a space
    bool space_logged = true;
    //iterate thru str
    for (int i = 0; i < len; i++)
    {
        //record if a space
        if (str[i] == ' ')
        {
            space_logged = true;
        }
        //otherwise if not a space and a space has been logged
        else if (str[i] != ' ' && space_logged)
        {
            //increment word_count and set space_logged to false
            word_count++;
            space_logged = false;
        }
    }

    return word_count;
}