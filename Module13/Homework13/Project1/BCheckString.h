#pragma once
#include <string>
#include <exception>
using namespace std;

//exception to be thrown
struct BoundsException : public exception
{
    string message;
    BoundsException(int idx)
    {
        message = "Index " + to_string(idx) + " out of bounds";
    }
    virtual const char * what() const noexcept
    {
        return message.c_str();
    }
};

class BCheckString : public string
{
    public:
        //passes string to parent constructor
        BCheckString(string s) : string(s) {}
        char operator[](int k)
        {
            //check if k is out of bounds
            if (k < 0 || k >= this->length())
            {
                throw BoundsException(k);
            }

            //returns character at idx k if not oob
            return this->at(k);
        }
};