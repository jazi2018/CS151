/* Instructor.h - Class describing an Instructor at MiraCosta.
 * Author:     <your name>
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Data members:
 *       department(string)
 *       is_permanent (bool)
 *       pay_rate (double)
 *       hours (double)
 *
 *    Functions:
 *       full constructor
 *       getters and setters for all data members
 *       showInfo
 */

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

using namespace std ;

         /*** Make this class a child of PersonAtMCC with public access ***/

class Instructor : public PersonAtMCC
{

    private:
        string department ;
        bool is_permanent ;
        double pay_rate ;
        double hours ;

    public :

        /**** Write the missing constructors for this class.  Use setters
              to assign values to members of the parent class, and
              assignment statements to assign values to member of
              this (the child) class. ****/

        Instructor(long id, string name, string address, string phone,
                   string department, bool is_permanent, double pay_rate, double hours)
        {
            setId(id); setName(name); setAddress(address); setPhone(phone);
            this->department = department; this->is_permanent = is_permanent;
            this->pay_rate = pay_rate; this->hours = hours;
        }

        // Getters for this class
        string getDepartment() const { return department ; }
        bool getIsPermanent() const { return is_permanent ; }
        double getPayRate() const { return pay_rate ; }
        double getHours() const { return hours ; }

        // Setters for this class only
        void setDepartment(string new_department) { department = new_department ; }
        void setIsPermanent(bool new_is_permanent) { is_permanent = new_is_permanent ; }
        void setPayRate(double new_pay_rate) { pay_rate = new_pay_rate ; }
        void setHours(double new_hours) { hours = new_hours ; }

        /**** COMPLETE THIS FUNCTION ****/

        // Display the instructor's info on the screen
        void showInfo() {
            //base class output
            cout << "ID: " << getId()
                 << "  Name: " << getName()
                 << "  Address: " << getAddress() << endl
                 << "    Phone: " << getPhone() << endl;
            
            //instructor class output
            cout << "    Department: " << getDepartment()
                 << "  Permanent?: " << (getIsPermanent() ? "Yes" : "No")
                 << "  Pay-Rate: " << getPayRate()
                 << "  Hours: " << getHours() << endl << endl;
        }
} ;

#endif
