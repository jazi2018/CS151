/* Money.cpp - Represents money using separate variables for dollars and cents
 * Author:     Chris Merrill
 * Module:     6
 * Project:    Lab #2
 * Description:
 *   Uses two variables, one (long long) representing dollars and a
 *      second (an int) representing cents.  The cents should always be
 *      between 0 and 99.
 */

#pragma once
#include <string>
#include <iostream>
using namespace std ;

class Money {

    private:
        // Instance variables
        long long dollars = 0 ;
        int cents = 0 ;                  // should be between 0 and 99

    public:
        // constructor takes a String representing dollars and cents and
        // divides into a "dollars" and "cents" variables
        Money(string amount) {
            int index = amount.find(".") ;
            if (index == -1) {                   // no decimal point
                dollars = stol(amount) ;
                cents = 0 ;
           } else {
               if (index == 0) {                 // no dollars
                   amount = "0" + amount ;
                   index++ ;
               }
               dollars = stol(amount.substr(0, index)) ;
               cents = stoi(amount.substr(index + 1, amount.length())) ;
           }
        }

        // Copy constructor
        Money(Money &amount) {
            dollars = amount.dollars ;
            cents = amount.cents ;
        }

        // Move constructor
        Money(Money &&amount) {
            dollars = amount.dollars ;
            cents = amount.cents ;
        }

        // Assignment operator
        Money operator=(const Money &amount) {
            dollars = amount.dollars ;
            cents = amount.cents ;
            return *this ;
        }

        // Returns the money amount as a string
        string getAmount() const {
            string zero = (cents <= 9 ? "0" : "") ;
            return to_string(dollars) + "." + zero + to_string(cents) ;
        }

        // Provide an instance member function to override the + operator
        Money operator+(const Money &right) const
        {
            long long dollar_sum = this->dollars + right.dollars;
            int cent_sum = this->cents + right.cents;
            if (cent_sum > 99)
            {
                cent_sum -= 100;
                dollar_sum += 1;
            }

            //create string of dollar and cent values to pass to constructor
            string money_string = to_string(dollar_sum) + "." + to_string(cent_sum);
            Money sum(money_string);
            return sum;
        }

        // Provide an instance member function to override the >= operator
        bool operator>=(const Money &right) const
        {
            long long left_total = this->dollars * 100 + this->cents;
            long long right_total = right.dollars * 100 + right.cents;

            if (left_total >= right_total)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Provide a friend function that can be used to display the value
        // of the Money in a cout statement
    friend ostream & operator<<(ostream &out, const Money &amount);
} ;

ostream & operator<<(ostream &out, const Money &amount)
{
    if (amount.cents <= 9)
    {
        out << "$" << amount.dollars << ".0" << amount.cents;
    }
    else
    {
        out << "$" << amount.dollars << "." << amount.cents;
    }

    return out;
}