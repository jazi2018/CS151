#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class EString
{
    private:
        char *string;
        int size;
    public:
        EString(const char *s = ""); //constructor
        ~EString();                  //destructor
        EString(const EString &);     //copy constructor
        void change (const char *); //reassign string
        int getSize() { return this->size; } //getter for size
        EString & operator=(const EString &);
        EString operator++();
        EString operator++(int);
        char & operator[](int);
    
    friend std::ostream & operator<<(std::ostream &, const EString &);
    friend EString operator+(const EString &, const EString &);
};

EString & EString::operator=(const EString &original)
{
    delete [] string;
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
    return *this;
}

std::ostream & operator<<(std::ostream &out, const EString &output_EString)
{
    out << output_EString.string;
    return out;
}

EString EString::operator++()
{
    for (int i = 0; i < this->size; i++)
    {
        //checks if char is lowercase
        if (string[i] >= 97 && string[i] <= 122)
        {
            //converts char to uppercase
            string[i] -= 32;
        }
    }
    return *this;
}

EString EString::operator++(int)
{
    //make copy of object to return
    EString copy = *this;
    
    for (int i = 0; i < this->size; i++)
    {
        //checks if char is lowercase
        if (string[i] >= 97 && string[i] <= 122)
        {
            //converts char to uppercase
            string[i] -= 32;
        }
    }

    return copy;
}

char & EString::operator[](int idx)
{
    //if index is invalid exit the program
    if (idx < 0 || idx >= this->size)
    {
        cout << "Invalid index" << endl;
        exit;
    }

    return this->string[idx];
}

EString operator+(const EString &str1, const EString &str2)
{
    //calculate new size, dynamically allocate char array
    int new_size = str1.size + str2.size;
    char *temp_string = new char[new_size + 1];

    //copy string values into new char array
    strcpy(temp_string, str1.string);
    strcat(temp_string, str2.string);

    //create new EString object to return, delete temporary allocated memory
    EString str3(temp_string);
    delete [] temp_string;
    return str3;
}