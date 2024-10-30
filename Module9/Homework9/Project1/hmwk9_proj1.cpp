/* hmwkN_projN.cpp - Takes a text file input and filters it for proper capitalization.
 * Author:     Jared Ziv
 * Module:     9
 * Project:    Homework, Part 1
 * Problem statement:  Write a program that asks the user for two filenames.
 *      The first file should be opened for input, and the second file should be opened for output.
 *      The program will read the contents of the first file character-by-character and convert every
 *      character to lowercase with the following exceptions:
 *          - The first character of each sentence should be uppercase. This includes the first character
 *            in the input file and any character that follows a period '.'  character.
 *          - The letter 'i' by itself also should be in upper-case.  This means 'i' is preceded and
 *            followed by a white space character.
 *
 * Algorithm:
 *      1. Accept input for input and output filenames using getline.
 *      2. Open files using ifstream for the input file and ofstream for the output file.
 *      3. Init variables for tracking previous char, current char, and if a sentence is needed.
 *      4. Using a while loop with a condition of file_in.get(current_char) (every iteration will get
 *         the next character to manipulate)
 *          a. If new_sentence is true and current char is not a space, output current char to file_out
 *          b. Otherwise if 
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //get file names
    string file1, file2;
    cout << "Enter name of input file: " << endl;
    getline(cin, file1);
    cout << "Enter name of output file: " << endl;
    getline(cin, file2);

    //open files for input and output
    ifstream file_in(file1, ios::in);
    ofstream file_out(file2, ios::out);

    char prev_char, current_char;
    bool new_sentence = true;
    while (file_in.get(current_char))
    {
        //if start of sentence capitalize
        if (new_sentence && !isspace(current_char))
        {
            file_out << current_char;
            new_sentence = false;
        }
        //check if lone i
        else if (current_char == 'I' && isspace(prev_char) && isspace(file_in.peek()))
        {
            file_out << current_char;
        }
        //otherwise lowercase
        else
        {
            //tolower returns an int, and since i'm not storing it into a char
            //before inputting it to the file i just cast it
            file_out << (char) tolower(current_char);
        }

        //check if new sentence
        if (prev_char == '.' && isspace(current_char))
        {
            new_sentence = true;
        }

        prev_char = current_char;
    }
    
    cout << "Success." << endl;

    file_in.close();
    file_out.close();

    return 0;
}