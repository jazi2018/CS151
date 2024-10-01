#pragma once
#include <cstring>

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
        EString & operator=(const EString &);
    friend void print(const EString &);
    friend ostream & operator<<(ostream &out, const EString &output_EString);
};

EString & EString::operator=(const EString &original)
{
    delete [] string;
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
    return *this;
}