#pragma once
#include "EString.h"
#include <iostream>

using namespace std;

//constructor
EString::EString(const char *original)
{
    //returns length of c str (*original)
    size = strlen(original);
    string = new char[size + 1];
    //copies the c str (*original) into the array (*string)
    strcpy(string, original);
}

//replace with another string object
void EString::change(const char *original)
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
EString::~EString()
{
    delete [] string;
    string = nullptr;
    size = 0;
}

//copy constructor
EString::EString(const EString &original)
{
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}
