#pragma once
#include <string>


class Numbers
{
    private:
        static const std::string
            less_than_20[20],
            tens[9],
            hundred,
            thousand;
        int number;
    public:
        Numbers(int); //constructor
        void print() const; //print function (const because class should not be altered)
    
};