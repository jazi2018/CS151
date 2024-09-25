#pragma once
#include "String.h"
#include <iostream>

using namespace std;

//constructor
String::String(const char *original)
{
    //returns length of c str (*original)
    size = strlen(original);
    string = new char[size + 1];
    //copies the c str (*original) into the array (*string)
    strcpy(string, original);
}

//replace with another string object
void String::change(const char *original)
{
    delete [] string;
    size = strlen(original);
    //note size + 1 instead of size because strlen DOES NOT include terminating
    //NULL character, but strcpy copies the NULL character, so allocation must
    //account for that
    string = new char[size + 1];
    strcpy(string, original);
}

//destructor
String::~String()
{
    delete [] string;
    string = nullptr;
    size = 0;
}

//copy constructor
String::String(const String &original)
{
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

void print(const String &ptr)
{
    cout << ptr.string << endl;
    //9. if the friend statement inside the string class is commented out,
    //the print function no longer has access to the member variable and
    //there is a compiler error
}