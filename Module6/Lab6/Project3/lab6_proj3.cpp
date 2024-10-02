/* lab6_proj3.cpp - creates two classes to demonstrate composition
 * Author: Jared Ziv
 * Module: 6
 * Project: 3 (lab)
 * Description:
 *      Creates two classes (TimeDate and Event). Uses TimeDate through composition of
 *      the Event class. Allows for the event class to track times and dates of starts
 *      and finishes with much less overhead due to the presence of the TimeDate class.
 *  Algorithm:
 *      Followed lab instructions.
 */
#include <iostream>
#include <string>

using namespace std;

class TimeDate
{
    private:
        int hour, minute, day;
        string month;
    public:
        //compiler was giving me issues, needed to add a default constructor
        TimeDate()
        {
            hour = 0;
            minute = 0;
            day = 0;
            month = "";
        }
        TimeDate(int hour, int minute, int day, string month)
        {
            this->hour = hour;
            this->minute = minute;
            this->day = day;
            this->month = month;
        }
        string getTimeDate()
        {
            string print_hour = to_string(hour);
            string am_pm = (hour < 12 ? "am" : "pm");
            if (hour == 0)
            {
                print_hour = "12";
            }
            else if (hour > 12)
            {
                print_hour = to_string(hour - 12);
            }
            return month + " " + to_string(day) + " at " +
                    print_hour + ":" + (minute < 10 ? "0" : "") +
                    to_string(minute) + am_pm;
        }
};

class Event
{
    private:
        TimeDate start_time, end_time;
        string description;
    public:
        Event(int start_hour, int start_minute, int start_day,
            string start_month, int end_hour, int end_minute,
            int end_day, string end_month, string description)
        {
            start_time = TimeDate(start_hour, start_minute, start_day, start_month);
            end_time = TimeDate(end_hour, end_minute, end_day, end_month);
            this->description = description;
        }

        string getEvent()
        {
            return description + " starts at " + start_time.getTimeDate() +
                    ", ends at " + end_time.getTimeDate();
        }
};

int main()
{
    Event party(17, 30, 14, "Oct.", 20, 30, 14, "Oct.", "My Brithday Party");
    cout << party.getEvent() << endl;

    Event ludum_dare(15, 0, 4, "Oct.", 23, 59, 7, "Oct.", "The 56th Ludum Dare game jam");
    cout << ludum_dare.getEvent();

    return 0;
}