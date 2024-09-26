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

const std::string Numbers::less_than_20[] = {
    "zero", "one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "ten", "eleven", "twelve",
    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
    "eighteen", "nineteen"
};

const std::string Numbers::tens[] = {
    "ten", "twenty", "thirty", "fourty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
};

const std::string Numbers::hundred = "hundred";

const std::string Numbers::thousand = "thousand";