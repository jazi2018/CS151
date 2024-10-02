#pragma once
#include <iostream>
#include <string>

using namespace std;

//this function is used for input validation within the class
string stringToLower(string input);

class DayOfYear
{
    private:
        static const string MONTHS[12];
        static const int DAYS_IN_MONTH[12];
        static const int ELAPSED_DAYS[12];
        int day;
    public:
        DayOfYear() { day = 1; }                //default constructor
        DayOfYear(int day) { this->day = day; } //paramaterized constructor
        DayOfYear(string month, int day)        //paramaterized constructor w string
        {
            //finding month index
            int idx = -1;
            for (int i = 0; i < 12; i++)
            {
                if (stringToLower(month) == stringToLower(MONTHS[i]))
                {
                    idx = i;
                }
            }
            //check if month input was valid
            if (idx == -1)
            {
                cout << "Invalid month input." << endl;
                exit(1);
            }

            //check validity of day
            if (day < 1 || day > DAYS_IN_MONTH[idx])
            {
                cout << "Invalid day input." << endl;
                exit(1);
            }

            //perform arithmetic to assign day value
            this->day = ELAPSED_DAYS[idx] + day;
        }

        DayOfYear operator++()        //prefix ++
        {
            this->day += 1;
            //if above 365, loop back to jan 1
            if (this->day > 365)
            {
                this->day = 1;
            }

            return *this;
        }

        DayOfYear operator++(int)     //postfix ++
        {
            //clone to return (this is a post increment)
            DayOfYear clone = *this;

            this->day += 1;

            if (this->day > 365)
            {
                this->day = 1;
            }
            
            return clone;
        }

        DayOfYear operator--()        //prefix --
        {
            this->day -= 1;
            //if less than jan 1, set to dec 31
            if (this->day < 1)
            {
                this->day = 365;
            }

            return *this;
        }

        DayOfYear operator--(int)     //postfix ++
        {
            DayOfYear clone = *this;

            this->day -= 1;

            if (this->day < 1)
            {
                this->day = 365;
            }

            return clone;
        }

        int getDay() const { return day; }      //day getter
    friend ostream & operator<<(ostream &out, const DayOfYear &doy);
};

const string DayOfYear::MONTHS[12] = {"January", "February", "March", "April", "May", "June", 
                                "July", "August", "September", "October", "November", "December"};
const int DayOfYear::DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int DayOfYear::ELAPSED_DAYS[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
                                        
string stringToLower(string input)
{
    //iterates thru whole string, converts to lower
    for (int i = 0; i < input.length(); i++)
    {
        tolower(input[i]);
    }

    return input;
}

ostream & operator<<(ostream &out, const DayOfYear &doy)
{
    /*
    If the day is greater than the elapsed days at the current index, it means
    it's a part of that month.
    i.e. Feb 1st = 32 elapsed days. This is > 31, and < 59, so it falls in Feb.
    Then, subtract the elapsed days to get the day of the month. 32 - 31 = Feb 1
    */
    //iterate through list of elapsed days backwards
    for (int i = 11; i >= 0; i--)
    {
        if (doy.day > doy.ELAPSED_DAYS[i])
        {
            //since the month is determined by the elapsed days, simple arithmetic calcs the day
            out << doy.MONTHS[i] << " " << doy.day - doy.ELAPSED_DAYS[i];
            return out;
        }
    }

    //if something goes wrong and out isn't returned in the loop, return out to keep the string
    //as it was
    return out;
}