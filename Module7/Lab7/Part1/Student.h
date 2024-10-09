/* Student.h - Describes students at MiraCosta (child of PersonAtMCC)
 * Author:     <your name>
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
                string major, int credits_recieved, bool applied_to_4_year,
                bool is_veteran) //parameterized constructor
        {
            setId(id); setName(name); setAddress(address); setPhone(phone);
            this->major = major; this->credits_received = credits_received;
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
                 << "  4-year? " << getAppliedTo4Year()
                 << "  Veteran? " << getIsVeteran() << endl << endl;

        }
} ;

#endif
