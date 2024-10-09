/* Staff.h - Header for staff members at MCC
 * Author:     Jared Ziv
 * Module:     7
 * Project:    Lab
 * Description:
 *
 *    Child of PersonAtMCC
 *
 *    Data members:
 *       extension (string)
 *       hire_date (string)
 *       pay_rate (double)
 *
 *    Functions:
 *       full constructor
 *       getters and setters for extension, hire_date, and pay_rate
 *       showInfo
 */

#ifndef STAFF_H
#define STAFF_H

using namespace std ;

         /*** Make this class a child of PersonAtMCC with public access ***/

class Staff : public PersonAtMCC
{
    private :
        string extension ;
        string hire_date ;
        double pay_rate ;

    public :

        /**** Write the missing constructors for this class.  Use setters
              to assign values to members of the parent class, and
              assignment statement to assign values to members of
              this (the child) class. ****/
        Staff(long id, string name, string address, string phone,
              string extension, string hire_date, double pay_rate)
        {
            setId(id); setName(name); setAddress(address); setPhone(phone);
            this->extension = extension; this->hire_date = hire_date;
            this->pay_rate = pay_rate;
        }

        // Getters
        string getExtension() const { return extension ; }
        string getHireDate() const { return hire_date ; }
        double getPayRate() const { return pay_rate ; }

        // Setters
        void setExtension(string new_extension) { extension = new_extension ; }
        void setHireDate(string new_hire_date) { hire_date = new_hire_date ; }
        void setPayRate(double new_pay_rate) { pay_rate = new_pay_rate ; }

        /**** COMPLETE THIS FUNCTION ****/

        // Display the staff member's info on the screen
        void showInfo() {
            //base class output
            cout << "ID: " << getId()
                 << "  Name: " << getName()
                 << "  Address: " << getAddress() << endl
                 << "    Phone: " << getPhone() << endl;

            //staff class output
            cout << "    Extension: " << getExtension()
                 << "  Hire Date: " << getHireDate()
                 << "  Pay Rate: " << getPayRate() << endl << endl;
        }
} ;

#endif
