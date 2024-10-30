/* lab9_proj1.cpp - Create a binary file consisting of 10 ints (1 - 10) and 10 doubles (square roots)
 * Author:     Jared Ziv
 * Module:     9
 * Project:    Lab, Part 1
 * Problem statement:  Create a binary file consisting of 10 ints (1 - 10) and 10 doubles (square roots).
 *      The file will be a binary file containing the 10 numbers (from 1 to 10) each as an  int, followed
 *      by the square roots of those numbers each as a double.
 *
 * Algorithm:
 *   1.  Followed lab instructions
 */
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    const string file_name = "array.dat";
    ofstream data_file(file_name, ios::binary | ios::out);
    if (!data_file)
    {
        cout << file_name << " not created or found. Exiting." << endl;
        exit(1);
    }

    for (int i = 1; i <= 10; i++)
    {
        data_file.write(reinterpret_cast <char *> (&i), sizeof(int));
    }
    for (double i = 1; i <= 10; i++)
    {
        double root = sqrt(i);
        data_file.write(reinterpret_cast <char *> (&root), sizeof(double));
    }

    data_file.close();
    return 0;
}