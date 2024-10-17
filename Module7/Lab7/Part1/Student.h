/* Student.h - Describes students at MiraCosta (child of PersonAtMCC)
 * Author:     Jared Ziv
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Child of PersonAtMCC
 *
 *    Data members:
 *       major (string)
 *       credits_received (int)
 *       applied_to_4_year (bool)
 *       is_veteran (bool)
 *
 *    Functions:
 *       full constructor
 *       getters and setters for all data members
 *       showInfo
 */

#ifndef STUDENT_H
#define STUDENT_H

using namespace std ;

         /*** Make this class a child of PersonAtMCC with public access ***/

class Student : public PersonAtMCC
{

    private :
        string major ;
        int credits_received ;
        bool applied_to_4_year ;
        bool is_veteran ;
        int test;

    public :

        /**** Write the missing constructors for this class.  Use setters
              to assign values to members of the parent class, and
              assignment statement to assign values to members of
              this (the child) class. ****/

        Student(long id, string name, string address, string phone, 
                string major, int credits, bool applied_to_4_year,
                bool is_veteran) //parameterized constructor
        {
            setId(id); setName(name); setAddress(address); setPhone(phone);
            this->major = major; this->credits_received = credits;
            /*
            With JUST credits_recieved, it gave an incorrect value if i used
            ' this->credits_received = credits_recieved '
            but gave a correct value for
            ' this->credits_recieved = credits ' (as long as parameter has a diff name)
            I have NO idea why it did this. The incorrect value was JUST for credits_recieved,
            and was ALWAYS -1163005939. It was always just that value, regardless of if I
            changed the order of parameters. In my github repo, I will include a screenshot of the
            incorrect output. If you know why it did that, please let me know!
            */
            this->applied_to_4_year = applied_to_4_year;
            this->is_veteran = is_veteran;
        }

        // Getters
        string getMajor() const { return major ; }
        int getCreditsReceived() const { return credits_received ; }
        bool getAppliedTo4Year() const { return applied_to_4_year ; }
        bool getIsVeteran() const { return is_veteran ; }

        // Setters
        void setMajor(string new_major) { major = new_major ; }
        void setCreditsReceived(int new_credits) { credits_received = new_credits ; }
        void setAppliedTo4Year(bool applied) { applied_to_4_year = applied ; }
        void setIsVeteran(bool new_is_veteran) { is_veteran = new_is_veteran ; }

        /**** COMPLETE THIS FUNCTION ****/

        // Display the student's info on the screen
        void showInfo() {
            //base class output
            cout << "ID: " << getId()
                 << "  Name: " << getName()
                 << "  Address: " << getAddress() << endl
                 << "    Phone: " << getPhone() << endl;
            
            //student class output
            cout << "    Major: " << getMajor()
                 << "  Credits: " << this->credits_received
                 << "  4-year? " << (getAppliedTo4Year() ? "Yes" : "No")
                 << "  Veteran? " << (getIsVeteran() ? "Yes" : "No") << endl << endl;

        }
} ;

#endif
