#pragma once
#include <string>

using namespace std;

class EncryptableString : public string
{
    EncryptableString(string obj) : string(obj) {} //string obj constructor
    EncryptableString(char *cstr) : string(cstr) {} //cstring constructor

    void encrypt()
    {
        //iterate through the string
        for (int i = 0; i < this->size(); i++)
        {
            //checks if character is between 'a' and 'z' (z not inclusive)
            if (this->at(i) < 122 && this->at(i) >= 97)
            {
                //increment character
                this->at(i)++;
            }
            //checks if character is 'z'
            else if (this->at(i) == 122)
            {
                //wraps around to 'a'
                this->at(i) = 97;
            }
            //checks if character is between 'A' and 'Z' (Z not inclusive)
            else if (this->at(i) < 90 && this->at(i) >= 65)
            {
                this->at(i)++;
            }
            //checks if character is 'Z'
            else if (this->at(i) == 90)
            {
                //wraps around to 'A'
                this->at(i) = 65;
            }
            //checks if character is between '0' and '9' (9 not inclusive)
            else if (this->at(i) < 57 && this->at(i) >= 48)
            {
                this->at(i)++;
            }
            //checks if character is '9'
            else if (this->at(i) == 57)
            {
                //wraps around to '0'
                this->at(i) = 0;
            }
        }
    }
};