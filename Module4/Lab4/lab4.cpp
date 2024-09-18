/*
lab4.cpp - Manipulate a time variable to different formats
Author:     Jared Ziv
Module:     4
Project:    1 (Lab)
Problem Statement: Demonstrate different features of the <ctime> library, utilizing
        TZ, time_t, and tm features to convert between different formats and make
        dates more readable. Also stores different events in the tm structure.

Algorithm:
    1. 
*/
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    //initialize array of days and months
    string days[7] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    string months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    //not on server-based system, so did not change TZ environment

    //create time_t variable to current time
    time_t now = time(NULL);

    tm *local = localtime(&now);

    cout << "Using printf and the tm struct:" << endl;
    //m/d/yy
    printf("%d/%d/%d\n", local->tm_mon + 1, local->tm_mday, local->tm_year - 100);

    //Month d, yyyy
    /*
    had to do some troubleshooting, was giving me very strange output. turns out
    c++ and c strings are different, so had to call function c_str() to format the
    string correctly for output using printf
    */
    printf("%s %d, %d\n", months[local->tm_mon].c_str(), local->tm_mday, local->tm_year + 1900);

    //d-Mon-yyyy
    string month_shortened = months[local->tm_mon];
    month_shortened.resize(3);
    printf("%d-%s-%d\n", local->tm_mday, month_shortened.c_str(), local->tm_year + 1900);

    cout << endl << "Using strftime:" << endl;
    char buffer[80];
    //strftime mm/dd/yy
    strftime(buffer, 80, "%D", local);
    cout << buffer << endl;

    //strftime Month dd, yyyy
    strftime(buffer, 80, "%B %d, %Y", local);
    cout << buffer << endl;

    //strftime dd-Mon-yyyy
    strftime(buffer, 80, "%d-%b-%Y", local);
    cout << buffer << endl;

    cout << endl << "The current time is:" << endl;
    strftime(buffer, 80, "%I:%M %p  (12 hour time)\n%R     (24 hour time)", local);
    cout << buffer << endl;

    //declaring an event
    tm event; //the date listed on my birth certificate
    event.tm_year = 101;
    event.tm_mon = 9;
    event.tm_mday = 6;
    event.tm_hour = 13;
    event.tm_min = 32;
    event.tm_sec = 14; //seconds are a randomly chosen value (not originally listed)
    event.tm_isdst = 1;

    time_t time_of_birth = mktime(&event);
    cout << endl << "My birth occured on "
         << ctime(&time_of_birth)
         << "and occured " << time_of_birth
         << " seconds after epoch!" << endl;

    //calculate seconds in a week
    int week_sec = 7 * 24 * 60 * 60;
    long long week_prior = time_of_birth - week_sec;
    cout << "The week before was " << ctime(&week_prior) << endl;

    //output day of week and day number using strftime
    return 0;
}