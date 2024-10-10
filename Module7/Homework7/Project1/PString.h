#pragma once
#include <iostream>
#include <string>

using namespace std;

class PString : public string
{
    public:
        PString(string obj) : string(obj) {} //string obj constructor
        PString(char *cstr) : string(cstr) {} //cstring constructor
        
        bool isPalindrome()
        {
            //define two iterators to go forward & backward through the string
            PString::iterator fwd_it = this->begin();
            PString::reverse_iterator bck_it = this->rbegin();
            
            //read through the string using the iterators while they arent at respective
            //ends of string
            while (fwd_it != this->end() && bck_it != this->rend())
            {
                //checks if the fwd iterator is equal to punctuation or a space (ASCII)
                while (*fwd_it >= 32 && *fwd_it <= 47)
                {
                    //iterates forward until it isnt
                    fwd_it++;
                    //if (during this loop) fwd_it reaches the end, the word string be a
                    //palendrome and true is returned
                    if (fwd_it == this->end())
                    {
                        return true;
                    }
                }
                //checks if the bck iterator is equal to punctuation or a space (ASCII)
                while (*bck_it >= 32 && *bck_it <= 47)
                {
                    //iterates 'forward' (reverse) until it isnt
                    bck_it++;
                    //if (during this loop) back_it reaches the reverse end, the string must
                    //be a palendrome and true is returned
                    if (bck_it == this->rend())
                    {
                        return true;
                    }
                }

                //once both iterators are NOT on punctuation or a space, check if
                //they are equivalent (tolower to ignore capitalization)
                if (tolower(*fwd_it) != tolower(*bck_it))
                {
                    //if they arent, its not a palendrome and false is returned
                    return false;
                }

                //iterate both and repeat loop until one reaches the end
                fwd_it++;
                bck_it++;
            }
            //if the loop is exited without returning false, the string is a palendrome
            return true;
        }
};