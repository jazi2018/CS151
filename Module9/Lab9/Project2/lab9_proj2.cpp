/* lab9_proj1.cpp - Multiply every number in the file by a fixed amount.
 * Author:     Jared Ziv
 * Module:     9
 * Project:    Lab, Part 2
 * Problem statement:  Create a menu that accepts user input and allows a multiplier to be assigned
 *      to each value in the previously created array.dat. Multiply each integer by that multiplier.
 *      do the same for the doubles.
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

    fstream data_file(file_name, ios::binary | ios::in | ios::out);
    if (!data_file)
    {
        cout << file_name << " could not be opened." << endl;
        exit(1);
    }

    double multiplier;
    cout << "Enter multiplier: " << endl;
    cin >> multiplier;

    // Read ints from the file, multiply, and store back in the file
    cout << "Reading and updating ints..." << endl ; 
    for (int i = 1 ; i <= 10 ; i++) {

        // read the next int from the file, saving read pointer position
        int data ;  
        long long position = data_file.tellg() ;  
        data_file.read(reinterpret_cast <char *>(&data), sizeof(int)) ;  

        // display on the screen and multiply
        cout << data << " -> " ;  
        data = round(data * multiplier) ; 
        cout << data << endl ; 

        // set write ptr to read's initial position, write new number  
        data_file.seekp(position, ios::beg) ; 
        data_file.write(reinterpret_cast <char *>(&data), sizeof(int)) ;  
    }

    // Read doubles from the file, multiply, and store back in the file
    cout << "Reading and updating doubles..." << endl ; 
    for (int i = 1 ; i <= 10 ; i++) {

        // read the next double from the file, saving read pointer position
        double data ;  
        long long position = data_file.tellg() ;  
        data_file.read(reinterpret_cast <char *>(&data), sizeof(double)) ;  

        // display on the screen and multiply
        cout << data << " -> " ;  
        data = data * multiplier ; 
        cout << data << " (root of " << pow(data, 2) << ')' <<endl ; 

        // set write ptr to read's initial position, write new number  
        data_file.seekp(position, ios::beg) ; 
        data_file.write(reinterpret_cast <char *>(&data), sizeof(double)) ;  
    }

    data_file.close();
}