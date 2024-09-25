#pragma once
#include <cstring>

class String
{
    private:
        char *string;
        int size;
    public:
        String(const char *s = ""); //constructor
        ~String();                  //destructor
        String(const String &);     //copy constructor
        void change (const char *); //reassign string
    
    friend void print(const String &);
};