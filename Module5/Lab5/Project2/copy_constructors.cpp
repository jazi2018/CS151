/*
copy_constructors.cpp - Creates a class that mimics c++ strings and demonstrates use of friend keyword
Author:     Jared Ziv
Module:     5
Project:    2 (Lab)
Problem Statement: 

Algorithm:
    Followed instructions listed on lab page.
*/
#include "String.cpp"

void print_two(String str1, String str2);

int main()
{
    cout << "Create two strings, one using a constructor, "
         << "another an assignment statement" << endl;

    // Manipulate Strings using a constructor and an 
    // assignment statement  
    String str1("MiraCosta College"); // constructor
    String str2 = str1;               // copy constructor
    print_two(str1, str2); //this function uses the friend print()

    // Use the change function and print
    cout << "\n After changing string 2 using change()" << endl;
    str2.change("San Diego State");
    print_two(str1, str2);

    // Use the change function on string 1 and print
    cout << "\nAfter changing string 1 using change()" << endl ;  
    str1.change("UCSD");
    print_two(str1, str2);

    return 0;
}

void print_two(String str1, String str2)
{
    cout << "str1: ";
    print(str1);

    cout << "str2: ";
    print(str2);
}